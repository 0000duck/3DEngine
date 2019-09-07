#pragma once
#include <QMatrix4x4>
#include <QMap>

#include <QOpenGLShaderProgram>

class Shader
{
public:
    Shader();
    Shader(QMatrix4x4 projection, QMatrix4x4 model, QMatrix4x4 view);

    QOpenGLShaderProgram simpleShader;
    QOpenGLShaderProgram phongShader;
    QOpenGLShaderProgram lightShader;

    QMatrix4x4 projection;
    QMatrix4x4 model;
    QMatrix4x4 view;

    void shaderBind(QString &shader);
    void shaderUnbind(QString &shader);

    bool loadShader();
private:
    QMap<QString, QOpenGLShaderProgram*> shaders;

};

