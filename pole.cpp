#include "pole.h"
#include "mainwindow.h"
#include <QThread>
#include <QApplication>
#include "gra.h"

pole::pole(QWidget *parent):    QPushButton(parent)
{
    connect(this,SIGNAL(clicked()),this,SLOT(ruch()));
    czyjruch=gracz;
    czy_wyswietlono=false;
}

void pole::ruch()
{
    if(stan==stat)
    {
        setStyleSheet(QString::fromUtf8("background-image: url(:/trafiony.bmp);"));
        stan=trafil;
        gra::czyj_ruch=gracz;
        setDisabled(true);
    }
    else if(stan==nic)
    {
        setStyleSheet(QString::fromUtf8("background-image: url(:/pudlo.bmp);"));
        stan=pudlo;
        gra::czyj_ruch=komputer;
        setDisabled(true);
    }

    QCursor kursor(Qt::ArrowCursor);
    setCursor(kursor);


}
