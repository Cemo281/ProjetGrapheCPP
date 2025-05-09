#ifndef INCLUDE_GRAPH_NON_O_H
#define INCLUDE_GRAPH_NON_O_H 4

/****************************************************
* Patron de Classe :TGraph
* **************************************************
* ROLE : Cette classe permet de gerer et modifier un graphe non oriente 
*			qui herite de la classe PGraphOrient
* **************************************************
* VERSION : 1.0
* AUTEUR : OZDEMIR ALI-CEM
* DATE : 28/04/2025
* *************************************************
* INCLUSIONS EXTERNES :
*/
#include "PGraphOrient.hpp"
#include "PSommet.hpp"
#include "PArc.hpp"
#include <vector>

using namespace std;

/* TYPES:
* Pas de type particulier de declare
*/

/* Variables :
* Pas de variable globale de declaree
*/

template<typename TData> class PGraph : public PGraphOrient<TData>
{
	//Attributs
private:
	//Pas d'attributs specifiques

public:
	//Constructeurs et destructeurs
		PGraph() = default; //Constructeur par defaut	

		explicit PGraph(const PGraphOrient<TData>& GRAParam) : PGraphOrient<TData>(GRAParam) {}


	//METHODES
		/**************************************************************************************************************************
		* METHODE : GRAAjouterArc
		* *************************************************************************************************************************
		* Entree: ptArc, un pointeur vers un arc
		* Necessite : Rien
		* Sortie: Rien
		* Entraine: Ajoute l'arc au graphe non oriente et son inverse
		***************************************************************************************************************************
		*/
		void GRAAjouterArc(PArc<TData>* ptArc) override;

		/**************************************************************************************************************************
		* METHODE : GRASupprimerArc
		* **************************************************************************************************************************
		* Entree: ptArc, Un pointeur vers un arc
		* Necessite: Rien
		* Sortie: Rien
		* Entrainee: Supprime l'arc et son inverse du graphe non oriente
		* **************************************************************************************************************************
		*/
		void GRASupprimerArc(PArc<TData>* ptArc) override;

		/***************************************************************************************************************************
		* METHODE : GRAAfficher
		* **************************************************************************************************************************
		* Entree : Rien
		* Necessite : Rien
		* Sortie : Rien
		* Entraine : Affiches le graphe non oriente dans la console
		* ***************************************************************************************************************************
		*/
		 void GRAAfficher() override;
};

#include "PGraph.tpp"

#endif