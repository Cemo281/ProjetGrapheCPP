#pragma once
#ifndef INCLUDE_SOMMET_H
#define INCLUDE_SOMMET_H 3

/****************************************************
* Patron de Classe :PGrapheOrient
* **************************************************
* ROLE : Cette classe permet de gérer et modifier un graphe orienté
* **************************************************
* VERSION : 1.0
* AUTEUR : ELAOULA KHAOULA
* DATE : 18/03/2025
* *************************************************
* INCLUSIONS EXTERNES :
*/
#include "CSommet.h"
#include "CArc.h"
#include <vector>
#include <exception>

using namespace std;


/* TYPES:
* Pas de type particulier de déclaré
*/

/* Variables :
* Pas de variable globale de déclarée
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
		* Entrée: Rien
		* Necéssite : Rien
		* Sortie: Rien
		* Entraine: Créer un graphe orienté
		***************************************************************************************************************************
		*/
		PGrapheOrient() { vGROLstArc = nullptr; vGROLstArc = nullptr; }

		/**************************************************************************************************************************
		* PGrapheOrient
		* *************************************************************************************************************************
		* Entrée: Le graphe orienté à copier
		* Necéssite : Rien
		* Sortie: Rien
		* Entraine: Créer un graphe orienté à partir d'un autre graphe orienté
		***************************************************************************************************************************
		*/
		PGrapheOrient(const PGrapheOrient& GROParam);

		/**************************************************************************************************************************
		* PGrapheOrient
		* *************************************************************************************************************************
		* Entrée: Fichier, le fichier contenant le graphe orienté
		* Necéssite : Le fichier doit être valide et bien formé (.txt)
		* Sortie: Rien
		* Entraine: Créer un graphe orienté à partir d'un fichier .txt
		***************************************************************************************************************************
		*/
		PGrapheOrient(ifstream& Fichier);

		/**************************************************************************************************************************
		* PGrapheOrient
		* *************************************************************************************************************************
		* Entrée: Rien
		* Necéssite : Rien
		* Sortie: Rien
		* Entraine: Détruit un graphe orienté
		***************************************************************************************************************************
		*/
		~PGrapheOrient();

	//Méthodes:
		/**************************************************************************************************************************
		* GROAjouterArc()
		* *************************************************************************************************************************
		* Entrée: Rien
		* Necéssite : Rien
		* Sortie: Rien
		* Entraine:Ajoute un arc au graphe
		***************************************************************************************************************************
		*/
		void GROAjouterArc(CArc* pArc);

		/***************************************************************************************************************************
		* GROAjouterSommet()
		* **************************************************************************************************************************
		* Entrée:Un pointeur vers un sommet (CSommet*)
		* Necéssite : Un sommet valide
		* Sortie: Rien
		* Entraine:Ajoute un sommet au graphe
		****************************************************************************************************************************
		*/
		void GROAjouterSommet(CSommet* pSom) { vGROLstSommet.push_back(pSom); }

		/***************************************************************************************************************************
		* SOMEstDansGraphe
		* **************************************************************************************************************************
		* Entrée : Un pointeur vers un sommet
		* Nécessite : Rien
		* Sortie : Booléen
		* Entraine : Vérifie si un sommet est dans le graphe
		* **************************************************************************************************************************
		*/
		bool SOMEstDansGraphe(CSommet* pSommet);

		/***************************************************************************************************************************
		* ARCestDansGraphe
		* **************************************************************************************************************************
		* Entrée : Un pointeur vers un arc
		* Nécessite : Rien
		* Sortie : Booléen
		* Entraine : Vérifie si un sommet est dans le graphe
		* **************************************************************************************************************************
		*/
		bool ARCEstDansGraphe(CArc* pArc);
};
#include"PGrapheOrient.th"

#endif