// ProjetGrapheCPP.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

using namespace std;

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "TArc.hpp"
#include "TSommet.hpp"
#include "TGrapheOrient.hpp"
#include <assert.h>

int main()
{
	TGrapheOrient<void*>* Graphe = new TGrapheOrient<void*>;
	// Test getline()
	string sLigne;
	ifstream FILE("C:/Users/alice/OneDrive/Desktop/fichier.txt");
	string sNbSom;
	string sNbArc;
	int iNbSom;
	int iNbArc;
	string sValSom;
	string sSomDepart;
	string sSomArrive;

	TSommet<void*>* SOMTmp;
	TArc<void*>* ARCTmp;

	cout << "========= DEBUT DE CREATION DU GRAPHE =========" << endl;
	cout << endl;
	getline(FILE, sLigne); // lire la première ligne
	int pos = sLigne.find("="); // trouver la position du "="
	sLigne.erase(0, pos + 1); // supprimer tout ce qui est avant le "="
	sLigne.erase(remove(sLigne.begin(), sLigne.end(), ' '), sLigne.end()); // retirer tout les espaces
	sNbSom = sLigne; // stocker le nombre de sommet


	getline(FILE, sLigne); // lire la deuxième ligne
	pos = sLigne.find("="); // trouver la position du "="
	sLigne.erase(0, pos + 1); // supprimer tout ce qui est avant le "="
	sLigne.erase(remove(sLigne.begin(), sLigne.end(), ' '), sLigne.end());// trouver la position du "="
	sNbArc = sLigne; // stocker le nombre d'arc

	// les convertir en entiers
	iNbSom = stoi(sNbSom);
	iNbArc = stoi(sNbArc);

	getline(FILE, sLigne); // lire la troisième ligne
	pos = sLigne.find("="); // trouver la position du "="
	sLigne.erase(0, pos + 1); // supprimer tout ce qui est avant le "="
	sLigne.erase(remove(sLigne.begin(), sLigne.end(), ' '), sLigne.end()); // retirer tout les espaces

	cout << "========= DEBUT DE CREATION DES SOMMETS =========" << endl;
	cout << endl;
	// Sommet
	if (sLigne == "[") {
		while (sLigne != "]") {
			getline(FILE, sLigne); // lire la ligne suivante
			if (sLigne == "]") {
				break; // sortir de la boucle si on atteint la fin de la liste
			}
			else {
				pos = sLigne.find("="); // trouver la position du "="
				sLigne.erase(0, pos + 1); // supprimer tout ce qui est avant le "="
				sLigne.erase(remove(sLigne.begin(), sLigne.end(), ' '), sLigne.end()); // retirer tout les espaces
				sValSom = sLigne; // stocker la valeur du sommet
				cout << "Sommet : " << sValSom << endl; // afficher la valeur du sommet
			}
			SOMTmp = new TSommet<void*>(stoi(sValSom));
			Graphe->GROAjouterSommet(SOMTmp);
		}
	}
	cout << endl;
	cout << "========= CREATION DES SOMMETS TERMINE =========" << endl;
	cout << endl;

	getline(FILE, sLigne); // lire la quatrième ligne
	pos = sLigne.find("="); // trouver la position du "="
	sLigne.erase(0, pos + 1); // supprimer tout ce qui est avant le "="
	sLigne.erase(remove(sLigne.begin(), sLigne.end(), ' '), sLigne.end()); // retirer tout les espaces

	cout << "========= DEBUT DE CREATION DES ARCS =========" << endl;
	cout << endl;

	// Arc
	if (sLigne == "[") {
		while (sLigne != "]") {
			getline(FILE, sLigne); // lire la ligne suivante
			sLigne.erase(remove(sLigne.begin(), sLigne.end(), ' '), sLigne.end()); // retirer tout les espaces
			if (sLigne == "]") {
				break; // sortir de la boucle si on atteint la fin de la liste
			}
			else {

				pos = sLigne.find(","); // trouver la position du "="

				sSomDepart = sLigne.substr(0, pos); // extraire la partie avant la virgule
				sSomArrive = sLigne.substr(pos + 1); // extraire la partie après la virgule
				
				pos = sSomDepart.find("="); // trouver la position du "="
				sSomDepart.erase(0, pos + 1); // supprimer tout ce qui est avant le "="

				pos = sSomArrive.find("="); // trouver la position du "="
				sSomArrive.erase(0, pos + 1); // supprimer tout ce qui est avant le "="

				cout << "Sommet de depart : " << sSomDepart << " Sommet d'arrive : " << sSomArrive << endl; // afficher la valeur du sommet

				ARCTmp = new TArc<void*>(stoi(sSomDepart), stoi(sSomArrive));
				if (Graphe->GROARCEstDansGraphe(ARCTmp) == false) {
					Graphe->GROAjouterArc(ARCTmp);
				}
				else {
					cout << "L'arc existe deja dans le graphe" << endl;
				}

			}
		}
		cout << endl;
		cout << "========= CREATION DES ARCS TERMINE =========" << endl;
		cout << endl;
		cout << "========= CREATION DU GRAPHE TERMINEE =========" << endl;
		cout << endl;
		cout << "========= AFFICHAGE DU GRAPHE =========" << endl;
		cout << endl;
		Graphe->GROAfficher();

		delete Graphe;
		FILE.close();

		bool test;
		TArc<void*>* ptArc = new TArc<void*>(1, 2);
		TArc<void*>* ptArc2 = new TArc<void*>(1, 2);
		test = (ptArc==ptArc2);
		assert(test == true);
		return 0;
	}
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
