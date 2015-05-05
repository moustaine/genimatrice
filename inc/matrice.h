#ifndef MAT_H
#define MAT_H

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

#include "coordonnee.h"
#include "couleur.h"


class Matrice
{
private:
	int Ml;					//Nb ligne
	int Mc;					//Nb Colonne
	std::map<Coordonnee, double> Mtab;	//Matrice Creuse



public:
//Constructeurs
	Matrice();								//Constructeur matrice vide
	Matrice(const bool);							//Constructeur de matrice
	Matrice(const std::string);						//Constructeur de matrice par fichier
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
	Matrice& operator/=(const double);					//Operateur /= Squalaire
	friend Matrice operator/(const Matrice&, const double);			//Operateur / Squalaire

	Matrice& operator+=(const Matrice&);					//Operateur += Matrice
	Matrice& operator-=(const Matrice&);					//Operateur -= Matrice
	Matrice& operator*=(const Matrice&);					//Operateur *= Matrice
	friend Matrice operator+(const Matrice&, const Matrice&);		//Operateur + Matrice
	friend Matrice operator-(const Matrice&, const Matrice&);		//Operateur - Matrice
	friend Matrice operator*(const Matrice&, const Matrice&);		//Operateur * Matrice
//Fonctions
	friend std::ostream &operator<<( std::ostream &, Matrice const &);	//Operateur <<
	bool Save(std::string) const;						//Sauvegarde la matrice
	std::string NomSave(std::string) const;					//Envoie le nom de la sauvegarde
	Matrice& Transpose();							//Transpose la matrice
	void Insert(int, int, double);						//Insere une valeur dans la case choisie
};



#endif //MAT_H
