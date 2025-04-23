#pragma once
//
// Created by Ali-Cem on 17/03/2025
//

#ifndef INCLUDE_SOMMET_H
#define INCLUDE_SOMMET_H 1

/****************************************************
* Classe : PSommet
* **************************************************
* ROLE : Cette classe permet gérer et modifier un sommet
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
* Pas de type particulier de déclaré
*/

/* Variables :
* Pas de variable globale de déclarée
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
    * Entrée : Rien
    * Nécessite : Rien
    * Sortie : Rien
    * Entraîne : Crée un sommet
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
    * Entrée : uiId, naturel, l'id du sommet
    * Nécessite : Rien
    * Sortie : Rien
    * Entraîne : Crée un sommet à partir de son id
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
    * Entrée : Rien
    * Nécessite : Rien
    * Sortie : Rien
    * Entraîne : Détruis un sommet
    *************************************************
    */
    ~PSommet();

    /************************************************
    * METHODE : SOMLireId
    * ***********************************************
    * Entrée : Rien
    * Nécessite : Rien
    * Sortie : Rien
    * Entraîne : Retournes l'id du sommet
    *************************************************
    */
    unsigned int SOMLireId() { return uiSOMId; }

    /************************************************
    * METHODE : SOMModifierId
    * ***********************************************
    * Entrée : uiNvId, naturel, le nouvel id
    * Nécessite : Rien
    * Sortie : Rien
    * Entraîne : Crée un sommet
    *************************************************
    */
    void SOMModifierId(unsigned int uiNvId) { uiSOMId = uiNvId; }

    /************************************************
    * METHODE : SOMAjouterArcPart
    * ***********************************************
    * Entrée : pArcPart, l'arc à ajouter
    * Nécessite : Rien
    * Sortie : Rien
    * Entraîne : Ajoutes un arc à la liste des
    *               arcs partant du sommet
    *************************************************
    */
    void SOMAjouterArcPart(TArc* pArcPart) { vSOMLstArcPartant->push_back(pArcPart); }

    /************************************************
    * METHODE : SOMAjouterArcArr
    * ***********************************************
    * Entrée : pArcArr, l'arc à ajouter
    * Nécessite : Rien
    * Sortie : Rien
    * Entraîne : Ajoutes un arc à la liste des
    *               arcs arrivant au sommet
    *************************************************
    */
    void SOMAjouterArcArr(TArc* pArcArr) { vSOMLstArcArrivant->push_back(pArcArr); }

    /************************************************
    * METHODE : SOMSupprimerArcArr
    * ***********************************************
    * Entrée : pArcArr, l'arc à supprimer
    * Nécessite : Rien
    * Sortie : Rien
    * Entraîne : Supprimes un arc de la liste des
    *               arcs arrivant au sommet
    *************************************************
    */
    int SOMSupprimerArcPart(TArc* pArcArr);

    /************************************************
    * METHODE : SOMSupprimerArcPart
    * ***********************************************
    * Entrée : pArcPart, l'arc à supprimer
    * Nécessite : Rien
    * Sortie : Rien
    * Entraîne : Supprimes un arc de la liste des
    *               arcs partant du sommet
    *************************************************
    */
    int SOMSupprimerArcArr(TArc* pArcPart);

	/************************************************
    * METHODE : SOMLireArcPartant
    * ***********************************************
    * Entrée : pos, la position de l'arc à lire
    * Nécessite : l'arc appartient à la liste
    * Sortie : Rien
    * Entraîne : Retournes les informations de l'arc
    *               partant du sommet
    *************************************************
    */
    TArc* SOMLireArcPartant(int pos) { return vSOMLstArcPartant->at(pos); }

    /************************************************
    * METHODE : SOMLireArcArrivant
    * ***********************************************
    * Entrée : l'arc à lire
    * Nécessite : l'arc appartient à la liste
    * Sortie : Rien
    * Entraîne : Retournes les informations de l'arc
    *               arrivant au sommet
    *************************************************
    */
    TArc* SOMLireArcArrivant(int pos) { return vSOMLstArcArrivant->at(pos); }

	/************************************************
    * METHODE : operateur==
    * ***********************************************
	* Entrée : pSommet, un pointeur vers un sommet
    * Nécessite : rien
	* Sortie : un booléen
	* Entraîne : Compare si deux pointeurs vers un sommet sont égaux
	*               True si ils sont égaux,
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
    * Entrée : pSommet, un pointeur vers l'arc partant du sommet
    * Nécessite : rien
    * Sortie : un booléen
	* Entraîne : Vérifie si le sommet existe déjà dans 
                    la liste des sommets partant
    * ***********************************************
    */
    bool EstDansLstPart(TArc* pArcPart);

    /************************************************
    * METHODE : EstDansLstArrivant
    * ***********************************************
    * Entrée : pSommet, un pointeur vers l'arc arrivant au sommet
    * Nécessite : rien
    * Sortie : un booléen
    * Entraîne : Vérifie si le sommet existe déjà 
                    dans la liste des sommets arrivant
    * ***********************************************
    */
	bool EstDansLstArrivant(TArc* pArcArr);

};

#endif