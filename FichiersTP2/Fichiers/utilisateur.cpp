/********************************************
* Titre: Travail pratique #2 - utilisateur.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#include "utilisateur.h"

// Constructeurs
Utilisateur::Utilisateur() : nom_(""), nombreDepenses_(0){
}

Utilisateur::Utilisateur(const string& nom)
	: nom_(nom), nombreDepenses_(0) {
}

Utilisateur::Utilisateur(const Utilisateur & utilisateur) 
	: nom_(utilisateur.nom_), nombreDepenses_(utilisateur.nombreDepenses_), depenses_(utilisateur.depenses_) {
}

//Destructeur
Utilisateur::~Utilisateur() {
	for (unsigned int i = 0; i < depenses_.size(); i++)
	{
		delete depenses_[i];
		depenses_[i] = nullptr;
	}
}

// Methodes d'acces
string Utilisateur::getNom() const {
	return nom_;
}

unsigned int Utilisateur::getNombreDepense() const {
	return nombreDepenses_;
}

double Utilisateur::getTotalDepenses() const {
	double total = 0;
	for (unsigned int i = 0; i < nombreDepenses_; i++) {
		total += depenses_[i]->getMontant();
	}
	return total;
}

vector< Depense* > Utilisateur::getDepenses() const {

	return depenses_;
}


//Methodes de modification
void Utilisateur::setNom(const string& nom) {
	nom_ = nom;
}

void Utilisateur::ajouterDepense(Depense* depense) {
	
	depenses_.push_back(depense);
	nombreDepenses_++;
}

// Methode d'affichage
ostream& operator<<(ostream& os, const Utilisateur& utilisateur)
{
	os << "Utilisateur : " << utilisateur.getNom() << " a depense pour un total de : " << utilisateur.getTotalDepenses() << endl
		<< "\t Liste de depenses : " << endl;
	for (unsigned int i = 0; i < utilisateur.nombreDepenses_; i++) {
		cout << "\t\t" << utilisateur.depenses_[i];
	}
	return os;
}