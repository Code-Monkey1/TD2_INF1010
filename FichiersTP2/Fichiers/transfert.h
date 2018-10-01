/********************************************
* Titre: Travail pratique #2 - transfert.h
* Date: 2 octobre 2018
* Auteurs: Raphael Geoffrion et Jules Lefebvre
*******************************************/

#ifndef TRANSFERT_H
#define TRANSFERT_H
#include "utilisateur.h"
#include <iostream>
#include <stdio.h>

using namespace std;

class Transfert {
public:

	// Constructeurs
	Transfert();
	Transfert(double montant, Utilisateur* expediteur, Utilisateur* receveur_);

	// Méthodes d'accès
	Utilisateur* getExpediteur() const;
	Utilisateur* getReceveur() const;
	double getMontant() const;


	// Méthodes de modification
	void setMontant(double montant);
	void setExpediteur(Utilisateur* expediteur);
	void setReceveur(Utilisateur* receveur);

	// Surcharge de l'operateur << pour afficher.
	friend ostream& operator<<(ostream& os, const Transfert& transfert);

private:
	double montant_;
	Utilisateur* expediteur_;
	Utilisateur* receveur_;


};

#endif