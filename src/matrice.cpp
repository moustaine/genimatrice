#include "../inc/matrice.h"

//-------------------------------------------------------Constructeur de matrice
Matrice::Matrice(const bool initialisation)
{
	std::string info = "";
	int nombreI = 0;
	double nombreD = 0;
	bool correct = true;

//Demande du nombre de ligne

	do
	{
		std::cout << "  - Inserer le nombre de ligne : ";
		getline(std::cin, info);
		nombreI = atoi(info.c_str());

		correct = (nombreI > 0);

		if(!correct) std::cout << rouge << "Veuillez inserer un nombre superieur a 0" << reset << std::endl;
		else Ml = nombreI;

	}while(!correct);

//Demande du nombre de colonne

	do
	{
		std::cout << "  - Inserer le nombre de colonne : ";
		getline(std::cin, info);
		nombreI = atoi(info.c_str());

		correct = (nombreI > 0);

		if(!correct) std::cout << rouge << "Veuillez inserer un nombre superieur a 0" << reset << std::endl;
		else Mc = nombreI;

	}while(!correct);


//------Initialisation

	if(initialisation)
	{
		std::cout << "  - Inserer un nombre réel pour toute les cases : ";
		getline(std::cin, info);
		nombreD = atof(info.c_str());

		if(nombreD != 0)
		{

//Initialisation du tableau

			for(int i = 0; i < Ml; i++)
			{
				for(int j = 0; j < Mc; j++)
				{
					Mtab[Coordonnee(i, j)] = nombreD;
				}
			}
		}
	}

//------Personnalisation

	else
	{

//Personnalisation du tableau

		for(int i = 0; i < Ml; i++)
		{
			for(int j = 0; j < Mc; j++)
			{
				std::cout << "  - Inserer un nombre réel pour la case (" << i << "|" << j << ") : ";
				getline(std::cin, info);
				nombreD = atof(info.c_str());

				if(nombreD != 0) Mtab[Coordonnee(i, j)] = nombreD;
			}
		}
	}
}

//-------------------------------------------------------Constructeur de matrice par fichier
Matrice::Matrice(std::string matrice)
{
	double nombre = 0;
	int l = 0, c = 0;

	std::ifstream fichier(matrice.c_str());
	if(fichier)		//Lecture du fichier
	{
		fichier >> Ml >> Mc;



		while(!fichier.eof())
		{
			fichier >> l >> c >> nombre;

			Mtab[Coordonnee(l, c)] = nombre;
		}

		fichier.close();//Fermeture du fichier
	}

	else
	{
		std::cerr << "Erreur : Fichier Inaccessible" << std::endl;
	}
}

//-------------------------------------------------------Destructeur
Matrice::~Matrice()
{
}

//-------------------------------------------------------Operateur
//Comparaison
 //Operateur ==
bool Matrice::operator==(const Matrice& A) const
{
	if((Ml == A.Ml) && (Mc == A.Mc))
	{
		std::map <Coordonnee, double>::const_iterator it, itA;

		for(it = Mtab.begin(), itA = A.Mtab.begin(); it != Mtab.end(); it++, itA++)
		{
			if((it->first != itA->first) && (it->second != itA->second)) return false;
		}
	}
	else return false;

	return true;
}

 //Operateur !=
bool Matrice::operator!=(const Matrice& A) const
{
	return !(*this == A);
}

//Arithmétique

Matrice& Matrice::operator=(const Matrice& A)
{
	Ml = A.Ml;
	Mc = A.Mc;

	Mtab.clear();

	std::map <Coordonnee, double>::const_iterator it;

	for(it = A.Mtab.begin(); it != A.Mtab.end(); it++)
	{
			Mtab[it->first] = it->second;
	}

	return *this;
}

 //Operateur *= Squalaire
Matrice& Matrice::operator*=(const double a)
{
	if(a == 0)
	{
		Mtab.clear();
	}
	else
	{
		std::map <Coordonnee, double>::iterator it;

		for(it = Mtab.begin(); it != Mtab.end(); it++)
		{
			it->second *= a;
		}
	}

	return *this;
}

 //Operateur * Squalaire
