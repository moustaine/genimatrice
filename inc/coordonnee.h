#ifndef COOR_H
#define COOR_H

#include <iostream>
#include <sstream>

class Coordonnee
{
protected :
	int Cx;		//Position en ligne
	int Cy;		//Position en colonne
public :

	Coordonnee(int = 0,int = 0);						//Constructeurs
	~Coordonnee();								//Destructeur

	int getCx() const;							//Cx
	int getCy() const;							//Cy
	
	Coordonnee& operator=(const Coordonnee&);				//Operateur =
	bool operator==(const Coordonnee&) const;				//Operateur ==
	bool operator!=(const Coordonnee&) const;				//Operateur !=
	bool operator<(const Coordonnee&) const;				//Operateur <
	bool operator>(const Coordonnee&) const;				//Operateur >
	bool operator<=(const Coordonnee&) const;				//Operateur <=
	bool operator>=(const Coordonnee&) const;				//Operateur >=
	friend std::ostream& operator<<(std::ostream&, const Coordonnee&);	//Operateur <<

	std::string toString() const;						//Retourne les coordonnées en string
};



#endif //COOR_H
