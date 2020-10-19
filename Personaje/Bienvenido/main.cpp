#include "mainbienvenido.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainBienvenido w;
    w.setGeometry( 300, 50, 500,600 );
    w.show();
    return a.exec();
}
