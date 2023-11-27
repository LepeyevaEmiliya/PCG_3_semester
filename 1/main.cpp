#include "mainwindow.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(720, 370);
    w.setWindowIcon(QIcon("1.png"));
    w.show();
    return a.exec();
}
