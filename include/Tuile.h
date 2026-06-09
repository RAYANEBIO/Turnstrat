#ifndef TUILE_H
#define TUILE_H


class Tuile
{
	public:
	// Constructeurs
		Tuile();
		Tuile(int ab, int ord, char type='n', bool oqp = false);
		Tuile(Tuile const& original);

	// Destructeur
		~Tuile();

	// Autres methodes
		void statut() const;
		bool occuper();
		bool liberer();
		bool est_valide() const;

	// Accesseurs
		int get_x() const;
		int get_y() const;
		char get_terrain() const;
		bool get_occupe() const;

	// Mutateurs
		void set_x(int val);
		void set_y(int val);
		void set_terrain(char val);
		void set_occupe(bool val);

	// Attributs
	protected:

	private:
		int x;
		int y;
		char terrain;
		bool occupe;
};

#endif // TUILE_H
