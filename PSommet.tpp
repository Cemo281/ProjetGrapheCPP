#include "PSommet.hpp"
#include "PArc.hpp"
#include <vector>

using namespace std;

 /************************************************
* METHODE : PSommet
* ***********************************************
* Entree : uiId, naturel, l'id du sommet
* Necessite : Rien
* Sortie : Rien
* Entraine : Cree un sommet a partir d'un id
*************************************************
*/
template <typename TData> PSommet<TData>::PSommet(unsigned int uiId) {
	uiSOMId = uiId;
}

/************************************************
* METHODE : PSommet
* ***********************************************
* Entree : SOMParam, le sommet a copier
* Necessite : Rien
* Sortie : Une copie du sommet
* Entraine : Cree un sommet a partir d'un autre sommet
*************************************************
*/
template<typename TData> PSommet<TData>::PSommet(const PSommet<TData>& SOMParam) {
	PArc<TData>* ptARCTmp;
	unsigned int uiBoucle;

	uiSOMId = SOMParam.uiSOMId;
	SOMData = SOMParam.SOMData;
	// Copie des arcs partant du sommet
	for (uiBoucle = 0; uiBoucle < SOMParam.vSOMLstArcPartant.size(); uiBoucle++)
	{
		ptARCTmp = new PArc<TData>(*(SOMParam.vSOMLstArcPartant.at(uiBoucle)));
		vSOMLstArcPartant.push_back(ptARCTmp);
	}
	// Copie des arcs arrivant au sommet
	for (uiBoucle = 0; uiBoucle < SOMParam.vSOMLstArcArrivant.size(); uiBoucle++)
	{
		ptARCTmp = new PArc<TData>(*(SOMParam.vSOMLstArcArrivant.at(uiBoucle)));
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
template <typename TData> unsigned int PSommet<TData>::SOMLireId() const { return uiSOMId; }

/************************************************
* METHODE : SOMModifierId
* ***********************************************
* Entree : uiNvId, naturel, le nouvel id
* Necessite : Rien
* Sortie : Rien
* Entraine : Cree un sommet
*************************************************
*/
template <typename TData> void PSommet<TData>::SOMModifierId(unsigned int uiNvId) { uiSOMId = uiNvId; }

/************************************************
* METHODE : SOMLireData
* ***********************************************
* Entree : Rien
* Nicessite : Rien
* Sortie : tSOMData, TData
* Entraine : Retournes la donnee du sommet
*************************************************
*/
template <typename TData> TData PSommet<TData>::SOMLireData() const { return SOMData; }

/************************************************
* METHODE : SOMModifierData
* ***********************************************
* Entree : Data, la nouvelle donnee
* Necessite : Rien
* Sortie : Rien
* Entraine : Modifie la donnee du sommet
* *************************************************
*/
template <typename TData> void PSommet<TData>::SOMModifierData(TData nvData) { SOMData = nvData; }

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
template <typename TData> void PSommet<TData>::SOMAjouterArcPart(PArc<TData>* ptArcPart) { vSOMLstArcPartant.push_back(ptArcPart); }

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
template <typename TData> PArc<TData>* PSommet<TData>::SOMLireArcPart(unsigned int uiPos) {
	if (uiPos < vSOMLstArcPartant.size()) 
	{
		return vSOMLstArcPartant.at(uiPos);
	}
	else
	{
		throw out_of_range("Position invalide dans la liste des arcs partant.");
	}
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
template <typename TData> PArc<TData>* PSommet<TData>::SOMLireArcArr(unsigned int uiPos) {
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
template <typename TData> void PSommet<TData>::SOMSupprimerArcPart(PArc<TData>* ptArcPart) {
	unsigned int uiBoucle;

	for (uiBoucle = 0; uiBoucle < vSOMLstArcPartant.size(); uiBoucle++)
	{
		if (vSOMLstArcPartant.at(uiBoucle) == ptArcPart)
		{
			vSOMLstArcPartant.erase(vSOMLstArcPartant.begin() + uiBoucle);
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
template <typename TData> void PSommet<TData>::SOMAjouterArcArr(PArc<TData>* ptArcArr) { vSOMLstArcArrivant.push_back(ptArcArr); }

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
template <typename TData> void PSommet<TData>::SOMSupprimerArcArr(PArc<TData>* ptArcArr) {
	unsigned int uiBoucle;

	for (uiBoucle = 0; uiBoucle < vSOMLstArcArrivant.size(); uiBoucle++)
	{
		if (vSOMLstArcArrivant.at(uiBoucle) == ptArcArr)
		{
			vSOMLstArcArrivant.erase(vSOMLstArcArrivant.begin() + uiBoucle);
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
template <typename TData> bool PSommet<TData>::operator==(const PSommet* ptSommet) const
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
template <typename TData> bool PSommet<TData>::SOMEstDansLstPart(PArc<TData>* ptArcPart) {
	unsigned int uiBoucle;

	for (uiBoucle = 0; uiBoucle < vSOMLstArcPartant.size(); uiBoucle++)
	{
		if (vSOMLstArcPartant.at(uiBoucle) == ptArcPart)
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
template <typename TData> bool PSommet<TData>::SOMEstDansLstArrivant(PArc<TData>* ptArcArr) {
	unsigned int uiBoucle;
	for (uiBoucle = 0; uiBoucle < vSOMLstArcArrivant.size(); uiBoucle++)
	{
		if (vSOMLstArcArrivant.at(uiBoucle) == ptArcArr)
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
template <typename TData> void PSommet<TData>::SOMInverser() {
	vSOMLstArcPartant.swap(vSOMLstArcArrivant);
}

/************************************************
* METHODE : SOMAfficher
* ***********************************************
* Entree : Rien
* Necessite : Rien
* Sortie : Rien
* Entraine : Affiches le sommet dans la console sous la forme suivante :
* 			Sommet <id> : <data>
* ***********************************************
*/
template <typename TData> void PSommet<TData>::SOMAfficher() {
	cout << "Sommet " << uiSOMId << " : ";
	if (SOMData != NULL)
	{
		cout << SOMData << endl;
	}
	else
	{
		cout << " " << endl;
	}
}

/************************************************
* METHODE : SOMLireTailleArcArrivant
* ***********************************************
* Entree : Rien
* Necessite : Rien
* Sortie : Un naturel
* Entraine : Retournes la taille de la liste des arcs arrivant
* *************************************************
*/
template <typename TData> unsigned int PSommet<TData>::SOMLireTailleArcPartant() const { return vSOMLstArcPartant.size(); }

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
template <typename TData> bool PSommet<TData>::operator<(const PSommet* ptSommet) const
{
	return (SOMData < ptSommet->SOMLireData());
}