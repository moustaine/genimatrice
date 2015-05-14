#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "matrice.h"
#include "couleur.h"

	void mainMenu();						//Gestionnaire de menu

	void afficheTitreGenimatrice();					//Affiche le grand titre Genimatrice
	void afficheTitreMP();						//Affiche Le titre du Menu Principal
	void afficheTitreCrM();						//Affiche Le titre de Création de matrice
	void afficheTitreMM();						//Affiche Le titre de Modification de matrice
	void afficheTitreCaM();						//Affiche Le titre de Calcul de matrice
	void afficheTitreChM();						//Affiche Le titre de Selection de matrice

	void afficheMP(std::string&);					//Affiche Le Menu Principal
	void afficheCrM(std::string&);					//Affiche Le Menu Création de matrice
	void afficheIM(std::string&);					//Affiche Le Menu Information de matrice
	void afficheMM(std::string&);					//Affiche Le Menu Modification de matrice
	void afficheCaM(std::string&);					//Affiche Le Menu Calcul de matrice
	void afficheTM(std::string&);					//Affiche Le Menu Transposé de matrice
	void afficheCalcul(std::string&, const int);			//Affiche Le Calcul de matrice
	int afficheSM(const int = 0);					//Affiche Le Menu Selection de matrice
	void afficheCredit(std::string&);				//Affiche Les crédits du logiciel

	std::string trouveFichier(const int);				//Donne le nom de la ligne demandée du fichier
	bool saveBdd(std::string, Matrice*);				//Sauvegarde dans la base de données
	bool removeSave(std::string);					//Supprime un fichier sauvegarde


#endif //MENU_H
