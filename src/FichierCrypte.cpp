#include "FichierCrypte.h"
#include <iostream>
#include "RC4.h"

FichierCrypte::FichierCrypte(string nomSource,bool cryptage,string extension)
{
    this->nomSource = nomSource;
    this->cryptage = cryptage;

    nomFichierDestination(extension);
}

FichierCrypte::~FichierCrypte()
{

}

void FichierCrypte::nomFichierDestination(string extension)
{
    int indice=nomSource.find(".");
    nomDestination.assign(nomSource,0,indice);
    if(!controleExtensionFichier(extension))
        if(cryptage)
            nomDestination.insert(nomDestination.size(),".cry");
        else
            nomDestination.insert(nomDestination.size(),".txt");
    else
        nomDestination.insert(nomDestination.size(),"."+extension);
}

bool FichierCrypte::controleExtensionFichier(string extension)
{
    bool result = true;

    if(extension.empty())
        result = false;
    else if(extension.length() > 3)
        result = false;
    else if(extension[0] >= '0' && extension[0] <= '9')
        result = false;

    return result;
}

bool FichierCrypte::crypteFichier()
{
    RC4 monRC4;
    unsigned char data;
    unsigned int compteur = 0;
    unsigned int tailleCle = monRC4.getTailleCle();
    vector <unsigned char> cle = monRC4.getCle();

    fichierSource.open(nomSource,ios::ate | ios::binary);
    if(fichierSource.tellg() <= 3)
    {
        fichierSource.close();
        return false;
    }

    fichierSource.seekg(0,ios::beg);
    fichierDestination.open(nomDestination,ios::binary);

    while(fichierSource.read(reinterpret_cast <char *>(&data),sizeof(data)))
    {
        if(compteur == 3)
        {
            fichierDestination.write(reinterpret_cast <char *>(&tailleCle),sizeof(tailleCle));
            fichierDestination.write(reinterpret_cast <char *>(&cle.front()),tailleCle);
        }

        compteur++;
         data = monRC4.chiffrage(data);
        fichierDestination.write(reinterpret_cast <char *>(&data),sizeof(data));
    }

    fichierSource.close();
    fichierDestination.close();

    return true;
}

void FichierCrypte::decrypteFichier()
{
    unsigned char data;
    unsigned int tailleCle;

    fichierSource.open(nomSource,ios::binary);
    fichierDestination.open(nomDestination,ios::binary);

    fichierSource.seekg(3,ios::beg);

    fichierSource.read(reinterpret_cast <char *>(&tailleCle),sizeof(tailleCle));

    vector <unsigned char> cle(tailleCle);

    fichierSource.read(reinterpret_cast <char *>(&cle.front()),tailleCle);

    RC4 monRC4(cle);


    fichierSource.seekg(0,ios::beg);
    for(unsigned int i=0;i<3;i++)
    {
        fichierSource.read(reinterpret_cast <char *>(&data),sizeof(data));
        data = monRC4.chiffrage(data);
        fichierDestination.write(reinterpret_cast <char *>(&data),sizeof(data));
    }

    fichierSource.seekg(3+sizeof(unsigned int)+sizeof(unsigned char)*tailleCle,ios::beg);

    while(fichierSource.read(reinterpret_cast <char *>(&data),sizeof(data)))
    {
        data = monRC4.chiffrage(data);
        fichierDestination.write(reinterpret_cast <char *>(&data),sizeof(data));
    }

    fichierSource.close();
    fichierDestination.close();
}

string FichierCrypte::getNomSource()
{
    return srcName;
}

string FichierCrypte:: getNomDestination()
{
    return destiName;
}
