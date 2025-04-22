#include "CSommet.hpp"

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
	vSOMLstArcArrivant->clear();
	vSOMLstArcPartant->clear();

	delete vSOMLstArcArrivant;
	delete vSOMLstArcPartant;
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
* Entrée : pArcPart, l'arc à supprimer
* Nécessite : Rien
* Sortie : Rien
* Entraîne : Supprimes un arc de la liste des
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
* Entrée : pSommet, un pointeur vers l'arc partant du sommet
* Nécessite : rien
* Sortie : un booléen
* Entraîne : Vérifie si le sommet existe déjà dans
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
* Entrée : pSommet, un pointeur vers l'arc arrivant au sommet
* Nécessite : rien
* Sortie : un booléen
* Entraîne : Vérifie si le sommet existe déjà
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