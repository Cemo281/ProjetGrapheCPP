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
		/**************************************************************************************************************************
		* PGraph
		* *************************************************************************************************************************
		* Entree: Rien
		* Necessite : Rien
		* Sortie: Rien
		* Entraine: Initialise un graph vide
		***************************************************************************************************************************
		*/
		PGraph() = default; //Constructeur par defaut	

		/**************************************************************************************************************************
		* PGraphOrient
		* *************************************************************************************************************************
		* Entree: GROParam, un graph
		* Necessite : Rien
		* Sortie: Rien
		* Entraine: Créer un graph à partir d'un autre graph
		***************************************************************************************************************************
		*/
		explicit PGraph(const PGraphOrient<TData>& GROParam) : PGraphOrient<TData>(GROParam) {}


	//METHODES
		/**************************************************************************************************************************
		* METHODE : GROAjouterArc
		* *************************************************************************************************************************
		* Entree: ptArc, un pointeur vers un arc
		* Necessite : Rien
		* Sortie: Rien
		* Entraine: Ajoute l'arc au graphe non oriente et son inverse
		***************************************************************************************************************************
		*/
		void GROAjouterArc(PArc<TData>* ptArc) override;

		/**************************************************************************************************************************
		* METHODE : GROSupprimerArc
		* **************************************************************************************************************************
		* Entree: ptArc, Un pointeur vers un arc
		* Necessite: Rien
		* Sortie: Rien
		* Entrainee: Supprime l'arc et son inverse du graphe non oriente
		* **************************************************************************************************************************
		*/
		void GROSupprimerArc(PArc<TData>* ptArc) override;

		/***************************************************************************************************************************
		* METHODE : GROAfficher
		* **************************************************************************************************************************
		* Entree : Rien
		* Necessite : Rien
		* Sortie : Rien
		* Entraine : Affiches le graphe non oriente dans la console
		* ***************************************************************************************************************************
		*/
		 void GROAfficher() override;
};

#include "PGraph.tpp"

#endif