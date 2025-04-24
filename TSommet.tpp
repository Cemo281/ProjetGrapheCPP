#include "TSommet.hpp"
#include "TArc.hpp"

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