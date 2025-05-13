#pragma once
//
// Created by Ali-Cem on 17/03/2025
//

#ifndef INCLUDE_SOMMET_H
#define INCLUDE_SOMMET_H 1

/****************************************************
* Classe : PSommet
* **************************************************
* ROLE : Cette classe permet gerer et modifier un sommet
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

using namespace std;

/* TYPES:
* Pas de type particulier de declare
*/

/* Variables :
* Pas de variable globale de declaree
*/

template<typename TData> class PSommet
{
    // ATTRIBUTS
private:
    unsigned int uiSOMId;                       // Id du sommet
    vector<PArc<TData>*> vSOMLstArcPartant;     // Liste des arcs partant du sommet
    vector<PArc<TData>*> vSOMLstArcArrivant;    // Liste des arcs arrivant au sommet
    TData SOMData;                              // Donnees du sommet

    // CONSTRUCTEURS ET DESTRUCTEURS
public:
    /************************************************
    * METHODE : PSommet
    * ***********************************************
    * Entree : Rien
    * Necessite : Rien
    * Sortie : Rien
    * Entraine : Cree un sommet
    *************************************************
    */
	PSommet() = default;

    /************************************************
    * METHODE : PSommet
    * ***********************************************
    * Entree : uiId, naturel, l'id du sommet
    * Necessite : Rien
    * Sortie : Rien
    * Entraine : Cree un sommet a partir d'un id
    *************************************************
    */
    PSommet(unsigned int uiId);

    /************************************************
    * METHODE : PSommet
    * ***********************************************
    * Entree : SOMParam, le sommet a copier
    * Necessite : Rien
    * Sortie : Une copie du sommet
    * Entraine : Cree un sommet a partir d'un autre sommet
    *************************************************
    */
    PSommet(const PSommet<TData>& SOMParam);

    /************************************************
    * METHODE : ~TSommet
    * ***********************************************
    * Entree : Rien
    * Necessite : Rien
    * Sortie : Rien
    * Entraine : Detruis le sommet
    *************************************************
    */
    ~PSommet() = default;

	// METHODES
    /************************************************
    * METHODE : SOMLireId
    * ***********************************************
    * Entree : Rien
    * Necessite : Rien
    * Sortie : uiSOMId, naturel
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
    * Sortie : tSOMData, TData
    * Entraine : Retournes la donnee du sommet
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
    * Entree : PArcPart, l'arc a ajouter
    * Necessite : Rien
    * Sortie : Rien
    * Entraine : Ajoutes un arc a la liste des
    *               arcs partant du sommet
    *************************************************
    */
    void SOMAjouterArcPart(PArc<TData>* ptArcPart);

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
	PArc<TData>* SOMLireArcPart(unsigned int uiPos);

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
    PArc<TData>* SOMLireArcArr(unsigned int uiPos);

    /************************************************
    * METHODE : SOMSupprimerArcPart
    * ***********************************************
    * Entree : ptArcPart, l'arc a supprimer
    * Necessite : Rien
    * Sortie : Rien
    * Entraine : Supprimes l'arc arc a la liste des
    *               arcs partant du sommet
    *************************************************
    */
    void SOMSupprimerArcPart(PArc<TData>* ptArcPart);

    /************************************************
    * METHODE : SOMAjouterArcArr
    * ***********************************************
    * Entree : ptArcArr, un pointeur vers l'arc a ajouter
    * Necessite : Rien
    * Sortie : Rien
    * Entraine : Ajoutes un arc a la liste des
    *               arcs arrivant au sommet
    *************************************************
    */
    void SOMAjouterArcArr(PArc<TData>* ptArcArr);

    /************************************************
    * METHODE : SOMSupprimerArcArr
    * ***********************************************
    * Entree : ptArcPart, l'arc a supprimer
    * Necessite : Rien
    * Sortie : Rien
    * Entraine : Supprimes l'arc a la liste des
    *               arcs arrivant au sommet
    *************************************************
    */
    void SOMSupprimerArcArr(PArc<TData>* ptArcPart);

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
    bool operator==(const PSommet* ptSommet) const;

    /************************************************
    * METHODE : SOMEstDansLstPart
    * ***********************************************
    * Entree : ptArcPart, un pointeur vers un arc
    * Necessite : Rien
    * Sortie : Un booleen
	* Entraine : Verifie si le sommet existe deja dans 
    *                la liste des sommets partant
    * ***********************************************
    */
	bool SOMEstDansLstPart(PArc<TData>* ptArcPart);

    /************************************************
    * METHODE : SomEstDansLstArrivant
    * ***********************************************
    * Entree : ptArcArr, un pointeur vers un arc
    * Necessite : Rien
    * Sortie : Un booleen
    * Entraine : Verifie si le sommet existe deja 
                    dans la liste des sommets arrivant
    * ***********************************************
    */
	bool SOMEstDansLstArrivant(PArc<TData>* ptArcArr);

    /*************************************************
    * METHODE : SOMInverser
    * ************************************************
    * Entree : Rien
    * Necessite : Rien
    * Sortie : Rien
	* Entraine : Inverse le sommet c'est a dire qu'il 
    *			place tout les sommet arrivant dans ceux partant et vice versa
    * ***********************************************
    */
	void SOMInverser();

	/************************************************
	* METHODE : SOMAfficher
	* ***********************************************
	* Entree : Rien
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : Affiches le sommet dans la console
	* ***********************************************
	*/
	void SOMAfficher();

    /************************************************
    * METHODE : SOMLireTailleArcArrivant
    * ***********************************************
    * Entree : Rien
    * Necessite : Rien
    * Sortie : Un naturel
    * Entraine : Retournes la taille de la liste des arcs arrivant
    * *************************************************
    */
    unsigned int SOMLireTailleArcPartant() const;

	/************************************************
	* operateur<
	* ***********************************************
	* Entree : ptSommet, un pointeur vers un sommet
	* Necessite : Rien
	* Sortie : Un booleen
	* Entraine : Compare si deux sommets sont egaux, c'est a dire
    *               compare leur data
	* ***********************************************
	*/
    bool operator<(const PSommet* ptSommet) const;
};
#include "PSommet.tpp"

#endif