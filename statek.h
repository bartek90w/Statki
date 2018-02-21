#pragma once
#include <vector>
#include "plansza.h"
#include "enum.h"
using namespace std;
class statek
{
public:
    statek(unsigned int ilosc);
    statek();
    ~statek();
    unsigned int zwroc_dlugosc() const;
    vector <int> wspolrzedne_x;
    vector <int> wspolrzedne_y;
    kierunek_statkow kierunek;
    stan_stat stan_statku;
    stan_stat sprawdz_zatopienie(plansza &p);
private:
    unsigned int dlugosc;
};

