#include <iostream>
#include <cstdlib>
#include "../inc/matrice.h"

using namespace std;

int main()
{
	Coordonnee Crd;

	cout << "Entrez les coordonnes de la matrice (ligne): ";
	cin >> Crd.Cx;
	cout << "Entrez les coordonnes de la matrice (colonne): ";
	cin >> Crd.Cy;

	if(Crd.Cx <10000 && Crd.Cy <10000) // Les valeurs ici (10000) sont a titre indicatif
	{
		Crd(cx, cy);
	}
	else
	{
		cout << "Vous avez pas rentre les bon parametres ! ";
	}

	// EXPLICATION DU CODE :
	// Dans le main de la matrice je verifie surtout que le mec a rentré les bons parametres
	// et si tout va bien, je lance le constructeur,sinon je renvoi un message d'erreur correspondant.

	return EXIT_SUCCESS;
}
