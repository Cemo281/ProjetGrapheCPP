#pragma once
//
// Created by Ali-Cem on 17/03/2025
//

#ifndef INCLUDE_ARC_H
#define INCLUDE_ARC_H 2

/****************************************************
* Classe : PArc
* **************************************************
* ROLE : Cette classe permet g�rer et modifier un arc
* **************************************************
* VERSION : 1.0
* AUTEUR : OZDEMIR Ali-Cem
* DATE : 03/03/2025
* *************************************************
* INCLUSIONS EXTERNES :
*/

/* TYPES:
* Pas de type particulier de d�clar�
*/

/* Variables :
* Pas de variable globale de d�clar�e
*/

template<class TData> class PArc
{
    // ATTRIBUTS
private:
    unsigned int uiARCIdDepart;
    unsigned int uiARCIdArrive;
	TData ARCData; // Donn�es de l'arc
    
    // CONSTRUCTEURS ET DESTRUCTEURS
public:
    /*************************************************
    * PArc
    * ***********************************************
    * Entr�e : Rien
    * N�cessite : Rien
    * Sortie : Rien
    * Entra�ne : Cr�e un arc
    *************************************************
    */
    PArc() = default;

    /*************************************************
    * PArc
    * ***********************************************
    * Entr�e : uiIdDepart, naturel, sommet de d�part
    *          uiIdArrive, naturel, sommet d'arriv�
    * N�cessite : Rien
    * Sortie : Rien
    * Entra�ne : Cr�er un arc � partir de l id de
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
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : D�truis un arc
    * ************************************************
    */
    ~PArc() = default;

    // METHODES
    /*************************************************
    * methode : ARCLireIdDepart
    * ***********************************************
    * Entr�e : Rien
    * N�cessite : Rien
    * Sortie : uiARCIdDepart, naturel
    * Entra�ne : Retournes l'id de l'arc de Depart
    *************************************************
    */
    unsigned int ARCLireIdDepart() { return uiARCIdDepart; }

    /*************************************************
    * methode : ARCLireIdArrive
    * ***********************************************
    * Entr�e : Rien
    * N�cessite : Rien
    * Sortie : uiARCIdArrive, naturel
    * Entra�ne : Retournes l'id de l'arc de D�part
    *************************************************
    */
    unsigned int ARCLireIdArrive() { return uiARCIdArrive; }

    /*************************************************
    * methode : ARCLireData
    * ***********************************************
    * Entr�e : Rien
    * N�cessite : Rien
    * Sortie : ARCData, TData
    * Entra�ne : Retournes la donn�e de l'arc
    *************************************************
    */
	TData ARCLireData() { return ARCData; }

    /*************************************************
    * methode : ARCModifierIdArrive
    * ***********************************************
    * Entr�e : uiNvIdArrive, naturel, l'id du nouvel
                arc d'arriv�
    * N�cessite : Rien
    * Sortie : Rien
    * Entra�ne : Modifie l'arc d'arriv�
    *************************************************
    */
    void ARCModifierIdArrive(unsigned int uiNvIdArrive) { uiARCIdArrive = uiNvIdArrive; }

    /*************************************************
    * ARCModifierIdDepart
    * ***********************************************
    * Entr�e : uiNvIdDepart, naturel, l'id du nouvel
    *            arc de depart
    * N�cessite : Rien
    * Sortie : Rien
    * Entra�ne : Modifie l'arc de d�part
    *************************************************
    */
    void ARCModifierIdDepart(unsigned int uiNvIdDepart) { uiARCIdDepart = uiNvIdDepart; }

    /*************************************************
	* methode : ARCModifierData
    * ***********************************************
	* Entr�e : newData, TData, la nouvelle donn�e
    * N�cessite : Rien
    * Sortie : Rien
	* Entra�ne : Modifie la donn�e de l'arc
    *************************************************
    */
	void ARCModifierData(TData newData) { ARCData = newData; }

	/*************************************************
	* operator==
    * ************************************************
	* Entr�e : un arc
	* N�cessite : Rien
	* Sortie : Bool�en
	* Entra�ne : Compare si deux arcs sont �gaux
	*               True si ils sont �gaux, 
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

