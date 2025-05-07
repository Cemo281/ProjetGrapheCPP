#include "TSommet.hpp"
#include "TArc.hpp"
#include <vector>

using namespace std;

 /************************************************
* METHODE : TSommet
* ***********************************************
* Entree : uiId, naturel, l'id du sommet
* Necessite : Rien
* Sortie : Rien
* Entraine : Cree un sommet a partir d'un id
*************************************************
*/
template <typename TData> TSommet<TData>::TSommet(unsigned int uiId) {
	uiSOMId = uiId;
}

/************************************************
* METHODE : TSommet
* ***********************************************
* Entree : SOMParam, le sommet a copier
* Necessite : Rien
* Sortie : Une copie du sommet
* Entraine : Cree un sommet a partir d'un autre sommet
*************************************************
*/
template<typename TData> TSommet<TData>::TSommet(const TSommet<TData>& SOMParam) {
	TArc<TData>* ptARCTmp;

	uiSOMId = SOMParam.uiSOMId;
	SOMData = SOMParam.SOMData;
	// Copie des arcs partant du sommet
	for (unsigned int iBoucle = 0; iBoucle < SOMParam.vSOMLstArcPartant.size(); iBoucle++)
	{
		ptARCTmp = new TArc<TData>(*(SOMParam.vSOMLstArcPartant.at(iBoucle)));
		vSOMLstArcPartant.push_back(ptARCTmp);
	}
	// Copie des arcs arrivant au sommet
	for (unsigned int iBoucle = 0; iBoucle < SOMParam.vSOMLstArcArrivant.size(); iBoucle++)
	{
		ptARCTmp = new TArc<TData>(*(SOMParam.vSOMLstArcArrivant.at(iBoucle)));
		vSOMLstArcArrivant.push_back(ptARCTmp);
	}

}

/************************************************
* METHODE : SOMLireId
* ***********************************************
* Entree : Rien
* Necessite : Rien
* Sortie : uiSOMId, naturel
* Entraine : Retournes l'id du sommet
*************************************************
*/
template <typename TData> unsigned int TSommet<TData>::SOMLireId() const { return uiSOMId; }

/************************************************
* METHODE : SOMModifierId
* ***********************************************
* Entree : uiNvId, naturel, le nouvel id
* Necessite : Rien
* Sortie : Rien
* Entraine : Cree un sommet
*************************************************
*/
template <typename TData> void TSommet<TData>::SOMModifierId(unsigned int uiNvId) { uiSOMId = uiNvId; }

/************************************************
* METHODE : SOMLireData
* ***********************************************
* Entree : Rien
* Nicessite : Rien
* Sortie : tSOMData, TData
* Entraine : Retournes la donnee du sommet
*************************************************
*/
template <typename TData> TData TSommet<TData>::SOMLireData() const { return SOMData; }

/************************************************
* METHODE : SOMModifierData
* ***********************************************
* Entree : Data, la nouvelle donnee
* Necessite : Rien
* Sortie : Rien
* Entraine : Modifie la donnee du sommet
* *************************************************
*/
template <typename TData> void TSommet<TData>::SOMModifierData(TData nvData) { SOMData = nvData; }

/************************************************
* METHODE : SOMAjouterArcPart
* ***********************************************
* Entree : ptArcPart, l'arc a ajouter
* Necessite : Rien
* Sortie : Rien
* Entraine : Ajoutes un arc de la liste des
*               arcs partant du sommet
*************************************************
*/
template <typename TData> void TSommet<TData>::SOMAjouterArcPart(TArc<TData>* ptArcPart) { vSOMLstArcPartant.push_back(ptArcPart); }

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
template <typename TData> TArc<TData>* TSommet<TData>::SOMLireArcPart(unsigned int uiPos) {
	if (uiPos < vSOMLstArcPartant.size())
		return vSOMLstArcPartant.at(uiPos);
	else
		throw out_of_range("Position invalide dans la liste des arcs partant.");
}

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
template <typename TData> TArc<TData>* TSommet<TData>::SOMLireArcArr(unsigned int uiPos) {
	if (uiPos < vSOMLstArcArrivant.size())
		return vSOMLstArcArrivant.at(uiPos);
	else
		throw out_of_range("Position invalide dans la liste des arcs arrivant.");
}

