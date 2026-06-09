#include "include/Unite.h"

// Constructeur par d�faut
Unite::Unite() : x(0), y(0), type('N'), nom ("name") {}

// Constructeur avec param�tres
Unite::Unite(int ab, int ord, char t, std::string n ) : x(ab), y(ord), type(t), nom(n) {}

// Constructeur de copie
Unite::Unite(const Unite& original)
{
    x = original.x;
    y = original.y;
    type = original.type;
    nom= original.nom;

}

// Destructeur
Unite::~Unite() {}

// D�placement vers une nouvelle position
bool Unite::se_deplacer(int ab, int ord)
{
    x = ab;
    y = ord;
    return true;
}

// T�l�portation (identique � d�placement ici, mais peut �tre �tendu)
bool Unite::se_teleporter(int ab, int ord)
{
    x = ab;
    y = ord;
    return true;
}

// Clonage (ici, on simule un clone en changeant la position)
bool Unite::clonage(int ab, int ord)
{
    x = ab;
    y = ord;
    return true;
};

// Accesseurs
int Unite::get_x() const { return x; }
int Unite::get_y() const { return y; }
char Unite::get_type() const { return type; }
std::string Unite::get_nom() const {
    return nom;}

// Mutateurs
void Unite::set_x(int val) { x = val; }
void Unite::set_y(int val) { y = val; }
void Unite::set_type(char val) { type = val; }
void Unite::set_nom(const std::string& n) { nom = n; }
