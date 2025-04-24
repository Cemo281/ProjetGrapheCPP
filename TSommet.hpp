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
    vector<TArc<TData>> vSOMLstArcPartant;
    vector<TArc<TData>> vSOMLstArcArrivant;
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
    TSommet(unsigned int uiId, TData Data)
    { 
        uiSOMId = uiId; 
        SOMData = Data;
    }

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

    /************************************************
    * METHODE : SOMLireId
    * ***********************************************
    * Entree : Rien
    * Necessite : Rien
    * Sortie : Rien
    * Entraine : Retournes l'id du sommet
    *************************************************
    */
    unsigned int SOMLireId() { return uiSOMId; }

    /************************************************
    * METHODE : SOMModifierId
    * ***********************************************
    * Entree : uiNvId, naturel, le nouvel id
    * Necessite : Rien
    * Sortie : Rien
    * Entraine : Cree un sommet
    *************************************************
    */
    void SOMModifierId(unsigned int uiNvId) { uiSOMId = uiNvId; }

    /************************************************
    * METHODE : SOMLireData
    * ***********************************************
    * Entree : Rien
    * Nicessite : Rien
    * Sortie : Rien
    * Entraine : Lit la donnee du sommet
    *************************************************
    */
    TData SOMLireData() { return SOMData; }

    /************************************************
    * METHODE : SOMAjouterArcPart
    * ***********************************************
    * Entree : pArcPart, l'arc a ajouter
    * Necessite : Rien
    * Sortie : Rien
    * Entraine : Ajoutes un arc a la liste des
    *               arcs partant du sommet
    *************************************************
    */
    void SOMAjouterArcPart(TArc<TData> &pArcPart) { vSOMLstArcPartant.push_back(pArcPart); }

    /************************************************
    * METHODE : SOMAjouterArcArr
    * ***********************************************
    * Entree : pArcArr, l'arc a ajouter
    * Necessite : Rien
    * Sortie : Rien
    * Entraine : Ajoutes un arc a la liste des
    *               arcs arrivant au sommet
    *************************************************
    */
    void SOMAjouterArcArr(TArc<TData> &pArcArr) { vSOMLstArcArrivant.push_back(pArcArr); }

	/************************************************
    * METHODE : SOMLireArcPartant
    * ***********************************************
    * Entree : pos, la position de l'arc a lire
    * Necessite : l'arc appartient a la liste
    * Sortie : Rien
    * Entraine : Retournes les informations de l'arc
    *               partant du sommet
    *************************************************
    */
    TArc<TData> SOMLireArcPartant(int pos) { return vSOMLstArcPartant.at(pos); }

    /************************************************
    * METHODE : SOMLireArcArrivant
    * ***********************************************
    * Entree : l'arc a lire
    * Necessite : l'arc appartient a la liste
    * Sortie : Rien
    * Entraine : Retournes les informations de l'arc
    *               arrivant au sommet
    *************************************************
    */
   TArc<TData> SOMLireArcArrivant(int pos) { return vSOMLstArcArrivant.at(pos); }

	/************************************************
    * METHODE : operateur==
    * ***********************************************
	* Entree : tSommet, un pointeur vers un sommet
    * Necessite : rien
	* Sortie : un booleen
	* Entraine : Compare si deux pointeurs vers un sommet sont egaux
	*               True si ils sont egaux,
	*               False sinon
	* ***********************************************
	*/
    bool operator==(const TSommet &tSommet) const
    {
        return uiSOMId == tSommet.uiSOMId && SOMData == tSommet.SOMData;
    }

    /************************************************
    * METHODE : EstDansLstPart
    * ***********************************************
    * Entree : tArcPart, un pointeur vers l'arc partant du sommet
    * Necessite : rien
    * Sortie : un booleen
	* Entraine : Verifie si le sommet existe deja dans 
    *                la liste des sommets partant
    * ***********************************************
    */
    bool EstDansLstPart(TArc<TData> &tArcPart);

    /************************************************
    * METHODE : EstDansLstArrivant
    * ***********************************************
    * Entree : tArcArr, un pointeur vers l'arc arrivant au sommet
    * Necessite : rien
    * Sortie : un booleen
    * Entraine : Verifie si le sommet existe deja 
                    dans la liste des sommets arrivant
    * ***********************************************
    */
	bool EstDansLstArrivant(TArc<TData> &tArcArr);

};
#include "TSommet.tpp"
#endif