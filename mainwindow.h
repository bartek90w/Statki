#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QObject>
#include "plansza.h"
#include "enum.h"
#include "gra.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void ruch_komp();
    void on_pushButton_2_clicked();
    void poziom1();
    void poziom2();

private:
    Ui::MainWindow *ui;
    gra *game;
    void rysowanie_plansz();
    void nowa_gra();
    void wyswietlenie_gracza();
    void kto_zaczyna();
    void czy_koniec_gracz();
    void czy_koniec_komputer();
    void koniec_gry();
    ruch kto_wygral;

};

#endif // MAINWINDOW_H
