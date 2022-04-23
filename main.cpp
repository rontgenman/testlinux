#include "tictactoew.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont myFont("Arial",22);
    a.setFont(myFont);
    tictactoew w;
    w.show();

    return a.exec();
}
