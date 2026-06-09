#include <iostream>
#include <cmath>

#include "include/Templier.h"
#include "include/Soldat.h"

Templier::Templier (int ab,int ord,std::string nom):
    Unite (ab,ord,'T',nom)
{

}
Templier:: Templier (Templier const& Original):
    Unite(Original)
{

}

Templier::~Templier()
{

}

bool Templier::attaquer(int x0, int y0)
{
    if(x0>0 && y0>0
       && abs(x-x0)<=1 && abs(y-y0)<=1
       && !(x==x0 && y==y0))
    {
        std::cout << "J'attaque" << std::endl;
        return true;
    }
    std::cout << "Je n'attaque pas" << std::endl;
    return false;
}

bool Templier::se_deplacer(int dx, int dy)
{
    if(abs(dx)>=1 && abs(dy)>=1
       && !(dx==0 && dy==0))
    {
        std::cout << "Je me déplace" << std::endl;
        Unite::se_deplacer(dx,dy);
        return true;
    }
    std::cout << "Je ne me déplace pas" << std::endl;
    return false;
}
bool Templier::se_teleporter(int ab, int ord)
{
    if(abs(ab)>=1 && abs(ord)>=1
       && !(ab==0 && ord==0))
    {
        std::cout << "Je me téléporte" << std::endl;
        Unite::se_teleporter(ab,ord);
        return true;
    }
    std::cout << "Je ne me téléporte pas" << std::endl;
    return false;
}

bool Templier::clonage(int ab, int ord)
{
    if (abs(ab) >= 1 && abs(ord) >= 1 && !(ab == 0 && ord == 0))
    {
        Unite* clone = new Templier(ab, ord); // ✅ Création correcte

        std::cout << "Clonage" << std::endl;
        clone->clonage(ab, ord); // ✅ Appel sur l'objet créé
        return new Templier;

        return true;
    }

    std::cout << "Non clonage" << std::endl;
    return false;
}
