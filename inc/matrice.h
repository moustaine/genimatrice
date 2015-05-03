#ifndef MAT_H
#define MAT_H

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string>

#include "coordonnee.h"


class Matrice
{
private:
	int Ml;					//Nb ligne
	int Mc;					//Nb Colonne
	bool Mcreux;				//Matrice Creuse(true) ou Matrice Pleine(false)
	int MnbZero;				//Nb de zero
	std::map<Coordonnee, double> MtabCreux;	//Matrice Creuse
	double **MtabPlein;			//Matrice Pleine

	std::string NomSave(std::string) const;					//Envoie le nom de la sauvegarde

public:
//Constructeurs
	Matrice(int = 1, int = 1, double = 0);					//Constructeur de matrice
	Matrice(std::string);							//Constructeur de matrice par fichier
//Destructeur
	~Matrice();								//Destructeur
//Operateur
	//Comparaison
	bool operator==(const Matrice&) const;					//Operateur ==
	bool operator!=(const Matrice&) const;					//Operateur !=
	//Arithmétique
	Matrice& operator=(const Matrice&);					//Operateur =

	Matrice& operator*=(const double);					//Operateur *= Squalaire
	friend Matrice operator*(const Matrice&, const double);			//Operateur * Squalaire

	Matrice& operator+=(const Matrice&);					//Operateur += Matrice
	Matrice& operator-=(const Matrice&);					//Operateur -= Matrice
	Matrice& operator*=(const Matrice&);					//Operateur *= Matrice
	friend Matrice operator+(const Matrice&, const Matrice&);		//Operateur + Matrice
	friend Matrice operator-(const Matrice&, const Matrice&);		//Operateur - Matrice
	friend Matrice operator*(const Matrice&, const Matrice&);		//Operateur * Matrice
//Fonctions
	friend std::ostream &operator<<( std::ostream &, Matrice const &);	//Operateur <<
	bool Save(std::string) const;						//Sauvegarde la matrice
	bool Transpose();							//Transpose la matrice
	bool Traduit();								//Si on a une Matrice Creuse on passe a Matrice Pleine et inversement
};



#endif //MAT_H
