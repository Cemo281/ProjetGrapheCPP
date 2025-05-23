#include "PArc.hpp"
#include <iostream>

using namespace std;

/*************************************************
* PArc
* ***********************************************
* Entree : uiIdDepart, naturel, sommet de depart
*          uiIdArrive, naturel, sommet d'arrive
* Necessite : Rien
* Sortie : Rien
* Entraine : Creer un arc a partir de l'id de
*            deux sommets
*************************************************
*/
template <typename TData> PArc<TData>::PArc(unsigned int uiIdDepart, unsigned int uiIdArrive)
{
    uiARCIdDepart = uiIdDepart;
    uiARCIdArrive = uiIdArrive;
}

/*************************************************
* PArc
* ***********************************************
* Entree : uiIdDepart, naturel, sommet de depart
*          uiIdArrive, naturel, sommet d'arrive
*          tData, TData, la donnee de l'arc
* Necessite : Rien
* Sortie : Rien
* Entraine : Creer un arc a partir de l'id de
*            deux sommets et d'une donnee
*************************************************
*/
template <typename TData> PArc<TData>::PArc(unsigned int uiIdDepart, unsigned int uiIdArrive, TData tData)
{
    uiARCIdDepart = uiIdDepart;
    uiARCIdArrive = uiIdArrive;
    ARCData = tData;
}

/*************************************************
* PArc
* ***********************************************
* Entree : ARCParam
* Necessite : Rien
* Sortie : Rien
* Entraine : Cree un nouvel arc en copiant un autre
*************************************************
*/
template <typename TData> PArc<TData>::PArc(const PArc<TData>& ARCParam)
{
    uiARCIdDepart = ARCParam.uiARCIdDepart;
    uiARCIdArrive = ARCParam.uiARCIdArrive;
    ARCData = ARCParam.ARCData;
}

/*************************************************
* METHODE : ARCLireIdDepart
* ***********************************************
* Entree : Rien
* Necessite : Rien
* Sortie : uiARCIdDepart, naturel
* Entraine : Retournes l'id du sommet de Depart
*************************************************
*/
template <typename TData> unsigned int PArc<TData>::ARCLireIdDepart() const { return uiARCIdDepart; }

/*************************************************
* METHODE : ARCLireIdArrive
* ***********************************************
* Entree : Rien
* Necessite : Rien
* Sortie : uiARCIdArrive, naturel
* Entraine : Retournes l'id du sommet de Depart
*************************************************
*/
template <typename TData> unsigned int PArc<TData>::ARCLireIdArrive() const { return uiARCIdArrive; }
  
/*************************************************
* METHODE : ARCLireData
* ***********************************************
* Entree : Rien
* Necessite : Rien
* Sortie : ARCData, TData
* Entraine : Retournes la donnee de l'arc
*************************************************
*/
template <typename TData> TData PArc<TData>::ARCLireData() const { return ARCData; }

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
template <typename TData> void PArc<TData>::ARCModifierIdArrive(unsigned int uiNvIdArrive) { uiARCIdArrive = uiNvIdArrive; }

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
template <typename TData> void PArc<TData>::ARCModifierIdDepart(unsigned int uiNvIdDepart) { uiARCIdDepart = uiNvIdDepart; }

/*************************************************
* METHODE : ARCModifierData
* ***********************************************
* Entree : tNwData, TData, la nouvelle donnee
* Necessite : Rien
* Sortie : Rien
* Entraine : Modifie la donnee de l'arc
*************************************************
*/
template <typename TData> void PArc<TData>::ARCModifierData(TData tNvData) { ARCData = tNvData; }

/*************************************************
* METHODE : operator==
* ************************************************
* Entree : ptArc, un pointeur vers l'arc
* Necessite : Rien
* Sortie : Booleen
* Entraine : Compare si deux arcs sont egaux
*               Vrai si ils sont egaux, 
*               Faux sinon
* ***********************************************
*/
template <typename TData> bool PArc<TData>::operator==(const PArc* ptArc) const
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
template <typename TData> void PArc<TData>::ARCInverser()
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
* Entraine : Affiches l'arc dans la console sous la forme suivante :
*            Arc <idDepart> -> <idArrive> : <data>
* ***********************************************
*/
template <typename TData> void PArc<TData>::ARCAfficher()
{
    cout << "Arc " << uiARCIdDepart << " -> " << uiARCIdArrive << ": ";
    if (ARCData != 0) {
        cout << ARCData;
    }
    cout << endl;
}

/*************************************************
* OPERATEUR : operator=
* ***********************************************
* Entree : ARCParam, une r�f�rence vers un autre arc
* Necessite : Rien
* Sortie : R�f�rence vers *this
* Entraine : Affecte les valeurs d'un autre arc � celui-ci
*************************************************
*/
template <typename TData> PArc<TData>& PArc<TData>::operator=(const PArc<TData>& ARCParam)
{
    if (this != &ARCParam) {
        uiARCIdDepart = ARCParam.uiARCIdDepart;
        uiARCIdArrive = ARCParam.uiARCIdArrive;
        ARCData = ARCParam.ARCData;
    }
    return *this;
}
