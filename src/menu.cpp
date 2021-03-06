#include "../inc/menu.h"

//--------------------------------------------------------------------------------------------------------------------------------------
//									MAIN MENU
//--------------------------------------------------------------------------------------------------------------------------------------
void mainMenu()
{
	std::string user = "";

	system("clear");

//Menu Principal

	afficheMP(user);

//Fin du Programme

	system("clear");
	std::cout << jaune << "\tMerci d'avoir utilise Genimatrice, A bientôt" << reset << std::endl;
}

//--------------------------------------------------------------------------------------------------------------------------------------
//									AFFICHAGE DES TITRES
//--------------------------------------------------------------------------------------------------------------------------------------
void afficheTitreGenimatrice()
{
std::cout << bleuT << " ██████╗ ███████╗███╗   ██╗██╗███████╗" << roseT << "███╗   ███╗ █████╗ ████████╗██████╗ ██╗ ██████╗███████╗" << std::endl;
std::cout << bleuT << "██╔════╝ ██╔════╝████╗  ██║██║██╔════╝" << roseT << "████╗ ████║██╔══██╗╚══██╔══╝██╔══██╗██║██╔════╝██╔════╝" << std::endl;
std::cout << bleuT << "██║  ███╗█████╗  ██╔██╗ ██║██║█████╗  " << roseT << "██╔████╔██║███████║   ██║   ██████╔╝██║██║     █████╗  " << std::endl;
std::cout << bleuT << "██║   ██║██╔══╝  ██║╚██╗██║██║██╔══╝  " << roseT << "██║╚██╔╝██║██╔══██║   ██║   ██╔══██╗██║██║     ██╔══╝  " << std::endl;
std::cout << bleuT << "╚██████╔╝███████╗██║ ╚████║██║███████╗" << roseT << "██║ ╚═╝ ██║██║  ██║   ██║   ██║  ██║██║╚██████╗███████╗" << std::endl;
std::cout << bleuT << " ╚═════╝ ╚══════╝╚═╝  ╚═══╝╚═╝╚══════╝" << roseT << "╚═╝     ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝ ╚═════╝╚══════╝" << reset << std::endl;
std::cout << "\t\t\t\t\t      By BenJ.J, Princess, JolieDemoiselle et Houdada" << std::endl << std::endl;
}

//--------------------------------------------------------------------------------------------------------------------------------------
void afficheTitreMP()
{
	std::cout << "\t\t+---------------------------+" << std::endl;
	std::cout << "\t\t M e n u   P r i n c i p a l " << std::endl;
	std::cout << "\t\t+---------------------------+" << std::endl << std::endl;
}

//--------------------------------------------------------------------------------------------------------------------------------------
void afficheTitreCrM()
{
	std::cout << "\t+-------------------------------------+" << std::endl;
	std::cout << "\t C r e a t i o n   d e   m a t r i c e " << std::endl;
	std::cout << "\t+-------------------------------------+" << std::endl << std::endl;
}

//--------------------------------------------------------------------------------------------------------------------------------------
void afficheTitreCaM()
{
	std::cout << "\t+---------------------------------+" << std::endl;
	std::cout << "\t C a l c u l   d e   m a t r i c e " << std::endl;
	std::cout << "\t+---------------------------------+" << std::endl << std::endl;
}

//--------------------------------------------------------------------------------------------------------------------------------------
void afficheTitreTM()
{
	std::cout << "\t+---------------------------------------+" << std::endl;
	std::cout << "\t T r a n s p o s e   d e   m a t r i c e " << std::endl;
	std::cout << "\t+---------------------------------------+" << std::endl << std::endl;
}

//--------------------------------------------------------------------------------------------------------------------------------------
void afficheTitreSM()
{
	std::cout << "\t+---------------------------------------+" << std::endl;
	std::cout << "\t S e l e c t i o n   d e   m a t r i c e " << std::endl;
	std::cout << "\t+---------------------------------------+" << std::endl << std::endl;
}

