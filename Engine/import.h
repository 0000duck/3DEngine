#pragma once
#include <QVector3D>
#include <QVector2D>
#include <QString>
#include <QOpenGLShaderProgram>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "mesh.h"
#include "object.h"
#include "scene.h"

class Import
{
public:
    Import(const char *pFile, Scene &sceneObj);

private:
    Assimp::Importer importer;
    const aiScene *scene;
    const char *pFile;
    QMatrix4x4 accTransform;

    bool loadScene();
    void nodeHandler(aiNode *node, Scene &sceneObj,
                     QMatrix4x4 &accTransform);
    Mesh meshHandler(aiMesh *mesh);

};

