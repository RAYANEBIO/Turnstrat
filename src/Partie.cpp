#include <iostream>
#include "include/Partie.h"
#include "include/Unite.h"
#include "include/Templier.h"

Partie::Partie() : plateau("Terrain de jeu", 8, 8) {}

Partie::~Partie()
{
    for (Unite* u : pieces)
        delete u;
}

bool Partie::ajouter_piece(Unite* piece)
{
    if (piece->get_x() < 0) piece->set_x(0);
    if (piece->get_x() >= plateau.get_largeur()) piece->set_x(plateau.get_largeur() - 1);
    if (piece->get_y() < 0) piece->set_y(0);
    if (piece->get_y() >= plateau.get_hauteur()) piece->set_y(plateau.get_hauteur() - 1);

    if (plateau.case_est_occupee(piece->get_x(), piece->get_y()))
    {
        std::cout << "Cette case est occup�e" << std::endl;
        return false;
    }

    pieces.push_back(piece);
    plateau.occuper_case(piece->get_x(), piece->get_y());
    return true;
}

bool Partie::se_deplacer(Unite* piece, int dx, int dy)
{
    int new_x = piece->get_x() + dx;
    int new_y = piece->get_y() + dy;

    if (new_x < 0 || new_x >= plateau.get_largeur() ||
        new_y < 0 || new_y >= plateau.get_hauteur())
    {
        std::cout << "Deplacement hors limites" << std::endl;
        return false;
    }

    if (plateau.case_est_occupee(new_x, new_y))
    {
        std::cout << "Case occup�e, d�placement impossible" << std::endl;
        return false;
    }

    plateau.liberer_case(piece->get_x(), piece->get_y());
    piece->se_deplacer(new_x, new_y);
    plateau.occuper_case(new_x, new_y);
    std::cout << "Deplacement de " << piece->get_nom() << " ("<< dx <<","<< dy << ")" << " vers " << "(" << new_x << ", " << new_y << ")" << std::endl;
    return true;
}

bool Partie::afficher() const
{
    std::cout << "+";
    for (int i = 0; i < plateau.get_largeur(); i++)
        std::cout << "---";
    std::cout << "+" << std::endl;

    for (int j = 0; j < plateau.get_hauteur(); j++)
    {
        std::cout << "|";
        for (int i = 0; i < plateau.get_largeur(); i++)
        {
            if (plateau.case_est_occupee(i, j))
            {
                for (Unite* u : pieces)
                {
                    if (u->get_x() == i && u->get_y() == j)
                    {
                        std::cout << " " << u->get_type() << " ";
                        break;
                    }
                }
            }
            else
            {
                std::cout << " " << plateau.case_a(i, j).get_terrain() << " ";
            }
        }
        std::cout << "|" << std::endl;
    }

    std::cout << "+";
    for (int i = 0; i < plateau.get_largeur(); i++)
        std::cout << "---";
    std::cout << "+" << std::endl;

    return true;
}
