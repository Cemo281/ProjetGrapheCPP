#include "CSommet.hpp"

/************************************************
* METHODE : ~CSommet
* ***********************************************
* Entr�e : Rien
* N�cessite : Rien
* Sortie : Rien
* Entra�ne : D�truis un sommet
*************************************************
*/
CSommet::~CSommet() {
	vSOMLstArcArrivant->clear();
	vSOMLstArcPartant->clear();

	delete vSOMLstArcArrivant;
	delete vSOMLstArcPartant;
};

/************************************************
* METHODE : SOMSupprimerArcArr
* ***********************************************
* Entr�e : pArcArr, l'arc � supprimer
* N�cessite : Rien
* Sortie : Rien
* Entra�ne : Supprimes un arc de la liste des
*               arcs arrivant au sommet
*************************************************
*/
int CSommet::SOMSupprimerArcPart(CArc* pArcArr)
{
	int iBoucle;
	for (iBoucle = 0; iBoucle < vSOMLstArcPartant->size(); iBoucle++)
	{
		if (vSOMLstArcPartant->at(iBoucle) == pArcArr)
		{
			vSOMLstArcPartant->erase(vSOMLstArcPartant->begin() + iBoucle);
			return 0;
		}
	}
	return 0;
}

/************************************************
* METHODE : SOMSupprimerArcPart
* ***********************************************
* Entr�e : pArcPart, l'arc � supprimer
* N�cessite : Rien
* Sortie : Rien
* Entra�ne : Supprimes un arc de la liste des
*               arcs partant du sommet
*************************************************
*/
int CSommet::SOMSupprimerArcArr(CArc* pArcPart) {
	int iBoucle;
	for (iBoucle = 0; iBoucle < vSOMLstArcArrivant->size(); iBoucle++)
	{
		if (vSOMLstArcArrivant->at(iBoucle) == pArcPart)
		{
			vSOMLstArcArrivant->erase(vSOMLstArcArrivant->begin() + iBoucle);
			return 0;
		}
	}
	return 0;
}

/************************************************
* METHODE : EstDansLstPart
* ***********************************************
* Entr�e : pSommet, un pointeur vers l'arc partant du sommet
* N�cessite : rien
* Sortie : un bool�en
* Entra�ne : V�rifie si le sommet existe d�j� dans
				la liste des sommets partant
* ***********************************************
*/
bool CSommet::EstDansLstPart(CArc* pArcPart) {
	int iBoucle;
	for (iBoucle = 0; iBoucle < vSOMLstArcPartant->size(); iBoucle++)
	{
		if (vSOMLstArcPartant->at(iBoucle) == pArcPart)
		{
			return true;
		}
	}
	return false;
}

/************************************************
* METHODE : EstDansLstArrivant
* ***********************************************
* Entr�e : pSommet, un pointeur vers l'arc arrivant au sommet
* N�cessite : rien
* Sortie : un bool�en
* Entra�ne : V�rifie si le sommet existe d�j�
				dans la liste des sommets arrivant
* ***********************************************
*/
bool CSommet::EstDansLstArrivant(CArc* pArcArr) {
	int iBoucle;
	for (iBoucle = 0; iBoucle < vSOMLstArcArrivant->size(); iBoucle++)
	{
		if (vSOMLstArcArrivant->at(iBoucle) == pArcArr)
		{
			return true;
		}
	}
	return false;
}