#pragma once
//
// Created by Ali-Cem on 17/03/2025
//

#ifndef INCLUDE_ARC_H
#define INCLUDE_ARC_H 2

/****************************************************
* Classe : TArc
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

template<typename TData> class TArc
{
    // ATTRIBUTS
private:
    unsigned int uiARCIdDepart;
    unsigned int uiARCIdArrive;
	TData ARCData; // Donnees de l'arc
    
    // CONSTRUCTEURS ET DESTRUCTEURS
public:
    /*************************************************
    * TArc
    * ***********************************************
    * Entree : Rien
    * Necessite : Rien
    * Sortie : Rien
    * Entraine : Cree un arc
    *************************************************
    */
    TArc() = default;

    /*************************************************
    * TArc
    * ***********************************************
    * Entree : uiIdDepart, naturel, sommet de depart
    *          uiIdArrive, naturel, sommet d'arrive
    * Necessite : Rien
    * Sortie : Rien
    * Entraine : Creer un arc a partir de l'id de
    *            deux sommets
    *************************************************
    */
    TArc(unsigned int uiIdDepart, unsigned int uiIdArrive, TData Data);

	/**************************************************
    * ~TArc
	* ************************************************
	* Entree : Rien
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : Detruis un arc
    * ************************************************
    */
    ~TArc() = default;

    // METHODES
    /*************************************************
    * METHODE : ARCLireIdDepart
    * ***********************************************
    * Entree : Rien
    * Necessite : Rien
    * Sortie : uiARCIdDepart, naturel
    * Entraine : Retournes l'id de l'arc de Depart
    *************************************************
    */
    unsigned int ARCLireIdDepart();

    /*************************************************
    * METHODE : ARCLireIdArrive
    * ***********************************************
    * Entree : Rien
    * Necessite : Rien
    * Sortie : uiARCIdArrive, naturel
    * Entraine : Retournes l'id de l'arc de Depart
    *************************************************
    */
    unsigned int ARCLireIdArrive();

    /*************************************************
    * METHODE : ARCLireData
    * ***********************************************
    * Entree : Rien
    * Necessite : Rien
    * Sortie : ARCData, TData
    * Entraine : Retournes la donnee de l'arc
    *************************************************
    */
	TData ARCLireData();

    /*************************************************
    * METHODE : ARCModifierIdArrive
    * ***********************************************
    * Entree : uiNvIdArrive, naturel, l'id du nouvel
                arc d'arrive
    * Necessite : Rien
    * Sortie : Rien
    * Entraine : Modifie l'arc d'arrive
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
    * Entraine : Modifie l'arc de depart
    *************************************************
    */
    void ARCModifierIdDepart(unsigned int uiNvIdDepart);

    /*************************************************
	* METHODE : ARCModifierData
    * ***********************************************
	* Entree : newData, TData, la nouvelle donnee
    * Necessite : Rien
    * Sortie : Rien
	* Entraine : Modifie la donnee de l'arc
    *************************************************
    */
	void ARCModifierData(TData &nvData);

	/*************************************************
	* METHODE : operator==
    * ************************************************
	* Entree : un arc
	* Necessite : Rien
	* Sortie : Booleen
	* Entraine : Compare si deux arcs sont egaux
	*               True si ils sont egaux, 
    *               False sinon
	* ***********************************************
    */
	bool operator==(const TArc* ptArc) const;
};
#include "TArc.tpp"

#endif

