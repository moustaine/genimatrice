#include "../inc/coordonnee.h"

Coordonnee::Coordonnee(int x,int y)								//Constructeurs
{
	Cx = x;
	Cy = y;
}

Coordonnee::~Coordonnee()									//Destructeur
{}

int Coordonnee::getCx() const									//Cx
{
	return Cx;
}

int Coordonnee::getCy() const									//Cy
{
	return Cy;
}

void Coordonnee::Affiche(std::ostream &flux) const						//Affichage
{
	flux << "(" << Cx << "|" << Cy << ")";	
}

Coordonnee & Coordonnee::operator=(const Coordonnee & A)					//Operateur =
{
	Cx = A.Cx;
	Cy = A.Cy;
	return *this;
}

bool Coordonnee::operator<(const Coordonnee & A) const						//Operateur <
{
	return (Cx != A.Cx) ? (Cx < A.Cx) : (Cy < A.Cy);
}

std::ostream &operator<<( std::ostream &flux, Coordonnee const& C)				//Operateur <<
{
    C.Affiche(flux) ;
    return flux;
}
