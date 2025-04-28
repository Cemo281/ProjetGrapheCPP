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
* Entree: ptSommet, un pointeur vers le sommet a ajouter
* Necessite : Rien
* Sortie: Rien
* Entraine: Ajoute le sommet au graphe orienté
****************************************************************************************************************************
*/
template<typename TData> void TGrapheOrient<TData>::GROAjouterSommet(TSommet<TData>* ptSommet) {
    vGROLstSommet.push_back(ptSommet);
}

/**************************************************************************************************************************
* METHODE : GROAjouterArc()
* *************************************************************************************************************************
* Entree: ptArc, un pointeur vers l'arc a ajouter
* Necessite : Rien
* Sortie: Rien
* Entraine: Ajoute l'arc au graphe
***************************************************************************************************************************
*/
template <typename TData> void TGrapheOrient<TData>::GROAjouterArc(TArc<TData>* ptArc) {
    vGROLstArc.push_back(tArc);
}

/***************************************************************************************************************************
* METHODE : SOMEstDansGraphe
* **************************************************************************************************************************
* Entree : ptSommet, un pointeur vers le sommet a verifier
* Necessite : Rien
* Sortie : Booleen
* Entraine : Verifie si le sommet appartient au graphe
* **************************************************************************************************************************
*/
template <typename TData> bool TGrapheOrient<TData>::GROSOMEstDansGraphe(TSommet<TData>* ptSommet) {
    unsigned int uiBoucle;

    for (uiBoucle = 0; uiBoucle < vGROLstSommet.size(); uiBoucle++) {
        if (vGROLstSommet.at(uiBoucle) == ptSommet) {
            return true;
        }
    }
    return false;
}

/***************************************************************************************************************************
* METHODE : GROARCEstDansGraphe
* **************************************************************************************************************************
* Entree : ptArc, un pointeur vers l'arc a verifier
* Necessite : Rien
* Sortie : Booleen
* Entraine : Verifie si l'arc appartient au graphe
***************************************************************************************************************************
*/
template <typename TData> bool TGrapheOrient<TData>::GROARCEstDansGraphe(TArc<TData>* ptArc) {
    int uiBoucle;

    for (uiBoucle = 0; uiBoucle < vGROLstArc; uiBoucle++) {
        if (vGROLstArc.at(uiBoucle) == tArc) {
            return true;
        }
    }
    return false;
}