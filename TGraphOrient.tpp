#include "TArc.hpp"
#include "TSommet.hpp"
#include "TGraphOrient.hpp"

using namespace std;

/**************************************************************************************************************************
* TGraphOrient
* *************************************************************************************************************************
* Entree: Le graphe oriente a copier
* Necessite : Rien
* Sortie: Rien
* Entraine: Initialise un graphe oriente a partir d'un autre graphe oriente
***************************************************************************************************************************
*/
template<typename TData> TGraphOrient<TData>::TGraphOrient(const TGraphOrient<TData>& GROParam)
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
* Sortie: tGROData, TData
* Entraine: Retournes les donnees du graphe
***************************************************************************************************************************
*/
template<typename TData> TData TGraphOrient<TData>::GROLireData() const { return tGROData; }

/**************************************************************************************************************************
* METHODE : GROModifierData
* *************************************************************************************************************************
* Entree: tNvData, les nouvelles donnees du graphe
* Necessite : Rien
* Sortie: Rien
* Entraine: Modifie les donnees du graphe par tNvData
***************************************************************************************************************************
*/
template<typename TData> void TGraphOrient<TData>::GROModiferData(TData tNvData) { tGROData = tNvData; }

/***************************************************************************************************************************
* METHODE : GROAjouterSommet
* **************************************************************************************************************************
* Entree: ptSommet, un pointeur vers le sommet a ajouter
* Necessite : Rien
* Sortie: Rien
* Entraine: Ajoute le sommet au graphe oriente
****************************************************************************************************************************
*/
template<typename TData> void TGraphOrient<TData>::GROAjouterSommet(TSommet<TData>* ptSommet) {
    if (this->GROSOMEstDansGraphe(ptSommet) == true) {
        return;
    }
    
    vGROLstSommet.push_back(ptSommet);
}

/***************************************************************************************************************************
* METHODE : GROSupprimerSommet
* **************************************************************************************************************************
* Entree: ptSommet, un pointeur vers un sommet
* Necessite : Rien
* Sortie: Rien
* Entraine: Supprimes le sommet du graphe oriente
****************************************************************************************************************************
*/
template<typename TData> void TGraphOrient<TData>::GROSupprimerSommet(TSommet<TData>* ptSommet) {
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
        // Suppressions des arcs arrivant au sommet
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

    delete ptSommet;
}

/**************************************************************************************************************************
* METHODE : GROAjouterArc()
* *************************************************************************************************************************
* Entree: ptArc, un pointeur vers un arc
* Necessite : Rien
* Sortie: Rien
* Entraine: Ajoute l'arc au graphe oriente
***************************************************************************************************************************
*/
template <typename TData> void TGraphOrient<TData>::GROAjouterArc(TArc<TData>* ptArc) {
    if (this->GROARCEstDansGraphe(ptArc) == true) {
        return;
    }
    if (this->GROSOMEstDansGraphe(ptArc->ARCLireIdDepart()) == false && this->GROSOMEstDansGraphe(ptArc->ARCLireIdArrive()) == false) {
        cout << "Erreur : Arc non ajoute" << endl;
        cout << "Les sommets " << ptArc->ARCLireIdDepart() << " et " << ptArc->ARCLireIdArrive() << " n'existent pas dans le graphe." << endl;
        return;
    } else if (this->GROSOMEstDansGraphe(ptArc->ARCLireIdDepart()) == false) {
        cout << "Erreur : Arc non ajoute" << endl;
        cout << "Le sommet " << ptArc->ARCLireIdDepart() << " n'existe pas dans le graphe." << endl;
        return;
    } else if (this->GROSOMEstDansGraphe(ptArc->ARCLireIdArrive()) == false) {
        cout << "Erreur : Arc non ajoute" << endl;
        cout << "Le sommet " << ptArc->ARCLireIdArrive() << " n'existe pas dans le graphe." << endl;
        return;
    }

    vGROLstArc.push_back(ptArc);
}

/**************************************************************************************************************************
* METHODE : GROSupprimerArc()
* *************************************************************************************************************************
* Entree: ptArc, un pointeur vers un arc
* Necessite : Rien
* Sortie: Rien
* Entraine: Supprimes l'arc du graphe oriente
***************************************************************************************************************************
*/
template <typename TData> void TGraphOrient<TData>::GROSupprimerArc(TArc<TData>* ptArc) {
    unsigned int uiIndexSommet, uiIndexArc;
    // Verifier si l'arc est dans le graphe
    if (this->GROARCEstDansGraphe(ptArc) == false) {
        return;
    }

    for (uiIndexArc = 0; uiIndexArc < vGROLstArc.size(); uiIndexArc++) {
        if (*(vGROLstArc.at(uiIndexArc)) == ptArc) {
            vGROLstArc.erase(vGROLstArc.begin() + uiIndexArc);
            return;
        }
    }

    for (uiIndexSommet = 0; uiIndexSommet < vGROLstSommet.size(); uiIndexSommet++) {
        // On supprime l'arc si il est dans la liste des arcs partant du sommet pour chacun des sommets
        if (vGROLstSommet.at(uiIndexSommet)->SOMEstDansLstPart(ptArc)) { 
            vGROLstSommet.at(uiIndexSommet)->SOMSupprimerArcPart(ptArc);
        }
        // On supprime l'arc si il est dans la liste des arcs arrivant au sommet pour chacun des sommets
        if (vGROLstSommet.at(uiIndexSommet)->SOMEstDansLstArrivant(ptArc)) {
            vGROLstSommet.at(uiIndexSommet)->SOMSupprimerArcArr(ptArc);
        }
    }

    delete ptArc;
}

