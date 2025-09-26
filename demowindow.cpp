#include "demowindow.h"

#include <QOpenGLContext>
#include <QOpenGLFunctions>

GLWidget::GLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
}


void GLWidget::paintGL()
{
    QOpenGLFunctions *gl = QOpenGLContext::currentContext()->functions();

    gl->glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    gl->glClear(GL_COLOR_BUFFER_BIT);

    // Schedule next frame
    update();
}


DemoWindow::DemoWindow(QWidget *parent)
    :QMainWindow(parent)
{
    setWindowTitle("QOpenGLWidget minimal reproduction");
    setMinimumSize(400, 300);

    GLWidget *glWidget = new GLWidget(this);
    setCentralWidget(glWidget);

    glWidget->update();
}
