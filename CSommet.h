#pragma once
//
// Created by Ali-Cem on 17/03/2025
//

#ifndef INCLUDE_SOMMET_H
#define INCLUDE_SOMMET_H 1

/****************************************************
* Classe : CSommet
* **************************************************
* ROLE : Cette classe permet gérer et modifier un sommet
* **************************************************
* VERSION : 1.0
* AUTEUR : OZDEMIR Ali-Cem
* DATE : 03/03/2025
* *************************************************
* INCLUSIONS EXTERNES :
*/
#include "CArc.h"
#include <vector>

/* TYPES:
* Pas de type particulier de déclaré
*/

/* Variables :
* Pas de variable globale de déclarée
*/

class CSommet
{
    // ATTRIBUTS
private:
    unsigned int uiSOMId;
    std::vector<CArc*> vSOMLstArcPartant;
    std::vector<CArc*> vSOMLstArcArrivant;

    // CONSTRUCTEURS ET DESTRUCTEURS
public:
    /************************************************
    * METHODE : CSommet
    * ***********************************************
    * Entrée : Rien
    * Nécessite : Rien
    * Sortie : Rien
    * Entraîne : Crée un sommet
    *************************************************
    */
    CSommet() = default;

    /************************************************
    * METHODE : CSommet
    * ***********************************************
    * Entrée : uiId, naturel, l'id du sommet
    * Nécessite : Rien
    * Sortie : Rien
    * Entraîne : Crée un sommet à partir de son id
    *************************************************
    */
    CSommet(unsigned int uiId) { uiSOMId = uiId; }

    /************************************************
    * METHODE : ~CSommet
    * ***********************************************
    * Entrée : Rien
    * Nécessite : Rien
    * Sortie : Rien
    * Entraîne : Détruis un sommet
    *************************************************
    */
    ~CSommet();

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
    void SOMAjouterArcPart(CArc* pArcPart) { vSOMLstArcPartant.push_back(pArcPart); }

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
    void SOMAjouterArcArr(CArc* pArcArr) { vSOMLstArcPartant.push_back(pArcArr); }

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
    int SOMSupprimerArcPart(CArc* pArcArr);

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
    int SOMSupprimerArcArr(CArc* pArcPart);

    /************************************************
    * METHODE : SOMLireArcPartant
    * ***********************************************
    * Entrée : l'arc à lire
    * Nécessite : l'arc appartient à la liste
    * Sortie : Rien
    * Entraîne : Retournes les informations de l'arc
    *               partant du sommet
    *************************************************
    */
    std::vector<CArc*> SOMLireArcPartant(int pos) { return vSOMLstArcPartant; }

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
    CArc* SOMLireArcArrivant(int pos) { return vSOMLstArcArrivant[pos]; }
};

#endif