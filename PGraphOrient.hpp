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
		vector<PArc<TData>*> vGRALstArc; 	   //liste des Arcs
		vector<PSommet<TData>*> vGRALstSommet; //liste des Sommets
		TData tGRAData;  					   //donnees du graphe
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
		PGraphOrient(const PGraphOrient<TData>& GRAParam);

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
		* METHODE : GRALireData
		* *************************************************************************************************************************
		* Entree: Rien
		* Necessite : Rien
		* Sortie: tGRAData, TData
		* Entraine: Retournes les donnees du graphe
		***************************************************************************************************************************
		*/
		TData GRALireData() const;

		/**************************************************************************************************************************
		* METHODE : GRAModifierData
		* *************************************************************************************************************************
		* Entree: tNvData, les nouvelles donnees du graphe
		* Necessite : Rien
		* Sortie: Rien
		* Entraine: Modifie les donnees du graphe par tNvData
		***************************************************************************************************************************
		*/
		void GRAModiferData(TData tNvData);

		/**************************************************************************************************************************
		* METHODE : GRAAjouterArc
		* *************************************************************************************************************************
		* Entree: ptArc, un pointeur vers un arc
		* Necessite : Rien
		* Sortie: Rien
		* Entraine: Ajoute l'arc au graphe oriente
		***************************************************************************************************************************
		*/
		virtual void GRAAjouterArc(PArc<TData>* ptArc);

		/**************************************************************************************************************************
		* METHODE : GRASupprimerArc
		* *************************************************************************************************************************
		* Entree: ptArc, un pointeur vers un arc
		* Necessite : Rien
		* Sortie: Rien
		* Entraine: Supprimes l'arc du graphe oriente
		***************************************************************************************************************************
		*/
		virtual void GRASupprimerArc(PArc<TData>* ptArc);

		/**************************************************************************************************************************
		* METHODE : GRALireArc
		* *************************************************************************************************************************
		* Entree: uiPos, la position de l'arc a lire
		* Necessite : Rien
		* Sortie: Un pointeur vers l'arc a la position uiPos
		* Entraine: Renvoie l'arc a la position uiPos
		***************************************************************************************************************************
		*/
		virtual PArc<TData>* GRALireArc(unsigned int uiPos);

		/***************************************************************************************************************************
		* METHODE : GRAAjouterSommet()
		* **************************************************************************************************************************
		* Entree: ptSommet,un pointeur vers le sommet a ajouter
		* Necessite : Rien
		* Sortie: Rien
		* Entraine: Ajoute le sommet au graphe oriente
		****************************************************************************************************************************
		*/
		void GRAAjouterSommet(PSommet<TData>* ptSommet);

		/***************************************************************************************************************************
		* METHODE : GRASupprimerSommet()
		* **************************************************************************************************************************
		* Entree: ptSommet,un pointeur vers un sommet
		* Necessite : Rien
		* Sortie: Rien
		* Entraine: Supprimes le sommet du graphe oriente
		****************************************************************************************************************************
		*/
		void GRASupprimerSommet(PSommet<TData>* ptSommet);

		/**************************************************************************************************************************
		* METHODE : GRALireArc
		* *************************************************************************************************************************
		* Entree: uiPos, la position de l'arc a lire
		* Necessite : uiPos doit etre valide
		* Sortie: Un pointeur vers l'arc a la position uiPos
		* Entraine: Renvoie l'arc a la position uiPos
		***************************************************************************************************************************
		*/
		PSommet<TData>* GRALireSommet(unsigned int uiPos);

		/***************************************************************************************************************************
		* METHODE : GRASOMEstDansGraphe
		* **************************************************************************************************************************
		* Entree : ptSommet ,un pointeur un sommet
		* Necessite : Rien
		* Sortie : Booleen
		* Entraine : Verifie si le sommet appartient au graphe oriente
		* **************************************************************************************************************************
		*/
		bool GRASOMEstDansGraphe(PSommet<TData>* ptSommet);

		/***************************************************************************************************************************
		* METHODE : GRASOMEstDansGraphe
		* **************************************************************************************************************************
		* Entree : uiIdSommet, l'id du sommet
		* Necessite : Rien
		* Sortie : Booleen
		* Entraine : Verifie si le sommet appartient au graphe oriente
		* **************************************************************************************************************************
		*/
		bool GRASOMEstDansGraphe(unsigned int uiIdSommet);

		/***************************************************************************************************************************
		* METHODE : GRAARCEstDansGraphe
		* **************************************************************************************************************************
		* Entree : pPArc, un pointeur vers un arc
		* Necessite : Rien
		* Sortie : Booleen
		* Entraine : Verifie si l'arc appartient au graphe
		* **************************************************************************************************************************
		*/
		bool GRAARCEstDansGraphe(PArc<TData>* ptArc);

		/***************************************************************************************************************************
		* METHODE : GRAInverser
		* **************************************************************************************************************************
		* Entree : Rien
		* Necessite : Rien
		* Sortie : Un pointeur vers une copie du graphe oriente mais qui est inverse
		* Entraine : Inverse le graphe oriente, c'est à dire inverse tous ses arcs et ses sommets
		* ***************************************************************************************************************************
		*/
		PGraphOrient<TData>* GRAInverser();

		/***************************************************************************************************************************
		* METHODE : GRAAfficher
		* **************************************************************************************************************************
		* Entree : Rien
		* Necessite : Rien
		* Sortie : Rien
		* Entraine : Affiches le graphe oriente dans la console
		* ***************************************************************************************************************************
		*/
		virtual void GRAAfficher();

		/***************************************************************************************************************************
		* METHODE : GRAFinaliser
		* **************************************************************************************************************************
		* Entree : Rien
		* Necessite : Rien
		* Sortie : Rien
		* Entraine : Affiches le graphe oriente dans la console
		* ***************************************************************************************************************************
		*/
		void GRAFinaliser();

		/***************************************************************************************************************************
		* METHODE : GRATailleLstArc
		* **************************************************************************************************************************
		* Entree : Rien
		* Necessite : Rien
		* Sortie : Naturel
		* Entraine : Retournes la taille de la liste d'arcs
		* ***************************************************************************************************************************
		*/
		unsigned int GRATailleLstArc() const { return vGRALstArc.size(); }

		/***************************************************************************************************************************
		* METHODE : GRATailleLstSommet
		* **************************************************************************************************************************
		* Entree : Rien
		* Necessite : Rien
		* Sortie : Naturel
		* Entraine : Retournes la taille de la liste de sommets
		* ***************************************************************************************************************************
		*/
		unsigned int GRATailleLstSommet() const { return vGRALstSommet.size(); }

		/***************************************************************************************************************************
		* METHODE : GRACycleHamiltonien
		* **************************************************************************************************************************
		* Entree : Rien
		* Necessite : Rien
		* Sortie : Liste de sommets formant un cycle hamiltonien
		* Entraine : Retournes un cycle hamiltonien du graphe oriente
		* ***************************************************************************************************************************
		*/
		vector<PSommet<TData>*> GRACycleHamiltonien(PSommet<TData>* ptSOMSource) const;
};
#include "PGraphOrient.tpp"

#endif