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
#include <QCheckBox>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>
#include <QtWidgets/QMainWindow>
#include <QKeyEvent>


#define BOARD_SIZE 5


class Win : public QWidget {

public:
    Win(QWidget *parent = nullptr);

protected:
    void keyPressEvent( QKeyEvent *event );

private:
    int x = 0;
    int y = 0;

    QCheckBox* checkboxes[BOARD_SIZE][BOARD_SIZE];


    void down();
    void stateToCheckboxes();
    void up();
    void right();
    void left();
};

Win::Win(QWidget *parent)
    : QWidget(parent) {

    //  auto *frame1 = new QFrame(this);
    //  frame1->setFrameStyle(QFrame::Box);
    //  frame1->setCursor(Qt::SizeAllCursor);

    //  auto *frame2 = new QFrame(this);
    //  frame2->setFrameStyle(QFrame::Box);
    //  frame2->setCursor(Qt::WaitCursor);

    //  auto *frame3 = new QFrame(this);
    //  frame3->setFrameStyle(QFrame::Box);
    //  frame3->setCursor(Qt::PointingHandCursor);

    //  auto *grid = new QGridLayout(this);
    //  grid->addWidget(frame1, 0, 0);
    //  grid->addWidget(frame2, 0, 1);
    //  grid->addWidget(frame3, 0, 2);

    //  setLayout(grid);

    auto *vbox = new QVBoxLayout();
    //    vbox->setSpacing(1);

    //    QCheckBox c("1", &window);
    this->setLayout(vbox);

    //    auto *settings = new QPushButton("Settings", window);
    //    vbox->addWidget(settings);

    for (int y = 0; y < BOARD_SIZE; y++) {
        auto *hl = new QHBoxLayout();
        for (int x = 0; x < BOARD_SIZE; x++) {
            auto *cb = new QCheckBox("x: " + QString::number(x) + "| y: " +QString::number(y));
            cb->setDisabled(true);
            hl->addWidget(cb);
            this->checkboxes[y][x] = cb;
        }
        vbox->addLayout(hl);
    }

    this->stateToCheckboxes();
}

void Win::keyPressEvent( QKeyEvent *event )
{
    qDebug() << "x: " + QString::number(this->x) + "| y: " +QString::number(this->y);
    switch( event->key() )
    {
    case Qt::Key_Up:
        qDebug() << "Key Up pressed";
        this->up();
        break;

    case Qt::Key_Down:
        qDebug() << "Key Down pressed";
        this->down();
        break;

    case Qt::Key_Right:
        qDebug() << "Key Right pressed";
        this->right();
        break;

    case Qt::Key_Left:
        qDebug() << "Key Left pressed";
        this->left();
        break;


    default:
        qDebug() << "Key pressed:" << event->key();
        break;
    }
    this->stateToCheckboxes();
}

void Win::down()
{
    if (y >= BOARD_SIZE - 1)
        y = 0;
    else
        y++;
}


void Win::right()
{
    if (x >= BOARD_SIZE - 1)
        x = 0;
    else
        x++;
}

void Win::up()
{
    if (y <= 0)
        y = BOARD_SIZE - 1;
    else
        y--;
}


void Win::left()
{
    if (x <= 0)
        x = BOARD_SIZE - 1;
    else
        x--;
}

void Win::stateToCheckboxes()
{
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            qDebug() << "y == this->y && x == this->x: " << QString::number(y == this->y && x == this->x);
            this->checkboxes[y][x]->setChecked(y == this->y && x == this->x);
        }
    }
}



//void addCheckboxes(QWidget *window) {

//    auto *vbox = new QVBoxLayout();
////    vbox->setSpacing(1);

////    QCheckBox c("1", &window);
//    window->setLayout(vbox);

////    auto *settings = new QPushButton("Settings", window);
////    vbox->addWidget(settings);

//    for (int y = 0; y < BOARD_SIZE; y++) {
//        auto *hl = new QHBoxLayout();
//        for (int x = 0; x < BOARD_SIZE; x++) {
//            auto *cb = new QCheckBox("x: " + QString::number(x) + "| y: " +QString::number(y));
//            hl->addWidget(cb);
//        }
//        vbox->addLayout(hl);
//    }
//}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //    QWidget window;
    Win window;
    window.resize(200, 120);

    //    QPushButton quit("Quit", &window);
    //    quit.setFont(QFont("Times", 18, QFont::Bold));
    //    quit.setGeometry(10, 40, 180, 40);
    //    QObject::connect(&quit, SIGNAL(clicked()), &app, SLOT(quit()));

    //    addCheckboxes(&window);

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
