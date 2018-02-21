#include "gra.h"
#include "plansza.h"
#include "statek.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <stdlib.h>
#include <QThread>
#include <QApplication>

using namespace std;

gra::gra()
{
    stang = trwa;
    srand(time(NULL));
    czyj_ruch=komputer;
    czy_zatopil=true;
    czy_losowac=true;
}


gra::~gra()
{
}

ruch gra::czyj_ruch;

void gra::losuj_statek(plansza & plan,statek & stat)
{
    int i, j, m, n;
    unsigned int k = 0, kierun,l=9;
    bool czy_mozna;
    bool czy_postawiony = false;
    while(czy_postawiony==false)
    {
        czy_mozna = true;
        i = rand() % 10;
        j = rand() % 10;
        m = i;
        n = j;
        kierun = rand()%4;
        switch (kierun)
        {
        case 0: stat.kierunek = gora;
            break;

        case 1: stat.kierunek = prawo;
            break;

        case 2: stat.kierunek = dol;
            break;

        case 3: stat.kierunek = lewo;
            break;

        }
        if (plan.tablica[i][j] == '|' && stat.kierunek == gora && j >= stat.zwroc_dlugosc() - 1)
        {
            k = 0;
            while (k < stat.zwroc_dlugosc() && czy_mozna == true)
            {
                if (plan.tablica[i][j] == '|')
                {
                    czy_mozna = true;
                    k++;
                    j--;
                }
                else czy_mozna = false;
            }
            k = 0;
            if (czy_mozna == true)
            {
                for (i = m - 1;i <= m + 1;i++)
                {
                     if (i >= 0 && i <= l && n + 1 >= 0 && n + 1 <= l) plan.tablica[i][n + 1] = 'O';
                }
                while (k < stat.zwroc_dlugosc())
                {
                    plan.tablica[m][n] = 'X';
                    stat.wspolrzedne_x.push_back(m);
                    stat.wspolrzedne_y.push_back(n);
                    if (m - 1 >= 0) plan.tablica[m - 1][n] = 'O';
                    if (m + 1 <= l) plan.tablica[m + 1][n] = 'O';
                    k++;
                    n--;
                }
                czy_postawiony = true;
                for (i = m - 1;i <= m + 1;i++)
                {
                    if (i >= 0 && i <= l && n >= 0 && n <= l) plan.tablica[i][n] = 'O';
                }

            }
        }

        if (plan.tablica[i][j] == '|' && stat.kierunek == prawo && i <= l-stat.zwroc_dlugosc()+1)
        {
            k = 0;
            while (k < stat.zwroc_dlugosc() && czy_mozna == true)
            {
                if (plan.tablica[i][j] == '|')
                {
                    czy_mozna = true;
                    k++;
                    i++;
                }
                else czy_mozna = false;
            }
            k = 0;
            if (czy_mozna == true)
            {
                for (i = n - 1;i <= n + 1;i++)
                {
                    if (i >= 0 && i <= l && m - 1 >= 0 && m - 1 <= l) plan.tablica[m-1][i] = 'O';
                }
                while (k < stat.zwroc_dlugosc())
                {
                    plan.tablica[m][n] = 'X';
                    stat.wspolrzedne_x.push_back(m);
                    stat.wspolrzedne_y.push_back(n);
                    if (n - 1 >= 0) plan.tablica[m][n-1] = 'O';
                    if (n + 1 <= l) plan.tablica[m][n+1] = 'O';
                    k++;
                    m++;
                }
                czy_postawiony = true;
                for (i = n - 1;i <= n + 1;i++)
                {
                    if (i >= 0 && i <= l && m >= 0 && m <= l) plan.tablica[m][i] = 'O';
                }

            }
        }

        if (plan.tablica[i][j] == '|' && stat.kierunek == dol && j <= l-stat.zwroc_dlugosc()+1)
        {
            k = 0;
            while (k < stat.zwroc_dlugosc() && czy_mozna == true)
            {
                if (plan.tablica[i][j] == '|')
                {
                    czy_mozna = true;
                    k++;
                    j++;
                }
                else czy_mozna = false;
            }
            k = 0;
            if (czy_mozna == true)
            {
                for (i = m - 1;i <= m + 1;i++)
                {
                    if (i >= 0 && i <= l && n - 1 >= 0 && n - 1 <= l) plan.tablica[i][n - 1] = 'O';
                }
                while (k < stat.zwroc_dlugosc())
                {
                    plan.tablica[m][n] = 'X';
                    stat.wspolrzedne_x.push_back(m);
                    stat.wspolrzedne_y.push_back(n);
                    if (m - 1 >= 0) plan.tablica[m - 1][n] = 'O';
                    if (m + 1 <= l) plan.tablica[m + 1][n] = 'O';
                    k++;
                    n++;
                }
                czy_postawiony = true;
                for (i = m - 1;i <= m + 1;i++)
                {
                    if (i >= 0 && i <= l && n >= 0 && n <= l) plan.tablica[i][n] = 'O';
                }

            }
        }

        if (plan.tablica[i][j] == '|' && stat.kierunek == lewo && i >= stat.zwroc_dlugosc() - 1)
        {
            k = 0;
            while (k < stat.zwroc_dlugosc() && czy_mozna == true)
            {
                if (plan.tablica[i][j] == '|')
                {
                    czy_mozna = true;
                    k++;
                    i--;
                }
                else czy_mozna = false;
            }
            k = 0;
            if (czy_mozna == true)
            {
                for (i = n - 1;i <= n + 1;i++)
                {
                    if (i >= 0 && i <= l && m + 1 >= 0 && m + 1 <= l) plan.tablica[m + 1][i] = 'O';
                }
                while (k < stat.zwroc_dlugosc())
                {
                    plan.tablica[m][n] = 'X';
                    stat.wspolrzedne_x.push_back(m);
                    stat.wspolrzedne_y.push_back(n);
                    if (n - 1 >= 0) plan.tablica[m][n - 1] = 'O';
                    if (n + 1 <= l) plan.tablica[m][n + 1] = 'O';
                    k++;
                    m--;
                }
                czy_postawiony = true;
                for (i = n - 1;i <= n + 1;i++)
                {
                    if (i >= 0 && i <= l && m >= 0 && m <= l) plan.tablica[m][i] = 'O';
                }

            }
        }
    }
}

