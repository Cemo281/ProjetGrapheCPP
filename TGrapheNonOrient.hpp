#ifndef INCLUDE_GRAPH_NON_O_H
#define INCLUDE_GRAPH_NON_O_H 4

/****************************************************
* Patron de Classe :TGrapheNonOrient
* **************************************************
* ROLE : Cette classe permet de gerer et modifier un graphe non oriente 
*			qui herite de la classe TGrapheOrient
* **************************************************
* VERSION : 1.0
* AUTEUR : OZDEMIR ALI-CEM
* DATE : 28/04/2025
* *************************************************
* INCLUSIONS EXTERNES :
*/
#include "TGrapheOrient.hpp"
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

template<typename TData> class TGrapheNonOrient : public TGrapheOrient<TData>
{
	//Attributs
private:
	//Pas d'attributs specifiques

	//Constructeurs et destructeurs
public:
	/**************************************************************************************************************************
	* TGrapheNonOrient
	* *************************************************************************************************************************
	* Entree: Rien
	* Necessite : Rien
	* Sortie: Rien
	* Entraine: Creer un graphe non oriente
	***************************************************************************************************************************
	*/
	TGrapheNonOrient() = default;

	/**************************************************************************************************************************
	* TGrapheNonOrient
	* *************************************************************************************************************************
	* Entree: Le graphe non oriente a copier
	* Necessite : Rien
	* Sortie: Rien
	* Entraine: Initialise un graphe non oriente a partir d'un autre graphe non oriente
	***************************************************************************************************************************
	*/
	TGrapheNonOrient(const TGrapheNonOrient& GROParam) = default;

	/**************************************************************************************************************************
	* ~TGrapheNonOrient
	* *************************************************************************************************************************
	* Entree: Rien
	* Necessite: Rien
	* Sortie: Rien
	* Entraine: Detruis un graphe non oriente
	* *************************************************************************************************************************
	*/
	~TGrapheNonOrient() = default;

	//METHODES
	/**************************************************************************************************************************
	* METHODE : GNOAjouterArc
	* **************************************************************************************************************************
	* Entree: ptArc, Un pointeur vers un arc
	* Necessite: Rien
	* Sortie: Rien
	* Entrainee: Ajoute l'arc et son inverse au graphe non oriente
	* **************************************************************************************************************************
	*/
	void GNOAjouterArc(TArc<TData>* ptArc);

	/**************************************************************************************************************************
	* METHODE : GNOSupprimerArc
	* **************************************************************************************************************************
	* Entree: ptArc, Un pointeur vers un arc
	* Necessite: Rien
	* Sortie: Rien
	* Entrainee: Supprime l'arc et son inverse du graphe non oriente
	* **************************************************************************************************************************
	*/
	void GNOSupprimerArc(TArc<TData>* ptArc);
};

#endif