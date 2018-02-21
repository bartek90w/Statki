#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <windows.h>
#include <QThread>
#include <QApplication>
#include <QMessageBox>
#include "gra.h"

using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    game=new gra;
    rysowanie_plansz();
    setStyleSheet("background-image: url(:/tlo.bmp);");
    ui->label_3->setAlignment(Qt::AlignCenter);
    ui->label_4->setAlignment(Qt::AlignCenter);
    ui->label_6->setAlignment(Qt::AlignCenter);
    ui->label_5->setAlignment(Qt::AlignCenter);
    ui->label_7->setAlignment(Qt::AlignCenter);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::rysowanie_plansz()
{

    for(int i = 0; i < 10; ++i)
       {
        for (int j = 0;j < 10;j++)
          {
           game->plang.plan[i][j] = new pole(this);
           game->plang.plan[i][j]->setGeometry(25+40*i,105+j*40,40,40);
           game->plang.plan[i][j]->setText("");
           game->plang.plan[i][j]->setStyleSheet(QString::fromUtf8("background-image: url(:/nic.bmp);"));
           game->plang.plan[i][j]->czyjruch=komputer;
           game->plang.plan[i][j]->setDisabled(true);

           game->plank.plan[i][j] = new pole(this);
           game->plank.plan[i][j]->setGeometry(603+40*i,105+j*40,40,40);
           game->plank.plan[i][j]->setText("");
           game->plank.plan[i][j]->setStyleSheet(QString::fromUtf8("background-image: url(:/nic.bmp);"));
           QCursor kursor(Qt::PointingHandCursor);
           game->plank.plan[i][j]->setCursor(kursor);
           game->plank.plan[i][j]->setDisabled(true);
           connect(game->plank.plan[i][j],SIGNAL(clicked()),this,SLOT(ruch_komp()));

        }
    }
}

void MainWindow::wyswietlenie_gracza()
{
    int i,j,k,m;
    for(i = 0; i < 10; i++)
       {
        for (j = 0;j < 10;j++)
          {
            if(game->plank.plan[i][j]->stan==trafil && game->plank.plan[i][j]->czy_wyswietlono==false)
            {
            game->plank.plan[i][j]->czy_wyswietlono=true;
            for (k = 0;k < 10;k++)
            {
                for (m = 0;m < game->statki_komputera[k].zwroc_dlugosc();m++)
                {
                    if (game->statki_komputera[k].wspolrzedne_x[m] == i && game->statki_komputera[k].wspolrzedne_y[m] == j) game->status=game->statki_komputera[k].sprawdz_zatopienie(game->plank);
                }
            }
            if(game->status==zatopiony) ui->label_6->setText("Trafiony zatopiony");
            else if(game->status==trafiony) ui->label_6->setText("Trafiony");
            }
            else if(game->plank.plan[i][j]->stan==pudlo && game->plank.plan[i][j]->czy_wyswietlono==false)
            {
                ui->label_6->setText("Pudło");
                game->plank.plan[i][j]->czy_wyswietlono=true;
            }
        }
    }
}

void MainWindow::kto_zaczyna()
{
    int i;
    i = rand() % 2;
    if(i==0) ui->label_3->setText("Ruch gracza");
    else
    {
        ui->label_3->setText("Ruch komputera");
        game->plank.plan[0][0]->czyjruch=komputer;
        ruch_komp();

    }
}

void MainWindow::ruch_komp()
{
    wyswietlenie_gracza();
    czy_koniec_gracz();
    if(game->stang==trwa)
    {
                if(gra::czyj_ruch==komputer)
                {
                    while(gra::czyj_ruch==komputer)
                    {
                        ui->label_3->setText("Ruch komputera");
                        QApplication::processEvents();
                        QThread::sleep(2);
                        game->ruch_komputera(game->plang);
                        if(game->status==trafiony) ui->label_4->setText("Trafiony");
                        else if(game->status==pudl) ui->label_4->setText("Pudło");
                        else if(game->status==zatopiony) ui->label_4->setText("Trafiony zatopiony");
                        czy_koniec_komputer();
                        if(game->stang==koniec) break;
                    }
                    gra::czyj_ruch=gracz;
                }
        if(game->stang==trwa)
        ui->label_3->setText("Ruch gracza");

    }
}

