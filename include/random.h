/**
*   \file random.h
*   \brief Tableau de nombres aléatoires.
*
*   Permet de disposer d'un tabeau de valeurs aléatoires évolutif.
*******************************************************************************/
#ifndef RANDOM_H
#define RANDOM_H
#include <vector>
#include <random>

/**
*   \namespace std
*   \brief Namespace pour la STL
*
*   Namespace de la STL.
*****************************************************************************/
using namespace std;



/**
*   \class Random
*   \brief Tableau de nombres aléatoires.
*
*   \author christian guézénec
*   \version 1.1
*   \date  11 avril 2021
******************************************************************************/
class Random
{
    private:

        /** \brief Tableau des valeurs. */
        vector <int> tabRandom;  /**< Tableau des valeurs aléatoires. */
        /** \brief Valeur aléatoire maxi. */
        int maxi;      /**< Valeur aléatoire maxi possible. */
        /** \brief Valeur aléatoire mini. */
        int mini;      /**< Valeur aléatoire mini possible. */
        /** \brief Taille du tableau. */
        int taille;    /**< Taille réelle du tableau (ajustement possible). */
        /** \brief Valeur unique ou non. */
        bool exclusif;  /**< Valeur unique dans le tableau ou non. */
		/** \brief Générateur aléatoire. */
        static mt19937 mt;		/**< Générateur Mersenne Twister. */
		/** \brief Fourchette de données avec le même degré de probabilité. */
        uniform_int_distribution <int> dis;   /**< Fourchette de données (maxi,mini) avec le même degré de probabilité. */
    public:
        /** \brief Constructeur. */
        Random(int mini,int maxi,int taille,bool exclusif = false);
        /** \brief Destructeur.
        *
        * Destructeur vide par défaut */
        ~Random() = default;
        /** \brief Retourne la taille du tableau. */
        int getTaille()const;
        /** \brief Modifie la taille du tableau et le reremplit. */
        void setTaille(int taille);
        /** \brief Retourne la valeur maxi possible. */
        int getMaxi()const;
        /** \brief Modifie la valeur maxi et reremplit le tableau. */
        void setMaxi(int maxi);
        /** \brief Retourne la valeur mini possible. */
        int getMini()const;
        /** \brief Modifie la valeur mini et reremplit le tableau. */
        void setMini(int mini);
        /** \brief Remplir le tableau. */
        void remplirTab();
        /** \brief Retourne une valeur du tableau en fonction de l'indice. */
        int operator[](int indice)const;
        /** \brief Retourne une valeur aléatoire comprise dans la fourchette spécifiée. */
        static int valeurUnique(int valMini,int valMaxi);
        /** \brief Retourne le tableau. */
        vector <int> getTableau() const;
    private:
        /** \brief Retourne une valeur aléatoire. */
        int calculValeur();
        /** \brief Inverse si besoin les valeurs mini et maxi. */
        static void inversionMaxiMini(int & mini,int & maxi);
        /** \brief Inverse si besoin les valeurs mini et maxi. */
        void inversionMaxiMini();
        /** \brief Test si la taille demandée est correcte et éventuellement la modifie. */
        void testTaille();
};
#endif // RANDOM_H
