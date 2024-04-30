#include "convertisseurtemp.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    convertisseurTemp w;
    w.show();
    return a.exec();
}
