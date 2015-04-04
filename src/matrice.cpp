#include "../inc/matrice.h"

//-------------------------------------------------------Constructeur de matrice 
Matrice::Matrice(int l, int c, double v)
{
	Ml=l;
	Mc=c;

	if(v != 0)
	{
		for(int i=0; i<Ml; i++)
		{
			for(int j=0; j<Mc; j++)
			{
				Mtab[Coordonnee(i,j)] = v;
			}
		}
	}
}

//-------------------------------------------------------Constructeur de matrice d'un fichier
Matrice::Matrice(std::string fichier)
{
	std::ifstream fichierCharger("fichier");
	double valeur;

	if(fichierCharger)		//Lecture du fichier
	{
		fichierCharger >> Ml >> Mc;
  
		for(int i=0; i<Ml; i++)
		{
			for(int j=0; j<Mc; j++)
			{
				fichierCharger >> valeur;

				if(valeur != 0)
				{
					Mtab[Coordonnee(i,j)] = valeur;
				}

			}
		}

		fichierCharger.close();	//Fermeture du fichier
	}

	else
	{
		std::cerr << "Erreur : Fichier Inaccessible" << std::endl;
	}
}

//-------------------------------------------------------Destructeur
Matrice::~Matrice()
{}

//-------------------------------------------------------Operateur
//Comparaison
 //Operateur ==
bool Matrice::operator==(Matrice const & M) const
{

}

 //Operateur !=
bool Matrice::operator!=(Matrice const & M) const
{

}

 //Operateur <
bool Matrice::operator<(Matrice const & M) const
{

}

 //Operateur >
bool Matrice::operator>(Matrice const & M) const
{

}

 //Operateur <=
bool Matrice::operator<=(Matrice const & M) const
{

}

 //Operateur >=
bool Matrice::operator>=(Matrice const & M) const
{

}

//Arithmétique
 //Operateur +=
Matrice& Matrice::operator+=(Matrice const &)
{

}

 //Operateur -=
Matrice& Matrice::operator-=(Matrice const &)
{

}

 //Operateur *=
Matrice& Matrice::operator*=(Matrice const &)
{

}

 //Operateur +
Matrice Matrice::operator+(Matrice const &)
{

}

 //Operateur -
Matrice Matrice::operator-(Matrice const &)
{

}

 //Operateur *
Matrice Matrice::operator*(Matrice const &)
{

}

//-------------------------------------------------------Fonction
 //Affiche la matrice
void Matrice::Affiche(std::ostream &flux) const
{
	std::map <Coordonnee, double>::const_iterator it;

	if(Mc <=  60) //Test du nombre de colonne
	{
		for(int i=0; i<Ml; i++)
		{
			for(int j=0; j<Mc; j++)
			{
				it = Mtab.find(Coordonnee(i,j));
				if(it != Mtab.end())
				{
					flux << it->second << " ";
				}
			
				else
				{
					flux << "0 ";
				}
			}
		
			flux << std::endl;
		}
	}

	else
	{
		for(int i=0; i<Ml; i++)
		{
			for(int j=0; j<Mc; j++)
			{
				it = Mtab.find(Coordonnee(i,j));
				if(it != Mtab.end())
				{
					flux << it->first << " = " << it->second << std::endl;
				}
			
				else
				{
					flux << "(" << i << "|" << j << ") = 0 " << std::endl;
				}
			}
		}		
	}
}

 //Sauvegarde la matrice
bool Matrice::Sauvegarde(std::string nom) const
{
	std::string nomFull = "./mat/" + nom;
	std::ofstream fichierSave(nomFull.c_str());
	if(fichierSave)			//Ecriture du fichier
	{
		std::map <Coordonnee, double>::const_iterator it;

		fichierSave << Ml << Mc;

		for(int i=0; i<Ml; i++)
		{
			for(int j=0; j<Mc; j++)
			{
				it = Mtab.find(Coordonnee(i,j));
				if(it != Mtab.end())
				{
					fichierSave << it->second << " ";
				}
			
				else
				{
					fichierSave << "0 ";
				}
			}
		}

		fichierSave.close();	//Fermeture du fichier
		return true;
	}

	return false;
}

 //Transpose la matrice
bool Matrice::Transpose()
{

}

 //Operateur <<
std::ostream &operator<<( std::ostream & flux, Matrice const & M)
{
	M.Affiche(flux);
	return flux;
}
