#include "../inc/matrice.h"

//-------------------------------------------------------Constructeur de matrice 
Matrice::Matrice(int l, int c, double v)
{
	Ml = l;
	Mc = c;

	if(v != 0)
	{
		Mcreux = false;
		MnbZero = 0;

//Création du tableau

		MtabPlein = new double*[Ml];
		for(int i = 0; i < Ml; i++)
		{
			MtabPlein[i] = new double[Mc];
		}

//Initialisation du tableau
		for(int i = 0; i < Ml; i++)
		{
			for(int j = 0; j < Mc; j++)
			{
				MtabPlein[i][j] = v;
			}
		}
	}

	else
	{
		Mcreux = true;
		MnbZero = Ml*Mc;
	}
}

//-------------------------------------------------------Constructeur de matrice par fichier
Matrice::Matrice(std::string matrice)
{
	double valeur = 0;

	MnbZero = 0;

	std::ifstream fichier(matrice.c_str());
	if(fichier)		//Lecture du fichier
	{
		fichier >> Ml >> Mc >> Mcreux;

		if(!Mcreux)
		{
//Création du tableau

			MtabPlein = new double*[Ml];
			for(int i = 0; i < Ml; i++)
			{
				MtabPlein[i] = new double[Mc];
			}

//Initialisation du tableau
			for(int i = 0; i < Ml; i++)
			{
				for(int j = 0; j < Mc; j++)
				{
					fichier >> valeur;

					if(valeur == 0) MnbZero++;

					MtabPlein[i][j] = valeur;
				}
			}
		}

		else
		{
			int l = 0, c = 0;

			fichier >> MnbZero;

			while(!fichier.eof())
			{
				fichier >> l >> c >> valeur;

				MtabCreux[Coordonnee(l, c)] = valeur;
			}
		}

		fichier.close();	//Fermeture du fichier
	}

	else
	{
		std::cerr << "Erreur : Fichier Inaccessible" << std::endl;
	}
}

//-------------------------------------------------------Destructeur
Matrice::~Matrice()
{
	if(!Mcreux)
	{
		for(int i = 0; i < Ml; i++)
		{
			delete [] MtabPlein[i];
		}

		delete [] MtabPlein;
	}
}

//-------------------------------------------------------Operateur
//Comparaison
 //Operateur ==
