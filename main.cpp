//#include "mainwindow.h"

//#include <QApplication>

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    return a.exec();
//}

//#include <QApplication>
//#include<QPushButton>

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    QPushButton HelloWorld("Hello World");
//    HelloWorld.resize(300,60);
//    HelloWorld.show();
//    return a.exec();
//}

#include <QApplication>
#include <QFont>
#include <QPushButton>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.resize(200, 120);

    QPushButton quit("Quit", &window);
    quit.setFont(QFont("Times", 18, QFont::Bold));
    quit.setGeometry(10, 40, 180, 40);
    QObject::connect(&quit, SIGNAL(clicked()), &app, SLOT(quit()));

    window.show();
    return app.exec();
}

//def addBoard(self):
//    """Add board that will contain snake and food: create layout and checkboxes."""
//    self.widgets.checkboxes = []
//    for _ in range(self.settings.cellNum):
//        row = []

//        hl = QHBoxLayout()

//        for _ in range(self.settings.cellNum):
//            c = QCheckBox()
//            c.setEnabled(False)
//            hl.addWidget(c)
//            row.append(c)

//        self.widgets.checkboxes.append(row)
//        self.widgets.layout.addLayout(hl)
