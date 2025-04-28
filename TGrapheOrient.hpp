#ifndef INCLUDE_GRAPHO_H
#define INCLUDE_GRAPHO_H 3

/****************************************************
* Patron de Classe :TGrapheOrient
* **************************************************
* ROLE : Cette classe permet de gerer et modifier un graphe oriente
* **************************************************
* VERSION : 1.0
* AUTEUR : ELAOULA KHAOULA
* DATE : 18/03/2025
* *************************************************
* INCLUSIONS EXTERNES :
*/
#include "TSommet.hpp"
#include "TArc.hpp"
#include <vector>
#include <exception>

using namespace std;

/* TYPES:
* Pas de type particulier de declare
*/

/* Variables :
* Pas de variable globale de declaree
*/

template<typename TData> class TGrapheOrient
{
	//Attributs:
	private:
		vector<TArc<TData>*> vGROLstArc; //liste des Arcs
		vector<TSommet<TData>*> vGROLstSommet; //liste des Sommets
		TData tGROData; //donnees du graphe
	//Constructeurs et destructeurs:
	public:
		/**************************************************************************************************************************
		* TGrapheOrient
		* *************************************************************************************************************************
		* Entree: Rien
		* Necessite : Rien
		* Sortie: Rien
		* Entraine: Initialise un graphe orienté vide
		
		***************************************************************************************************************************
		*/
		TGrapheOrient() = default;

		/**************************************************************************************************************************
		* TGrapheOrient
		* *************************************************************************************************************************
		* Entree: Le graphe oriente a copier
		* Necessite : Rien
		* Sortie: Rien
		* Entraine: Creer un graphe oriente a partir d'un autre graphe oriente
		***************************************************************************************************************************
		*/
		TGrapheOrient(const TGrapheOrient<TData>& GROParam);

		/**************************************************************************************************************************
		* TGrapheOrient
		* *************************************************************************************************************************
		* Entree: Fichier, le fichier contenant le graphe oriente
		* Necessite : Le fichier doit etre valide et bien forme (.txt)
		* Sortie: Rien
		* Entraine: Creer un graphe oriente a partir d'un fichier .txt
		***************************************************************************************************************************
		*/
		// TGrapheOrient(ifstream &Fichier);

		/**************************************************************************************************************************
		* TGrapheOrient
		* *************************************************************************************************************************
		* Entree: Rien
		* Necessite : Rien
		* Sortie: Rien
		* Entraine: Detruit un graphe oriente
		***************************************************************************************************************************
		*/
		~TGrapheOrient() = default;

	//METHODES:
		/**************************************************************************************************************************
		* METHODE : GROAjouterArc()
		* *************************************************************************************************************************
		* Entree:ptArc, un pointeur vers l'arc a ajouter
		* Necessite : Rien
		* Sortie: Rien
		* Entraine: Ajoute l'arc au graphe orienté
		***************************************************************************************************************************
		*/
		void GROAjouterArc(TArc<TData>* ptArc);

		/***************************************************************************************************************************
		* METHODE : GROAjouterSommet()
		* **************************************************************************************************************************
		* Entree: ptSommet,un pointeur vers le sommet a ajouter
		* Necessite : Rien
		* Sortie: Rien
		* Entraine: Ajoute le sommet au graphe orienté
		****************************************************************************************************************************
		*/
		void GROAjouterSommet(TSommet<TData>* ptSom);

		/***************************************************************************************************************************
		* METHODE : SOMEstDansGraphe
		* **************************************************************************************************************************
		* Entree : ptSommet ,un pointeur vers le sommet a ajouter
		* Necessite : Rien
		* Sortie : Booleen
		* Entraine : Verifie si le sommet appartient au graphe orienté
		* **************************************************************************************************************************
		*/
		bool GROSOMEstDansGraphe(TSommet<TData>* ptSommet);

		/***************************************************************************************************************************
		* METHODE : GROARCEstDansGraphe
		* **************************************************************************************************************************
		* Entree : ptArc pinteur vers l'arc à ajouter 
		* Necessite : Rien
		* Sortie : Booleen
		* Entraine : Verifie si l'arc appartient au graphe
		* **************************************************************************************************************************
		*/
		bool GROARCEstDansGraphe(TArc<TData>* ptArc);
};
#include "TGrapheOrient.tpp"

#endif