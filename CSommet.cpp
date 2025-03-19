#include "CSommet.h"

/************************************************
* METHODE : ~CSommet
* ***********************************************
* Entrée : Rien
* Nécessite : Rien
* Sortie : Rien
* Entraîne : Détruis un sommet
*************************************************
*/
CSommet::~CSommet() {
	for (auto arc : vSOMLstArcPartant) {
		delete arc;
	}
	for (auto arc : vSOMLstArcArrivant) {
		delete arc;
	}
	delete this;
};

/************************************************
* METHODE : SOMSupprimerArcArr
* ***********************************************
* Entrée : pArcArr, l'arc à supprimer
* Nécessite : Rien
* Sortie : Rien
* Entraîne : Supprimes un arc de la liste des
*               arcs arrivant au sommet
*************************************************
*/
int CSommet::SOMSupprimerArcPart(CArc* pArcArr)
{
	int iBoucle;
	for (iBoucle = 0; iBoucle < vSOMLstArcPartant.size(); iBoucle++)
	{
		if (vSOMLstArcPartant[iBoucle] == pArcArr)
		{
			vSOMLstArcPartant.erase(vSOMLstArcPartant.begin() + iBoucle);
			return 0;
		}
	}
	return 0;
}

/************************************************
* METHODE : SOMSupprimerArcPart
* ***********************************************
* Entrée : pArcPart, l'arc à supprimer
* Nécessite : Rien
* Sortie : Rien
* Entraîne : Supprimes un arc de la liste des
*               arcs partant du sommet
*************************************************
*/
int CSommet::SOMSupprimerArcArr(CArc* pArcPart) {
	int iBoucle;
	for (iBoucle = 0; iBoucle < vSOMLstArcArrivant.size(); iBoucle++)
	{
		if (vSOMLstArcArrivant[iBoucle] == pArcPart)
		{
			vSOMLstArcArrivant.erase(vSOMLstArcArrivant.begin() + iBoucle);
			return 0;
		}
	}
	return 0;
}