//--------------------------------------------------------------------------------------------------------------------------------------
//									AFFICHAGE DES MENUS
//--------------------------------------------------------------------------------------------------------------------------------------
void afficheMP(std::string& user)
{
	do
	{
		afficheTitreGenimatrice();
		afficheTitreMP();

		std::cout << "\t\t   1 = Creation de matrice" << std::endl;
		std::cout << "\t\t   2 = Transpose matrice" << std::endl;
		std::cout << "\t\t   3 = Calcul de matrice" << std::endl;

		std::cout << "\t\t   q = Quitter" << std::endl << std::endl;

		std::cout << "  - Veuillez indiquer votre choix (1, 2, 3 ou q): ";
		getline(std::cin, user);

		if(user == "1") afficheCrM(user);
		else if(user == "2") afficheTM(user);
		else if(user == "3") afficheCaM(user);
		else if(user == "q") {}//Quitter
		else //Erreur
		{
			system("clear");
			std::cout << rouge << "            Veuillez inserer 1, 2, 3 ou q            " << reset << std::endl;
		}

	}while(user != "q");
}

//--------------------------------------------------------------------------------------------------------------------------------------
void afficheCrM(std::string& user)
{
	system("clear");

	do
	{
	
		afficheTitreCrM();

		std::cout << "\t\t   1 = Matrice Pleine" << std::endl;
		std::cout << "\t\t   2 = Matrice Personnalisee" << std::endl << std::endl;

		std::cout << "\t\t   r = Retour" << std::endl;
		std::cout << "\t\t   q = Quitter" << std::endl << std::endl;

		std::cout << "  - Veuillez indiquer votre choix (1, 2, r ou q): ";
		getline(std::cin, user);

		system("clear");

		Matrice *A = NULL;

		if(user == "1")
		{
			A = new Matrice(true);
			user = "m";
		}

		else if(user == "2")
		{
			A = new Matrice(false);
			user = "m";
		}

		else if(user == "r") system("clear"); //Retourner menu precedent
		else if(user == "q"){} //Quitter
		else //Erreur
		{
			system("clear");
			std::cout << rouge << "             Veuillez inserer 1, 2, r ou q              " << reset << std::endl;
			if(user == "m") user == "pas m";
		}

		if(user == "m")
		{
			do
			{
				std::cout << std::endl << *A << std::endl << std::endl << "  - Voulez vous modifier des valeurs de la matrice ? (y, r ou q): ";
				getline(std::cin, user);

				if(user == "y")
				{
					double v = 0;
					int l = 0, c = 0;

					std::cout << std::endl << std::endl << "  - Veuillez inserer la ligne : ";
					getline(std::cin, user);
					l = atoi(user.c_str());

					std::cout << "  - Veuillez inserer la colonne : ";
					getline(std::cin, user);
					c = atoi(user.c_str());

					std::cout << "  - Veuillez inserer la valeur : ";
					getline(std::cin, user);
					v = atof(user.c_str());

					A->Insert(l, c, v);
				}
				else if(user == "r") system("clear"); //Retourner menu precedent
				else if(user == "q"){} //Quitter
				else //Erreur
				{
					system("clear");
					std::cout << rouge << "             Veuillez inserer y, r ou q              " << reset << std::endl;
				}
			}while(user != "q" && user != "r");

			std::string tmp = "";

			std::cout << std::endl << *A << std::endl << std::endl << "  - Veuillez donner un nom à la matrice : ";
			getline(std::cin, tmp);

			saveBdd(tmp, A);

			delete A;
			A = NULL;

			system("clear");
		}

	}while(user != "q" && user != "r");

	system("clear");
}

//--------------------------------------------------------------------------------------------------------------------------------------
void afficheCaM(std::string& user)
{
	system("clear");

	do
	{
		afficheTitreCaM();

		std::cout << "\t\t   1 = Matrice * Squalaire" << std::endl;
		std::cout << "\t\t   2 = Matrice / Squalaire" << std::endl;
		std::cout << "\t\t   3 = Matrice + Matrice" << std::endl;
		std::cout << "\t\t   4 = Matrice - Matrice" << std::endl;
		std::cout << "\t\t   5 = Matrice * Matrice" << std::endl << std::endl;

		std::cout << "\t\t   r = Retour" << std::endl;
		std::cout << "\t\t   q = Quitter" << std::endl << std::endl;

		std::cout << "  - Veuillez indiquer votre choix (1, 2, 3, 4, 5, r ou q): ";
		getline(std::cin, user);

		if(user == "1" || user == "2" || user == "3" || user == "4" || user == "5") afficheSM(user, atoi(user.c_str()));
		else if(user == "r") system("clear"); //Retourner menu precedent
		else if(user == "q"){} //Quitter
		else //Erreur
		{
			system("clear");
			std::cout << rouge << "             Veuillez inserer 1, 2, r ou q              " << reset << std::endl;
		}

	}while(user != "q" && user != "r");
}

