#include "widget.h"
#include <QApplication>
int map[24][24];
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
