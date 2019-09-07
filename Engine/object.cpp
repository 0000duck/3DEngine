#include "object.h"

Object::Object()
{
}

Object::~Object()
{
    projection = nullptr;
    view = nullptr;
}

void Object::drawObject(QOpenGLShaderProgram &program)
{
    for(int i = 0; i < meshes.size(); ++i)
    {
        meshes[i].Draw(program, projection, view);
    }
}

void Object::loadObj()
{
    for(int i = 0; i < meshes.size(); ++i)
    {
        meshes[i].setupMesh();
    }
}
