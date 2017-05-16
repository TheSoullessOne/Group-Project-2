#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setWindowState(Qt::WindowMaximized);        // Sets the window to full screen

    return a.exec();
}