void gra::ruch_komputera_latwy(plansza &p)
{
    int i, j, k, m;
    int l=9;
    i = rand() % 10;
    j = rand() % 10;
    bool nie_mozna;
    czyj_ruch=komputer;
    if(poziom==trudny)
    {
        nie_mozna=true;
        while(nie_mozna==true)
        {
            i = rand() % 10;
            j = rand() % 10;
            for(k=i-1; k<=i+1; k++)
            {
                for(m=j-1 ; m<=j+1; m++)
                {
                    if(k>=0 && m>=0 && k<=l && m<=l && p.plan[k][m]->stan == trafil)
                    {
                        nie_mozna=true;
                        break;
                    }
                    else if(k<0 || m<0 || k>l || m>l || p.plan[k][m]->stan != trafil) nie_mozna=false;
                }
                if(nie_mozna==true) break;
            }
            if(p.plan[i][j]->stan == pudlo || p.plan[i][j]->stan == trafil) nie_mozna=true;
        }
    }
        while (p.plan[i][j]->stan == pudlo || p.plan[i][j]->stan == trafil)
        {
            i = rand() % 10;
            j = rand() % 10;
        }

    if (p.plan[i][j]->stan == stat)
    {
        czyj_ruch = komputer;
        p.plan[i][j]->stan = trafil;
        p.plan[i][j]->setStyleSheet(QString::fromUtf8("background-image: url(:/trafiony.bmp);"));
        for (k = 0;k < 10;k++)
        {
            for (m = 0;m < statki_gracza[k].zwroc_dlugosc();m++)
            {
                if (statki_gracza[k].wspolrzedne_x[m] == i && statki_gracza[k].wspolrzedne_y[m] == j) status=statki_gracza[k].sprawdz_zatopienie(p);
            }
        }
        if(status==trafiony)
        {
            czy_zatopil=false;
            a=i;
            b=j;
        }
        else if(status==zatopiony)
        {
            czy_zatopil=true;
        }
    }
    else
    {
        if ( p.plan[i][j]->stan!=trafil) p.plan[i][j]->stan=pudlo;
        status=pudl;
        p.plan[i][j]->setStyleSheet(QString::fromUtf8("background-image: url(:/pudlo.bmp);"));
        czyj_ruch = gracz;
        czy_zatopil=true;
    }
    czy_losowac=true;
}

