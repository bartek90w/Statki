#include <QApplication>
#include "gra.h"
#include "plansza.h"
#include "statek.h"
#include "mainwindow.h"
#include <iostream>

using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();


}
