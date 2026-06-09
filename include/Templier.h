#ifndef TEMPLIER_H
#define TEMPLIER_H
#include "Unite.h"

class Templier: public Unite
{
    public:
        //constructeurs
        Templier(int ab = 0, int ord = 0,std::string nom = "Soldat");
        Templier(const Templier& Original);
        bool est_templier() const override
        {
        return true;
        };

        //Destructeur
        ~Templier();

        //AUTRES METHODES
       bool attaquer(int x0, int y0);
        bool se_deplacer(int dx, int dy);
        bool se_teleporter(int ab,int ord);
        bool clonage(int ab, int ord);

    protected:

    private:
};

#endif // TEMPLIER_H