bool Matrice::operator==(const Matrice& A) const
{
	if((Ml == A.Ml) && (Mc == A.Mc) && (Mcreux == A.Mcreux))
	{
		if(Mcreux)
		{
			std::map <Coordonnee, double>::const_iterator it1, it2;

			for(it1 = MtabCreux.begin(), it2 = A.MtabCreux.begin(); it1 != MtabCreux.end(); it1++, it2++)
			{
				if((it1->first != it2->first) || (it1->second != it2->second)) return false;
			}
		}
		else
		{
			for(int i = 0; i < Ml; i++)
			{
				for(int j = 0; j < Mc; j++)
				{
					if(MtabPlein[i][j] != A.MtabPlein[i][j]) return false;
				}
			}
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
	if(Mcreux != A.Mcreux)
	{
		if(Mcreux)
		{
			MtabCreux.clear();
		}
		else
		{
			for(int i = 0; i < Ml; i++)
			{
				delete [] MtabPlein[i];
			}

			delete [] MtabPlein;

			MtabPlein = NULL;
		}
	}

	Ml = A.Ml;
	Mc = A.Mc;
	Mcreux = A.Mcreux;
	MnbZero = A.MnbZero;

	if(!Mcreux)
	{

//Création du tableau

		MtabPlein = new double*[Ml];
		for(int i = 0; i < Ml; i++)
		{
			MtabPlein[i] = new double[Mc];
		}

//Copie du tableau

		for(int i = 0; i < Ml; i++)
		{
			for(int j = 0; j < Mc; j++)
			{
				MtabPlein[i][j] = A.MtabPlein[i][j];
			}
		}
	}
	else
	{
		std::map <Coordonnee, double>::const_iterator it;

		for(it = A.MtabCreux.begin(); it != A.MtabCreux.end(); it++)
		{
			MtabCreux[it->first] = it->second;
		}
	}

	return *this;
}

 //Operateur *= Squalaire
Matrice& Matrice::operator*=(const double a)
{
	if(Mcreux)
	{
		if(a == 0)
		{
			MtabCreux.clear();
			MnbZero = Ml*Mc;
		}
		else
		{
			std::map <Coordonnee, double>::iterator it;

			for(it = MtabCreux.begin(); it != MtabCreux.end(); it++)
			{
				it->second *= a;
			}
		}
	}
	else
	{
		if(a == 0)
		{
			for(int i = 0; i < Ml; i++)
			{
				delete [] MtabPlein[i];
			}

			delete [] MtabPlein;

			MtabPlein = NULL;

			MnbZero = Ml*Mc;
		}
		else
		{
			for(int i = 0; i < Ml; i++)
			{
				for(int j = 0; j < Mc; j++)
				{
					MtabPlein[i][j] *= a;
				}
			}
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
Matrice& Matrice::operator+=(Matrice const & A)
{

}

 //Operateur -= Matrice
Matrice& Matrice::operator-=(Matrice const & A)
{

}

 //Operateur *= Matrice
Matrice& Matrice::operator*=(Matrice const & A)
{

}

 //Operateur + Matrice
Matrice operator+(Matrice const & A, const Matrice& B)
{

}

 //Operateur - Matrice
Matrice operator-(Matrice const & A, const Matrice& B)
{

}

 //Operateur * Matrice
Matrice operator*(Matrice const & A, const Matrice& B)
{

}

//-------------------------------------------------------Fonction
 //Affiche la matrice
std::ostream& operator<<(std::ostream& flux, const Matrice& A)
{
	bool tailleAffichable = ((A.Ml <= 40) && (A.Mc <= 15));

	if(A.Mcreux)
	{
//Affichage Matrice Creuse
		std::map <Coordonnee, double>::const_iterator it;
		it = A.MtabCreux.begin();

		if(tailleAffichable)
		{
	//Affichage petite Matrice
			for(int i = 0; i < A.Ml; i++)
			{
				for(int j = 0; j < A.Mc; j++)
				{
					if(it->first == Coordonnee(i, j) && it != A.MtabCreux.end())
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

			if(it == A.MtabCreux.end())
			{
				flux << "Toutes les cases sont à 0";
			}
			else
			{
				for(it = A.MtabCreux.begin(); it != A.MtabCreux.end(); it++)
				{
					flux << it->first << " = " << it->second << std::endl;
				}
			}
		}
	}
	else
	{
//Affichage Matrice Pleine
		if(tailleAffichable)
		{
	//Affichage petite Matrice
			for(int i = 0; i < A.Ml; i++)
			{
				for(int j = 0; j < A.Mc; j++)
				{
					flux << A.MtabPlein[i][j] << "\t";
				}

				flux << std::endl;
			}
		}
		else
		{
	//Affichage grande Matrice
			for(int i = 0; i < A.Ml; i++)
			{
				for(int j = 0; j < A.Mc; j++)
				{
					flux << i << "|" << j << " = " << A.MtabPlein[i][j] << std::endl;
				}
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
		fichierSave << Ml << " " << Mc << " " << Mcreux;

		if(Mcreux)
		{
			fichierSave << " " << MnbZero << std::endl;

			std::map <Coordonnee, double>::const_iterator it;

			for(it = MtabCreux.begin(); it != MtabCreux.end(); it++)
			{
				fichierSave << it->first.toString() << " " << it->second << std::endl;
			}
		}
		else
		{
			fichierSave << std::endl;

			for(int i = 0; i < Ml; i++)
			{
				for(int j = 0; j < Mc; j++)
				{
					fichierSave << MtabPlein[i][j] << " ";
				}

				fichierSave << std::endl;
			}			
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

bool Matrice::Traduit()
{

}
