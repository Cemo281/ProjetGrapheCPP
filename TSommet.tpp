#include "TSommet.hpp"
#include "TArc.hpp"

/************************************************
* METHODE : SOMLireId
* ***********************************************
* Entree : Rien
* Necessite : Rien
* Sortie : Rien
* Entraine : Retournes l'id du sommet
*************************************************
*/
template <typename TData> unsigned int TSommet<TData>::SOMLireId() { return uiSOMId; }

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
* Sortie : Rien
* Entraine : Lit la donnee du sommet
*************************************************
*/
template <typename TData> TData TSommet<TData>::SOMLireData() { return SOMData; }

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
template <typename TData> void TSommet<TData>::SOMAjouterArcPart(TArc<TData> &pArcPart) { vSOMLstArcPartant.push_back(pArcPart); }

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
template <typename TData> void TSommet<TData>::SOMAjouterArcArr(TArc<TData> &pArcArr) { vSOMLstArcArrivant.push_back(pArcArr); }

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
template <typename TData> TArc<TData> TSommet<TData>::SOMLireArcPartant(int pos) { return vSOMLstArcPartant.at(pos); }

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
template <typename TData> TArc<TData> TSommet<TData>::SOMLireArcArrivant(int pos) { return vSOMLstArcArrivant.at(pos); }

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
template <typename TData> bool TSommet<TData>::operator==(const TSommet &tSommet) const
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
template <typename TData> bool TSommet<TData>::EstDansLstPart(TArc<TData> &tArcPart) {
	int iBoucle;
	for (iBoucle = 0; iBoucle < vSOMLstArcPartant.size(); iBoucle++)
	{
		if (vSOMLstArcPartant.at(iBoucle) == tArcPart)
		{
			return true;
		}
	}
	return false;
}

/************************************************
* METHODE : EstDansLstArrivant
* ***********************************************
* Entree : tArcArr, un pointeur vers l'arc arrivant au sommet
* Necessite : rien
* Sortie : un booleen
* Entraine : Verifie si le sommet existe deja 
				dans la liste des sommets arrivant
* *************************************************
*/
template <typename TData> bool TSommet<TData>::EstDansLstArrivant(TArc<TData> &tArcArr) {
	int iBoucle;
	for (iBoucle = 0; iBoucle < vSOMLstArcArrivant.size(); iBoucle++)
	{
		if (vSOMLstArcArrivant.at(iBoucle) == tArcArr)
		{
			return true;
		}
	}
	return false;
}