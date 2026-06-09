#ifndef CARTE_H
#define CARTE_H

#include <string>
#include <vector>

#include "Tuile.h"

class Carte
{
    public:
        // Constructeur
        Carte();
        Carte(std::string nom, int largeur = 4, int hauteur = 3);
        Carte(Carte const& original);


        // Destructeur
        ~Carte();

        // Autres methodes
        void statut() const;
        bool afficher() const;
        int nbre_cases() const;

        bool modifier_terrain(int x, int y, char t);
        bool occuper_case(int x, int y);
        bool liberer_case(int x, int y);
        bool case_est_occupee(int x, int y) const;

        Tuile case_a(int x, int y) const;

        // Accesseur
        std::string get_nom() const;
        int get_largeur() const;
        int get_hauteur() const;
        std::vector<std::vector<Tuile>> get_cases() const;

        // Mutateur
        void set_nom(std::string val);
        void set_largeur(int val);
        void set_hauteur(int val);
        void set_cases(std::vector<std::vector<Tuile>> plan);

        // Attributs

    protected:

    private:
        std::string n;
        int w;
        int h;
        std::vector<std::vector<Tuile>> cases;
};

#endif // CARTE_H
