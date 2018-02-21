#include "statek.h"
#include "plansza.h"
#include <iostream>

using namespace std;

statek::statek(unsigned int ilosc)
{
    dlugosc = ilosc;
    stan_statku = dobry;
}

statek::statek()
{
}


statek::~statek()
{
}

unsigned int statek::zwroc_dlugosc() const
{
    return dlugosc;
}


stan_stat statek::sprawdz_zatopienie(plansza & p)
{
    int i;
    for (i = 0;i < dlugosc;i++)
    {
        if (p.plan[wspolrzedne_x[i]][wspolrzedne_y[i]]->stan == trafil) stan_statku = zatopiony;
        else
        {
            stan_statku = trafiony;
            break;
        }
    }
    return stan_statku;

}
