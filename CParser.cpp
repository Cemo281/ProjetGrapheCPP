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
* METHODE : PARRecupType
* ********************************
* Entree: PARFichier, le fichier a parser
* Necessite: Le fichier doit être bien forme
* Sortie: Rien
* Entraine: Recupere le type sur la premiere ligne du fichier PARFichier
* ********************************
*/
void CParser::PARRecupType(ifstream& PARFichier) {
	string sLigne1, sLigne2;
	unsigned int uiIndex, uiPos;

	getline(PARFichier, sLigne1);
	sLigne1.erase(remove(sLigne1.begin(), sLigne1.end(), ' '), sLigne1.end()); // retirer tout les espaces
	for (uiIndex = 0; uiIndex < sLigne1.size(); uiIndex++) { sLigne1[uiIndex] = tolower(sLigne1[uiIndex]); } // on met toute les lettres en minuscule
	uiPos = sLigne1.find('=');
	// On regarde si un type a été mis
	sLigne2 = sLigne1.substr(0, uiPos);
	if (sLigne2 != "type" && sLigne2 != "types") {
		// S'il n'y en a pas, on met PARType a void
		PARType = "void";
		return;
	}
	// Sinon, on stock le type
	sLigne1.erase(0, uiPos + 1); // Retirer tout ce qu'il y'a avant le '=':  Type=<type> => <type>
	PARType = sLigne1;
	return;
}

/*********************************
* Parser
* ********************************
* Entree : PARFichier, le fichier a parser
* Necessite : Voir le README pour le bon formatage du fichier.
* Sortie : Un Graphe
* Entraine : Retourne un graphe
* *********************************
*/
PGraphOrient<void*>* CParser::PARGrapheO(ifstream& PARFichier) {
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
			Graphe->GROAjouterSommet(SOMTmp);				// ajouter le sommet au graphe
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
				pos = sLigne.find(","); // trouver la position du ","

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
				Graphe->GROAjouterArc(ARCTmp);
			}
		}
		PARFichier.close();
	}

	if (Graphe->GROTailleLstArc() != uiNbArc && Graphe->GROTailleLstSommet() != uiNbSom) {
		throw invalid_argument("Erreur : Le nombre d'arcs et de sommet ne correspond pas aux nombres indique dans le fichier");
	}
	else if (Graphe->GROTailleLstArc() != uiNbArc) {
		throw invalid_argument("Erreur : Le nombre d'arcs ne correspond pas au nombre indique dans le fichier");
	}
	else if (Graphe->GROTailleLstSommet() != uiNbSom) {
		throw invalid_argument("Erreur : Le nombre de sommet ne correspond pas au nombre indique dans le fichier");
	}

	return Graphe;
}

/**********************************************************************************/
PGraphOrient<unsigned int>* CParser::PARGROEntierNS(ifstream& PARFichier) {
	PGraphOrient<unsigned int>* Graphe = new PGraphOrient<unsigned int>;

	string sLigne;                 // pour stocker la ligne lue
	string sNbSom, sNbArc;         // pour stocker le nombre de sommet et d'arc
	string sValSom;				   // pour stocker la valeur du sommet
	string sSomDepart, sSomArrive, sPoids; // pour stocker le sommet de depart, d'arrive et le poids
	unsigned int uiNbSom, uiNbArc;			   // pour convertir le nombre de sommet et d'arc en entier 
	unsigned int uiSomDepart, uiSomArrive, uiPoids;    // pour convertir les sommets de depart et d'arrive en entier

	PSommet<unsigned int>* SOMTmp;        // pour stocker le sommet temporaire
	PArc<unsigned int>* ARCTmp;		   // pour stocker l'arc temporaire	

	getline(PARFichier, sLigne);   // lire la seconde ligne
	sLigne.erase(remove(sLigne.begin(), sLigne.end(), ' '), sLigne.end()); // retirer tout les espaces
	int pos = sLigne.find("=");    // trouver la position du "="
	sLigne.erase(0, pos + 1);      // supprimer tout ce qui est avant le "="
	sNbSom = sLigne;               // stocker le nombre de sommet

	getline(PARFichier, sLigne);   // lire la troisieme ligne
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

			SOMTmp = new PSommet<unsigned int>(stoi(sValSom));
			Graphe->GROAjouterSommet(SOMTmp);				// ajouter le sommet au graphe
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
				pos = sLigne.find(","); // trouver la position du ","

				sSomDepart = sLigne.substr(0, pos);  // extraire la partie avant la virgule
				sSomArrive = sLigne.substr(pos + 1); // extraire la partie apr�s la virgule
		
				pos = sSomArrive.find(',');
				sPoids = sSomArrive.substr(pos + 1); // extraire la partie apr�s la virgule
				sSomArrive = sSomArrive.substr(0, pos);  // extraire la partie avant la virgule

				pos = sSomDepart.find("=");   // trouver la position du "="
				sSomDepart.erase(0, pos + 1); // supprimer tout ce qui est avant le "="
 
				pos = sSomArrive.find("=");   // trouver la position du "="
				sSomArrive.erase(0, pos + 1); // supprimer tout ce qui est avant le "="
			
				pos = sPoids.find("=");   // trouver la position du "="
				sPoids.erase(0, pos + 1); // supprimer tout ce qui est avant le "="
				
				// Convertis les sommets en entier
				uiSomDepart = stoi(sSomDepart);
				uiSomArrive = stoi(sSomArrive);
				uiPoids = stoi(sPoids);

				ARCTmp = new PArc<unsigned int>(uiSomDepart, uiSomArrive, uiPoids);
				Graphe->GROAjouterArc(ARCTmp);
			}
		}
		PARFichier.close();
	}

	if (Graphe->GROTailleLstArc() != uiNbArc && Graphe->GROTailleLstSommet() != uiNbSom) {
		throw invalid_argument("Erreur : Le nombre d'arcs et de sommet ne correspond pas aux nombres indique dans le fichier");
	}
	else if (Graphe->GROTailleLstArc() != uiNbArc) {
		throw invalid_argument("Erreur : Le nombre d'arcs ne correspond pas au nombre indique dans le fichier");
	}
	else if (Graphe->GROTailleLstSommet() != uiNbSom) {
		throw invalid_argument("Erreur : Le nombre de sommet ne correspond pas au nombre indique dans le fichier");
	}

	return Graphe;
}