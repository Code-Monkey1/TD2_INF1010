/********************************************
* Titre: Travail pratique #2 - utilisateur.h
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <string>
#include <iostream>
#include <vector>
#include "depense.h"

using namespace std;

class Utilisateur {
public:
	// Constructeurs
	Utilisateur();
	Utilisateur(const string& nom);
	Utilisateur(const Utilisateur& utilisateur);

	// Destructeur
	~Utilisateur();

	// Methodes d'accès
	string getNom() const;
	unsigned int getNombreDepense() const;
	double getTotalDepenses() const;
	vector< Depense* > getDepenses() const;

	// Methodes de modification
	void setNom(const string& nom);

	// Surcharge de l'operateur +=. Permet d’ajouter une dépense à l’utilisateur. Renvoie ensuite une référence à l’utilisateur.
	Utilisateur& operator+=(Depense* depense);

	// Surcharge de l'operateur =. Écrase les attributs de l’utilisateur par les attributs
	// de l’utilisateur passé en paramètre et qui renvoie ensuite une référence à l’utilisateur.
	Utilisateur& operator=(const Utilisateur& utilisateur);

	// Surcharge de l'operateur << pour l'affichage.
	friend ostream& operator<<(ostream& os, const Utilisateur& utilisateur);

private:
	string nom_;
	unsigned int nombreDepenses_;
	vector< Depense* > depenses_;

};
#endif