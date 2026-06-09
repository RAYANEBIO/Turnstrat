#ifndef UNITE_H
#define UNITE_H
#include <string>


class Unite
{
    public:
        // Constructeur
        Unite();
        Unite(int ab, int ord, char t = 'N', std::string nom = "name");
        Unite(Unite const& original);
       virtual bool est_templier () const
        {
        return false;
        };

        //Destructeur
        ~Unite();

        // Autres methodes
        bool se_deplacer(int ab, int ord);
        bool se_teleporter(int ab,int ord);
        bool clonage(int ab, int ord);

        // Accesseur
        int get_x() const;
        int get_y() const;
        char get_type() const;
        std::string get_nom () const;

        // Mutateur
        void set_x(int val);
        void set_y(int val);
        void set_type(char val);
        void set_nom(const std::string& n);



    protected:
        int x;
        int y;
        char type;
        std::string nom;

    private:
};

#endif // UNITé_H
