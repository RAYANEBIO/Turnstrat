#include <iostream>
#include <cmath>

#include "include/Tuile.h"

using namespace std;

// Constructeurs
Tuile::Tuile()
{
    x=0;
    y=0;
    terrain='n';
    occupe=false;
}

Tuile::Tuile(int ab, int ord, char type, bool oqp)
{
    x=abs(ab);
    y=abs(ord);
    terrain=type;
    occupe=oqp;
}

Tuile::Tuile(Tuile const& original)
{
    x=original.x;
    y=original.y;
    terrain=original.terrain;
    occupe=original.occupe;
}

// Destructeur
Tuile::~Tuile()
{
}

// Autres methodes
void Tuile::statut() const
{
    cout << "Statut de la Tuile ("<< x << "," << y <<"):" << endl;
    cout << "\tTerrain: "<< terrain << endl;

    cout << "\tOccupé: ";
    if(occupe)
        cout << "Oui";
    else
        cout << "Non";
    cout << endl << endl;
}

bool Tuile::occuper()
{
    if(!occupe)
    {
        occupe=true;
        return true;
    }
    return false;
}

bool Tuile::liberer()
{
    if(occupe)
    {
        occupe=false;
        return true;
    }
    return false;
}

bool Tuile::est_valide() const
{
    return (terrain!='!');
}

// Accesseurs
int Tuile::get_x() const
{
    return x;
}

int Tuile::get_y() const
{
    return y;
}

char Tuile::get_terrain() const
{
    return terrain;
}

bool Tuile::get_occupe() const
{
    return occupe;
}

// Mutateurs
void Tuile::set_x(int val)
{
    x=abs(val);
}

void Tuile::set_y(int val)
{
    y=abs(val);
}

void Tuile::set_terrain(char val)
{
    terrain=val;
}

void Tuile::set_occupe(bool val)
{
    occupe=val;
}


