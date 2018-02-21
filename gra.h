#pragma once
#include "plansza.h"
#include "statek.h"
#include "enum.h"
class gra
{
public:
    gra();
    ~gra();
    statek statki_gracza[10];
    statek statki_komputera[10];
    plansza plank;
    plansza plang;
    static ruch czyj_ruch;
    stan_stat status;
    poziom_trudnosci poziom;
    stan_gry stang;
    ruch kto_wygral;
    bool czy_zatopil;
    kierunek_statkow kierunek;
    bool czy_losowac;
    bool losowanie;
    int a,b;
    void ruch_komputera(plansza &p);
    void losuj_statek(plansza & plan, statek & stat);
    void rozstawienie_statkow_komputera(plansza &plansza);
    void rozstawienie_statkow_gracza(plansza &plansza);
    void ruch_komputera_latwy(plansza &p);
    void ruch_komputera_trudny(plansza &p);


};

