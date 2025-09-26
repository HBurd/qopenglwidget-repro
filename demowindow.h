#ifndef IMGUIWRAPPER_DEMOWINDOW_H
#define IMGUIWRAPPER_DEMOWINDOW_H

#include <QMainWindow>
#include <QOpenGLWidget>
#include <QWidget>


class GLWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    GLWidget(QWidget *parent = nullptr);

protected:
    void paintGL() override;
};




class DemoWindow : public QMainWindow
{
    Q_OBJECT
public:
    DemoWindow(QWidget *parent = nullptr);
};

#endif
