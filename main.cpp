#include "mariacargo.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MariaCargo w;
    w.show();
    return a.exec();
}
