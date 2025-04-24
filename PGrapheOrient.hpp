#ifndef INCLUDE_GRAPHO_H
#define INCLUDE_GRAPHO_H 3

/****************************************************
* Patron de Classe :PGrapheOrient
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
template<typename TData> class PGrapheOrient
{
	//Attributs:
	private:
		vector<TArc<TData>> vGROLstArc; //liste des Arcs
		vector<TSommet<TData>> vGROLstSommet; //liste des Sommets
	//Constructeurs et destructeurs:
	public:
		/**************************************************************************************************************************
		* PGrapheOrient
		* *************************************************************************************************************************
		* Entree: Rien
		* Necessite : Rien
		* Sortie: Rien
		* Entraine: Creer un graphe oriente
		***************************************************************************************************************************
		*/
		PGrapheOrient() { vGROLstArc = nullptr; vGROLstSommet = nullptr; }

		/**************************************************************************************************************************
		* PGrapheOrient
		* *************************************************************************************************************************
		* Entree: Le graphe oriente a copier
		* Necessite : Rien
		* Sortie: Rien
		* Entraine: Creer un graphe oriente a partir d'un autre graphe oriente
		***************************************************************************************************************************
		*/
		PGrapheOrient(const PGrapheOrient& GROParam) {
			vGROLstArc = new vector<TArc<TData>>();
			vGROLstSommet = new vector<TSommet<TData>>();
			for (int iBoucle = 0; iBoucle < GROParam.vGROLstArc->size(); iBoucle++) {
				vGROLstArc->push_back(GROParam.vGROLstArc->at(iBoucle));
			}
			for (int iBoucle = 0; iBoucle < GROParam.vGROLstSommet->size(); iBoucle++) {
				vGROLstSommet->push_back(GROParam.vGROLstSommet->at(iBoucle));
			}
		}

		/**************************************************************************************************************************
		* PGrapheOrient
		* *************************************************************************************************************************
		* Entree: Fichier, le fichier contenant le graphe oriente
		* Necessite : Le fichier doit etre valide et bien forme (.txt)
		* Sortie: Rien
		* Entraine: Creer un graphe oriente a partir d'un fichier .txt
		***************************************************************************************************************************
		*/
		// PGrapheOrient(ifstream& Fichier);

		/**************************************************************************************************************************
		* PGrapheOrient
		* *************************************************************************************************************************
		* Entree: Rien
		* Necessite : Rien
		* Sortie: Rien
		* Entraine: Detruit un graphe oriente
		***************************************************************************************************************************
		*/
		~PGrapheOrient();

	//Methodes:
		/**************************************************************************************************************************
		* GROAjouterArc()
		* *************************************************************************************************************************
		* Entree: Rien
		* Necessite : Rien
		* Sortie: Rien
		* Entraine:Ajoute un arc au graphe
		***************************************************************************************************************************
		*/
		void GROAjouterArc(TArc<TData>& tArc);

		/***************************************************************************************************************************
		* GROAjouterSommet()
		* **************************************************************************************************************************
		* Entree:Un pointeur vers un sommet (CSommet*)
		* Necessite : Un sommet valide
		* Sortie: Rien
		* Entraine:Ajoute un sommet au graphe
		****************************************************************************************************************************
		*/
		void GROAjouterSommet(TSommet<TData>& pSom) { vGROLstSommet.push_back(pSom); }

		/***************************************************************************************************************************
		* SOMEstDansGraphe
		* **************************************************************************************************************************
		* Entree : Un pointeur vers un sommet
		* Necessite : Rien
		* Sortie : Booleen
		* Entraine : Verifie si un sommet est dans le graphe
		* **************************************************************************************************************************
		*/
		bool GROSOMEstDansGraphe(TSommet<TData>& pSommet);

		/***************************************************************************************************************************
		* ARCestDansGraphe
		* **************************************************************************************************************************
		* Entree : Un pointeur vers un arc
		* Necessite : Rien
		* Sortie : Booleen
		* Entraine : Verifie si un sommet est dans le graphe
		* **************************************************************************************************************************
		*/
		bool GROARCEstDansGraphe(TArc<TData>& pArc) {
			int iBoucle;

			for (iBoucle = 0; iBoucle < vGROLstArc; iBoucle++) {
				if (vGROLstArc[iBoucle] == pArc) {
					return true;
				}
			}
			return false;
		}

		/***************************************************************************************************************************
		* METHODE : GROInverserGraphe
		* **************************************************************************************************************************
		* Entree : rien
		* Necessite : rien
		* Sortie : Le graphe oriente inverse
		* Entraine : Inverse les arcs du graphe
		* **************************************************************************************************************************
		*/
		PGrapheOrient* GROInverserGraphe();
};
#include"PGrapheOrient.tpp"

#endif