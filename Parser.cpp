//
// Created by Ali-Cem on 02/05/2025
//

/****************************************************
* FONCTION : Parser
* **************************************************
* ROLE : Cet algorithme permet de parser un fichier
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
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

/*********************************
* Parser
* ********************************
* Entree : Le nom du fichier a parser
* Necessite : Rien
* Sortie : Un Graphe
* Entraine : Retourne un graphe
* *********************************
*/
TGrapheOrient<void*> Parser(ifstream& Fichier) {
	TGrapheOrient<void*>* Graphe = new TGrapheOrient<void*>();
	string sLigne;
	unsigned int uiSommetDepart, uiSommetArrive;
	string sConteneur;

	getline(Fichier, sLigne);

	return *Graphe;
}