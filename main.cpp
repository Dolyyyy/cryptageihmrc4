#include <FichierCrypte.h>
#include <iostream>

using namespace std;

int main()
{
    const string nomFichier = "alexistropbeau";

    FichierCrypte *f = new FichierCrypte(nomFichier + ".txt");

    f->crypteFichier();
    delete f;

    f = new FichierCrypte(nomFichier + ".cry", false, "fin");
    f->decrypteFichier();

    cout << "Fichier crypte -> " << nomFichier;

    delete f;
    return 0;
}
