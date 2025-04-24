#pragma once
//
// Created by Ali-Cem on 17/03/2025
//

#ifndef INCLUDE_SOMMET_H
#define INCLUDE_SOMMET_H 1

/****************************************************
* Classe : TSommet
* **************************************************
* ROLE : Cette classe permet g�rer et modifier un sommet
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
* Pas de type particulier de d�clar�
*/

/* Variables :
* Pas de variable globale de d�clar�e
*/

template<class TData> class TSommet
{
    // ATTRIBUTS
private:
    unsigned int uiSOMId;
    vector<TArc<TData>> vSOMLstArcPartant;
    vector<TArc<TData>> vSOMLstArcArrivant;
    TData SOMData; // Donn�es du sommet

    // CONSTRUCTEURS ET DESTRUCTEURS
public:
    /************************************************
    * METHODE : TSommet
    * ***********************************************
    * Entr�e : Rien
    * N�cessite : Rien
    * Sortie : Rien
    * Entra�ne : Cr�e un sommet
    *************************************************
    */
	TSommet() = default;

    /************************************************
    * METHODE : TSommet
    * ***********************************************
    * Entr�e : uiId, naturel, l'id du sommet
    * N�cessite : Rien
    * Sortie : Rien
    * Entra�ne : Cr�e un sommet � partir de son id
    *************************************************
    */
    TSommet(unsigned int uiId, TData &Data)
    { 
        uiSOMId = uiId; 
        vSOMLstArcArrivant = vector<TArc<TData>>();
        vSOMLstArcPartant = vector<TArc<TData>>();
        SOMData = Data;
    }

    /************************************************
    * METHODE : ~TSommet
    * ***********************************************
    * Entr�e : Rien
    * N�cessite : Rien
    * Sortie : Rien
    * Entra�ne : D�truis un sommet
    *************************************************
    */
    ~TSommet() = default;

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
    void SOMAjouterArcPart(TArc<TData> &pArcPart) { vSOMLstArcPartant.push_back(pArcPart); }

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
    void SOMAjouterArcArr(TArc<TData> &pArcArr) { vSOMLstArcArrivant.push_back(pArcArr); }

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
    TArc<TData> SOMLireArcPartant(int pos) { return vSOMLstArcPartant.at(pos); }

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
   TArc<TData> SOMLireArcArrivant(int pos) { return vSOMLstArcArrivant.at(pos); }

	/************************************************
    * METHODE : operateur==
    * ***********************************************
	* Entr�e : tSommet, un pointeur vers un sommet
    * N�cessite : rien
	* Sortie : un bool�en
	* Entra�ne : Compare si deux pointeurs vers un sommet sont �gaux
	*               True si ils sont �gaux,
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
    * Entr�e : tArcPart, un pointeur vers l'arc partant du sommet
    * N�cessite : rien
    * Sortie : un bool�en
	* Entra�ne : V�rifie si le sommet existe d�j� dans 
    *                la liste des sommets partant
    * ***********************************************
    */
    bool EstDansLstPart(TArc<TData> &tArcPart);

    /************************************************
    * METHODE : EstDansLstArrivant
    * ***********************************************
    * Entr�e : tArcArr, un pointeur vers l'arc arrivant au sommet
    * N�cessite : rien
    * Sortie : un bool�en
    * Entra�ne : V�rifie si le sommet existe d�j� 
                    dans la liste des sommets arrivant
    * ***********************************************
    */
	bool EstDansLstArrivant(TArc<TData> &tArcArr);

};

#endif