//--------------------------------------------------------------------------------------------------------------------------------------
void afficheTM(std::string& user)
{
	do
	{
		system("clear");

		afficheTitreSM();

		int i = 0, maxChoix = 0, choix = 0;
		std::string mat = "", info = "";
		Matrice* A = NULL;

		std::ifstream fichier("./mat/Matrice.bdd");
		if(fichier)		//Lecture du fichier
		{
//affichage de la liste de fichiers
			while(!fichier.eof())
			{
				i++;

				getline(fichier, info);

				if(info != "")
				{
					std::cout << "\t\t   " << i << " = " << info << std::endl;
				}
			}

			fichier.close();//Fermeture du fichier
		}

		else
		{
			std::cerr << rouge << "Erreur : Fichier Inaccessible" << std::endl;
		}

//Affichage si aucun fichier
		if(i-1 == 0)
		{
			std::cout << "\t\t   Aucune Matrice" << std::endl;
		}

		std::cout << std::endl;
		std::cout << "\t\t   r = Retour" << std::endl;
		std::cout << "\t\t   q = Quitter" << std::endl << std::endl;
	
//Test des différentes possibilités de demande de choix
		if(i-1 > 1)	  std::cout << "  - Veuillez indiquer votre choix (1 à " << i-1 << ", r, q ou x[choix] pour supprimer) : ";
		else if(i-1 == 1) std::cout << "  - Veuillez indiquer votre choix (1 , r, q ou x1 pour supprimer) : ";
		else		  std::cout << "  - Veuillez créer des matrices (r ou q) : ";

		maxChoix = i-1;

		getline(std::cin, user);
		choix = atoi(user.c_str()); // on change string en int

		if(user != "q" && user != "r" && user[0] != 'x')
		{
			if(choix <= maxChoix && choix > 0) //Test si le choix est valide
			{
				mat = trouveFichier(choix);

				A = new Matrice("./mat/"+mat);

				A->Transpose();

				std::cout << std::endl << *A << std::endl << "  - Voulez vous sauvegarder la matrice ? (y, n) : ";
				getline(std::cin, user);

				if(user == "y")
				{
					std::cout << std::endl << *A << std::endl << "  - Veuillez donner un nom à la matrice : ";
					getline(std::cin, user);

					saveBdd(user, A);			
				}

				delete A;
				A = NULL;
			}

			else
			{
				system("clear");
				if(maxChoix > 1) std::cout << rouge << "        Veuillez inserer 1 à " << maxChoix << ", r, q ou x[choix]        " << reset << std::endl;
				else if(maxChoix == 1) std::cout << rouge << "             Veuillez inserer 1, r, q ou x1             " << reset << std::endl;
				else std::cout << rouge << "                Veuillez inserer r ou q                 " << reset << std::endl;
			}
		}

		else if(user[0] == 'x')
		{
			user.erase(0,1); //supprime le x
			choix = atoi(user.c_str()); // on change string en int
			if(choix <= maxChoix && choix > 0) //Test si le choix est valide
			{
				removeSave(trouveFichier(choix));
				system("clear");
			}

			else
			{
				system("clear");
				if(maxChoix > 1) std::cout << rouge << "        Veuillez inserer 1 à " << maxChoix << ", r, q ou x[choix]        " << reset << std::endl;
				else if(maxChoix == 1) std::cout << rouge << "             Veuillez inserer 1, r, q ou x1             " << reset << std::endl;
				else std::cout << rouge << "                Veuillez inserer r ou q                 " << reset << std::endl;
			}	
		}
	}while(user != "r" && user != "q");

	system("clear");
}