void gra::ruch_komputera_trudny(plansza &p)
{
    if(czy_zatopil==true) ruch_komputera_latwy(p);
    else
    {
        int i,j;
        unsigned int z=0,x=0;
        i=a;
        j=b;
        int kierun;
        int l=9;
        czyj_ruch=komputer;
        while(czy_losowac==true)
        {
            i=a;
            j=b;
            kierun = rand() % 4;
            switch (kierun)
            {
            case 0: kierunek = gora;
                break;

            case 1: kierunek = prawo;
                break;

            case 2: kierunek = dol;
                break;

            case 3: kierunek = lewo;
                break;
            }

            if(kierunek==gora)
            {
                j--;
                if((i-1>=0 && j-1>=0 && p.plan[i-1][j-1]->stan == trafil) || (j-1>=0 && p.plan[i][j-1]->stan == trafil) || (j-1>=0 && i+1<=l && p.plan[i+1][j-1]->stan == trafil))
                    losowanie=true;
                else losowanie=false;
            }
            if(kierunek==prawo)
            {
                i++;
                if((i+1<=l && j-1>=0 && p.plan[i+1][j-1]->stan == trafil) || (i+1<=l && p.plan[i+1][j]->stan == trafil) || (i+1<=l && j+1<=l && p.plan[i+1][j+1]->stan == trafil))
                    losowanie=true;
                else losowanie=false;
            }
            if(kierunek==dol)
            {
                j++;
                if((i-1>=0 && j+1<=l && p.plan[i-1][j+1]->stan == trafil) || (j+1<=l && p.plan[i][j+1]->stan == trafil) || (j+1<=l && i+1<=l && p.plan[i+1][j+1]->stan == trafil))
                    losowanie=true;
                else losowanie=false;
            }
            if(kierunek==lewo)
            {
                i--;
                if((i-1>=0 && j-1>=0 && p.plan[i-1][j-1]->stan == trafil) || (i-1>=0 && p.plan[i-1][j]->stan == trafil) || (i-1>=0 && j+1<=l && p.plan[i-1][j+1]->stan == trafil))
                    losowanie=true;
                else losowanie=false;
            }
            if(i<0 || j<0 || i>l || j>l || p.plan[i][j]->stan == pudlo || p.plan[i][j]->stan == trafil || losowanie==true) czy_losowac=true;
            else
            czy_losowac=false;
            z++;
        }
        if(z==0)
        {
        if(kierunek==gora && x==0)
        {
            j--;
            if(j<0 || p.plan[i][j]->stan == pudlo || (i-1>=0 && j-1>=0 && p.plan[i-1][j-1]->stan == trafil) || (j-1>=0 && p.plan[i][j-1]->stan == trafil) || (j-1>=0 && i+1<=l && p.plan[i+1][j-1]->stan == trafil))
            {
                kierunek=dol;
                x++;
                while(p.plan[i][j]->stan!=stat)
                {
                    j++;
                }
            }
        }
        if(kierunek==prawo && x==0)
        {
            i++;
            if(i>l || p.plan[i][j]->stan == pudlo || (i+1<=l && j-1>=0 && p.plan[i+1][j-1]->stan == trafil) || (i+1<=l && p.plan[i+1][j]->stan == trafil) || (i+1<=l && j+1<=l && p.plan[i+1][j+1]->stan == trafil))
            {
                kierunek=lewo;
                x++;
                while(p.plan[i][j]->stan!=stat)
                {
                    i--;
                }
            }
        }
        if(kierunek==dol && x==0)
        {
            j++;
            if(j>l || p.plan[i][j]->stan == pudlo || (i-1>=0 && j+1<=l && p.plan[i-1][j+1]->stan == trafil) || (j+1<=l && p.plan[i][j+1]->stan == trafil) || (j+1<=l && i+1<=l && p.plan[i+1][j+1]->stan == trafil))
            {
                kierunek=gora;
                x++;
                while(p.plan[i][j]->stan!=stat)
                {
                    j--;
                }
            }
        }
        if(kierunek==lewo && x==0)
        {
            i--;
            if(i<0 || p.plan[i][j]->stan == pudlo || (i-1>=0 && j-1>=0 && p.plan[i-1][j-1]->stan == trafil) || (i-1>=0 && p.plan[i-1][j]->stan == trafil) || (i-1>=0 && j+1<=l && p.plan[i-1][j+1]->stan == trafil))
            {
                kierunek=prawo;
                x++;
                while(p.plan[i][j]->stan!=stat)
                {
                    i++;
                }
            }
        }
        }
        x=0;
        if (p.plan[i][j]->stan == stat)
        {
            czyj_ruch = komputer;
            p.plan[i][j]->stan = trafil;
            p.plan[i][j]->setStyleSheet(QString::fromUtf8("background-image: url(:/trafiony.bmp);"));
            for (int k = 0;k < 10;k++)
            {
                for (int m = 0;m < statki_gracza[k].zwroc_dlugosc();m++)
                {
                    if (statki_gracza[k].wspolrzedne_x[m] == i && statki_gracza[k].wspolrzedne_y[m] == j) status=statki_gracza[k].sprawdz_zatopienie(p);
                }
            }
            if(status==trafiony)
            {
                czy_zatopil=false;
                czy_losowac=false;
                a=i;
                b=j;
            }
            else if(status==zatopiony)
            {
                czy_zatopil=true;
                czy_losowac=true;
            }
        }
        else
        {
            if ( p.plan[i][j]->stan==nic) p.plan[i][j]->stan=pudlo;
            status=pudl;
            p.plan[i][j]->setStyleSheet(QString::fromUtf8("background-image: url(:/pudlo.bmp);"));
            czyj_ruch = gracz;
            czy_zatopil=false;
            if(z==0)
            {
                if(kierunek==gora && x==0)
                {
                    kierunek=dol;
                    x++;
                    while(p.plan[i][j+1]->stan!=stat)
                    {
                        j++;
                    }
                }
                if(kierunek==dol && x==0)
                {
                    kierunek=gora;
                    x++;
                    while(p.plan[i][j-1]->stan!=stat)
                    {
                        j--;
                    }
                }
                if(kierunek==lewo && x==0)
                {
                    kierunek=prawo;
                    x++;
                    while(p.plan[i+1][j]->stan!=stat)
                    {
                        i++;
                    }
                }
                if(kierunek==prawo && x==0)
                {
                    kierunek=lewo;
                    x++;
                    while(p.plan[i-1][j]->stan!=stat)
                    {
                        i--;
                    }
                }
                czy_losowac=false;
                a=i;
                b=j;
            }
            else czy_losowac=true;
        }
    }

}

