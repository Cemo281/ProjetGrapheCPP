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
#include "PSommet.hpp"
#include "PArc.hpp"
#include <set>
#include <vector>
#include <exception>

using namespace std;

/* TYPES:
* Pas de type particulier de declare
*/

/* Variables :
* Pas de variable globale de declaree
*/

template<typename TData> class PGraphOrient
{
	//Attributs:
	private:
		vector<PArc<TData>*> vGROLstArc; 	   //liste des Arcs
		vector<PSommet<TData>*> vGROLstSommet; //liste des Sommets
		TData tGROData;  					   //donnees du graphe
	//Constructeurs et destructeurs:
	public:
		/**************************************************************************************************************************
		* PGraphOrient
		* *************************************************************************************************************************
		* Entree: Rien
		* Necessite : Rien
		* Sortie: Rien
		* Entraine: Initialise un graphe oriente vide
		***************************************************************************************************************************
		*/
		PGraphOrient() = default;

		/**************************************************************************************************************************
		* PGraphOrient
		* *************************************************************************************************************************
		* Entree: Le graphe oriente a copier
		* Necessite : Rien
		* Sortie: Rien
		* Entraine: Initialise un graphe oriente a partir d'un autre graphe oriente
		***************************************************************************************************************************
		*/
		PGraphOrient(const PGraphOrient<TData>& GROParam);

		/**************************************************************************************************************************
		* PGraphOrient
		* *************************************************************************************************************************
		* Entree: Rien
		* Necessite : Rien
		* Sortie: Rien
		* Entraine: Detruit un graphe orisnte
		***************************************************************************************************************************
		*/
		virtual ~PGraphOrient() = default;

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
		virtual void GROAjouterArc(PArc<TData>* ptArc);

		/**************************************************************************************************************************
		* METHODE : GROSupprimerArc
		* *************************************************************************************************************************
		* Entree: ptArc, un pointeur vers un arc
		* Necessite : Rien
		* Sortie: Rien
		* Entraine: Supprimes l'arc du GROphe oriente
		***************************************************************************************************************************
		*/
		virtual void GROSupprimerArc(PArc<TData>* ptArc);

		/**************************************************************************************************************************
		* METHODE : GROLireArc
		* *************************************************************************************************************************
		* Entree: uiPos, la position de l'arc a lire
		* Necessite : Rien
		* Sortie: Un pointeur vers l'arc a la position uiPos
		* Entraine: Renvoie l'arc a la position uiPos
		***************************************************************************************************************************
		*/
		virtual PArc<TData>* GROLireArc(unsigned int uiPos);

		/***************************************************************************************************************************
		* METHODE : GROAjouterSommet()
		* **************************************************************************************************************************
		* Entree: ptSommet,un pointeur vers le sommet a ajouter
		* Necessite : Rien
		* Sortie: Rien
		* Entraine: Ajoute le sommet au graphe oriente
		****************************************************************************************************************************
		*/
		void GROAjouterSommet(PSommet<TData>* ptSommet);

		/***************************************************************************************************************************
		* METHODE : GROSupprimerSommet()
		* **************************************************************************************************************************
		* Entree: ptSommet,un pointeur vers un sommet
		* Necessite : Rien
		* Sortie: Rien
		* Entraine: Supprimes le sommet du graphe oriente
		****************************************************************************************************************************
		*/
		void GROSupprimerSommet(PSommet<TData>* ptSommet);

		/**************************************************************************************************************************
		* METHODE : GROLireArc
		* *************************************************************************************************************************
		* Entree: uiPos, la position de l'arc a lire
		* Necessite : uiPos doit etre valide
		* Sortie: Un pointeur vers l'arc a la position uiPos
		* Entraine: Renvoie l'arc a la position uiPos
		***************************************************************************************************************************
		*/
		PSommet<TData>* GROLireSommet(unsigned int uiPos);

		/***************************************************************************************************************************
		* METHODE : GROSOMEstDansGraphe
		* **************************************************************************************************************************
		* Entree : ptSommet ,un pointeur un sommet
		* Necessite : Rien
		* Sortie : Booleen
		* Entraine : Verifie si le sommet appartient au graphe oriente
		* **************************************************************************************************************************
		*/
		bool GROSOMEstDansGraphe(PSommet<TData>* ptSommet) const;

		/***************************************************************************************************************************
		* METHODE : GROSOMEstDansGraphe
		* **************************************************************************************************************************
		* Entree : uiIdSommet, l'id du sommet
		* Necessite : Rien
		* Sortie : Booleen
		* Entraine : Verifie si le sommet appartient au graphe oriente
		* **************************************************************************************************************************
		*/
		bool GROSOMEstDansGraphe(unsigned int uiIdSommet) const;

		/***************************************************************************************************************************
		* METHODE : GROARCEstDansGraphe
		* **************************************************************************************************************************
		* Entree : pPArc, un pointeur vers un arc
		* Necessite : Rien
		* Sortie : Booleen
		* Entraine : Verifie si l'arc appartient au graphe
		* **************************************************************************************************************************
		*/
		bool GROARCEstDansGraphe(PArc<TData>* ptArc);

		/***************************************************************************************************************************
		* METHODE : GROInverser
		* **************************************************************************************************************************
		* Entree : Rien
		* Necessite : Rien
		* Sortie : Un pointeur vers une copie du graphe oriente mais qui est inverse
		* Entraine : Inverse le graphe oriente, c'est à dire inverse tous ses arcs et ses sommets
		* ***************************************************************************************************************************
		*/
		PGraphOrient<TData>* GROInverser();

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
		unsigned int GROTailleLstArc() const;

		/***************************************************************************************************************************
		* METHODE : GROTailleLstSommet
		* **************************************************************************************************************************
		* Entree : Rien
		* Necessite : Rien
		* Sortie : Naturel
		* Entraine : Retournes la taille de la liste de sommets
		* **************************************************************************************************************************
		*/
		unsigned int GROTailleLstSommet() const;

		/***************************************************************************************************************************
		* METHODE : GROCycleHamiltonien
		* **************************************************************************************************************************
		* Entree : ptSOMSource, un pointeur vers le sommet de départ du cycle.
		* Necessite : - Les arcs doivent être pondéré.
		*             - Le graph ne doit pas possèder de sommets, d'arcs ou d'ensembles d'arcs isolé. Il doit être unifié.
		*                   Un graph non unifié = pas de cycle hamiltonien
		* Sortie : Un vector contenant les sommets formant le cycle hamiltonien.
		* Entraine : Affiches sur la console un cycle hamiltonien du graphe oriente.
		* ***************************************************************************************************************************
		*/
		vector<PSommet<TData>*> GROCycleHamiltonien(PSommet<TData>* ptSOMSource);

		/**************************************************************************************************************************
		* METHODE : Dijkstra
		* *************************************************************************************************************************
		* Entree : ptSommetDepart, un pointeur vers le sommet de depart
		* Necessite : Les arcs doivent être pondéré.
		* Sortie : Un pointeur vers le sommet le plus eloigne du sommet de depart
		* Entraine : Retournes le sommet le plus eloigne du sommet de depart
		* **************************************************************************************************************************
		*/
		PSommet<TData>* Dijkstra(PSommet<TData>* ptSommetDepart) const;

		/**************************************************************************************************************************
		* OPERATEUR : operator=
		* *************************************************************************************************************************
		* Entree: GROParam, le graphe oriente à copier
		* Necessite : Rien
		* Sortie: Référence sur *this
		* Entraine: Affecte le contenu d'un graphe oriente à un autre
		***************************************************************************************************************************
		*/
		PGraphOrient<TData>& operator=(const PGraphOrient<TData>& GROParam);
};
#include "PGraphOrient.tpp"

#endif