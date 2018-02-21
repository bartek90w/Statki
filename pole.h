#ifndef POLE_H
#define POLE_H
#include <QPushButton>
#include <QObject>
#include "enum.h"
class pole
        :public QPushButton
{
        Q_OBJECT
public:
    pole(QWidget *parent);
    stan_pola stan;
    ruch czyjruch;
    bool czy_wyswietlono;

public slots:
        void ruch();

};

#endif // POLE_H
