#include <iostream>
#include <cstdlib>

#include "../inc/matrice.h"

using namespace std;

int main()
{
	system("clear");

//Test constructeur nouveau

	Matrice A(5, 5);
	Matrice B(10, 10, 1);

//Test affiche

	cout << endl << A << endl << endl << B << endl;

//Test sauvegarde

	A.Save("A");
	B.Save("B");

//Test constructeur fichier

	Matrice C("./mat/5-5-A.mat");
	cout << C << endl;

	Matrice D("./mat/10-10-B.mat");
	cout << D << endl;

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
	cout << "B *= 2 : " << endl << endl << B << endl;

//=
	C = B;
	cout << "C = B : " << endl << endl << C << endl;

	return EXIT_SUCCESS;
}
