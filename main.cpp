//#include "mainwindow.h"

//#include <QApplication>

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    return a.exec();
//}

#include <QApplication>
#include<QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPushButton HelloWorld("Hello World");
    HelloWorld.resize(300,60);
    HelloWorld.show();
    return a.exec();
}
