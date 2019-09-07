#pragma once

#include <QVector3D>
#include <QVector2D>
#include <QVector>

struct VertexData{
  QVector3D pos;
  QVector3D normal;
  QVector2D texCoord;
};

#define VERTEX_FTR {QVector3D( 1.0f,  1.0f,  1.0f), QVector3D( 0.0f, 0.0f, 1.0f ), QVector2D(1, 1)}
#define VERTEX_FTL {QVector3D(-1.0f,  1.0f,  1.0f), QVector3D( 0.0f, 1.0f, 0.0f ), QVector2D(0, 1)}
#define VERTEX_FBL {QVector3D(-1.0f, -1.0f,  1.0f), QVector3D( 0.0f, 0.0f, 1.0f ), QVector2D(0, 0)}
#define VERTEX_FBR {QVector3D( 1.0f, -1.0f,  1.0f), QVector3D( 0.0f, 0.0f, 0.0f ), QVector2D(1, 0)}

// Back Verticies
#define VERTEX_BTR {QVector3D( 1.0f,  1.0f, -1.0f), QVector3D( 1.0f, 1.0f, 0.0f ), QVector2D(1, 1)}
#define VERTEX_BTL {QVector3D(-1.0f,  1.0f, -1.0f), QVector3D( 0.0f, 1.0f, 1.0f ), QVector2D(0, 1)}
#define VERTEX_BBL {QVector3D(-1.0f, -1.0f, -1.0f), QVector3D( 1.0f, 0.0f, 1.0f ), QVector2D(0, 0)}
#define VERTEX_BBR {QVector3D( 1.0f, -1.0f, -1.0f), QVector3D( 1.0f, 1.0f, 1.0f ), QVector2D(1, 0)}

//// Create a colored cube
extern QVector<VertexData> cube_vertexes = {
  // Face 1 (Front)
    VERTEX_FTR, VERTEX_FTL, VERTEX_FBL,
    VERTEX_FBL, VERTEX_FBR, VERTEX_FTR,
  // Face 2 (Back)
    VERTEX_BBR, VERTEX_BTL, VERTEX_BTR,
    VERTEX_BTL, VERTEX_BBR, VERTEX_BBL,
  // Face 3 (Top)
    VERTEX_FTR, VERTEX_BTR, VERTEX_BTL,
    VERTEX_BTL, VERTEX_FTL, VERTEX_FTR,
  // Face 4 (Bottom)
    VERTEX_FBR, VERTEX_FBL, VERTEX_BBL,
    VERTEX_BBL, VERTEX_BBR, VERTEX_FBR,
  // Face 5 (Left)
    VERTEX_FBL, VERTEX_FTL, VERTEX_BTL,
    VERTEX_FBL, VERTEX_BTL, VERTEX_BBL,
  // Face 6 (Right)
    VERTEX_FTR, VERTEX_FBR, VERTEX_BBR,
    VERTEX_BBR, VERTEX_BTR, VERTEX_FTR
};

