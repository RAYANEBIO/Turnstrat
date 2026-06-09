#include "include/Carte.h"
#include <cmath>
#include <iostream>
#include <string>

/**

    exterieur   h   y   j
    interieur   w   x   i

**/

using namespace std;

// Constructeur
Carte::Carte():
    n("Carte sans nom"), w(4), h(3)
{
    for(int j=0; j<h; j++)
    {
        vector<Tuile> ligne;
        for(int i=0; i<w; i++)
        {
            Tuile t(i,j);
            ligne.push_back(t);
        }
        cases.push_back(ligne);
    }
}


Carte::Carte(string nom, int largeur, int hauteur)
{
    n = nom;
    w = abs(largeur);
    h = abs(hauteur);

    if(w<1)
        w=1;
    if(w>100)
        w=100;

    if(h<1)
        h=1;
    if(h>100)
        h=100;

    for(int j=0; j<h; j++)
    {
        vector<Tuile> ligne;
        for(int i=0; i<w; i++)
        {
            Tuile t(i,j);
            ligne.push_back(t);
        }
        cases.push_back(ligne);
    }
}

Carte::Carte(Carte const& original):
    n(original.n),
    w(original.w),
    h(original.h),
    cases(original.cases)
{
}

// Destructeur
Carte::~Carte()
{
    cout<< "La carte " << n << " a �t� d�truite!" << endl;
}

// Autres methodes
void Carte::statut() const
{
    cout << "Statut de la carte: " << n << " [" << w << " x " << h << "]" << endl;
}

bool Carte::afficher() const
{
    cout <<"+";
    for (int i = 0; i<w; i++)
    {
        cout << "---";
    }
    cout << "+" << endl;


    for (int j=0; j<h; j++)
    {
        cout << "|" ;
        for (int i=0; i<w ; i++)
        {
            cout <<" "<< cases[j][i].get_terrain() <<" ";
        }
        cout << "|" << endl;
    }


    cout <<"+";
    for (int i = 0; i<w; i++)
    {
        cout << "---";
    }
    cout << "+" << endl;
    return true;
}

int Carte::nbre_cases() const
{
    return w*h;
}

bool Carte::modifier_terrain(int x, int y, char t)
{
    if(x < 0
    || x >= w
    || y < 0
    || y >= h)
        return false;

    cases[y][x].set_terrain(t);
    return true;
}

bool Carte::occuper_case(int x, int y)
{
    if(x < 0
    || x >= w
    || y < 0
    || y >= h)
        return false;

    cases[y][x].occuper();
    return true;
}

bool Carte::liberer_case(int x, int y)
{
    if(x < 0
    || x >= w
    || y < 0
    || y >= h)
        return false;

    cases[y][x].liberer();
    return true;
}

bool Carte::case_est_occupee(int x, int y) const
{
    return cases[y][x].get_occupe();
}


Tuile Carte::case_a(int x, int y) const
{
    if(x < 0
    || x >= w
    || y < 0
    || y >= h)
    {
        Tuile t(w,h,'!');
        return t;
    }
    return cases[y][x];
}

// Accesseur
string Carte::get_nom() const
{
    return n;
}

int Carte::get_largeur() const
{
    return w;
}

int Carte::get_hauteur() const
{
    return h;
}

vector<vector<Tuile>> Carte::get_cases() const
{
    return cases;
}

// Mutateur
void Carte::set_nom(string val)
{
    n = val;
}

void Carte::set_largeur(int val)
{
    if(val>=1 && val<=100 && val != w)
    {
        if(val>w)
        {
            int n = val-w;// Nombre de cases � rajouter
            for(int j=0; j<h; j++)
                for(int i=0; i<n; i++)
                {
                    Tuile t(i+w,j);
                    cases[j].push_back(t);
                }
        }
        else
        {
            int n = w-val;// Nombre de cases � retirer
            for(int j=0; j<h; j++)
                for(int i=0; i<n; i++)
                    cases[j].pop_back();
        }
        w=val;
    }
}

void Carte::set_hauteur(int val)
{
    if(val>=1 && val<=100 && val != h)
    {
        if(val>h)
        {
            int n = val-h;// Nombre de lignes � rajouter
            for(int j=0; j<n; j++)
            {
                vector<Tuile> ligne;
                for(int i=0; i<w; i++)
                {
                    Tuile t(i,j+h);
                    ligne.push_back(t);
                }
                cases.push_back(ligne);
            }
        }
        else
        {
            int n = h-val;// Nombre de lignes � retirer
            for(int j=0; j<n; j++)
                cases.pop_back();
        }
        h=val;
    }
}

void Carte::set_cases(vector<vector<Tuile>> plan)
{
    w = 1;
    h = plan.size();

    for(int j=0; j<h; j++)
        if(plan[j].size()>w)
            w=plan[j].size();

    cases.clear();

    for(int j=0; j<h; j++)
    {
        vector<Tuile> ligne;
        for(int i=0; i<w; i++)
        {
            char type='n';
            bool oqp=false;

            if(i<plan[j].size())
            {
                type=plan[j][i].get_terrain();
                oqp=plan[j][i].get_occupe();
            }

            Tuile t(i,j,type,oqp);
            ligne.push_back(t);
        }
        cases.push_back(ligne);
    }
}



/*


*/
