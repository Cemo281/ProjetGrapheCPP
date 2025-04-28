#include "TArc.hpp"
#include "TSommet.hpp"
#include "TGrapheOrient.hpp"

using namespace std;

/**************************************************************************************************************************
* TGrapheOrient
* *************************************************************************************************************************
* Entree: Le graphe oriente a copier
* Necessite : Rien
* Sortie: Rien
* Entraine: Creer un graphe oriente a partir d'un autre graphe oriente
***************************************************************************************************************************
*/
template<typename TData> TGrapheOrient<TData>::TGrapheOrient(const TGrapheOrient<TData>& GROParam )
{
    unsigned int uiBoucle;

    vGROLstArc = vector<TArc<TData>>();
    vGROLstSommet = new vector<TSommet<TData>>();
    for (uiBoucle = 0; uiBoucle < GROParam.vGROLstArc.size(); uiBoucle++) {
        vGROLstArc.push_back(GROParam.vGROLstArc.at(uiBoucle));
    }
    for (uiBoucle = 0; uiBoucle < GROParam.vGROLstSommet.size(); uiBoucle++) {
        vGROLstSommet.push_back(GROParam.vGROLstSommet.at(uiBoucle));
    }
};

/***************************************************************************************************************************
* METHODE : GROAjouterSommet()
* **************************************************************************************************************************
* Entree: tSommet(référence vers le sommet a verifier)
* Necessite : Rien
* Sortie: Rien
* Entraine: Ajoute le sommet au graphe orienté
****************************************************************************************************************************
*/
template<typename TData> void TGrapheOrient<TData>::GROAjouterSommet(TSommet<TData> &pSommet) {
    vGROLstSommet.push_back(tSommet);
}

/**************************************************************************************************************************
* METHODE : GROAjouterArc()
* *************************************************************************************************************************
* Entree: tArc, l'arc a ajouter
* Necessite : Rien
* Sortie: Rien
* Entraine: Ajoute l'arc au graphe
***************************************************************************************************************************
*/
template <typename TData> void TGrapheOrient<TData>::GROAjouterArc(TArc<TData> &tArc) {
    vGROLstArc.push_back(tArc);
}

/***************************************************************************************************************************
* METHODE : SOMEstDansGraphe
* **************************************************************************************************************************
* Entree : tSommet, le sommet a verifier
* Necessite : Rien
* Sortie : Booleen
* Entraine : Verifie si le sommet appartient au graphe
* **************************************************************************************************************************
*/
template <typename TData> bool TGrapheOrient<TData>::GROSOMEstDansGraphe(TSommet<TData> &tSommet) {
    unsigned int uiBoucle;

    for (uiBoucle = 0; uiBoucle < vGROLstSommet.size(); uiBoucle++) {
        if (vGROLstSommet.at(uiBoucle) == tSommet) {
            return true;
        }
    }
    return false;
}

/***************************************************************************************************************************
* METHODE : GROARCEstDansGraphe
* **************************************************************************************************************************
* Entree : tArc, l'arc a verifier
* Necessite : Rien
* Sortie : Booleen
* Entraine : Verifie si l'arc appartient au graphe
***************************************************************************************************************************
*/
template <typename TData> bool TGrapheOrient<TData>::GROARCEstDansGraphe(TArc<TData> &tArc) {
    int uiBoucle;

    for (uiBoucle = 0; uiBoucle < vGROLstArc; uiBoucle++) {
        if (vGROLstArc.at(uiBoucle) == tArc) {
            return true;
        }
    }
    return false;
}