/************************************************
* METHODE : SOMSupprimerArcPart
* ***********************************************
* Entree : ptArcPart, un pointeur vers l'arc a supprimer
* Necessite : Rien
* Sortie : Rien
* Entraine : Supprimes l' arc de la liste des
*               arcs partant du sommet
*************************************************
*/
template <typename TData> void TSommet<TData>::SOMSupprimerArcPart(TArc<TData>* ptArcPart) {
	for (int iBoucle = 0; iBoucle < vSOMLstArcPartant.size(); iBoucle++)
	{
		if (vSOMLstArcPartant.at(iBoucle) == ptArcPart)
		{
			vSOMLstArcPartant.erase(vSOMLstArcPartant.begin() + iBoucle);
			return;
		}
	}
}

/************************************************
* METHODE : SOMAjouterArcArr
* ***********************************************
* Entree : ptArcArr, un pointeur vers l'arc a ajouter
* Necessite : Rien
* Sortie : Rien
* Entraine : Ajoutes un arc de la liste des
*               arcs arrivant au sommet
*************************************************
*/
template <typename TData> void TSommet<TData>::SOMAjouterArcArr(TArc<TData>* ptArcArr) { vSOMLstArcArrivant.push_back(ptArcArr); }

/************************************************
* METHODE : SOMSupprimerArcArr
* ***********************************************
* Entree : ptArcArr, l'arc a supprimer
* Necessite : Rien
* Sortie : Rien
* Entraine : Supprimes l'arc de la liste des
*               arcs arrivant au sommet
*************************************************
*/
template <typename TData> void TSommet<TData>::SOMSupprimerArcArr(TArc<TData>* ptArcArr) {
	for (int iBoucle = 0; iBoucle < vSOMLstArcArrivant.size(); iBoucle++)
	{
		if (vSOMLstArcArrivant.at(iBoucle) == ptArcArr)
		{
			vSOMLstArcArrivant.erase(vSOMLstArcArrivant.begin() + iBoucle);
			return;
		}
	}
}

/************************************************
* METHODE : operateur==
* ***********************************************
* Entree : ptSommet, un pointeur vers un sommet
* Necessite : Rien
* Sortie : Un booleen
* Entraine : Compare si deux pointeurs vers un sommet sont egaux
*               True si ils sont egaux,
*               False sinon
* ***********************************************
*/
template <typename TData> bool TSommet<TData>::operator==(const TSommet* ptSommet) const
{
	return uiSOMId == ptSommet->uiSOMId && SOMData == ptSommet->SOMData;
}

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
template <typename TData> bool TSommet<TData>::SOMEstDansLstPart(TArc<TData>* ptArcPart) {
	int iBoucle;
	for (iBoucle = 0; iBoucle < vSOMLstArcPartant.size(); iBoucle++)
	{
		if (vSOMLstArcPartant.at(iBoucle) == ptArcPart)
		{
			return true;
		}
	}
	return false;
}

/************************************************
* METHODE : SOMEstDansLstArrivant
* ***********************************************
* Entree : ptArcArr, un pointeur vers un arc
* Necessite : Rien
* Sortie : Un booleen
* Entraine : Verifie si le sommet existe deja 
				dans la liste des sommets arrivant
* *************************************************
*/
template <typename TData> bool TSommet<TData>::SOMEstDansLstArrivant(TArc<TData>* ptArcArr) {
	int iBoucle;
	for (iBoucle = 0; iBoucle < vSOMLstArcArrivant.size(); iBoucle++)
	{
		if (vSOMLstArcArrivant.at(iBoucle) == ptArcArr)
		{
			return true;
		}
	}
	return false;
}

/******************************************************************
* METHODE : SOMInverser
* *****************************************************************
* Entree : Rien
* Necessite : Rien
* Sortie : Rien
* Entraine : Inverse le sommet c'est a dire qu'il 
*			place tout les sommet arrivant dans ceux partant et vice versa
* *****************************************************************
*/
template <typename TData> void TSommet<TData>::SOMInverser() {
	vSOMLstArcPartant.swap(vSOMLstArcArrivant);
}