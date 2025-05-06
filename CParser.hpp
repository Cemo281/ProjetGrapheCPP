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
#include "TGrapheOrient.hpp"

class CParser
{
public:
	/*********************************
	* Parser
	* ********************************
	* Entree : Le nom du fichier a parser
	* Necessite : Rien
	* Sortie : Un Graphe
	* Entraine : Retourne un graphe
	* *********************************
	*/
	TGrapheOrient<void*>* ParseGraph(ifstream& FILE);
};

#endif