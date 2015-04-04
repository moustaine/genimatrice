#ifndef MAT_H
#define MAT_H

#include <iostream>
#include <map>
#include <fstream>
#include "coordonnee.h"

class Matrice
{
private:
	int Ml;					//Nb ligne
	int Mc;					//Nb Colonne
	std::map<Coordonnee, double> Mtab;	//Matrice Creuse

public:
//Constructeurs
	Matrice(int = 1, int = 1, double = 0);			//Constructeur de matrice
	Matrice(std::string);					//Constructeur de matrice d'un fichier
//Destructeur
	~Matrice();						//Destructeur
//Operateur
	//Comparaison
	bool operator==(Matrice const &) const;			//Operateur ==
	bool operator!=(Matrice const &) const;			//Operateur !=
	bool operator<(Matrice const &) const;			//Operateur <
	bool operator>(Matrice const &) const;			//Operateur >
	bool operator<=(Matrice const &) const;			//Operateur <=
	bool operator>=(Matrice const &) const;			//Operateur >=
	//Arithmétique
	Matrice& operator+=(Matrice const &);			//Operateur +=
	Matrice& operator-=(Matrice const &);			//Operateur -=
	Matrice& operator*=(Matrice const &);			//Operateur *=

	Matrice operator+(Matrice const &);			//Operateur +
	Matrice operator-(Matrice const &);			//Operateur -
	Matrice operator*(Matrice const &);			//Operateur *

//Fonctions
	void Affiche(std::ostream &) const;			//Affiche la matrice
	bool Sauvegarde(std::string) const;			//Sauvegarde la matrice
	bool Transpose();					//Transpose la matrice
	

};

std::ostream &operator<<( std::ostream &, Matrice const &);	//Operateur <<

#endif //MAT_H