void gra::ruch_komputera(plansza &p)
{
    if(stang==trwa)
    {
        if(poziom==latwy) ruch_komputera_latwy(p);
        else ruch_komputera_trudny(p);
    }
    else czyj_ruch=gracz;
}


void gra::rozstawienie_statkow_komputera(plansza & plansza)
{
    int i,j;
    statek czterok(4), trzy1k(3), trzy2k(3), dwu1k(2), dwu2k(2), dwu3k(2), jedno1k(1), jedno2k(1), jedno3k(1), jedno4k(1);

    statki_komputera[0] = czterok;
    statki_komputera[1] = trzy1k;
    statki_komputera[2] = trzy2k;
    statki_komputera[3] = dwu1k;
    statki_komputera[4] = dwu2k;
    statki_komputera[5] = dwu3k;
    statki_komputera[6] = jedno1k;
    statki_komputera[7] = jedno2k;
    statki_komputera[8] = jedno3k;
    statki_komputera[9] = jedno4k;

    for (i = 0;i < 10;i++)
    {
        losuj_statek(plansza, statki_komputera[i]);
    }
}

void gra::rozstawienie_statkow_gracza(plansza & plansza)
{
    int i, j;
    statek czterog(4), trzy1g(3), trzy2g(3), dwu1g(2), dwu2g(2), dwu3g(2), jedno1g(1), jedno2g(1), jedno3g(1), jedno4g(1);

    statki_gracza[0] = czterog;
    statki_gracza[1] = trzy1g;
    statki_gracza[2] = trzy2g;
    statki_gracza[3] = dwu1g;
    statki_gracza[4] = dwu2g;
    statki_gracza[5] = dwu3g;
    statki_gracza[6] = jedno1g;
    statki_gracza[7] = jedno2g;
    statki_gracza[8] = jedno3g;
    statki_gracza[9] = jedno4g;

    for (i = 0;i < 10;i++)
    {
        losuj_statek(plansza, statki_gracza[i]);
    }
}
