#include "TArc.hpp"
#include <iostream>

using namespace std;

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
template <typename TData> TArc<TData>::TArc(unsigned int uiIdDepart, unsigned int uiIdArrive)
{
    uiARCIdDepart = uiIdDepart;
    uiARCIdArrive = uiIdArrive;
}

/*************************************************
* METHODE : ARCLireIdDepart
* ***********************************************
* Entree : Rien
* Necessite : Rien
* Sortie : uiARCIdDepart, naturel
* Entraine : Retournes l'id de l'arc de Depart
*************************************************
*/
template <typename TData> unsigned int TArc<TData>::ARCLireIdDepart() const { return uiARCIdDepart; }

/*************************************************
* METHODE : ARCLireIdArrive
* ***********************************************
* Entree : Rien
* Necessite : Rien
* Sortie : uiARCIdArrive, naturel
* Entraine : Retournes l'id de l'arc de Depart
*************************************************
*/
template <typename TData> unsigned int TArc<TData>::ARCLireIdArrive() const { return uiARCIdArrive; }
  
/*************************************************
* METHODE : ARCLireData
* ***********************************************
* Entree : Rien
* Necessite : Rien
* Sortie : ARCData, TData
* Entraine : Retournes la donnee de l'arc
*************************************************
*/
template <typename TData> TData TArc<TData>::ARCLireData() const { return ARCData; }

/*************************************************
* METHODE : ARCModifierIdArrive
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
* METHODE : ARCModifierIdDepart
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
* METHODE : ARCModifierData
* ***********************************************
* Entree : newData, TData, la nouvelle donnee
* Necessite : Rien
* Sortie : Rien
* Entraine : Modifie la donnee de l'arc
*************************************************
*/
template <typename TData> void TArc<TData>::ARCModifierData(TData &nvData) { ARCData = nvData; }

/*************************************************
* METHODE : operator==
* ************************************************
* Entree : un arc
* Necessite : Rien
* Sortie : Booleen
* Entraine : Compare si deux arcs sont egaux
*               Vrai si ils sont egaux, 
*               Faux sinon
* ***********************************************
*/
template <typename TData> bool TArc<TData>::operator==(const TArc* ptArc) const
{
    if (uiARCIdDepart == ptArc->ARCLireIdDepart() && uiARCIdArrive == ptArc->ARCLireIdArrive() && ARCData == ptArc->ARCLireData()) return true;
    return false;
}

/*************************************************
* METHODE : ARCInverser
* ************************************************
* Entree : Rien
* Necessite : Rien
* Sortie : Rien
* Entraine : Inverse l'arc
* ***********************************************
*/
template <typename TData> void TArc<TData>::ARCInverser()
{
    unsigned int uiARCTemp = uiARCIdDepart;
    uiARCIdDepart = uiARCIdArrive;
    uiARCIdArrive = uiARCTemp;
}

/*************************************************
* METHODE : ARCAfficher
* ************************************************
* Entree : Rien
* Necessite : Rien
* Sortie : Rien
* Entraine : Affiches l'arc dans la console, son sommet de depart,
*               son sommet d'arrivee ainsi que sa donnee
* ***********************************************
*/
template <typename TData> void TArc<TData>::ARCAfficher()
{
    cout << "Arc " << uiARCIdDepart << " -> " << uiARCIdArrive << ": ";
    if (ARCData != nullptr) {
            ARCData;
    }
    cout << endl;
}