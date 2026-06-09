#ifndef SOLDAT_H
#define SOLDAT_H

#include "Unite.h"


class Soldat : public Unite
{
    public:
        //Constructeurs
        Soldat(int ab = 0, int ord = 0 , std::string nom = "Soldat");
        Soldat(Soldat const& original);

        //Destructeur
        ~Soldat();

        //Autres methodes
        bool attaquer(int x0, int y0);
        bool se_deplacer(int dx, int dy);

    protected:

    private:
};

#endif // SOLDAT_H
