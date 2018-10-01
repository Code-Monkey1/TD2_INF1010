/********************************************
* Titre: Travail pratique #2 - main.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#include <iostream>
#include "depense.h"
#include "utilisateur.h"
#include  "transfert.h"
#include "groupe.h"

using namespace std;

int main() {

	cout << "\t \tBienvenue sur PolyCount " << endl << " *****************************************************" << endl;

	// Initialisation des depenses
	Depense* d1 = &Depense("d1", 12, "IGA");
	Depense* d2 = &Depense("d2", 11, "Provigo");
	Depense* d3 = &Depense("d3", 5, "Jean-drapeau");
	Depense* d4 = &Depense("d4", 23, "Vieux port");
	Depense* d5 = &Depense("d5", 17, "Metro");
	Depense* d6 = &Depense("d6", 29, "Desjardins");
	// Exemples d'utilisation du constructeur par copie et de l'operateur d'assignation
	Depense* d7 = &Depense(*d5);
	(*d7).setNom("d7");
	(*d7).setLieu("Maisonnee");

	Depense* d8 = &Depense();
	d8 = d1;
	(*d8).setNom("d8");
	(*d8).setLieu("Banque scotia");

	// Initialisation des utilisateurs
	Utilisateur* u1 = &Utilisateur("Martin");
	Utilisateur* u2 = &Utilisateur("Franklin");
	Utilisateur* u3 = &Utilisateur("Geraldine");
	Utilisateur* u4 = &Utilisateur("Bernard");

	//Exemple d'utilisation de l'operateur d'assignation
	Utilisateur* u5 = &Utilisateur();
	u5 = u1;
	(*u5).setNom("Christian");

	// Initialisation du groupe
	Groupe groupe = Groupe("vacances");

	// Ajout des utilisateurs et des depenses au groupe
	((((groupe += u1) += u2) += u3) += u4) += u5;

	groupe.ajouterDepense(d1, u1).ajouterDepense(d2, u1).ajouterDepense(d3, u2).ajouterDepense(d4, u3).ajouterDepense(d5, u4)
		.ajouterDepense(d6, u5).ajouterDepense(d7, u3).ajouterDepense(d8, u4);
	
	
	cout << groupe;
	// Equilibrage des comptes
	groupe.equilibrerComptes();
	cout << groupe;

	// TODO: Terminez le programme correctement

	system("pause");
	return 0;
}
