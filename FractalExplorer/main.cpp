#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QApplication::setWindowIcon(QIcon(":/icon/appIcon"));
    w.show();
    return a.exec();
}
