#include "random.h"
#include <stdlib.h>
#include <time.h>
#include <algorithm>

mt19937 Random::mt(time(nullptr));

Random::Random(int mini,int maxi,int taille,bool exclusif)
{

    this->maxi = maxi;
    this->mini = mini;
    this->taille = taille;
    this->exclusif = exclusif;

    inversionMaxiMini();
    dis = uniform_int_distribution <int>(this->mini,this->maxi);
    testTaille();
    remplirTab();
}

void Random::inversionMaxiMini(int & mini,int & maxi)
{
    int inter;

    if(mini>maxi)
    {
        inter=mini;
        mini=maxi;
        maxi=inter;
    }
}

void Random::inversionMaxiMini()
{
    int inter;

    if(mini>maxi)
    {
        inter=mini;
        mini=maxi;
        maxi=inter;
    }
}

void Random::remplirTab()
{
    int aleatoire;
    tabRandom.clear();

    do
    {
        aleatoire=calculValeur();
        if(exclusif)
            while(find(tabRandom.begin(), tabRandom.end(),aleatoire) != tabRandom.end())
                aleatoire=calculValeur();

        tabRandom.push_back(aleatoire);

    }
    while(static_cast <int>(tabRandom.size()) < taille);
}

void Random::testTaille()
{
    if(exclusif)
        if(maxi - mini + 1 < taille)
            taille = maxi - mini + 1;
}

int Random::calculValeur()
{
     return dis(mt);
}
int Random::valeurUnique(int mini,int maxi)
{
    inversionMaxiMini(mini,maxi);

    uniform_int_distribution<int> dis(mini,maxi);

    return dis(mt);
}

int Random::getTaille()const
{
    return taille;
}

void Random::setTaille(int taille)
{
    this->taille = taille;
    testTaille();
    remplirTab();
}

int Random::getMaxi()const
{
    return maxi;
}

void Random::setMaxi(int maxi)
{
    this->maxi = maxi;
    inversionMaxiMini();
    dis = uniform_int_distribution <int>(this->mini,this->maxi);
    testTaille();
    remplirTab();
}

int Random::getMini()const
{
    return mini;
}

void Random::setMini(int mini)
{
    this->mini = mini;
    inversionMaxiMini();
    dis = uniform_int_distribution <int>(this->mini,this->maxi);
    testTaille();
    remplirTab();
}

int Random::operator[](int indice)const
{
    int res = -1;

    if(indice < taille)
        res = tabRandom[indice];
    return res;
};

vector <int> Random::getTableau() const
{
    return tabRandom;
}
