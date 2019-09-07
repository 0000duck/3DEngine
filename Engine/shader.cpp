#include "shader.h"

Shader::Shader()
{
    shaders = {
        {"simpleshader", &simpleShader},
        {"phongshader", &phongShader},
        {"lightshader", &lightShader}
    };

}

Shader::Shader(QMatrix4x4 projection, QMatrix4x4 model, QMatrix4x4 view)
{
    this->projection = projection;
    this->model = model;
    this->view = view;
}

void Shader::shaderBind(QString &shader)
{
    shaders.value(shader)->bind();
}

void Shader::shaderUnbind(QString &shader)
{
    shaders.value(shader)->release();
}

bool Shader::loadShader()
{
    // load all shaders from Map
    QMap<QString, QOpenGLShaderProgram*>::const_iterator i = shaders.constBegin();
    while(i != shaders.constEnd())
    {
        QString path_to_vertShader = ":/" + i.key() + ".vert";
        QString path_to_fragShader = ":/" + i.key() + ".frag";

        if(!i.value()->addShaderFromSourceFile(QOpenGLShader::Vertex, path_to_vertShader))
            return false;
        if(!i.value()->addShaderFromSourceFile(QOpenGLShader::Fragment, path_to_fragShader))
            return false;
        if(!i.value()->link())
            return false;
        if(!i.value()->bind())
            return false;
        ++i;
    }

    return true;
}
