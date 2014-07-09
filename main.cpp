#include "testsr7270.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestSR7270 w;
    w.show();

    return a.exec();
}
