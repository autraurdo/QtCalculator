#include "mainwindow.h"
#include "actions.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Actions w;
    w.show();
    return a.exec();
}
