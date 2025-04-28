#include "TSommet.hpp"
#include "TArc.hpp"
#include <vector>

using namespace std;

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
* Entree : pArcPart, l'arc a ajouter
* Necessite : Rien
* Sortie : Rien
* Entraine : Ajoutes un arc a la liste des
*               arcs partant du sommet
*************************************************
*/
template <typename TData> void TSommet<TData>::SOMAjouterArcPart(TArc<TData>* ptArcPart) { vSOMLstArcPartant.push_back(ptArcPart); }

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
* Entree : pArcArr, l'arc a ajouter
* Necessite : Rien
* Sortie : Rien
* Entraine : Ajoutes un arc a la liste des
*               arcs arrivant au sommet
*************************************************
*/
template <typename TData> void TSommet<TData>::SOMAjouterArcArr(TArc<TData>* ptArcArr) { vSOMLstArcArrivant.push_back(ptArcArr); }

/************************************************
* METHODE : SOMSupprimerArcArr
* ***********************************************
* Entree : ptArcArr, l'arc a ajouter
* Necessite : Rien
* Sortie : Rien
* Entraine : Ajoutes un arc a la liste des
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
* Necessite : rien
* Sortie : un booleen
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
* Entree : ptArcPart, un pointeur vers l'arc partant du sommet
* Necessite : rien
* Sortie : un booleen
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
* Entree : ptArcArr, un pointeur vers l'arc arrivant au sommet
* Necessite : rien
* Sortie : un booleen
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
