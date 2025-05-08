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
#include "TArc.hpp"
#include "TSommet.hpp"
#include "TGraphOrient.hpp"

class CParser
{
public:
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
	TGraphOrient<void*>* ParseGraph(ifstream& PARFichier);
};

#endif