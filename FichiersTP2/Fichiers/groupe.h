/********************************************
* Titre: Travail pratique #2 - groupe.h
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#ifndef GROUPE_H
#define GROUPE_H

#include <string>
#include <vector>
#include "transfert.h"

using namespace std;

class Groupe {
public:
	// Constructeurs
	Groupe();
	Groupe(const string& nom);

	// Destructeur
	~Groupe();

	// Methodes d'acces
	string getNom() const;
	unsigned int getNombreDepenses() const;
	double getTotalDepenses() const;

	// Methodes de modification
	void setNom(const string& nom);

	// Methodes d'ajout
	// Surcharge d'operateur +=. Permet d'ajouter un utilisateur au groupe et de renvoyer une référence et de renvoyer une référence vers le groupe.
	Groupe& operator+=(Utilisateur* ptrNouvUtilisateur);
	
	void ajouterDepense(Depense* ptrNouvDepense, Utilisateur* ptrUtilisateur);
	

	// Methodes de calcul
	void calculerComptes();
	void equilibrerComptes();

	// Surcharge de l'operateur << pour afficher le contenu du groupe.
	friend ostream& operator<<(ostream& os, const Groupe& groupe);

private:
	string nom_;
	vector<Utilisateur*> utilisateurs_;
	unsigned int nombreUtilisateurs_;
	vector<Depense*> depenses_;
	unsigned int nombreDepenses_;
	vector<Transfert*> transferts_;
	unsigned int nombreTransferts_;
	vector<double> comptes_;

};

#endif
