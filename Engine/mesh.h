#pragma once

#include <QVector3D>
#include <QVector2D>
#include <QVector>
#include <QOpenGLFunctions_4_3_Core>
#include <QOpenGLFunctions>
#include <QOpenGLTexture>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>

struct Vertex
{
  QVector3D pos;
  QVector3D Normal;
  QVector2D texCoord;
};

struct Texture
{
    quint8 id;
    QString type;
};

class Mesh : protected QOpenGLFunctions_4_3_Core
{
public:

    Mesh(QVector<Vertex> vertices,
         QVector<GLuint> indices);

    ~Mesh();

    Mesh(const Mesh &mesh); // Copy constructor
    Mesh& operator=(const Mesh &mesh);

    void Draw(QOpenGLShaderProgram &program,
              const QMatrix4x4 *projection, const QMatrix4x4 *view);

    QVector<Vertex> vertices;
    QVector<Texture> textures;
    QVector<GLuint> indices;

    QMatrix4x4 model;

    void setupMesh();
private:
    QOpenGLBuffer vbo;
    QOpenGLBuffer ibo;
    QOpenGLVertexArrayObject vao;
};
