#pragma once
//
// Created by Ali-Cem on 17/03/2025
//

#ifndef INCLUDE_ARC_H
#define INCLUDE_ARC_H 2

/****************************************************
* Classe : PArc
* **************************************************
* ROLE : Cette classe permet gerer et modifier un arc
* **************************************************
* VERSION : 1.0
* AUTEUR : OZDEMIR Ali-Cem
* DATE : 03/03/2025
* *************************************************
* INCLUSIONS EXTERNES :
*/

/* TYPES:
* Pas de type particulier de declare
*/

/* Variables :
* Pas de variable globale de declaree
*/

template<typename TData> class PArc
{
    // ATTRIBUTS
private:
    unsigned int uiARCIdDepart;     // Id du sommets de depart
    unsigned int uiARCIdArrive;     // Id du sommets d'arrive
	TData ARCData;                  // Donnee de l'arc
    
    // CONSTRUCTEURS ET DESTRUCTEURS
public:
    /*************************************************
    * PArc
    * ************************************************
    * Entree : Rien
    * Necessite : Rien
    * Sortie : Rien
    * Entraine : Cree un arc
    *************************************************
    */
    PArc() = default;

    /*************************************************
    * PArc
    * ***********************************************
    * Entree : uiIdDepart, naturel, sommet de depart
    *          uiIdArrive, naturel, sommet d'arrive
    * Necessite : Rien
    * Sortie : Rien
    * Entraine : Creer un arc a partir de l'id de
    *            deux sommets
    *************************************************
    */
    PArc(unsigned int uiIdDepart, unsigned int uiIdArrive);

    /*************************************************
    * PArc
    * ***********************************************
    * Entree : uiIdDepart, naturel, sommet de depart
    *          uiIdArrive, naturel, sommet d'arrive
    *          tData, TData, la donnee de l'arc
    * Necessite : Rien
    * Sortie : Rien
    * Entraine : Creer un arc a partir de l'id de
    *            deux sommets et d'une donnee
    *************************************************
    */
    PArc(unsigned int uiIdDepart, unsigned int uiIdArrive, TData tData);

	/**************************************************
    * ~TArc
	* ************************************************
	* Entree : Rien
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : Detruis un arc
    * ************************************************
    */
    ~PArc() = default;

    // METHODES
    /*************************************************
    * METHODE : ARCLireIdDepart
    * ***********************************************
    * Entree : Rien
    * Necessite : Rien
    * Sortie : uiARCIdDepart, naturel
    * Entraine : Retournes l'id du sommet de Depart
    *************************************************
    */
    unsigned int ARCLireIdDepart() const;

    /*************************************************
    * METHODE : ARCLireIdArrive
    * ***********************************************
    * Entree : Rien
    * Necessite : Rien
    * Sortie : uiARCIdArrive, naturel
    * Entraine : Retournes l'id du sommet d'Arrivee
    *************************************************
    */
    unsigned int ARCLireIdArrive() const;

    /*************************************************
    * METHODE : ARCLireData
    * ***********************************************
    * Entree : Rien
    * Necessite : Rien
    * Sortie : ARCData, TData
    * Entraine : Retournes la donnee de l'arc
    *************************************************
    */
	TData ARCLireData() const;

    /*************************************************
    * METHODE : ARCModifierIdArrive
    * ***********************************************
    * Entree : uiNvIdArrive, naturel, l'id du nouvel
    *            arc d'arrive
    * Necessite : Rien
    * Sortie : Rien
    * Entraine : Modifie le sommet d'arrive
    *************************************************
    */
    void ARCModifierIdArrive(unsigned int uiNvIdArrive);

    /*************************************************
    * METHODE : ARCModifierIdDepart
    * ***********************************************
    * Entree : uiNvIdDepart, naturel, l'id du nouvel
    *            arc de depart
    * Necessite : Rien
    * Sortie : Rien
    * Entraine : Modifie le sommet de depart
    *************************************************
    */
    void ARCModifierIdDepart(unsigned int uiNvIdDepart);

    /*************************************************
	* METHODE : ARCModifierData
    * ***********************************************
	* Entree : tNvData, TData, la nouvelle donnee
    * Necessite : Rien
    * Sortie : Rien
	* Entraine : Modifie la donnee de l'arc
    *************************************************
    */
	void ARCModifierData(TData tNvData);

	/*************************************************
	* METHODE : operator==
    * ************************************************
	* Entree : ptArc, un pointeur vers l'arc
	* Necessite : Rien
	* Sortie : Booleen
	* Entraine : Compare si deux arcs sont egaux
	*               True si ils sont egaux, 
    *               False sinon
	* ***********************************************
    */
	bool operator==(const PArc* ptArc) const;

    /*************************************************
    * METHODE : ARCInverser
    * ************************************************
    * Entree : Rien
    * Necessite : Rien
    * Sortie : Rien
	* Entraine : Inverse l'arc
    * ***********************************************
    */
	void ARCInverser();

    /*************************************************
	* METHODE : ARCAfficher
    * ************************************************
    * Entree : Rien
    * Necessite : Rien
    * Sortie : Rien
	* Entraine : Affiches l'arc dans la console, son sommet de depart,
	*               son sommet d'arrivee ainsi que sa donnee
    * ***********************************************
    */
    void ARCAfficher();
};
#include "PArc.tpp"

#endif