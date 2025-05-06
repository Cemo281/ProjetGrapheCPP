#pragma once
//
// Created by Ali-Cem on 17/03/2025
//

#ifndef INCLUDE_SOMMET_H
#define INCLUDE_SOMMET_H 1

/****************************************************
* Classe : TSommet
* **************************************************
* ROLE : Cette classe permet gerer et modifier un sommet
* **************************************************
* VERSION : 1.0
* AUTEUR : OZDEMIR Ali-Cem
* DATE : 03/03/2025
* *************************************************
* INCLUSIONS EXTERNES :
*/
#include "TArc.hpp"
#include <vector>
#include <assert.h>

using namespace std;

/* TYPES:
* Pas de type particulier de declare
*/

/* Variables :
* Pas de variable globale de declaree
*/

template<typename TData> class TSommet
{
    // ATTRIBUTS
private:
    unsigned int uiSOMId;
    vector<TArc<TData>*> vSOMLstArcPartant;
    vector<TArc<TData>*> vSOMLstArcArrivant;
    TData SOMData; // Donnees du sommet

    // CONSTRUCTEURS ET DESTRUCTEURS
public:
    /************************************************
    * METHODE : TSommet
    * ***********************************************
    * Entree : Rien
    * Necessite : Rien
    * Sortie : Rien
    * Entraine : Cree un sommet
    *************************************************
    */
	TSommet() = default;

    /************************************************
    * METHODE : TSommet
    * ***********************************************
    * Entree : uiId, naturel, l'id du sommet
    * Necessite : Rien
    * Sortie : Rien
    * Entraine : Cree un sommet a partir de son id
    *************************************************
    */
    TSommet(unsigned int uiId)
    { 
        uiSOMId = uiId; 
    }

    /************************************************
    * METHODE : TSommet
    * ***********************************************
    * Entree : SOMParam, un sommet a copier
    * Necessite : Rien
    * Sortie : Une copie du sommet
    * Entraine : Cree un sommet a partir d'un autre sommet
    *************************************************
    */
    TSommet(const TSommet<TData>& SOMParam);

    /************************************************
    * METHODE : ~TSommet
    * ***********************************************
    * Entree : Rien
    * Necessite : Rien
    * Sortie : Rien
    * Entraine : Detruis un sommet
    *************************************************
    */
    ~TSommet() = default;

	// METHODES
    /************************************************
    * METHODE : SOMLireId
    * ***********************************************
    * Entree : Rien
    * Necessite : Rien
    * Sortie : Rien
    * Entraine : Retournes l'id du sommet
    *************************************************
    */
    unsigned int SOMLireId() const;

    /************************************************
    * METHODE : SOMModifierId
    * ***********************************************
    * Entree : uiNvId, naturel, le nouvel id
    * Necessite : Rien
    * Sortie : Rien
    * Entraine : Cree un sommet
    *************************************************
    */
    void SOMModifierId(unsigned int uiNvId);

    /************************************************
    * METHODE : SOMLireData
    * ***********************************************
    * Entree : Rien
    * Necessite : Rien
    * Sortie : Rien
    * Entraine : Lit la donnee du sommet
    *************************************************
    */
    TData SOMLireData() const;

    /************************************************
    * METHODE : SOMModifierData
    * ***********************************************
    * Entree : Data, la nouvelle donnee
    * Necessite : Rien
    * Sortie : Rien
    * Entraine : Modifie la donnee du sommet
    * *************************************************
    */
    void SOMModifierData(TData nvData);

    /************************************************
    * METHODE : SOMAjouterArcPart
    * ***********************************************
    * Entree : tArcPart, l'arc a ajouter
    * Necessite : Rien
    * Sortie : Rien
    * Entraine : Ajoutes un arc a la liste des
    *               arcs partant du sommet
    *************************************************
    */
    void SOMAjouterArcPart(TArc<TData>* ptArcPart);

    /************************************************
	* METHODE : SOMLireArcPart
    * ***********************************************
	* Entree : uiPos, Naturel, la position de l'arc
    * Necessite : Rien
	* Sortie : Un pointeur vers l'arc
	* Entraine : Retournes un pointeur vers l'arc 
                    partant du sommet
    *************************************************
    */
	TArc<TData>* SOMLireArcPart(unsigned int uiPos);

    /************************************************
    * METHODE : SOMLireArcArr
    * ***********************************************
    * Entree : uiPos, Naturel, la position de l'arc
    * Necessite : Rien
    * Sortie : Un pointeur vers l'arc
    * Entraine : Retournes un pointeur vers l'arc
	*               arrivant au sommet
    *************************************************
	*/
    TArc<TData>* SOMLireArcArr(unsigned int uiPos);

    /************************************************
    * METHODE : SOMSupprimerArcPart
    * ***********************************************
    * Entree : ptArcPart, l'arc a ajouter
    * Necessite : Rien
    * Sortie : Rien
    * Entraine : Ajoutes un arc a la liste des
    *               arcs partant du sommet
    *************************************************
    */
    void SOMSupprimerArcPart(TArc<TData>* ptArcPart);

    /************************************************
    * METHODE : SOMAjouterArcArr
    * ***********************************************
    * Entree : tArcArr, l'arc a ajouter
    * Necessite : Rien
    * Sortie : Rien
    * Entraine : Ajoutes un arc a la liste des
    *               arcs arrivant au sommet
    *************************************************
    */
    void SOMAjouterArcArr(TArc<TData>* ptArcArr);

    /************************************************
    * METHODE : SOMSupprimerArcArr
    * ***********************************************
    * Entree : ptArcPart, l'arc a ajouter
    * Necessite : Rien
    * Sortie : Rien
    * Entraine : Ajoutes un arc a la liste des
    *               arcs arrivant au sommet
    *************************************************
    */
    void SOMSupprimerArcArr(TArc<TData>* ptArcPart);

	/************************************************
    * METHODE : operateur==
    * ***********************************************
	* Entree : ptSommet, un pointeur vers un sommet
    * Necessite : rien
	* Sortie : un booleen
	* Entraine : Compare si deux pointeurs vers un sommet sont egaux
	*               True si ils sont egaux,
	*               False sinon
	* ***********************************************
	*/
    bool operator==(const TSommet* ptSommet) const;

    /************************************************
    * METHODE : SOMEstDansLstPart
    * ***********************************************
    * Entree : ptArcPart, un pointeur vers l'arc partant du sommet
    * Necessite : rien
    * Sortie : un booleen
	* Entraine : Verifie si le sommet existe deja dans 
    *                la liste des sommets partant
    * ***********************************************
    */
	bool SOMEstDansLstPart(TArc<TData>* ptArcPart);

    /************************************************
    * METHODE : SomEstDansLstArrivant
    * ***********************************************
    * Entree : ptArcArr, un pointeur vers l'arc arrivant au sommet
    * Necessite : rien
    * Sortie : un booleen
    * Entraine : Verifie si le sommet existe deja 
                    dans la liste des sommets arrivant
    * ***********************************************
    */
	bool SOMEstDansLstArrivant(TArc<TData>* ptArcArr);

    /*************************************************
    * METHODE : SOMInverser
    * ************************************************
    * Entree : Rien
    * Necessite : Rien
    * Sortie : Rien
	* Entraine : Inverse le sommet c'est � dire qu'il 
    *			place tout les sommet arrivant dans ceux partant et vice versa
    * ***********************************************
    */
	void SOMInverser();
};
#include "TSommet.tpp"

#endif