#pragma once
//
// Created by Ali-Cem on 17/03/2025
//

#ifndef INCLUDE_SOMMET_H
#define INCLUDE_SOMMET_H 1

/****************************************************
* Classe : PSommet
* **************************************************
* ROLE : Cette classe permet g�rer et modifier un sommet
* **************************************************
* VERSION : 1.0
* AUTEUR : OZDEMIR Ali-Cem
* DATE : 03/03/2025
* *************************************************
* INCLUSIONS EXTERNES :
*/
#include "PArc.hpp"
#include <vector>
#include <assert.h>

/* TYPES:
* Pas de type particulier de d�clar�
*/

/* Variables :
* Pas de variable globale de d�clar�e
*/

template<class TArc> class PSommet
{
    // ATTRIBUTS
private:
    unsigned int uiSOMId;
    std::vector<TArc*>* vSOMLstArcPartant;
    std::vector<TArc*>* vSOMLstArcArrivant;

    // CONSTRUCTEURS ET DESTRUCTEURS
public:
    /************************************************
    * METHODE : PSommet
    * ***********************************************
    * Entr�e : Rien
    * N�cessite : Rien
    * Sortie : Rien
    * Entra�ne : Cr�e un sommet
    *************************************************
    */
	PSommet() 
    {
		uiSOMId = 0;
		vSOMLstArcPartant = new std::vector<TArc*>();
		vSOMLstArcArrivant = new std::vector<TArc*>();
	}

    /************************************************
    * METHODE : PSommet
    * ***********************************************
    * Entr�e : uiId, naturel, l'id du sommet
    * N�cessite : Rien
    * Sortie : Rien
    * Entra�ne : Cr�e un sommet � partir de son id
    *************************************************
    */
    PSommet(unsigned int uiId) 
    { 
        uiSOMId = uiId; 
	    vSOMLstArcPartant = new std::vector<TArc*>();
	    vSOMLstArcArrivant = new std::vector<TArc*>();
    }

    /************************************************
    * METHODE : ~PSommet
    * ***********************************************
    * Entr�e : Rien
    * N�cessite : Rien
    * Sortie : Rien
    * Entra�ne : D�truis un sommet
    *************************************************
    */
    ~PSommet();

    /************************************************
    * METHODE : SOMLireId
    * ***********************************************
    * Entr�e : Rien
    * N�cessite : Rien
    * Sortie : Rien
    * Entra�ne : Retournes l'id du sommet
    *************************************************
    */
    unsigned int SOMLireId() { return uiSOMId; }

    /************************************************
    * METHODE : SOMModifierId
    * ***********************************************
    * Entr�e : uiNvId, naturel, le nouvel id
    * N�cessite : Rien
    * Sortie : Rien
    * Entra�ne : Cr�e un sommet
    *************************************************
    */
    void SOMModifierId(unsigned int uiNvId) { uiSOMId = uiNvId; }

    /************************************************
    * METHODE : SOMAjouterArcPart
    * ***********************************************
    * Entr�e : pArcPart, l'arc � ajouter
    * N�cessite : Rien
    * Sortie : Rien
    * Entra�ne : Ajoutes un arc � la liste des
    *               arcs partant du sommet
    *************************************************
    */
    void SOMAjouterArcPart(TArc* pArcPart) { vSOMLstArcPartant->push_back(pArcPart); }

    /************************************************
    * METHODE : SOMAjouterArcArr
    * ***********************************************
    * Entr�e : pArcArr, l'arc � ajouter
    * N�cessite : Rien
    * Sortie : Rien
    * Entra�ne : Ajoutes un arc � la liste des
    *               arcs arrivant au sommet
    *************************************************
    */
    void SOMAjouterArcArr(TArc* pArcArr) { vSOMLstArcArrivant->push_back(pArcArr); }

    /************************************************
    * METHODE : SOMSupprimerArcArr
    * ***********************************************
    * Entr�e : pArcArr, l'arc � supprimer
    * N�cessite : Rien
    * Sortie : Rien
    * Entra�ne : Supprimes un arc de la liste des
    *               arcs arrivant au sommet
    *************************************************
    */
    int SOMSupprimerArcPart(TArc* pArcArr);

    /************************************************
    * METHODE : SOMSupprimerArcPart
    * ***********************************************
    * Entr�e : pArcPart, l'arc � supprimer
    * N�cessite : Rien
    * Sortie : Rien
    * Entra�ne : Supprimes un arc de la liste des
    *               arcs partant du sommet
    *************************************************
    */
    int SOMSupprimerArcArr(TArc* pArcPart);

	/************************************************
    * METHODE : SOMLireArcPartant
    * ***********************************************
    * Entr�e : pos, la position de l'arc � lire
    * N�cessite : l'arc appartient � la liste
    * Sortie : Rien
    * Entra�ne : Retournes les informations de l'arc
    *               partant du sommet
    *************************************************
    */
    TArc* SOMLireArcPartant(int pos) { return vSOMLstArcPartant->at(pos); }

    /************************************************
    * METHODE : SOMLireArcArrivant
    * ***********************************************
    * Entr�e : l'arc � lire
    * N�cessite : l'arc appartient � la liste
    * Sortie : Rien
    * Entra�ne : Retournes les informations de l'arc
    *               arrivant au sommet
    *************************************************
    */
    TArc* SOMLireArcArrivant(int pos) { return vSOMLstArcArrivant->at(pos); }

	/************************************************
    * METHODE : operateur==
    * ***********************************************
	* Entr�e : pSommet, un pointeur vers un sommet
    * N�cessite : rien
	* Sortie : un bool�en
	* Entra�ne : Compare si deux pointeurs vers un sommet sont �gaux
	*               True si ils sont �gaux,
	*               False sinon
	* ***********************************************
	*/
    bool operator==(const PSommet* pSommet) const
    {
        return uiSOMId == pSommet->uiSOMId;
    }

    /************************************************
    * METHODE : EstDansLstPart
    * ***********************************************
    * Entr�e : pSommet, un pointeur vers l'arc partant du sommet
    * N�cessite : rien
    * Sortie : un bool�en
	* Entra�ne : V�rifie si le sommet existe d�j� dans 
                    la liste des sommets partant
    * ***********************************************
    */
    bool EstDansLstPart(TArc* pArcPart);

    /************************************************
    * METHODE : EstDansLstArrivant
    * ***********************************************
    * Entr�e : pSommet, un pointeur vers l'arc arrivant au sommet
    * N�cessite : rien
    * Sortie : un bool�en
    * Entra�ne : V�rifie si le sommet existe d�j� 
                    dans la liste des sommets arrivant
    * ***********************************************
    */
	bool EstDansLstArrivant(TArc* pArcArr);

};

#endif