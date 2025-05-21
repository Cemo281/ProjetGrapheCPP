#pragma once

//
// Created by Ali-Cem on 02/05/2025
//

#ifndef INCLUDE_PARSER_H
#define INCLUDE_PARSER_H 5

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
#include <string>
#include <fstream>

using namespace std;

class CParser
{
private: 
	string PARType;  // Afin de stocker le type du graph creer.

public:
	/*********************************
	* METHODE : PARLireType
	* ********************************
	* Entree: Rien
	* Necessite: Rien
	* Sortie: PARType
	* Entraine: Retourne le type du graph parser
	* ********************************
	*/
	string PARLireType() const { return PARType; }

	/*********************************
	* METHODE : PARRecupType
	* ********************************
	* Entree: PARFichier, le fichier a parser
	* Necessite: Le fichier doit être bien forme
	* Sortie: Rien
	* Entraine: Recupere le type sur la premiere ligne du fichier PARFichier
	* ********************************
	*/
	void PARRecupType(ifstream& PARFichier);

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
	PGraphOrient<unsigned int>* PARGROEntierNS(ifstream& PARFichier);

	PGraphOrient<double>* PARGROReel(ifstream& PARFichier);

	PGraphOrient<void*>* PARGrapheO(ifstream& PARFichier);
};

#endif