QVector<VertexData> vertices = {
    // Vertex data for face 0
    {QVector3D(-1.0f, -1.0f,  1.0f), QVector3D(0, 0, 1), QVector2D(0.0f, 0.0f)},  // v0
    {QVector3D( 1.0f, -1.0f,  1.0f),  QVector3D(0, 0, 1), QVector2D(0.33f, 0.0f)}, // v1
    {QVector3D(-1.0f,  1.0f,  1.0f),  QVector3D(0, 0, 1),  QVector2D(0.0f, 0.5f)},  // v2
    {QVector3D( 1.0f,  1.0f,  1.0f),  QVector3D(0, 0, 1), QVector2D(0.33f, 0.5f)}, // v3

    // Vertex data for face 1
    {QVector3D( 1.0f, -1.0f,  1.0f), QVector3D(1, 0, 0), QVector2D( 0.0f, 0.5f)}, // v4
    {QVector3D( 1.0f, -1.0f, -1.0f), QVector3D(1, 0, 0), QVector2D(0.33f, 0.5f)}, // v5
    {QVector3D( 1.0f,  1.0f,  1.0f), QVector3D(1, 0, 0), QVector2D(0.0f, 1.0f)},  // v6
    {QVector3D( 1.0f,  1.0f, -1.0f), QVector3D(1, 0, 0), QVector2D(0.33f, 1.0f)}, // v7

    // Vertex data for face 2
    {QVector3D( 1.0f, -1.0f, -1.0f), QVector3D(0, 0, -1), QVector2D(0.66f, 0.5f)}, // v8
    {QVector3D(-1.0f, -1.0f, -1.0f), QVector3D(0, 0, -1), QVector2D(1.0f, 0.5f)},  // v9
    {QVector3D( 1.0f,  1.0f, -1.0f), QVector3D(0, 0, -1), QVector2D(0.66f, 1.0f)}, // v10
    {QVector3D(-1.0f,  1.0f, -1.0f), QVector3D(0, 0, -1), QVector2D(1.0f, 1.0f)},  // v11

    // Vertex data for face 3
    {QVector3D(-1.0f, -1.0f, -1.0f), QVector3D(-1, 0, 0), QVector2D(0.66f, 0.0f)}, // v12
    {QVector3D(-1.0f, -1.0f,  1.0f), QVector3D(-1, 0, 0), QVector2D(1.0f, 0.0f)},  // v13
    {QVector3D(-1.0f,  1.0f, -1.0f), QVector3D(-1, 0, 0), QVector2D(0.66f, 0.5f)}, // v14
    {QVector3D(-1.0f,  1.0f,  1.0f), QVector3D(-1, 0, 0), QVector2D(1.0f, 0.5f)},  // v15

    // Vertex data for face 4
    {QVector3D(-1.0f, -1.0f, -1.0f), QVector3D(0, -1, 0), QVector2D(0.33f, 0.0f)}, // v16
    {QVector3D( 1.0f, -1.0f, -1.0f), QVector3D(0, -1, 0), QVector2D(0.66f, 0.0f)}, // v17
    {QVector3D(-1.0f, -1.0f,  1.0f), QVector3D(0, -1, 0), QVector2D(0.33f, 0.5f)}, // v18
    {QVector3D( 1.0f, -1.0f,  1.0f), QVector3D(0, -1, 0), QVector2D(0.66f, 0.5f)}, // v19

    // Vertex data for face 5
    {QVector3D(-1.0f,  1.0f,  1.0f), QVector3D(0, 1, 0), QVector2D(0.33f, 0.5f)}, // v20
    {QVector3D( 1.0f,  1.0f,  1.0f), QVector3D(0, 1, 0), QVector2D(0.66f, 0.5f)}, // v21
    {QVector3D(-1.0f,  1.0f, -1.0f), QVector3D(0, 1, 0), QVector2D(0.33f, 1.0f)}, // v22
    {QVector3D( 1.0f,  1.0f, -1.0f), QVector3D(0, 1, 0), QVector2D(0.66f, 1.0f)}  // v23
};

extern ushort indices[] = {
     0,  1,  2,  3,  3,     // Face 0 - triangle strip ( v0,  v1,  v2,  v3)
     4,  4,  5,  6,  7,  7, // Face 1 - triangle strip ( v4,  v5,  v6,  v7)
     8,  8,  9, 10, 11, 11, // Face 2 - triangle strip ( v8,  v9, v10, v11)
    12, 12, 13, 14, 15, 15, // Face 3 - triangle strip (v12, v13, v14, v15)
    16, 16, 17, 18, 19, 19, // Face 4 - triangle strip (v16, v17, v18, v19)
    20, 20, 21, 22, 23      // Face 5 - triangle strip (v20, v21, v22, v23)
};

#undef VERTEX_BBR
#undef VERTEX_BBL
#undef VERTEX_BTL
#undef VERTEX_BTR

#undef VERTEX_FBR
#undef VERTEX_FBL
#undef VERTEX_FTL
#undef VERTEX_FTR
