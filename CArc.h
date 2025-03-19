#pragma once
//
// Created by Ali-Cem on 17/03/2025
//

#ifndef INCLUDE_ARC_H
#define INCLUDE_ARC_H 2

/****************************************************
* Classe : CArc
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
    * Entr�e : Rien
    * N�cessite : Rien
    * Sortie : Rien
    * Entra�ne : Cr�e un arc
    *************************************************
    */
    CArc() = default;

    /*************************************************
    * CArc
    * ***********************************************
    * Entr�e : uiIdDepart, naturel, arc de d�part
    *          uiIdArrive, naturel, arc d arrive
    * N�cessite : Rien
    * Sortie : Rien
    * Entra�ne : Cr�er un arc � partir de l id de
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
       * Entr�e : Rien
       * N�cessite : Rien
       * Sortie : uiARCIdDepart, naturel
       * Entra�ne : Retourbe l id de l'arc de Depart
       *************************************************
       */
    unsigned int ARCLireIdDepart() { return uiARCIdDepart; }

    /*************************************************
    * methode : ARCLireIdArrive
    * ***********************************************
    * Entr�e : Rien
    * N�cessite : Rien
    * Sortie : uiARCIdArrive, naturel
    * Entra�ne : Retourbe l id de l'arc de Depart
    *************************************************
    */
    unsigned int ARCLireIdArrive() { return uiARCIdArrive; }

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
};

#endif

