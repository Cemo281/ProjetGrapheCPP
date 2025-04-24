#include "TSommet.hpp"
#include "TArc.hpp"

/************************************************
* METHODE : EstDansLstPart
* ***********************************************
* Entr�e : tArcPart, un pointeur vers l'arc partant du sommet
* N�cessite : rien
* Sortie : un bool�en
* Entra�ne : V�rifie si le sommet existe d�j� dans 
*                la liste des sommets partant
* ***********************************************
*/
template <class TData> bool TSommet<TData>::EstDansLstPart(TArc<TData> &tArcPart) {
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
* Entr�e : tArcArr, un pointeur vers l'arc arrivant au sommet
* N�cessite : rien
* Sortie : un bool�en
* Entra�ne : V�rifie si le sommet existe d�j� 
				dans la liste des sommets arrivant
* *************************************************
*/
template <class TData> bool TSommet<TData>::EstDansLstArrivant(TArc<TData> &tArcArr) {
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