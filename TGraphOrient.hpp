#ifndef INCLUDE_GRAPHO_H
#define INCLUDE_GRAPHO_H 3

/****************************************************
* Patron de Classe :TGraphOrient
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

template<typename TData> class TGraphOrient
{
	//Attributs:
	private:
		vector<TArc<TData>*> vGROLstArc; 	   //liste des Arcs
		vector<TSommet<TData>*> vGROLstSommet; //liste des Sommets
		TData tGROData;  					   //donnees du graphe
	//Constructeurs et destructeurs:
	public:
		/**************************************************************************************************************************
		* TGraphOrient
		* *************************************************************************************************************************
		* Entree: Rien
		* Necessite : Rien
		* Sortie: Rien
		* Entraine: Initialise un graphe oriente vide
		***************************************************************************************************************************
		*/
		TGraphOrient() = default;

		/**************************************************************************************************************************
		* TGraphOrient
		* *************************************************************************************************************************
		* Entree: Le graphe oriente a copier
		* Necessite : Rien
		* Sortie: Rien
		* Entraine: Initialise un graphe oriente a partir d'un autre graphe oriente
		***************************************************************************************************************************
		*/
		TGraphOrient(const TGraphOrient<TData>& GROParam);

		/**************************************************************************************************************************
		* TGraphOrient
		* *************************************************************************************************************************
		* Entree: Fichier, le fichier contenant le graphe oriente
		* Necessite : Le fichier doit etre valide et bien forme
		* Sortie: Rien
		* Entraine: Initialise un graphe oriente a partir d'un fichier
		***************************************************************************************************************************
		*/
		TGraphOrient(ifstream &Fichier);

		/**************************************************************************************************************************
		* TGraphOrient
		* *************************************************************************************************************************
		* Entree: Rien
		* Necessite : Rien
		* Sortie: Rien
		* Entraine: Detruit un graphe orisnte
		***************************************************************************************************************************
		*/
		virtual ~TGraphOrient() = default;

	//METHODES:
		/**************************************************************************************************************************
		* METHODE : GROLireData
		* *************************************************************************************************************************
		* Entree: Rien
		* Necessite : Rien
		* Sortie: tGROData, TData
		* Entraine: Retournes les donnees du graphe
		***************************************************************************************************************************
		*/
		TData GROLireData() const;

		/**************************************************************************************************************************
		* METHODE : GROModifierData
		* *************************************************************************************************************************
		* Entree: tNvData, les nouvelles donnees du graphe
		* Necessite : Rien
		* Sortie: Rien
		* Entraine: Modifie les donnees du graphe par tNvData
		***************************************************************************************************************************
		*/
		void GROModiferData(TData tNvData);

		/**************************************************************************************************************************
		* METHODE : GROAjouterArc
		* *************************************************************************************************************************
		* Entree: ptArc, un pointeur vers un arc
		* Necessite : Rien
		* Sortie: Rien
		* Entraine: Ajoute l'arc au graphe oriente
		***************************************************************************************************************************
		*/
		virtual void GROAjouterArc(TArc<TData>* ptArc);

		/**************************************************************************************************************************
		* METHODE : GROSupprimerArc
		* *************************************************************************************************************************
		* Entree: ptArc, un pointeur vers un arc
		* Necessite : Rien
		* Sortie: Rien
		* Entraine: Supprimes l'arc du graphe oriente
		***************************************************************************************************************************
		*/
		virtual void GROSupprimerArc(TArc<TData>* ptArc);

		/**************************************************************************************************************************
		* METHODE : GROLireArc
		* *************************************************************************************************************************
		* Entree: uiPos, la position de l'arc a lire
		* Necessite : Rien
		* Sortie: Un pointeur vers l'arc a la position uiPos
		* Entraine: Renvoie l'arc a la position uiPos
		***************************************************************************************************************************
		*/
		virtual TArc<TData>* GROLireArc(unsigned int uiPos);

		/***************************************************************************************************************************
		* METHODE : GROAjouterSommet()
		* **************************************************************************************************************************
		* Entree: ptSommet,un pointeur vers le sommet a ajouter
		* Necessite : Rien
		* Sortie: Rien
		* Entraine: Ajoute le sommet au graphe oriente
		****************************************************************************************************************************
		*/
		void GROAjouterSommet(TSommet<TData>* ptSommet);

		/***************************************************************************************************************************
		* METHODE : GROSupprimerSommet()
		* **************************************************************************************************************************
		* Entree: ptSommet,un pointeur vers un sommet
		* Necessite : Rien
		* Sortie: Rien
		* Entraine: Supprimes le sommet du graphe oriente
		****************************************************************************************************************************
		*/
		void GROSupprimerSommet(TSommet<TData>* ptSommet);

		/**************************************************************************************************************************
		* METHODE : GROLireArc
		* *************************************************************************************************************************
		* Entree: uiPos, la position de l'arc a lire
		* Necessite : uiPos doit etre valide
		* Sortie: Un pointeur vers l'arc a la position uiPos
		* Entraine: Renvoie l'arc a la position uiPos
		***************************************************************************************************************************
		*/
		TSommet<TData>* GROLireSommet(unsigned int uiPos);

		/***************************************************************************************************************************
		* METHODE : GROSOMEstDansGraphe
		* **************************************************************************************************************************
		* Entree : ptSommet ,un pointeur un sommet
		* Necessite : Rien
		* Sortie : Booleen
		* Entraine : Verifie si le sommet appartient au graphe oriente
		* **************************************************************************************************************************
		*/
		bool GROSOMEstDansGraphe(TSommet<TData>* ptSommet);

		/***************************************************************************************************************************
		* METHODE : GROSOMEstDansGraphe
		* **************************************************************************************************************************
		* Entree : uiIdSommet, l'id du sommet
		* Necessite : Rien
		* Sortie : Booleen
		* Entraine : Verifie si le sommet appartient au graphe oriente
		* **************************************************************************************************************************
		*/
		bool GROSOMEstDansGraphe(unsigned int uiIdSommet);

		/***************************************************************************************************************************
		* METHODE : GROARCEstDansGraphe
		* **************************************************************************************************************************
		* Entree : ptArc, un pointeur vers un arc
		* Necessite : Rien
		* Sortie : Booleen
		* Entraine : Verifie si l'arc appartient au graphe
		* **************************************************************************************************************************
		*/
		bool GROARCEstDansGraphe(TArc<TData>* ptArc);

		/***************************************************************************************************************************
		* METHODE : GROInverser
		* **************************************************************************************************************************
		* Entree : Rien
		* Necessite : Rien
		* Sortie : Un pointeur vers une copie du graphe oriente mais qui est inverse
		* Entraine : Inverse le graphe oriente, c'est à dire inverse tous ses arcs et ses sommets
		* ***************************************************************************************************************************
		*/
		TGraphOrient<TData>* GROInverser();

		/***************************************************************************************************************************
		* METHODE : GROAfficher
		* **************************************************************************************************************************
		* Entree : Rien
		* Necessite : Rien
		* Sortie : Rien
		* Entraine : Affiches le graphe oriente dans la console
		* ***************************************************************************************************************************
		*/
		virtual void GROAfficher();

		/***************************************************************************************************************************
		* METHODE : GROFinaliser
		* **************************************************************************************************************************
		* Entree : Rien
		* Necessite : Rien
		* Sortie : Rien
		* Entraine : Affiches le graphe oriente dans la console
		* ***************************************************************************************************************************
		*/
		void GROFinaliser();

		/***************************************************************************************************************************
		* METHODE : GROTailleLstArc
		* **************************************************************************************************************************
		* Entree : Rien
		* Necessite : Rien
		* Sortie : Naturel
		* Entraine : Retournes la taille de la liste d'arcs
		* ***************************************************************************************************************************
		*/
		unsigned int GROTailleLstArc() const { return vGROLstArc.size(); }

		/***************************************************************************************************************************
		* METHODE : GROTailleLstSommet
		* **************************************************************************************************************************
		* Entree : Rien
		* Necessite : Rien
		* Sortie : Naturel
		* Entraine : Retournes la taille de la liste de sommets
		* ***************************************************************************************************************************
		*/
		unsigned int GROTailleLstSommet() const { return vGROLstSommet.size(); }
};
#include "TGraphOrient.tpp"

#endif