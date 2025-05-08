#ifndef INCLUDE_GRAPH_NON_O_H
#define INCLUDE_GRAPH_NON_O_H 4

/****************************************************
* Patron de Classe :TGraph
* **************************************************
* ROLE : Cette classe permet de gerer et modifier un graphe non oriente 
*			qui herite de la classe TGraphOrient
* **************************************************
* VERSION : 1.0
* AUTEUR : OZDEMIR ALI-CEM
* DATE : 28/04/2025
* *************************************************
* INCLUSIONS EXTERNES :
*/
#include "TGraphOrient.hpp"
#include "TSommet.hpp"
#include "TArc.hpp"
#include <vector>

using namespace std;

/* TYPES:
* Pas de type particulier de declare
*/

/* Variables :
* Pas de variable globale de declaree
*/

template<typename TData> class TGraph : public TGraphOrient<TData>
{
	//Attributs
private:
	//Pas d'attributs specifiques

public:
	//Constructeurs et destructeurs
		TGraph() = default; //Constructeur par defaut	

		explicit TGraph(const TGraphOrient<TData>& GROParam) : TGraphOrient<TData>(GROParam) {}


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
		void GROAjouterArc(TArc<TData>* ptArc) override;

		/**************************************************************************************************************************
		* METHODE : GROSupprimerArc
		* **************************************************************************************************************************
		* Entree: ptArc, Un pointeur vers un arc
		* Necessite: Rien
		* Sortie: Rien
		* Entrainee: Supprime l'arc et son inverse du graphe non oriente
		* **************************************************************************************************************************
		*/
		void GROSupprimerArc(TArc<TData>* ptArc) override;

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

#include "TGraph.tpp"

#endif