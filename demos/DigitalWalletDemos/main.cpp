#include "hello1.h"
#include <QMainWindow>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);  // show phần hello
    hello1 w;
    w.show();
    return app.exec();
}