//--------------------------------------------------------------------------------------------------------------------------------------
int afficheSM(std::string& user, const int type)
{
	system("clear");

	afficheTitreSM();

	int i = 0, maxChoix = 0, choix1 = 0, choix2 = 0;
	double v = 0;
	std::string mat1 = "", mat2 = "", info = "";
	Matrice *A = NULL, *B = NULL, *C = NULL;

	std::ifstream fichier("./mat/Matrice.bdd");
	if(fichier)		//Lecture du fichier
	{
//affichage de la liste de fichiers
		while(!fichier.eof())
		{
			i++;

			getline(fichier, info);

			if(info != "")
			{
				std::cout << "\t\t   " << i << " = " << info << std::endl;
			}
		}

		fichier.close();//Fermeture du fichier
	}

	else
	{
		std::cerr << rouge << "Erreur : Fichier Inaccessible" << std::endl;
	}

//Affichage si aucun fichier
	if(i-1 == 0)
	{
		std::cout << "\t\t   Aucune Matrice" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "\t\t   r = Retour" << std::endl;
	std::cout << "\t\t   q = Quitter" << std::endl << std::endl;
	
//Test des différentes possibilités de demande de choix
	if(user == "1" || user == "2")
	{
		if(i-1 > 1)	  std::cout << "  - Veuillez indiquer votre choix (1 à " << i-1 << ", r, q ou x[choix] pour supprimer) : ";
		else if(i-1 == 1) std::cout << "  - Veuillez indiquer votre choix (1 , r, q ou x1 pour supprimer) : ";
		else		  std::cout << "  - Veuillez créer des matrices (r ou q) : ";

		maxChoix = i-1;

		getline(std::cin, user);
		choix1 = atoi(user.c_str()); // on change string en int

		std::cout << "  - Veuillez indiquer votre choix pour le squalaire : ";
		getline(std::cin, user);
		v = atof(user.c_str());
	}
	else if(user == "3" || user == "4" || user == "5")
	{
		if(i-1 > 1)
		{
			std::cout << "  - Veuillez indiquer votre choix comme matrice (1 à " << i-1 << ", r, q ou x[choix] pour supprimer)" << std::endl;
			std::cout << "  - Veuillez indiquer votre choix pour la première matrice : ";
			getline(std::cin, user);
			choix1 = atoi(user.c_str()); // on change string en int

			if(user[0] != 'x')
			{
				std::cout << "  - Veuillez indiquer votre choix pour la deuxieme matrice : ";
				getline(std::cin, user);
				choix2 = atoi(user.c_str()); // on change string en int
			}
		}
		else if(i-1 == 1)
		{
			std::cout << "  - Veuillez créer des matrices ou le calcul ce fera sur la matrice elle meme (1 , r, q ou x1 pour supprimer) : ";
			getline(std::cin, user);
			choix1 = atoi(user.c_str()); // on change string en int
			choix2 = choix1;
		}
		else std::cout << "  - Veuillez créer des matrices (r ou q)";

		maxChoix = i-1;
	}

	if(user != "q" && user != "r" && user[0] != 'x')
	{
		if(((type == 1 || type == 2) && choix1 <= maxChoix && choix1 > 0) || ((type == 3 || type == 4 || type == 5) && choix1 <= maxChoix && choix1 > 0 && choix2 <= maxChoix && choix2 > 0)) //Test si le choix est valide
		{
			mat1 = trouveFichier(choix1);
			if(type == 3 || type == 4 || type == 5) mat2 = trouveFichier(choix2);

			A = new Matrice("./mat/"+mat1);
			if(type == 3 || type == 4 || type == 5) B = new Matrice("./mat/"+mat2);

			C = new Matrice();

			if(type == 1)
			{
				*C = *A * v;
			}
			else if(type == 2)
			{
				*C = *A / v;
			}
			else if(type == 3)
			{
				*C = *A + *B;
			}
			else if(type == 4)
			{
				*C = *A - *B;
			}
			else if(type == 5)
			{
				*C = *A * *B;
			}

			std::cout << std::endl << *C << std::endl << "  - Voulez vous sauvegarder la matrice ? (y, n) : ";
			getline(std::cin, user);

			if(user == "y")
			{
				std::cout << std::endl << *C << std::endl << "  - Veuillez donner un nom à la matrice : ";
				getline(std::cin, user);

				saveBdd(user, C);			
			}

			delete A;
			A = NULL;
			delete B;
			B = NULL;
			delete C;
			C = NULL;
		}

		else
		{
			system("clear");
			if(maxChoix > 1) std::cout << rouge << "        Veuillez inserer 1 à " << maxChoix << ", r, q ou x[choix]        " << reset << std::endl;
			else if(maxChoix == 1) std::cout << rouge << "             Veuillez inserer 1, r, q ou x1             " << reset << std::endl;
			else std::cout << rouge << "                Veuillez inserer r ou q                 " << reset << std::endl;
		}
	}

	else if(user[0] == 'x')
	{
		user.erase(0,1); //supprime le x
		choix2 = atoi(user.c_str()); // on change string en int
		if(choix2 <= maxChoix && choix2 > 0) //Test si le choix est valide
		{
			removeSave(trouveFichier(choix2));
			system("clear");
		}

		else
		{
			system("clear");
			if(maxChoix > 1) std::cout << rouge << "        Veuillez inserer 1 à " << maxChoix << ", r, q ou x[choix]        " << reset << std::endl;
			else if(maxChoix == 1) std::cout << rouge << "             Veuillez inserer 1, r, q ou x1             " << reset << std::endl;
			else std::cout << rouge << "                Veuillez inserer r ou q                 " << reset << std::endl;
		}	
	}

	system("clear");
}

//--------------------------------------------------------------------------------------------------------------------------------------
//									OUTILS
//--------------------------------------------------------------------------------------------------------------------------------------
std::string trouveFichier(const int ligne)
{
	std::string info = "";
	int i = 0;

	std::ifstream fichier("./mat/Matrice.bdd");
	if(fichier)				//Lecture du fichier
	{
		while(!fichier.eof())
		{
			i++;

			getline(fichier, info);

			if(i == ligne)
			{
				fichier.close();//Fermeture du fichier (valeur trouver)
				return info;
			}
		}

		fichier.close();		//Fermeture du fichier (valeur non trouver)
	}

	else
	{
		std::cerr << rouge << "Erreur : Fichier Inaccessible" << std::endl;
	}

	return 0;
}

//--------------------------------------------------------------------------------------------------------------------------------------
bool saveBdd(std::string nom, Matrice* A)
{

std::string info = "";

//efface ligne bdd si elle existe
	rename("./mat/Matrice.bdd", "./mat/Matrice.bdd.tmp"); //renomme la bdd en bdd temporaire
	std::ifstream fichierBDDCTmp("./mat/Matrice.bdd.tmp");
	std::ofstream fichierBDDC("./mat/Matrice.bdd");

	if(fichierBDDC && fichierBDDCTmp)	//Lecture et Ecriture de fichier
	{
		while(std::getline(fichierBDDCTmp, info))
		{
			if(info != A->NomSave(nom))
			{
				fichierBDDC << info << std::endl;	
			}
		}

		fichierBDDCTmp.close();	//Fermeture du fichier Lecture
		fichierBDDC.close();	//Fermeture du fichier Ecriture

		remove("./mat/Matrice.bdd.tmp");
	}

//creer la sauvegarde

	A->Save(nom);

//met a jour la bdd
	std::ofstream fichierBDD("./mat/Matrice.bdd", std::ios::app);

	if(fichierBDD)			//Ecriture du fichier
	{
		fichierBDD << A->NomSave(nom) << std::endl;

		fichierBDD.close();	//Fermeture du fichier
		return true;
	}

	else
	{
		std::cerr << rouge << "Erreur : Fichier Inaccessible" << std::endl;
		return false;
	}
}

//--------------------------------------------------------------------------------------------------------------------------------------
bool removeSave(std::string fichier)
{
	if(fichier != "0")
	{
		rename("./mat/Matrice.bdd", "./mat/Matrice.bdd.tmp"); //renomme la bdd en bdd temporaire

		std::ifstream fichierBDDTmp("./mat/Matrice.bdd.tmp");
		std::ofstream fichierBDD("./mat/Matrice.bdd");
		std::string valeur;
		bool supprimer = false;

		if(fichierBDD && fichierBDDTmp)	//Lecture et Ecriture de fichier
		{
			while(std::getline(fichierBDDTmp, valeur))
			{
				if(valeur != fichier)
				{
					fichierBDD << valeur << std::endl;	
				}
			}

			fichierBDDTmp.close();	//Fermeture du fichier Lecture
			fichierBDD.close();	//Fermeture du fichier Ecriture

			remove("./mat/Matrice.bdd.tmp");
			supprimer = true;
		}
		else
		{
			std::cerr << rouge << "Erreur : Fichier Inaccessible" << std::endl;
			return false;
		}

		if(supprimer)
		{
			fichier = "./mat/"+fichier;
			remove(fichier.c_str());
			return true;
		}
	}

	return false;
}
