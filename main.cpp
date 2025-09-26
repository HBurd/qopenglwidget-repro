/* Project headers */
#include "demowindow.h"

/* Qt headers */
#include <QApplication>

int main(int argc, char **argv)
{
    QApplication application(argc, argv);
    DemoWindow window(nullptr);
    window.show();
    return application.exec();
}
