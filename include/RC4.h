#ifndef RC4H
#define RC4H
#include <vector>

using namespace std;

class RC4
{
    private:
        vector <unsigned char> tableauEtat;
        vector <unsigned char> maCle;
        unsigned int tailleCle;

        const unsigned int tailleTableauEtat;
        unsigned int i;
        unsigned int j;
    public:
        RC4(unsigned int tailleCle = 0);
        RC4(unsigned char * cle,int tailleCle);
        RC4(vector <unsigned char> cle);
        void initCodageDecodage();
        unsigned char chiffrage(unsigned char octet);
        vector <unsigned char> getCle();
        unsigned int getTailleCle();
    private:
        void genereCle();
        void melangeTableauEtat();
        void swap(unsigned char* val1,unsigned char* val2);
};
#endif
