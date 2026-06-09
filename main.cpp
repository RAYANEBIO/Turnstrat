#include <iostream>
#include "include/Partie.h"
#include "include/Soldat.h"
#include "include/Templier.h"

int main()
{
    Partie partie1;

    // Cr�ation des unit�s
    Soldat* R = new Soldat(5, 4, "ryan" );
    Templier* J = new Templier(6, 7, "jade");
    Soldat* G = new Soldat(4,5,"gard");
    Templier* Y = new Templier (7,8,"yame");

    // Ajout des unit�s au plateau
    partie1.ajouter_piece(R);
    partie1.ajouter_piece(J);
    partie1.ajouter_piece(G);
    partie1.ajouter_piece(Y);

    std::cout << "Avant deplacement :" << std::endl;
    partie1.afficher();

    // D�placement des unit�s
    partie1.se_deplacer(R, -1, 0);
    partie1.se_deplacer(J, -1, 0);

    std::cout << "After deplacement :" << std::endl;
    partie1.afficher();
    partie1.attaquer_piece(G,R);
    partie1.afficher();

    return 0;
}
