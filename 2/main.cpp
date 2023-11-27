#include "mainwindow.h"

#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWindow;

    mainWindow.setWindowTitle("Image Viewer");
    mainWindow.setWindowIcon(QIcon("загружено.png"));
    mainWindow.show();
    return app.exec();
}
