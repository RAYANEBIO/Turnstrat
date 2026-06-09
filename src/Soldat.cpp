#include <iostream>
#include <cmath>

#include "include/Soldat.h"

using namespace std;

//Constructeurs
Soldat::Soldat(int ab, int ord,std::string nom ):
    Unite(ab,ord,'S',nom)
{

}

Soldat::Soldat(Soldat const& original):
    Unite(original)
{
}

//Destructeur
Soldat::~Soldat()
{
    //dtor
}

//Autres methodes
bool Soldat::attaquer(int x0, int y0)
{
    if(x0>0 && y0>0
       && abs(x-x0)<=1 && abs(y-y0)<=1
       && !(x==x0 && y==y0))/*&& !( x0 = ab ; y0= orb )*/
    {
        cout << "J'attaque" << endl;
        return true;
    }
    cout << "Je n'attaque pas" << endl;
    return false;
}

bool Soldat::se_deplacer(int dx, int dy)
{
    if(abs(dx)>=1 && abs(dy)>=1
       && !(dx==0 && dy==0))
    {
        cout << "Je me d�place" << endl;
        Unite::se_deplacer(x+dx,y+dy);
        return true;
    }
    cout << "Je ne me d�place pas" << endl;
    return false;
}


