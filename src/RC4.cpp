#include "RC4.h"
#include <iostream>
#include "random.h"

RC4::RC4(unsigned int tailleCle):tailleTableauEtat(256)
{
    tableauEtat.resize(tailleTableauEtat);

    if(tailleCle==0)
        this->tailleCle = Random::valeurUnique(40,255);
    else
        this->tailleCle = tailleCle;
    genereCle();
    initCodageDecodage();
}

RC4::RC4(unsigned char * cle,int taille):tailleTableauEtat(256)
{
    tableauEtat.resize(tailleTableauEtat);
    this->tailleCle = taille;
    maCle.resize(tailleCle);

    copy(cle,cle+taille,maCle.begin());

    initCodageDecodage();
}

RC4::RC4(vector <unsigned char> cle):tailleTableauEtat(256)
{
    tableauEtat.resize(tailleTableauEtat);
    maCle = cle;
    tailleCle = cle.size();
    initCodageDecodage();
}

void RC4::initCodageDecodage()
{
    for(unsigned int compte = 0;compte<tableauEtat.size();compte++)
        tableauEtat[compte] = compte;

    melangeTableauEtat();

    i=0;
    j=0;
}

unsigned char RC4::chiffrage(unsigned char octet)
{
    unsigned char n;

    i=(i+1)%tailleTableauEtat;
    j=(j+tableauEtat[i])%tailleTableauEtat;

    swap(&tableauEtat[i],&tableauEtat[j]);
    n=(tableauEtat[i]+tableauEtat[j])%tailleTableauEtat;

    return octet ^ tableauEtat[n];
}

void RC4::genereCle()
{
    Random cle(1,255,tailleCle);
    vector <int> retour = cle.getTableau();

    maCle = vector <unsigned char>(retour.begin(),retour.end());

}

vector <unsigned char> RC4::getCle()
{
    return maCle;
}

void RC4::swap(unsigned char* val1,unsigned char * val2)
{
    unsigned char inter;

    inter=*val1;
    *val1=*val2;
    *val2=inter;
}

void RC4::melangeTableauEtat()
{
    unsigned int i,j=0,indiceCle;


    for(i=0;i<tailleTableauEtat;i++)
    {
        indiceCle=i % tailleCle;
        j=(j+tableauEtat[i]+maCle[indiceCle]) % tailleTableauEtat;

        swap(&tableauEtat[i],&tableauEtat[j]);
   }
}

 unsigned int RC4::getTailleCle()
 {
    return  tailleCle;
 }
