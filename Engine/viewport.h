#pragma once

#include <QOpenGLWindow>
#include <QOpenGLFunctions_4_3_Core>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLShaderProgram>

#include <QMatrix4x4>
#include <QVector>
#include <QVector3D>
#include <QDebug>
#include <QString>
#include <QMouseEvent>

#include "engine.h"

class Viewport : public QOpenGLWindow
{
  Q_OBJECT

public:
  Viewport();
  ~Viewport() override;

private:
  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;

  void mousePressEvent(QMouseEvent *e) override;
  void mouseMoveEvent(QMouseEvent *e) override;

  void printContextInformation();

  Engine *eng;

  QMatrix4x4 projection;

  QPoint m_lastPos;
  int m_yRot = 0;
  int m_xRot = 0;

public slots:
  void setXRotation(int angle);
  void setYRotation(int angle);

signals:
  void xRotationChanged(int angle);
  void yRotationChanged(int angle);

};
