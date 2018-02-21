#include "plansza.h"
#include <iostream>

using namespace std;


plansza::plansza()
{
    int i,j;

    for (i = 0;i < 10;i++)
    {
        for (j = 0;j < 10;j++)
        {
            tablica[i][j] = '|';
        }

    }

}


plansza::~plansza()
{
}

