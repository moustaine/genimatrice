#include "../inc/matrice.h"

//-------------------------------------------------------Constructeur de matrice vide
Matrice::Matrice()
{
	Ml = 1;
	Mc = 1;
}

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

		if((Mtab.empty()) && !(A.Mtab.empty())) return false;

		for(it = Mtab.begin(), itA = A.Mtab.begin(); it != Mtab.end(); it++, itA++)
		{
			if(!((it->first == itA->first) && (it->second == itA->second))) return false;
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
 //Operateur =
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

 //Operateur /= Squalaire
Matrice& Matrice::operator/=(const double a)
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
			it->second /= a;
		}
	}

	return *this;
}

 //Operateur / Squalaire
Matrice operator/(const Matrice& A, const double a)
{
	Matrice resultat = A;
	return resultat /= a;
}

 //Operateur += Matrice
Matrice& Matrice::operator+=(const Matrice& A)
{
	if(Mtab.empty())
	{
		*this = A;
	}
	else
	{
		if(Ml == A.Ml && Mc == A.Mc && !A.Mtab.empty())
		{
			std::map <Coordonnee, double>::iterator it;
			std::map <Coordonnee, double>::const_iterator itA;

//Addition de chaque cases

			it = Mtab.begin();
			itA = A.Mtab.begin();

			for(int i = 0; i < Ml; i++)
			{
				for(int j = 0; j < Mc; j++)
				{
					if(it->first == Coordonnee(i, j))
					{
						if(itA->first == Coordonnee(i, j))
						{
							it->second += itA->second;

							itA++;
						}

						it++;
					}
					else
					{
						if(itA->first == Coordonnee(i, j))
						{
							Mtab[itA->first] = itA->second;

							itA++;
						}
					}
				}
			}
		}
	}

	return *this;
}

 //Operateur -= Matrice
Matrice& Matrice::operator-=(const Matrice& A)
{
	if(Mtab.empty())
	{
		*this = A*-1;
	}
	else
	{
		if(Ml == A.Ml && Mc == A.Mc && !A.Mtab.empty())
		{
			std::map <Coordonnee, double>::iterator it;
			std::map <Coordonnee, double>::const_iterator itA;

//Soustraction de chaque cases

			it = Mtab.begin();
			itA = A.Mtab.begin();

			for(int i = 0; i < Ml; i++)
			{
				for(int j = 0; j < Mc; j++)
				{
					if(it->first == Coordonnee(i, j))
					{
						if(itA->first == Coordonnee(i, j))
						{
							it->second -= itA->second;

							itA++;
						}

						it++;
					}
					else
					{
						if(itA->first == Coordonnee(i, j))
						{
							Mtab[itA->first] = -itA->second;

							itA++;
						}
					}
				}
			}
		}
	}

	return *this;
}

 //Operateur *= Matrice
Matrice& Matrice::operator*=(const Matrice& A)
{

	if(Ml == A.Mc && Mc == A.Ml)
	{

//Création d'un tableau temporaire de la première matrice

		double **tmpT = new double*[Ml];
		for(int i = 0; i < Ml; i++)
		{
			tmpT[i] = new double[Mc];
		}

//Copie de la première matrice

		std::map <Coordonnee, double>::const_iterator itT;
		itT = Mtab.begin();

		for(int i = 0; i < Ml; i++)
		{
			for(int j = 0; j < Mc; j++)
			{
				if(itT == Mtab.end()) tmpT[i][j] = 0;
				else
				{
					if(itT->first == Coordonnee(i, j))
					{
						tmpT[i][j] = itT->second;
						itT++;
					}
					else tmpT[i][j] = 0;
				}
			}
		}

//Création d'un tableau temporaire de la seconde matrice

		double **tmpA = new double*[A.Ml];
		for(int i = 0; i < A.Ml; i++)
		{
			tmpA[i] = new double[A.Mc];
		}

//Copie de la seconde matrice

		std::map <Coordonnee, double>::const_iterator itA;
		itA = A.Mtab.begin(); 

		for(int i = 0; i < A.Ml; i++)
		{
			for(int j = 0; j < A.Mc; j++)
			{
				if(itA == A.Mtab.end()) tmpA[i][j] = 0;
				else
				{
					if(itA->first == Coordonnee(i, j))
					{
						tmpA[i][j] = itA->second;
						itA++;
					}
					else tmpA[i][j] = 0;
				}
			}
		}

//Modification de la première matrice

		Mc = A.Mc;
		Mtab.clear();

//Multiplication des matrices

		for(int i = 0; i < Ml; i++)//ligne
		{
			for(int j = 0; j < Mc; j++)//colonne
			{
				double tmp = 0;

				for(int k = 0; k < A.Ml; k++)//ligne de T et colonne de A
				{
					tmp += (tmpT[i][k] * tmpA[k][j]);
				}

				Mtab[Coordonnee(i, j)] = tmp;
			}
		}

//Suppression première matrice temporaire

		for(int i = 0; i < Ml; i++)
		{
			delete [] tmpT[i];
		}

		delete [] tmpT;

//Suppression seconde matrice temporaire

		for(int i = 0; i < A.Ml; i++)
		{
			delete [] tmpA[i];
		}

		delete [] tmpA;
	}

	return *this;
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
	Matrice resultat = A;
	return resultat *= B;
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
			flux << "Matrice trop grande pour être affichee";
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
Matrice& Matrice::Transpose()
{
//Création d'un tableau temporaire de la matrice

	double **tmp = new double*[Ml];
	for(int i = 0; i < Ml; i++)
	{
		tmp[i] = new double[Mc];
	}

//Copie de la matrice

	std::map <Coordonnee, double>::const_iterator it;
	it = Mtab.begin();

	for(int i = 0; i < Ml; i++)
	{
		for(int j = 0; j < Mc; j++)
		{
			if(it == Mtab.end()) tmp[i][j] = 0;
			else
			{
				if(it->first == Coordonnee(i, j))
				{
					tmp[i][j] = it->second;
					it++;
				}
				else tmp[i][j] = 0;
			}
		}
	}

//Transposer de la matrice

	Mtab.clear();

	for(int i = 0; i < Ml; i++)
	{
		for(int j = 0; j < Mc; j++)
		{
			if(tmp[i][j] != 0)
			{
				Mtab[Coordonnee(j, i)] = tmp[i][j];
			}
		}
	}

	int ml = Ml;

	Ml = Mc;
	Mc = ml;

//Suppression matrice temporaire

		for(int i = 0; i < Mc; i++)
		{
			delete [] tmp[i];
		}

		delete [] tmp;
}

 //Insere une valeur dans la case choisie
void Matrice::Insert(int l, int c, double v)
{
	std::map <Coordonnee, double>::iterator it;
	it = Mtab.find(Coordonnee(l, c));

	if(it == Mtab.end()) Mtab[Coordonnee(l, c)] = v;
	else it->second = v;
}

