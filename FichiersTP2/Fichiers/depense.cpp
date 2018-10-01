/********************************************
* Titre: Travail pratique #2 - depense.cpp
* Date: 2 octobre 2018
* Auteurs: Raphael Geoffrion et Jules Lefebvre
*******************************************/

#include "depense.h"

// Constucteurs
Depense::Depense() : nom_("inconnue"), montant_(0.0), lieu_(nullptr) {
}

Depense::Depense(const string& nom, double montant, string lieu): nom_(nom),
	montant_(montant), lieu_(nullptr){

	lieu_ = new string (lieu);
}

Depense::Depense(const Depense & depense): nom_(depense.nom_), montant_(depense.montant_), lieu_(nullptr)
{
	lieu_ = new string(*(depense.lieu_));
}

//Destructeur
Depense::~Depense()
{
	delete lieu_;
	lieu_ = nullptr;
}

// Methodes d'acces
string Depense::getNom() const {
	return nom_;
}

double Depense::getMontant() const {
	return montant_;
}

string Depense::getLieu() const
{
	return (*lieu_);
}

// Methodes de modifications
void Depense::setNom(const string& nom) {
	nom_ = nom;
}

void Depense::setMontant(double montant) {
	montant_ = montant;
}

void Depense::setLieu(string lieu)
{
	delete lieu_;
	lieu_ = nullptr;
	lieu_ = new string (lieu);
}

// Surcharge de l'operateur =
Depense & Depense::operator=(const Depense & depense)
{
	if (this != &depense) {

		delete lieu_;
		lieu_ = nullptr;
		lieu_ = new string(*(depense.lieu_));
		nom_ = depense.nom_;
		montant_ = depense.montant_;
	}
	return *this;
}

// Methode d'affichage

ostream& operator<<(ostream& os, const Depense& depense)
{
	os << "Achat: " << depense.getNom()
		<< "\tPrix: " << depense.getMontant() << "$\tLieu: " << depense.getLieu()
		<< endl;
	return os;
}
