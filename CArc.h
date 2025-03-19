#pragma once
//
// Created by Ali-Cem on 17/03/2025
//

#ifndef INCLUDE_ARC_H
#define INCLUDE_ARC_H 2

/****************************************************
* Classe : CArc
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

class CArc
{
    // ATTRIBUTS
private:
    unsigned int uiARCIdDepart;
    unsigned int uiARCIdArrive;
    // CONSTRUCTEURS ET DESTRUCTEURS
public:
    /*************************************************
    * CArc
    * ***********************************************
    * Entrée : Rien
    * Nécessite : Rien
    * Sortie : Rien
    * Entraîne : Crée un arc
    *************************************************
    */
    CArc() = default;

    /*************************************************
    * CArc
    * ***********************************************
    * Entrée : uiIdDepart, naturel, arc de départ
    *          uiIdArrive, naturel, arc d arrive
    * Nécessite : Rien
    * Sortie : Rien
    * Entraîne : Créer un arc à partir de l id de
                deux autres arc
    *************************************************
    */
    CArc(unsigned int uiIdDepart, unsigned int uiIdArrive)
    {
        uiARCIdDepart = uiIdDepart;
        uiARCIdArrive = uiIdArrive;
    }

    // METHODES
       /*************************************************
       * methode : ARCLireIdDepart
       * ***********************************************
       * Entrée : Rien
       * Nécessite : Rien
       * Sortie : uiARCIdDepart, naturel
       * Entraîne : Retourbe l id de l'arc de Depart
       *************************************************
       */
    unsigned int ARCLireIdDepart() { return uiARCIdDepart; }

    /*************************************************
    * methode : ARCLireIdArrive
    * ***********************************************
    * Entrée : Rien
    * Nécessite : Rien
    * Sortie : uiARCIdArrive, naturel
    * Entraîne : Retourbe l id de l'arc de Depart
    *************************************************
    */
    unsigned int ARCLireIdArrive() { return uiARCIdArrive; }

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
};

#endif

