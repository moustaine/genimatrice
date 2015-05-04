#include <iostream>
#include <cstdlib>

#include "../inc/matrice.h"

using namespace std;

int main()
{
	system("clear");

//Test constructeur nouveau et affiche

	cout << "Matrice A :" << endl;
	Matrice A(true);
//	cout << endl << A << endl;

	cout << "Matrice B :" << endl;
	Matrice B(true);
//	cout << endl << B << endl;	

//Test sauvegarde

	A.Save("A");
	B.Save("B");

//Test constructeur fichier

	string fichier = "./mat/1000-1000-A.mat";

	cout << "Matrice C :" << endl;
	Matrice C(fichier);
//	cout << C << endl;

	fichier = "./mat/1000-1000-B.mat";

	cout << "Matrice D :" << endl;
	Matrice D(fichier);
//	cout << D << endl;

//Test Comparaison
// ==

	cout << "A == B : " << (A == B) << endl;
	cout << "B == D : " << (B == D) << endl;

// !=

	cout << "A != B : " << (A != B) << endl;
	cout << "B != D : " << (B != D) << endl << endl;

//Test Arithmétique
//*= Squalaire
	B *= 2;
//	cout << "B *= 2 : " << endl << endl << B << endl;

//= et * Squalaire
	C = B * 2;
//	cout << "C = B * B : " << endl << endl << C << endl;

//+ Matrice
	D = B + C;
//	cout << "D = B + C : " << endl << endl << D << endl;

//- Matrice
	D = B - C;
//	cout << "D = B - C : " << endl << endl << D << endl;

	return EXIT_SUCCESS;
}
