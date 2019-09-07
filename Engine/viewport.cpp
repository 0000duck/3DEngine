#include "viewport.h"
#include "shapes.cpp"
#include "Engine/import.h"

Viewport::Viewport() :
    eng(new Engine())
{
}

Viewport::~Viewport()
{
    delete eng;
    eng = nullptr;
}

void Viewport::initializeGL()
{
    printContextInformation();

    eng->initEngine();

    Import monkey("/home/semyon/Projects/QtProjects/MyEngine/resources/new.obj",
                   *eng->scene);

    eng->loadObjects();
}

void Viewport::resizeGL(int w, int h)
{
    float aspect = w / float(h);

    projection.setToIdentity();
    projection.perspective(45.0, aspect, 0.1f, 100);

    eng->scene->setProjection(projection);
}

void Viewport::paintGL()
{

    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    QMatrix4x4 view;
    view.setToIdentity();
    view.translate(0, 0, -10);
    view.rotate(m_xRot / 16.0f, 1, 0, 0);
    view.rotate(m_yRot / 16.0f, 0, 1, 0);

    eng->scene->setView(view);
    eng->scene->objects[0].drawObject(eng->shaderProgram->phongShader);
}

void Viewport::printContextInformation()
{
    QString glType;
    QString glVersion;
    QString glProfile;

    // Get Version Information
    glType = (context()->isOpenGLES()) ? "OpenGL ES" : "OpenGL";
    glVersion = reinterpret_cast<const char*>(glGetString(GL_VERSION));

    // Get Profile Information
    #define CASE(c) case QSurfaceFormat::c: glProfile = #c; break
    switch (format().profile())
    {
        CASE(NoProfile);
        CASE(CoreProfile);
        CASE(CompatibilityProfile);
    }
    #undef CASE

    // qPrintable() will print our QString w/o quotes around it.
    qDebug() << qPrintable(glType) << qPrintable(glVersion)
             << "(" << qPrintable(glProfile) << ")";
}

void Viewport::mousePressEvent(QMouseEvent *e)
{
    m_lastPos = e->pos();
}

void Viewport::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->x() - m_lastPos.x();
    int dy = e->y() - m_lastPos.y();

    if (e->buttons() & Qt::MiddleButton)
    {
        setXRotation(m_xRot + 8 * dy);
        setYRotation(m_yRot + 8 * dx);
    }
    m_lastPos = e->pos();
}

static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360 * 16)
        angle -= 360 * 16;
}

void Viewport::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != m_xRot)
    {
        m_xRot = angle;
        emit xRotationChanged(angle);
        update();
    }
}

void Viewport::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != m_yRot)
    {
        m_yRot = angle;
        emit yRotationChanged(angle);
        update();
    }
}