/**************************************************************************************************************************
* METHODE : GROLireArc
* *************************************************************************************************************************
* Entree: uiPos, la position de l'arc a lire
* Necessite : Rien
* Sortie: Un pointeur vers l'arc a la position uiPos
* Entraine: Renvoie l'arc a la position iPos
***************************************************************************************************************************
*/
template <typename TData> TArc<TData>* TGraphOrient<TData>::GROLireArc(unsigned int uiPos)
{
    if (uiPos < vGROLstArc.size()) {
        return vGROLstArc.at(uiPos);
    }
    else {
        throw out_of_range("Position invalide dans la liste des arcs.");
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
template <typename TData> TSommet<TData>* TGraphOrient<TData>::GROLireSommet(unsigned int uiPos)
{
    if (uiPos < vGROLstSommet.size()) {
        return vGROLstSommet.at(uiPos);
    }
    else {
        throw out_of_range("Position invalide dans la liste des sommets.");
    }
}

/***************************************************************************************************************************
* METHODE : GROSOMEstDansGraphe
* **************************************************************************************************************************
* Entree : uiIdSommet, l'id du sommet
* Necessite : Rien
* Sortie : Booleen
* Entraine : Verifie si le sommet appartient au graphe oriente
* **************************************************************************************************************************
*/
template <typename TData> bool TGraphOrient<TData>::GROSOMEstDansGraphe(unsigned int uiIdSommet) {
    unsigned int uiBoucle;

    if (vGROLstSommet.size() == 0) {
        return false;
    }

    for (uiBoucle = 0; uiBoucle < vGROLstSommet.size(); uiBoucle++) {
        if (vGROLstSommet.at(uiBoucle)->SOMLireId() == uiIdSommet) {
            return true;
        }
    }
    
    return false;
}

/***************************************************************************************************************************
* METHODE : GROSOMEstDansGraphe
* **************************************************************************************************************************
* Entree : ptSommet ,un pointeur un sommet
* Necessite : Rien
* Sortie : Booleen
* Entraine : Verifie si le sommet appartient au graphe oriente
* **************************************************************************************************************************
*/
template <typename TData> bool TGraphOrient<TData>::GROSOMEstDansGraphe(TSommet<TData>* ptSommet) {
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
* Entree : ptArc, un pointeur vers un arc
* Necessite : Rien
* Sortie : Booleen
* Entraine : Verifie si l'arc appartient au graphe
***************************************************************************************************************************
*/
template <typename TData> bool TGraphOrient<TData>::GROARCEstDansGraphe(TArc<TData>* ptArc) {
    unsigned int uiBoucle;

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
* Sortie : Un pointeur vers une copie du graphe oriente mais qui est inverse
* Entraine : Inverse le graphe oriente, c'est à dire inverse tous ses arcs et ses sommets
* ***************************************************************************************************************************
*/
template<typename TData> TGraphOrient<TData>* TGraphOrient<TData>::GROInverser() {
    unsigned int uiBoucle;
    TGraphOrient<TData>* ptGROInverse = new TGraphOrient<TData>(*this);

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
template<typename TData> void TGraphOrient<TData>::GROAfficher() {
    unsigned int uiBoucle;

    if (vGROLstArc.size() == 0 || vGROLstSommet.size() == 0) {
        throw runtime_error("Le graphe est vide");
    }

    cout << "=== Liste des sommets ===" << endl << endl;

    for (uiBoucle = 0; uiBoucle < vGROLstSommet.size(); uiBoucle++) {
        cout << "Sommet " << vGROLstSommet.at(uiBoucle)->SOMLireId() << ": ";

        if (vGROLstSommet.at(uiBoucle)->SOMLireData() != nullptr) {
            cout << vGROLstSommet.at(uiBoucle)->SOMLireData();
        }
        cout << endl;
    }
    cout << endl;
    cout << "==========================" << endl << endl;
    cout << "===== Liste des Arcs =====" << endl << endl;

    for (uiBoucle = 0; uiBoucle < vGROLstArc.size(); uiBoucle++) {
        vGROLstArc.at(uiBoucle)->ARCAfficher();    
    }
    cout << endl;
    cout << "==========================" << endl << endl;
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
template<typename TData> void TGraphOrient<TData>::GROFinaliser() {
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