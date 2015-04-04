#ifndef COOR_H
#define COOR_H

#include <iostream>

class Coordonnee
{
protected :
	int Cx;								//Position en ligne
	int Cy;								//Position en colonne
public :

	Coordonnee(int = 0,int = 0);					//Constructeurs
	
	~Coordonnee();							//Destructeur

	int getCx() const;						//Cx
	int getCy() const;						//Cy

	void Affiche(std::ostream &) const;				//Affichage
	
	Coordonnee & operator=(const Coordonnee &);			//Operateur =
	bool operator<(const Coordonnee &) const;			//Operateur <

};

std::ostream &operator<<( std::ostream &, Coordonnee const&);		//Operateur <<

#endif //COOR_H
