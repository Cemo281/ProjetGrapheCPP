#include "TArc.hpp"

/*************************************************
* TArc
* ***********************************************
* Entree : uiIdDepart, naturel, sommet de depart
*          uiIdArrive, naturel, sommet d'arrive
* Necessite : Rien
* Sortie : Rien
* Entraine : Creer un arc a partir de l id de
*            deux sommets
*************************************************
*/
template <typename TData> TArc<TData>::TArc(unsigned int uiIdDepart, unsigned int uiIdArrive, TData Data) 
{
    uiARCIdDepart = uiIdDepart;
    uiARCIdArrive = uiIdArrive;
    ARCData = Data;
}

/*************************************************
* methode : ARCLireIdDepart
* ***********************************************
* Entree : Rien
* Necessite : Rien
* Sortie : uiARCIdDepart, naturel
* Entraine : Retournes l'id de l'arc de Depart
*************************************************
*/
template <typename TData> unsigned int TArc<TData>::ARCLireIdDepart() { return uiARCIdDepart; }

/*************************************************
* methode : ARCLireIdArrive
* ***********************************************
* Entree : Rien
* Necessite : Rien
* Sortie : uiARCIdArrive, naturel
* Entraine : Retournes l'id de l'arc de Depart
*************************************************
*/
template <typename TData> unsigned int TArc<TData>::ARCLireIdArrive() { return uiARCIdArrive; }

/*************************************************
* methode : ARCLireData
* ***********************************************
* Entree : Rien
* Necessite : Rien
* Sortie : ARCData, TData
* Entraine : Retournes la donnee de l'arc
*************************************************
*/
template <typename TData> TData TArc<TData>::ARCLireData() { return ARCData; }

/*************************************************
* methode : ARCModifierIdArrive
* ***********************************************
* Entree : uiNvIdArrive, naturel, l'id du nouvel
            arc d'arrive
* Necessite : Rien
* Sortie : Rien
* Entraine : Modifie l'arc d'arrive
*************************************************
*/
template <typename TData> void TArc<TData>::ARCModifierIdArrive(unsigned int uiNvIdArrive) { uiARCIdArrive = uiNvIdArrive; }

/*************************************************
* methode : ARCModifierIdDepart
* ***********************************************
* Entree : uiNvIdDepart, naturel, l'id du nouvel
*            arc de depart
* Necessite : Rien
* Sortie : Rien
* Entraine : Modifie l'arc de depart
*************************************************
*/
template <typename TData> void TArc<TData>::ARCModifierIdDepart(unsigned int uiNvIdDepart) { uiARCIdDepart = uiNvIdDepart; }

/*************************************************
* methode : ARCModifierData
* ***********************************************
* Entree : newData, TData, la nouvelle donnee
* Necessite : Rien
* Sortie : Rien
* Entraine : Modifie la donnee de l'arc
*************************************************
*/
template <typename TData> void TArc<TData>::ARCModifierData(TData &nvData) { ARCData = nvData; }

/*************************************************
* methode : operator==
* ************************************************
* Entree : un arc
* Necessite : Rien
* Sortie : Booleen
* Entraine : Compare si deux arcs sont egaux
*               Vrai si ils sont egaux, 
*               Faux sinon
* ***********************************************
*/
template <typename TData> bool TArc<TData>::operator==(const TArc &tArc) const
{
    if (uiARCIdDepart == tArc.uiARCIdDepart && uiARCIdArrive == tArc.uiARCIdArrive && ARCData == tArc.ARCData) return true;
    return false;
}