//
// Created by Ali-Cem on 02/05/2025
//

/****************************************************
* CLASSE : CParser
* **************************************************
* ROLE : Cet classe permet de parser un fichier
* **************************************************
* VERSION : 1.0
* AUTEUR : OZDEMIR Ali-Cem
* DATE : 03/03/2025
* *************************************************
* INCLUSIONS EXTERNES :
*/
#include "TArc.hpp"
#include "TSommet.hpp"
#include "TGrapheOrient.hpp"
#include "CParser.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <exception>

using namespace std;

/*********************************
* Parser
* ********************************
* Entree : Le nom du fichier a parser
* Necessite : Respecter le format du fichier
* Sortie : Un Graphe
* Entraine : Retourne un graphe
* *********************************
*/
TGrapheOrient<void*>* CParser::ParseGraph(ifstream& FILE) {
	TGrapheOrient<void*>* Graphe = new TGrapheOrient<void*>;

	string sLigne;                 // pour stocker la ligne lue
	string sNbSom, sNbArc;         // pour stocker le nombre de sommet et d'arc
	string sValSom;				   // pour stocker la valeur du sommet
	string sSomDepart, sSomArrive; // pour stocker le sommet de depart et d'arrive
	int iNbSom, iNbArc;			   // pour convertir le nombre de sommet et d'arc en entier 
	int iSomDepart, iSomArrive;    // pour convertir les sommets de depart et d'arrive en entier

	TSommet<void*>* SOMTmp;        // pour stocker le sommet temporaire
	TArc<void*>* ARCTmp;		   // pour stocker l'arc temporaire	

	getline(FILE, sLigne); // lire la premiere ligne
	sLigne.erase(remove(sLigne.begin(), sLigne.end(), ' '), sLigne.end()); // retirer tout les espaces
	int pos = sLigne.find("="); // trouver la position du "="
	sLigne.erase(0, pos + 1); // supprimer tout ce qui est avant le "="
	sNbSom = sLigne; // stocker le nombre de sommet

	getline(FILE, sLigne); // lire la deuxieme ligne
	sLigne.erase(remove(sLigne.begin(), sLigne.end(), ' '), sLigne.end()); // retirer tout les espaces
	pos = sLigne.find("="); // trouver la position du "="
	sLigne.erase(0, pos + 1); // supprimer tout ce qui est avant le "="
	sNbArc = sLigne; // stocker le nombre d'arc

	// les convertir en entiers
	iNbSom = stoi(sNbSom);
	iNbArc = stoi(sNbArc);

	getline(FILE, sLigne); // lire la ligne des sommets
	sLigne.erase(remove(sLigne.begin(), sLigne.end(), ' '), sLigne.end()); // retirer tout les espaces
	pos = sLigne.find("="); // trouver la position du "="
	sLigne.erase(0, pos + 1); // supprimer tout ce qui est avant le "="

	// Sommet
	if (sLigne == "[") {
		while (sLigne != "]") {
			getline(FILE, sLigne); // lire la ligne suivante
			if (sLigne == "]") {
				break; // sortir de la boucle si on atteint la fin de la liste de sommet a creer
			}
			else {
				pos = sLigne.find("="); // trouver la position du "="
				sLigne.erase(0, pos + 1); // supprimer tout ce qui est avant le "="
				sLigne.erase(remove(sLigne.begin(), sLigne.end(), ' '), sLigne.end()); // retirer tout les espaces
				sValSom = sLigne; // stocker la valeur du sommet
			}

			SOMTmp = new TSommet<void*>(stoi(sValSom));
			if (Graphe->GROSOMEstDansGraphe(SOMTmp) == false) { // verifier si le sommet n'est pas deja dans le graphe
				Graphe->GROAjouterSommet(SOMTmp);				// ajouter le sommet au graphe
			}
		}
	}
	else {
		throw runtime_error("Erreur : Il n'y a pas de sommet");
	}

	getline(FILE, sLigne);    // lire la ligne des arcs
	pos = sLigne.find("=");   // trouver la position du "="
	sLigne.erase(0, pos + 1); // supprimer tout ce qui est avant le "="
	sLigne.erase(remove(sLigne.begin(), sLigne.end(), ' '), sLigne.end()); // retirer tout les espaces

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

				sSomDepart = sLigne.substr(0, pos);  // extraire la partie avant la virgule
				sSomArrive = sLigne.substr(pos + 1); // extraire la partie apr�s la virgule

				pos = sSomDepart.find("=");   // trouver la position du "="
				sSomDepart.erase(0, pos + 1); // supprimer tout ce qui est avant le "="

				pos = sSomArrive.find("=");   // trouver la position du "="
				sSomArrive.erase(0, pos + 1); // supprimer tout ce qui est avant le "="
				
				iSomDepart = stoi(sSomDepart);
				iSomArrive = stoi(sSomArrive);



				ARCTmp = new TArc<void*>(iSomDepart, iSomArrive);
				if (Graphe->GROARCEstDansGraphe(ARCTmp) == false) {
					Graphe->GROAjouterArc(ARCTmp);
				}
			}
		}
		FILE.close();
	}

	if (Graphe->GROTailleLstArc() != iNbArc && Graphe->GROTailleLstSommet() != iNbSom) {
		cout << "Le nombre d'arcs et de sommet ne correspond pas aux nombres indique dans le fichier" << endl;
		throw invalid_argument("Erreur : Le nombre d'arcs et de sommet ne correspond pas aux nombres indique dans le fichier");
	}
	else if (Graphe->GROTailleLstArc() != iNbArc) {
		cout << "Le nombre d'arcs ne correspond pas au nombre indique dans le fichier" << endl;
		throw invalid_argument("Erreur : Le nombre d'arcs ne correspond pas au nombre indique dans le fichier");
	}
	else if (Graphe->GROTailleLstSommet() != iNbSom) {
		cout << "Le nombre de sommet ne correspond pas au nombre indique dans le fichier" << endl;
		throw invalid_argument("Erreur : Le nombre de sommet ne correspond pas au nombre indique dans le fichier");
	}

	return Graphe;
}