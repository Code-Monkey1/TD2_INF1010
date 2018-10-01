/********************************************
* Titre: Travail pratique #2 - depense.h
* Date: 2 octobre 2018
* Auteurs: Raphael Geoffrion et Jules Lefebvre
*******************************************/

#ifndef DEPENSE_H
#define DEPENSE_H

#include <string>
#include <iostream>

using namespace std;

class Depense {
public:
	// Constructeurs
	Depense();
	Depense(const string& nom, double montant, string lieu);
	Depense(const Depense& depense);

	//Destructeur
	~Depense();

	// Methodes d'acces
	string getNom() const;
	double getMontant() const;
	string getLieu() const;

	// Methodes de modifications
	void setNom(const string& nom);
	void setMontant(double montant);
	void setLieu(string lieu);

	// Surcharge de l'operateur =
	Depense& operator=(const Depense& depense);

	// Surcharge de l'operateur <<
	friend ostream& operator<<(ostream& os, const Depense& depense);

private:
	string nom_;
	double montant_;
	string* lieu_;
};
#endif