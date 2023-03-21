/**
*   \file FichierCrypte.h
*   \brief Cryptage d'un fichier.
*
*   Permet de crypter et de décrypter un fichier avec l'algorithme RC4.
*******************************************************************************/
#ifndef FichierCrypteH
#define FichierCrypteH
#include <string>
#include <fstream>
#include <vector>

/**
*   \namespace std
*   \brief Namespace pour la STL
*
*   Namespace de la STL.
*****************************************************************************/
using namespace std;

/** \brief Classe RC4. */
class RC4;


/**
*   \class FichierCrypte
*   \brief Cryptage ou décryptage d'un fichier en RC4.
*
*   \author christian guézénec
*   \version 1.1
*   \date  11 avril 2021
******************************************************************************/
class FichierCrypte
{
    private:
        /** \brief Nom du source. */
        string nomSource;                   /**< Nom du fichier source à crypter ou décrypter. */
        /** \brief Nom du destination. */
        string nomDestination;              /**< Nom du fichier destination crypté ou décrypté. */
        /** \brief Cryptage ou non. */
        bool cryptage;                      /**< Indique si l'on doit crypter ou décrypter. */
        /** \brief Fichier source */
        ifstream fichierSource;              /**< Manipulation du fichier source. */
        /** \brief Fichier destination. */
        ofstream fichierDestination;         /**< Manipilation du fichier destination. */
    public:
        // contructeur : cryptage par défaut, cry extension par défaut pour le
        // crypatge, txt extension par défaut pour le décryptage
        /** \brief Constructeur. */
        FichierCrypte(string source,bool cryptage=true,string extension = "");
        /** \brief Destructeur. */
        ~FichierCrypte();
        /** \brief  Décrypter le fichier. */
        void decrypteFichier();
        /** \brief  Crypter le fichier. */
        bool crypteFichier();
        /** \brief Retourner le nom du fichier source. */
        string getNomSource();
        /** \brief Retourner le nom du fichier destination. */
        string getNomDestination();
    private:
        /** \brief Controler l'extension du fichier destination. */
        bool controleExtensionFichier(string extension);
        /** \brief Créer le nom du fichier destination. */
        void nomFichierDestination(string extension);
};
#endif
