#ifndef INCLUDE_GRAPHO_H
#define INCLUDE_GRAPHO_H 3

/****************************************************
* Patron de Classe :PGrapheOrient
* **************************************************
* ROLE : Cette classe permet de g�rer et modifier un graphe orient�
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
* Pas de type particulier de d�clar�
*/

/* Variables :
* Pas de variable globale de d�clar�e
*/
template<class TData> class PGrapheOrient
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
		* Entr�e: Rien
		* Nec�ssite : Rien
		* Sortie: Rien
		* Entraine: Cr�er un graphe orient�
		***************************************************************************************************************************
		*/
		PGrapheOrient() { vGROLstArc = nullptr; vGROLstSommet = nullptr; }

		/**************************************************************************************************************************
		* PGrapheOrient
		* *************************************************************************************************************************
		* Entr�e: Le graphe orient� � copier
		* Nec�ssite : Rien
		* Sortie: Rien
		* Entraine: Cr�er un graphe orient� � partir d'un autre graphe orient�
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
		* Entr�e: Fichier, le fichier contenant le graphe orient�
		* Nec�ssite : Le fichier doit �tre valide et bien form� (.txt)
		* Sortie: Rien
		* Entraine: Cr�er un graphe orient� � partir d'un fichier .txt
		***************************************************************************************************************************
		*/
		PGrapheOrient(ifstream& Fichier);

		/**************************************************************************************************************************
		* PGrapheOrient
		* *************************************************************************************************************************
		* Entr�e: Rien
		* Nec�ssite : Rien
		* Sortie: Rien
		* Entraine: D�truit un graphe orient�
		***************************************************************************************************************************
		*/
		~PGrapheOrient();

	//M�thodes:
		/**************************************************************************************************************************
		* GROAjouterArc()
		* *************************************************************************************************************************
		* Entr�e: Rien
		* Nec�ssite : Rien
		* Sortie: Rien
		* Entraine:Ajoute un arc au graphe
		***************************************************************************************************************************
		*/
		void GROAjouterArc(TArc<TData>& tArc);

		/***************************************************************************************************************************
		* GROAjouterSommet()
		* **************************************************************************************************************************
		* Entr�e:Un pointeur vers un sommet (CSommet*)
		* Nec�ssite : Un sommet valide
		* Sortie: Rien
		* Entraine:Ajoute un sommet au graphe
		****************************************************************************************************************************
		*/
		void GROAjouterSommet(TSommet<TData>& pSom) { vGROLstSommet.push_back(pSom); }

		/***************************************************************************************************************************
		* SOMEstDansGraphe
		* **************************************************************************************************************************
		* Entr�e : Un pointeur vers un sommet
		* N�cessite : Rien
		* Sortie : Bool�en
		* Entraine : V�rifie si un sommet est dans le graphe
		* **************************************************************************************************************************
		*/
		bool GROSOMEstDansGraphe(TSommet<TData>& pSommet);

		/***************************************************************************************************************************
		* ARCestDansGraphe
		* **************************************************************************************************************************
		* Entr�e : Un pointeur vers un arc
		* N�cessite : Rien
		* Sortie : Bool�en
		* Entraine : V�rifie si un sommet est dans le graphe
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
		* Entr�e : rien
		* N�cessite : rien
		* Sortie : Le graphe orient� invers�
		* Entraine : Inverse les arcs du graphe
		* **************************************************************************************************************************
		*/
		PGrapheOrient* GROInverserGraphe();
};
#include"PGrapheOrient.tpp"

#endif