Matrice operator*(const Matrice& A, const double a)
{
	Matrice resultat = A;
	return resultat *= a;
}

 //Operateur += Matrice
Matrice& Matrice::operator+=(const Matrice& A)
{
	if(Ml == A.Ml && Mc == A.Mc)
	{
		std::map <Coordonnee, double>::iterator it;
		std::map <Coordonnee, double>::const_iterator itA;

//Addition de chaque cases

		it = Mtab.begin();
		itA = A.Mtab.begin();

		while(itA != A.Mtab.end())
		{
			if(it->first == itA->first)
			{
				it->second += itA->second;

				it++;
				itA++;
			}
			else if(itA->first < it->first)
			{
				Mtab[itA->first] = itA->second;

				itA++;
			}
		}
	}

	return *this;
}

 //Operateur -= Matrice
Matrice& Matrice::operator-=(const Matrice& A)
{
	if(Ml == A.Ml && Mc == A.Mc)
	{
		std::map <Coordonnee, double>::iterator it;
		std::map <Coordonnee, double>::const_iterator itA;

//Soustraction de chaque cases

		it = Mtab.begin();
		itA = A.Mtab.begin();

		while(itA != A.Mtab.end())
		{
			if(it->first == itA->first)
			{
				it->second -= itA->second;

				it++;
				itA++;
			}
			else if(itA->first < it->first)
			{
				Mtab[itA->first] = -itA->second;

				itA++;
			}
		}
	}

	return *this;
}

 //Operateur *= Matrice
Matrice& Matrice::operator*=(const Matrice& A)
{

}

 //Operateur + Matrice
Matrice operator+(const Matrice& A, const Matrice& B)
{
	Matrice resultat = A;
	return resultat += B;
}

 //Operateur - Matrice
Matrice operator-(const Matrice& A, const Matrice& B)
{
	Matrice resultat = A;
	return resultat -= B;
}

 //Operateur * Matrice
Matrice operator*(const Matrice& A, const Matrice& B)
{

}

//-------------------------------------------------------Fonction
 //Affiche la matrice
std::ostream& operator<<(std::ostream& flux, const Matrice& A)
{
	bool tailleAffichable = ((A.Ml <= 40) && (A.Mc <= 15));

	std::map <Coordonnee, double>::const_iterator it;
	it = A.Mtab.begin();

	if(tailleAffichable)
	{
//Affichage petite Matrice
		for(int i = 0; i < A.Ml; i++)
		{
			for(int j = 0; j < A.Mc; j++)
			{
				if(it->first == Coordonnee(i, j) && it != A.Mtab.end())
				{
					flux << it->second << "\t";

					it++;
				}
				else flux << "0\t";
			}
		
			flux << std::endl;
		}
	}
	else
	{
//Affichage grande Matrice

		if(it == A.Mtab.end())
		{
			flux << "Toutes les cases sont à 0";
		}
		else
		{
			for(it = A.Mtab.begin(); it != A.Mtab.end(); it++)
			{
				flux << it->first << " = " << it->second << std::endl;
			}
		}
	}

	return flux;
}

 //Sauvegarde la matrice
bool Matrice::Save(std::string nom) const
{
	std::string nomFull = "./mat/" + NomSave(nom);

	std::ofstream fichierSave(nomFull.c_str());
	if(fichierSave)			//Ecriture du fichier
	{
		fichierSave << Ml << " " << Mc << std::endl;

		std::map <Coordonnee, double>::const_iterator it;

		for(it = Mtab.begin(); it != Mtab.end(); it++)
		{
			fichierSave << it->first.toString() << " " << it->second << std::endl;
		}

		fichierSave.close();	//Fermeture du fichier
		return true;
	}

	return false;
}

 //Envoie le nom de la sauvegarde
std::string Matrice::NomSave(std::string nom) const
{
	std::stringstream out;

	out << Ml << "-" << Mc << "-" << nom << ".mat"; 

	return out.str();
}

 //Transpose la matrice
bool Matrice::Transpose()
{

}