void MainWindow::poziom1()
{
    game->poziom=latwy;
    ui->label_7->setText("Łatwy");
    kto_zaczyna();
}

void MainWindow::poziom2()
{
    game->poziom=trudny;
    ui->label_7->setText("Trudny");
    kto_zaczyna();
}

void MainWindow::on_pushButton_2_clicked()
{
    nowa_gra();
    QMessageBox msgbox;
    msgbox.setText("Wybierz poziom trudnosci");
    msgbox.setStandardButtons(0);
    QPushButton* latwy = new QPushButton("Łatwy");
    msgbox.addButton(latwy ,QMessageBox::AcceptRole);
    connect(latwy,SIGNAL(clicked()),this,SLOT(poziom1()));
    QPushButton* trudny = new QPushButton("Trudny");
    msgbox.addButton(trudny ,QMessageBox::AcceptRole);
    connect(trudny,SIGNAL(clicked()),this,SLOT(poziom2()));
    msgbox.exec();
}

void MainWindow::nowa_gra()
{
    delete game;
    game=new gra;
    ui->label_4->setStyleSheet(QString::fromUtf8("background-image: url(:/napis.jpg); color: white;"));
    ui->label_6->setStyleSheet(QString::fromUtf8("background-image: url(:/napis.jpg); color: white;"));
    ui->label_5->setText("Poziom: ");
    ui->label_3->setText("");
    ui->label_4->setText("");
    ui->label_6->setText("");
    ui->label_7->setText("");
    game->rozstawienie_statkow_gracza(game->plang);
    game->rozstawienie_statkow_komputera(game->plank);
    for(int i = 0; i < 10; ++i)
       {
        for (int j = 0;j < 10;j++)
          {
            if(game->plang.tablica[i][j]=='X') game->plang.plan[i][j]->stan=stat;
            else game->plang.plan[i][j]->stan=nic;
            if(game->plang.plan[i][j]->stan==stat) game->plang.plan[i][j]->setStyleSheet(QString::fromUtf8("background-image: url(:/statek.bmp);"));
            else game->plang.plan[i][j]->setStyleSheet(QString::fromUtf8("background-image: url(:/nic.bmp);"));

            if(game->plank.tablica[i][j]=='X') game->plank.plan[i][j]->stan=stat;
            else game->plank.plan[i][j]->stan=nic;
            game->plank.plan[i][j]->setStyleSheet(QString::fromUtf8("background-image: url(:/nic.bmp);"));
            game->plank.plan[i][j]->czy_wyswietlono=false;
            QCursor kursor(Qt::PointingHandCursor);
            game->plank.plan[i][j]->setCursor(kursor);
            game->plank.plan[i][j]->setEnabled(true);

        }
    }

}

void MainWindow::czy_koniec_gracz()
{
    int k;
    for (k = 0;k < 10;k++)
    {
            if (game->statki_komputera[k].stan_statku==zatopiony) game->stang=koniec;
            else game->stang=trwa;
            if (game->stang==trwa) break;
        }
    if(game->stang==koniec)
    {
        kto_wygral=gracz;
        koniec_gry();
    }
}

void MainWindow::czy_koniec_komputer()
{
    int k;
    for (k = 0;k < 10;k++)
    {
            if (game->statki_gracza[k].stan_statku==zatopiony) game->stang=koniec;
            else game->stang=trwa;
            if (game->stang==trwa) break;
        }
    if(game->stang==koniec)
    {
        kto_wygral=komputer;
        koniec_gry();
    }

}

void MainWindow::koniec_gry()
{
    int i,j;
    for(i = 0; i < 10; ++i)
       {
        for (j = 0;j < 10;j++)
          {
               game->plank.plan[i][j]->setDisabled(true);
        }
    }
    QMessageBox msgbox;
    if(kto_wygral==gracz)
    msgbox.setText("Koniec gry! Wygrał gracz.");
    else msgbox.setText("Koniec gry! Wygrał komputer.");
    ui->label_3->setText("Koniec gry!");
    msgbox.exec();

}
