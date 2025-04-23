#pragma once
//
// Created by Ali-Cem on 17/03/2025
//

#ifndef INCLUDE_ARC_H
#define INCLUDE_ARC_H 2

/****************************************************
* Classe : PArc
* **************************************************
* ROLE : Cette classe permet gérer et modifier un arc
* **************************************************
* VERSION : 1.0
* AUTEUR : OZDEMIR Ali-Cem
* DATE : 03/03/2025
* *************************************************
* INCLUSIONS EXTERNES :
*/

/* TYPES:
* Pas de type particulier de déclaré
*/

/* Variables :
* Pas de variable globale de déclarée
*/

template<class TData> class PArc
{
    // ATTRIBUTS
private:
    unsigned int uiARCIdDepart;
    unsigned int uiARCIdArrive;
	TData ARCData; // Données de l'arc
    
    // CONSTRUCTEURS ET DESTRUCTEURS
public:
    /*************************************************
    * PArc
    * ***********************************************
    * Entrée : Rien
    * Nécessite : Rien
    * Sortie : Rien
    * Entraîne : Crée un arc
    *************************************************
    */
    PArc() = default;

    /*************************************************
    * PArc
    * ***********************************************
    * Entrée : uiIdDepart, naturel, sommet de départ
    *          uiIdArrive, naturel, sommet d'arrivé
    * Nécessite : Rien
    * Sortie : Rien
    * Entraîne : Créer un arc à partir de l id de
                deux sommets
    *************************************************
    */
    PArc(unsigned int uiIdDepart, unsigned int uiIdArrive, TData Data)
    {
        uiARCIdDepart = uiIdDepart;
        uiARCIdArrive = uiIdArrive;
		ARCData = Data;
    }

	/**************************************************
    * ~PArc
	* ************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : Détruis un arc
    * ************************************************
    */
    ~PArc() = default;

    // METHODES
    /*************************************************
    * methode : ARCLireIdDepart
    * ***********************************************
    * Entrée : Rien
    * Nécessite : Rien
    * Sortie : uiARCIdDepart, naturel
    * Entraîne : Retournes l'id de l'arc de Depart
    *************************************************
    */
    unsigned int ARCLireIdDepart() { return uiARCIdDepart; }

    /*************************************************
    * methode : ARCLireIdArrive
    * ***********************************************
    * Entrée : Rien
    * Nécessite : Rien
    * Sortie : uiARCIdArrive, naturel
    * Entraîne : Retournes l'id de l'arc de Départ
    *************************************************
    */
    unsigned int ARCLireIdArrive() { return uiARCIdArrive; }

    /*************************************************
    * methode : ARCLireData
    * ***********************************************
    * Entrée : Rien
    * Nécessite : Rien
    * Sortie : ARCData, TData
    * Entraîne : Retournes la donnée de l'arc
    *************************************************
    */
	TData ARCLireData() { return ARCData; }

    /*************************************************
    * methode : ARCModifierIdArrive
    * ***********************************************
    * Entrée : uiNvIdArrive, naturel, l'id du nouvel
                arc d'arrivé
    * Nécessite : Rien
    * Sortie : Rien
    * Entraîne : Modifie l'arc d'arrivé
    *************************************************
    */
    void ARCModifierIdArrive(unsigned int uiNvIdArrive) { uiARCIdArrive = uiNvIdArrive; }

    /*************************************************
    * ARCModifierIdDepart
    * ***********************************************
    * Entrée : uiNvIdDepart, naturel, l'id du nouvel
    *            arc de depart
    * Nécessite : Rien
    * Sortie : Rien
    * Entraîne : Modifie l'arc de départ
    *************************************************
    */
    void ARCModifierIdDepart(unsigned int uiNvIdDepart) { uiARCIdDepart = uiNvIdDepart; }

    /*************************************************
	* methode : ARCModifierData
    * ***********************************************
	* Entrée : newData, TData, la nouvelle donnée
    * Nécessite : Rien
    * Sortie : Rien
	* Entraîne : Modifie la donnée de l'arc
    *************************************************
    */
	void ARCModifierData(TData newData) { ARCData = newData; }

	/*************************************************
	* operator==
    * ************************************************
	* Entrée : un arc
	* Nécessite : Rien
	* Sortie : Booléen
	* Entraîne : Compare si deux arcs sont égaux
	*               True si ils sont égaux, 
    *               False sinon
	* ***********************************************
    */
	bool operator==(const PArc* pArc) const
	{
		if (uiARCIdDepart == pArc->uiARCIdDepart && uiARCIdArrive == pArc->uiARCIdArrive && ARCData == pArc->ARCData) return true;
	    return false;
	}
};

#endif

