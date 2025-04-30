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
template<typename TData> TGrapheOrient<TData>::TGrapheOrient(const TGrapheOrient<TData>& GROParam)
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

/**************************************************************************************************************************
* METHODE : GROLireData
* *************************************************************************************************************************
* Entree: Rien
* Necessite : Rien
* Sortie: tData, les donnees du graphe
* Entraine: Retournes les donnees du graphe
***************************************************************************************************************************
*/
template<typename TData> TData TGrapheOrient<TData>::GROLireData() { return tGROData; }

/**************************************************************************************************************************
* METHODE : GROModifierData
* *************************************************************************************************************************
* Entree: tNvData, les nouvelles donnees du graphe
* Necessite : Les données doivent être du même type que le graphe
* Sortie: tData, les donnees du graphe
* Entraine: Retournes les donnees du graphe
***************************************************************************************************************************
*/
template<typename TData> void TGrapheOrient<TData>::GROModiferData(TData tNvData) { tGROData = tNvData; }

/***************************************************************************************************************************
* METHODE : GROAjouterSommet()
* **************************************************************************************************************************
* Entree: ptSommet, un pointeur vers le sommet a ajouter
* Necessite : Rien
* Sortie: Rien
* Entraine: Ajoute le sommet au graphe oriente
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
    vGROLstArc.push_back(ptArc);
}

/**************************************************************************************************************************
* METHODE : GROLireArc
* *************************************************************************************************************************
* Entree: uiPos, la position de l'arc a lire
* Necessite : uiPos doit etre valide
* Sortie: Un pointeur vers l'arc a la position uiPos
* Entraine: Renvoie l'arc a la position uiPos
***************************************************************************************************************************
*/
template <typename TData> TArc<TData>* TGrapheOrient<TData>::GROLireArc(unsigned int uiPos) const
{
    if (uiPos < vGROLstArc.size())
        return vGROLstArc.at(uiPos);
    else
        throw out_of_range("Position invalide dans la liste des arcs.");
}

/**************************************************************************************************************************
* METHODE : GROLireArc
* *************************************************************************************************************************
* Entree: uiPos, la position de l'arc a lire
* Necessite : uiPos doit etre valide
* Sortie: Un pointeur vers l'arc a la position uiPos
* Entraine: Renvoie l'arc a la position uiPos
***************************************************************************************************************************
*/
template <typename TData> TSommet<TData>* TGrapheOrient<TData>::GROLireSommet(unsigned int uiPos) const
{
    if (uiPos < vGROLstSommet.size())
        return vGROLstSommet.at(uiPos);
    else
        throw out_of_range("Position invalide dans la liste des sommets.");
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
        if (vGROLstArc.at(uiBoucle) == ptArc) {
            return true;
        }
    }
    return false;
}

/***************************************************************************************************************************
* METHODE : GROInverser
* Entree : Rien
* Sortie : Rien
* Entraine : Inverse le graphe oriente, c'est à dire inverse tous ses arcs et ses sommets
* ***************************************************************************************************************************
*/
template<typename TData> void TGrapheOrient<TData>::GROInverser() {
    unsigned int uiBoucle;
    for (uiBoucle = 0; uiBoucle < vGROLstArc.size(); uiBoucle++) {
        vGROLstArc.at(uiBoucle)->ARCInverser();
    }
    for (uiBoucle = 0; uiBoucle < vGROLstSommet.size(); uiBoucle++) {
        vGROLstSommet.at(uiBoucle)->SOMInverser();
    }
}