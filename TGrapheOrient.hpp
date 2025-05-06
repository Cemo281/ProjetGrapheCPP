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
		* Entraine: Initialise un graphe orient� vide
		
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
		TGrapheOrient(ifstream &Fichier);

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
		* METHODE : GROLireData
		* *************************************************************************************************************************
		* Entree: Rien
		* Necessite : Rien
		* Sortie: tData, les donnees du graphe
		* Entraine: Retournes les donnees du graphe
		***************************************************************************************************************************
		*/
		TData GROLireData();

		/**************************************************************************************************************************
		* METHODE : GROModifierData
		* *************************************************************************************************************************
		* Entree: tNvData, les nouvelles donnees du graphe
		* Necessite : Les données doivent être du même type que le graphe
		* Sortie: tData, les donnees du graphe
		* Entraine: Retournes les donnees du graphe
		***************************************************************************************************************************
		*/
		void GROModiferData(TData tNvData);

		/**************************************************************************************************************************
		* METHODE : GROAjouterArc()
		* *************************************************************************************************************************
		* Entree: ptArc, un pointeur vers l'arc a ajouter
		* Necessite : Rien
		* Sortie: Rien
		* Entraine: Ajoute l'arc au graphe orient�
		***************************************************************************************************************************
		*/
		void GROAjouterArc(TArc<TData>* ptArc);

		/**************************************************************************************************************************
		* METHODE : GROLireArc
		* *************************************************************************************************************************
		* Entree: iPos, la position de l'arc a lire
		* Necessite : iPos doit etre valide
		* Sortie: Un pointeur vers l'arc a la position iPosS
		* Entraine: Renvoie l'arc a la position iPos
		***************************************************************************************************************************
		*/
		TArc<TData>* GROLireArc(unsigned int iPos) const;

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
		* Entree: ptSommet,un pointeur vers le sommet a supprimer
		* Necessite : Rien
		* Sortie: Rien
		* Entraine: Supprime le sommet du graphe oriente
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
		TSommet<TData>* GROLireSommet(unsigned int uiPos) const;

		/***************************************************************************************************************************
		* METHODE : GROSOMEstDansGraphe
		* **************************************************************************************************************************
		* Entree : ptSommet ,un pointeur vers le sommet a ajouter
		* Necessite : Rien
		* Sortie : Booleen
		* Entraine : Verifie si le sommet appartient au graphe orient�
		* **************************************************************************************************************************
		*/
		bool GROSOMEstDansGraphe(TSommet<TData>* ptSommet);

		/***************************************************************************************************************************
		* METHODE : GROARCEstDansGraphe
		* **************************************************************************************************************************
		* Entree : ptArc pinteur vers l'arc � ajouter 
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
		* Sortie : Rien
		* Entraine : Inverse le graphe oriente, c'est à dire inverse tous ses arcs et ses sommets
		* ***************************************************************************************************************************
		*/
		TGrapheOrient<TData>* GROInverser();

		/***************************************************************************************************************************
		* METHODE : GROAfficher
		* **************************************************************************************************************************
		* Entree : Rien
		* Necessite : Rien
		* Sortie : Rien
		* Entraine : Affiches le graphe oriente dans la console
		* ***************************************************************************************************************************
		*/
		void GROAfficher();

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
		* Sortie : Rien
		* Entraine : Retourne la taille de la liste d'arcs
		* ***************************************************************************************************************************
		*/
		unsigned int GROTailleLstArc() const { return vGROLstArc.size(); }

		/***************************************************************************************************************************
		* METHODE : GROTailleLstSommet
		* **************************************************************************************************************************
		* Entree : Rien
		* Necessite : Rien
		* Sortie : Rien
		* Entraine : Retourne la taille de la liste de sommet
		* ***************************************************************************************************************************
		*/
		unsigned int GROTailleLstSommet() const { return vGROLstSommet.size(); }
};
#include "TGrapheOrient.tpp"

#endif