#include <iostream>
#include <cstdlib>

#include "../inc/matrice.h"

using namespace std;

int main()
{
	system("clear");

//Test constructeur nouveau et affiche

	cout << "Matrice A :" << endl;
	Matrice A(false);
	cout << endl << A << endl;

	cout << "Matrice B :" << endl;
	Matrice B(false);
	cout << endl << B << endl;	

//Test sauvegarde

	A.Save("A");
	B.Save("B");

//Test constructeur fichier

	string fichier = "./mat/2-3-C.mat";

	cout << "Matrice C :" << endl;
	Matrice C(fichier);
	cout << C << endl;

	fichier = "./mat/3-2-D.mat";

	cout << "Matrice D :" << endl;
	Matrice D(fichier);
	cout << D << endl;

//Constructeur vide

	cout << "Matrice E :" << endl;
	Matrice E;
	cout << E << endl;

//Test =

	cout << "E = A :" << endl;
	E = A;
	cout << E << endl;

//Test Comparaison
// ==

	cout << "A == B : " << (A == B) << endl;
	cout << "A == E : " << (A == E) << endl;

// !=

	cout << "A != B : " << (A != B) << endl;
	cout << "A != E : " << (A != E) << endl << endl;

//Test Arithmétique

// *= Squalaire
	A *= 5;
	cout << "A *= 5 : " << endl << endl << A << endl;
	
// * Squalaire
	A = A * 5;
	cout << "A = A * 5 : " << endl << endl << A << endl;
	
// /= Squalaire
	A /= 5;
	cout << "A /= 5 : " << endl << endl << A << endl; 
	
// / Squalaire
	A = A / 5;
	cout << "A = A / 5 : " << endl << endl << A << endl;

// += Matrice
	A += B;
	cout << "A += B : " << endl << endl << A << endl;

// + Matrice
	A = A + B;
	cout << "A = A + B : " << endl << endl << A << endl;
	
// - Matrice
	A = A - B;
	cout << "A = A - B : " << endl << endl << A << endl;

// -= Matrice
	A -= B;
	cout << "A -= B : " << endl << endl << A << endl;

// *= Matrice
	C *= D;
	cout << "C *= D : " << endl << endl << C << endl;
	
// * Matrice
	C = C * D;
	cout << "C = C * D : " << endl << endl << C << endl;

// Transpose
	A.Transpose();
	cout << "A^t : " << endl << endl << A << endl;
	
// Insert
	A.Insert(1,1,5);
	cout << "Ligne : 1" << "\t" << "Colonne : 1" << "\t" << "Nouvelle Valeur : 5" << endl << endl << A << endl;

	return EXIT_SUCCESS;
}
