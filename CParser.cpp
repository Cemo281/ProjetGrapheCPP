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
#include "PArc.hpp"
#include "PSommet.hpp"
#include "PGraphOrient.hpp"
#include "CParser.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <exception>

using namespace std;

/*********************************
* Parser
* ********************************
* Entree : PARFichier, le fichier a parser
* Necessite : Le fichier doit etre de la forme suivante:
*	NBSommets=<Nombre_de_Sommets_du_graphe>
*	NBArcs=< Nombre_d_arcs_du_graphe >
*	Sommets=[
*	Numero=<Numéro_sommet >
*	Numero=<Numéro_sommet>
*	…
*	Numero=<Numéro_sommet>
*	]
*	Arcs=[
*	Debut=<Sommet_départ_arc>, Fin=<Sommet_arrivée_arc>
*	Debut=<Sommet_départ_arc>, Fin=<Sommet_arrivée_arc>
*	…
*	Debut=<Sommet_départ_arc>, Fin=<Sommet_arrivée_arc>
*	]
* Les sommets doivent etre avant les arcs.
* Sortie : Un Graphe
* Entraine : Retourne un graphe
* *********************************
*/
PGraphOrient<void*>* CParser::ParseGraph(ifstream& PARFichier) {
	PGraphOrient<void*>* Graphe = new PGraphOrient<void*>;

	string sLigne;                 // pour stocker la ligne lue
	string sNbSom, sNbArc;         // pour stocker le nombre de sommet et d'arc
	string sValSom;				   // pour stocker la valeur du sommet
	string sSomDepart, sSomArrive; // pour stocker le sommet de depart et d'arrive
	unsigned int uiNbSom, uiNbArc;			   // pour convertir le nombre de sommet et d'arc en entier 
	unsigned int uiSomDepart, uiSomArrive;    // pour convertir les sommets de depart et d'arrive en entier

	PSommet<void*>* SOMTmp;        // pour stocker le sommet temporaire
	PArc<void*>* ARCTmp;		   // pour stocker l'arc temporaire	

	getline(PARFichier, sLigne);   // lire la premiere ligne
	sLigne.erase(remove(sLigne.begin(), sLigne.end(), ' '), sLigne.end()); // retirer tout les espaces
	int pos = sLigne.find("=");    // trouver la position du "="
	sLigne.erase(0, pos + 1);      // supprimer tout ce qui est avant le "="
	sNbSom = sLigne;               // stocker le nombre de sommet

	getline(PARFichier, sLigne);   // lire la deuxieme ligne
	sLigne.erase(remove(sLigne.begin(), sLigne.end(), ' '), sLigne.end()); // retirer tout les espaces
	pos = sLigne.find("=");        // trouver la position du "="
	sLigne.erase(0, pos + 1);      // supprimer tout ce qui est avant le "="
	sNbArc = sLigne;               // stocker le nombre d'arc

	// les convertir en entiers
	uiNbSom = stoi(sNbSom);
	uiNbArc = stoi(sNbArc);

	getline(PARFichier, sLigne);    // lire la ligne des sommets
	sLigne.erase(remove(sLigne.begin(), sLigne.end(), ' '), sLigne.end()); // retirer tout les espaces
	pos = sLigne.find("=");         // trouver la position du "="
	sLigne.erase(0, pos + 1);       // supprimer tout ce qui est avant le "="

	// Sommet
	if (sLigne == "[") {
		while (sLigne != "]") {
			getline(PARFichier, sLigne); // lire la ligne suivante
			if (sLigne == "]") {
				break;  // sortir de la boucle si on atteint la fin de la liste de sommet a creer
			}
			else {
				pos = sLigne.find("=");   // trouver la position du "="
				sLigne.erase(0, pos + 1); // supprimer tout ce qui est avant le "="
				sLigne.erase(remove(sLigne.begin(), sLigne.end(), ' '), sLigne.end()); // retirer tout les espaces
				sValSom = sLigne;         // stocker la valeur du sommet
			}

			SOMTmp = new PSommet<void*>(stoi(sValSom));
			Graphe->GRAAjouterSommet(SOMTmp);				// ajouter le sommet au graphe
		}
	}
	else {
		throw runtime_error("Erreur : La liste des sommets n'est pas bien formatee");
	}

	getline(PARFichier, sLigne);	// lire la ligne des arcs
	pos = sLigne.find("=");		    // trouver la position du "="
	sLigne.erase(0, pos + 1);       // supprimer tout ce qui est avant le "="
	sLigne.erase(remove(sLigne.begin(), sLigne.end(), ' '), sLigne.end()); // retirer tout les espaces

	// Arc
	if (sLigne == "[") {
		while (sLigne != "]") {
			getline(PARFichier, sLigne); // lire la ligne suivante
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
				
				// Convertis les sommets en entier
				uiSomDepart = stoi(sSomDepart); 
				uiSomArrive = stoi(sSomArrive); 

				ARCTmp = new PArc<void*>(uiSomDepart, uiSomArrive);
				Graphe->GRAAjouterArc(ARCTmp);
			}
		}
		PARFichier.close();
	}

	if (Graphe->GRATailleLstArc() != uiNbArc && Graphe->GRATailleLstSommet() != uiNbSom) {
		throw invalid_argument("Erreur : Le nombre d'arcs et de sommet ne correspond pas aux nombres indique dans le fichier");
	}
	else if (Graphe->GRATailleLstArc() != uiNbArc) {
		throw invalid_argument("Erreur : Le nombre d'arcs ne correspond pas au nombre indique dans le fichier");
	}
	else if (Graphe->GRATailleLstSommet() != uiNbSom) {
		throw invalid_argument("Erreur : Le nombre de sommet ne correspond pas au nombre indique dans le fichier");
	}

	return Graphe;
}