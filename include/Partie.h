#ifndef PARTIE_H
#define PARTIE_H

#include "Carte.h"
#include "Unite.h"

class Partie
{
    public:
        Partie();
        ~Partie();

    // Methodes
    bool afficher() const;
    void afficher_plateau() const;
    bool ajouter_piece(Unite* piece);
    bool se_deplacer(Unite* piece, int ab, int ord);
    bool attaquer_piece (Unite* piece1, Unite* piece2)
{
    int new_x = piece2-> get_x() ;
    int new_y = piece2-> get_y() ;

     if ((!piece2 -> est_templier()) || ((piece1-> est_templier() && piece2-> est_templier()) ))
    {
        if (plateau.case_est_occupee(new_x,new_y))
    {
        plateau.liberer_case(piece1->get_x(), piece1->get_y());
        piece1->set_x(new_x);
        piece1->set_y(new_y);
        piece1->se_deplacer(new_x, new_y);
    plateau.occuper_case(new_x, new_y);
        std::cout << piece1-> get_nom() << " a attaque " << piece2-> get_nom() << std::endl;
        delete piece2;
        return true;
    }
    }
    std::cout << " Impossible d'attaquer" << std::endl;
    return false;
}


    protected:
        Carte plateau;
        std::vector<Unite*> pieces;

    private:
};

#endif // PARTIE_H
