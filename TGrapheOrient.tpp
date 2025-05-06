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

    TArc<TData>* ptARCTmp;
    TSommet<TData>* ptSOMTmp;

    tGROData = GROParam.tGROData;

    for (uiBoucle = 0; uiBoucle < GROParam.vGROLstArc.size(); uiBoucle++) {
        ptARCTmp = new TArc<TData>(*(GROParam.vGROLstArc.at(uiBoucle)));
        vGROLstArc.push_back(ptARCTmp);
    }
    for (uiBoucle = 0; uiBoucle < GROParam.vGROLstSommet.size(); uiBoucle++) {
        ptSOMTmp = new TSommet<TData>(*(GROParam.vGROLstSommet.at(uiBoucle)));
        vGROLstSommet.push_back(ptSOMTmp);
    }
}

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

/***************************************************************************************************************************
* METHODE : GROSupprimerSommet()
* **************************************************************************************************************************
* Entree: ptSommet,un pointeur vers le sommet a supprimer
* Necessite : Rien
* Sortie: Rien
* Entraine: Supprime le sommet du graphe oriente
****************************************************************************************************************************
*/
template<typename TData> void TGrapheOrient<TData>::GROSupprimerSommet(TSommet<TData>* ptSommet) {
    unsigned int uiBoucle;

    // Verifier si le sommet est dans le graphe
    if (this->GROSOMEstDansGraphe(ptSommet) == false) {
        return;
    }

    for (uiBoucle = 0; uiBoucle < vGROLstArc.size(); uiBoucle++) {
        // Suppressions des arcs qui partent du sommet
        if (vGROLstArc.at(uiBoucle)->ARCLireIdDepart() == ptSommet->SOMLireId()) {
            vGROLstArc.erase(vGROLstArc.begin() + uiBoucle);
            uiBoucle--;
        // Suppressuibs des arcs arrivant au sommet
        } else if (vGROLstArc.at(uiBoucle)->ARCLireIdArrive() == ptSommet->SOMLireId()) {
            vGROLstArc.erase(vGROLstArc.begin() + uiBoucle);
            uiBoucle--;   
        }
    }

    // Supprimer le sommet de la liste des sommets
    for (uiBoucle = 0; uiBoucle < vGROLstSommet.size(); uiBoucle++) {
        if (*(vGROLstSommet.at(uiBoucle)) == ptSommet) {
            vGROLstSommet.erase(vGROLstSommet.begin() + uiBoucle);
            return;
        }
    }
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
* METHODE : GROSupprimerArc()
* *************************************************************************************************************************
* Entree: ptArc, un pointeur vers l'arc a supprimer
* Necessite : Rien
* Sortie: Rien
* Entraine: Supprimes l'arc du graphe oriente
***************************************************************************************************************************
*/
template <typename TData> void TGrapheOrient<TData>::GROSupprimerArc(TArc<TData>* ptArc) {
    unsigned int uiBoucle;
    // Verifier si l'arc est dans le graphe
    if (this->GROARCEstDansGraphe(ptArc) == false) {
        return;
    }
    for (uiBoucle = 0; uiBoucle < vGROLstArc.size(); uiBoucle++) {
        if (*(vGROLstArc.at(uiBoucle)) == ptArc) {
            vGROLstArc.erase(vGROLstArc.begin() + uiBoucle);
            return;
        }
    }
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
* METHODE : GROSOMEstDansGraphe
* **************************************************************************************************************************
* Entree : ptSommet, un pointeur vers le sommet a verifier
* Necessite : Rien
* Sortie : Booleen
* Entraine : Verifie si le sommet appartient au graphe
* **************************************************************************************************************************
*/
template <typename TData> bool TGrapheOrient<TData>::GROSOMEstDansGraphe(TSommet<TData>* ptSommet) {
    unsigned int uiBoucle;

    if (vGROLstSommet.size() == 0) {
        return false;
    }

    for (uiBoucle = 0; uiBoucle < vGROLstSommet.size(); uiBoucle++) {
        if (*(vGROLstSommet.at(uiBoucle)) == ptSommet) {
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

    if (vGROLstArc.size() == 0) {
        return false;
    }

    for (uiBoucle = 0; uiBoucle < vGROLstArc.size(); uiBoucle++) {
        if (*(vGROLstArc.at(uiBoucle)) == ptArc) {
            return true;
        }
    }
    return false;
}

/***************************************************************************************************************************
* METHODE : GROInverser
* **************************************************************************************************************************
* Entree : Rien
* Necessite : Rien
* Sortie : Une copie du graphe oriente inverse
* Entraine : Inverse le graphe oriente, c'est a dire inverse tous ses arcs et ses sommets
* ***************************************************************************************************************************
*/
template<typename TData> TGrapheOrient<TData>* TGrapheOrient<TData>::GROInverser() {
    unsigned int uiBoucle;
    TGrapheOrient<TData>* ptGROInverse = new TGrapheOrient<TData>(*this);

    for (uiBoucle = 0; uiBoucle < vGROLstArc.size(); uiBoucle++) {
        ptGROInverse->vGROLstArc.at(uiBoucle)->ARCInverser();
    }
    for (uiBoucle = 0; uiBoucle < vGROLstSommet.size(); uiBoucle++) {
        ptGROInverse->vGROLstSommet.at(uiBoucle)->SOMInverser();
    }
    return ptGROInverse;
}

/***************************************************************************************************************************
* METHODE : GROAfficher
* **************************************************************************************************************************
* Entree : Rien
* Necessite : Rien
* Sortie : Rien
* Entraine : Affiches le graphe oriente dans la console
* ***************************************************************************************************************************
*/
template<typename TData> void TGrapheOrient<TData>::GROAfficher() {
    unsigned int uiBoucle;

    if (vGROLstArc.size() == 0 || vGROLstSommet.size() == 0) {
        throw runtime_error("Le graphe est vide");
    }

    cout << "Liste des sommets : " << endl;
    for (uiBoucle = 0; uiBoucle < vGROLstSommet.size(); uiBoucle++) {
        cout << "Sommet " << vGROLstSommet.at(uiBoucle)->SOMLireId() << ": ";

        if (vGROLstSommet.at(uiBoucle)->SOMLireData() != nullptr) {
            cout << vGROLstSommet.at(uiBoucle)->SOMLireData();
        }
        cout << endl;
    }
    cout << "Liste des arcs : " << endl;
    for (uiBoucle = 0; uiBoucle < vGROLstArc.size(); uiBoucle++) {
        vGROLstArc.at(uiBoucle)->ARCAfficher();    
    }
}

/***************************************************************************************************************************
* METHODE : GROFinaliser
* **************************************************************************************************************************
* Entree : Rien
* Necessite : Rien
* Sortie : Rien
* Entraine : Affiches le graphe oriente dans la console
* ***************************************************************************************************************************
*/
template<typename TData> void TGrapheOrient<TData>::GROFinaliser() {
    unsigned int uiIndexSommet, uiIndexArc;
    TArc<TData>* ptArc;
    TSommet<TData>* ptSommet;

    if (vGROLstArc.size() == 0 || vGROLstSommet.size() == 0) {
        throw runtime_error("Le graphe est vide");
    }

    for (uiIndexArc = 0; uiIndexArc < vGROLstArc.size(); uiIndexArc++) {
        ptArc = vGROLstArc.at(uiIndexArc);

        for (uiIndexSommet = 0; uiIndexSommet < vGROLstSommet.size(); uiIndexSommet++) {
            ptSommet = vGROLstSommet.at(uiIndexSommet);

            if (ptArc->ARCLireIdDepart() == ptSommet->SOMLireId()) {
                ptSommet->SOMAjouterArcPart(ptArc);
            }
            if (ptArc->ARCLireIdArrive() == ptSommet->SOMLireId()) {
                ptSommet->SOMAjouterArcArr(ptArc);
            }
        }
    }
}