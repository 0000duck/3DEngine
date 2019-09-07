#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Engine/viewport.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Viewport *viewport = new Viewport;
    QWidget *container = QWidget::createWindowContainer(viewport);

    ui->viewport->addWidget(container);
}

MainWindow::~MainWindow()
{
    delete ui;
}
