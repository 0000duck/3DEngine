#include "mesh.h"

Mesh::Mesh(QVector<Vertex> vertices,
           QVector<GLuint> indices)
           : ibo(QOpenGLBuffer::IndexBuffer)
{
    this->vertices = vertices;
    this->indices = indices;
}

Mesh::Mesh(const Mesh &mesh)
    : ibo(QOpenGLBuffer::IndexBuffer)
{
    this->vertices = mesh.vertices;
    this->indices = mesh.indices;

}

Mesh::~Mesh()
{
}

Mesh &Mesh::operator=(const Mesh &mesh)
{
    this->vertices = mesh.vertices;
    this->indices = mesh.indices;

    return *this;
}

void Mesh::Draw(QOpenGLShaderProgram &program,
                const QMatrix4x4 *projection, const QMatrix4x4 *view)
{
    program.bind();

    program.setUniformValue("projection", *projection);
    program.setUniformValue("view", *view);
    program.setUniformValue("model", model);
    program.setUniformValue("objectColor", QVector3D(0.0, 0.5, 0.75));
    program.setUniformValue("lightColor", QVector3D(1.0, 1.0, 1.0));
    program.setUniformValue("lightPos", QVector3D(1.0f, 1.0f, 2.0f));
    program.setUniformValue("Kd", QVector3D(1.0f, 1.0f, 1.0f));
    program.setUniformValue("Ld", QVector3D(1.0f, 1.0f, 1.0f));

    vao.bind();
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, nullptr);
    vao.release();
    program.release();
}

void Mesh::setupMesh()
{
    initializeOpenGLFunctions();
    vao.create();
    vbo.create();
    ibo.create();

    vao.bind();
    vbo.bind();
    vbo.allocate(vertices.data(),
                 vertices.length() * int(sizeof(Vertex)));

    ibo.bind();
    ibo.allocate(indices.data(),
                 indices.length() * int(sizeof(GLuint)));

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
                          sizeof(Vertex), nullptr);
    glEnableVertexAttribArray(0);

    // this var for more readable code
    void *offsetof_Normal = reinterpret_cast<void*>(
                            offsetof(Vertex, Normal));
    void *offsetof_texCoord = reinterpret_cast<void*>(
                            offsetof(Vertex, texCoord));

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,
                          sizeof(Vertex), offsetof_Normal);
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE,
                          sizeof(Vertex), offsetof_texCoord);
    glEnableVertexAttribArray(2);

    vbo.release();
    vao.release();
}
