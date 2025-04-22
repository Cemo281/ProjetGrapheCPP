#pragma once
#ifndef INCLUDE_SOMMET_H
#define INCLUDE_SOMMET_H 3

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
#include "CSommet.hpp"
#include "CArc.hpp"
#include <vector>
#include <exception>

using namespace std;


/* TYPES:
* Pas de type particulier de d�clar�
*/

/* Variables :
* Pas de variable globale de d�clar�e
*/
template<class T> class PGrapheOrient
{
	//Attributs:
	private:
		vector<T*> vGROLstArc //liste des Arcs
		vector<T*> vGROLstSommet //liste des Sommets
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
		PGrapheOrient() { vGROLstArc = nullptr; vGROLstArc = nullptr; }

		/**************************************************************************************************************************
		* PGrapheOrient
		* *************************************************************************************************************************
		* Entr�e: Le graphe orient� � copier
		* Nec�ssite : Rien
		* Sortie: Rien
		* Entraine: Cr�er un graphe orient� � partir d'un autre graphe orient�
		***************************************************************************************************************************
		*/
		PGrapheOrient* PGrapheOrient(const PGrapheOrient& GROParam) {
			PGrapheOrient GROCopie = new ;
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
		void GROAjouterArc(CArc* pArc);

		/***************************************************************************************************************************
		* GROAjouterSommet()
		* **************************************************************************************************************************
		* Entr�e:Un pointeur vers un sommet (CSommet*)
		* Nec�ssite : Un sommet valide
		* Sortie: Rien
		* Entraine:Ajoute un sommet au graphe
		****************************************************************************************************************************
		*/
		void GROAjouterSommet(CSommet* pSom) { vGROLstSommet.push_back(pSom); }

		/***************************************************************************************************************************
		* SOMEstDansGraphe
		* **************************************************************************************************************************
		* Entr�e : Un pointeur vers un sommet
		* N�cessite : Rien
		* Sortie : Bool�en
		* Entraine : V�rifie si un sommet est dans le graphe
		* **************************************************************************************************************************
		*/
		bool GROSOMEstDansGraphe(CSommet* pSommet);

		/***************************************************************************************************************************
		* ARCestDansGraphe
		* **************************************************************************************************************************
		* Entr�e : Un pointeur vers un arc
		* N�cessite : Rien
		* Sortie : Bool�en
		* Entraine : V�rifie si un sommet est dans le graphe
		* **************************************************************************************************************************
		*/
		bool GROARCEstDansGraphe(CArc* pArc) {
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
#include"PGrapheOrient.th"

#endif