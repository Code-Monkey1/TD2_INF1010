/********************************************
* Titre: Travail pratique #2 - groupe.cpp
* Date: 2 octobre 2018
* Auteurs: Raphael Geoffrion et Jules Lefebvre
*******************************************/

#include "groupe.h"

// Constructeurs
Groupe::Groupe() :
	nom_(""),
	nombreDepenses_(0),
	nombreUtilisateurs_(0),
	nombreTransferts_(0)
{
}

Groupe::Groupe(const string& nom) :
	nom_(nom),
	nombreDepenses_(0),
	nombreUtilisateurs_(0),
	nombreTransferts_(0)
{
}

Groupe::~Groupe() {
}

// Methodes d'acces
string Groupe::getNom() const {
	return nom_;
}

unsigned int Groupe::getNombreDepenses() const {
	return nombreDepenses_;
}

double Groupe::getTotalDepenses() const {
	double total = 0;
	for (int i = 0; i < nombreDepenses_; i++) {
		total += depenses_[i]->getMontant();
	}
	return total;
}

// Methodes de modifications
void Groupe::setNom(const string& nom) {
	nom_ = nom;
}



// Methodes d'ajout

Groupe& Groupe::operator+=(Utilisateur *ptrNouvUtilisateur)
{
	nombreUtilisateurs_++;
	utilisateurs_.push_back(ptrNouvUtilisateur);
	return *this;
}


Groupe & Groupe::ajouterDepense(Depense* ptrNouvDepense, Utilisateur* ptrUtilisateur) {
	//Ajout dépense au groupe.
	nombreDepenses_++;
	depenses_.push_back(ptrNouvDepense);
	//Ajout dépense à l'utilisateur.
	(*ptrUtilisateur)+=(ptrNouvDepense);
	//Retourne le groupe.
	return *this;
}

void Groupe::calculerComptes()
{
	double moyenne = getTotalDepenses() / nombreUtilisateurs_;
	for (int i = 0; i < nombreUtilisateurs_; i++) {
		comptes_[i] = ((utilisateurs_[i]->getTotalDepenses()) - moyenne);
	}
}

void Groupe::equilibrerComptes() {
	calculerComptes();
	bool calcul = true;
	int count = 0;
	while (calcul) {
		double max = 0;
		double min = 0;
		int indexMax = 0;
		int indexMin = 0;

		// On cherche le compte le plus eleve et le moins eleve
		for (int i = 0; i < nombreUtilisateurs_; i++) {
			if (comptes_[i] > max) {
				max = comptes_[i];
				indexMax = i;
			}
			if (comptes_[i] < min) {
				min = comptes_[i];
				indexMin = i;
			}
		}

		// On cherche lequel des deux a la dette la plus grande
		if (-min <= max) {
			transferts_[nombreTransferts_++] = new Transfert(-min, utilisateurs_[indexMin], utilisateurs_[indexMax]);
			comptes_[indexMax] += min;
			comptes_[indexMin] = 0;
		}
		else {
			transferts_[nombreTransferts_++] = new Transfert(max, utilisateurs_[indexMin], utilisateurs_[indexMax]);
			comptes_[indexMax] = 0;
			comptes_[indexMin] += max;
		}

		// On incremente le nombre de comptes mis a 0
		count++;
		if (-min == max) {
			count++;
		}
		if (count >= nombreUtilisateurs_ - 1) {
			calcul = false;
		}
	}
}


// Methode d'affichage

ostream & operator<<(ostream & os, const Groupe & groupe)
{
	os << "L'evenement " << groupe.getNom() << " a coute un total de " << groupe.getTotalDepenses() << " :  \n\n";
	for (int i = 0; i < groupe.nombreUtilisateurs_; i++) {
		os << groupe.utilisateurs_[i];
	}
	os << endl;

	if (groupe.nombreTransferts_ != 0) {
		os << "Les transferts suivants ont ete realises pour equilibrer  : " << endl;
		for (int i = 0; i < groupe.nombreTransferts_; i++) {
			os << "\t";
			os << groupe.transferts_[i];
		}
	}
	else {
		os << "Les comptes ne sont pas equilibres" << endl << endl;
	}
	os << endl;
	
	return os;
}
