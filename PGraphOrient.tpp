#include "PArc.hpp"
#include "PSommet.hpp"
#include "PGraphOrient.hpp"
#include <queue>
#include <set>

using namespace std;

/**************************************************************************************************************************
* PGraphOrient
* *************************************************************************************************************************
* Entree: Le graphe oriente a copier
* Necessite : Rien
* Sortie: Rien
* Entraine: Initialise un graphe oriente a partir d'un autre graphe oriente
***************************************************************************************************************************
*/
template<typename TData> PGraphOrient<TData>::PGraphOrient(const PGraphOrient<TData>& GRAParam)
{
    unsigned int uiBoucle;

    PArc<TData>* ptARCTmp;
    PSommet<TData>* ptSOMTmp;

    tGRAData = GRAParam.tGRAData;

    for (uiBoucle = 0; uiBoucle < GRAParam.vGRALstArc.size(); uiBoucle++) {
        ptARCTmp = new PArc<TData>(*(GRAParam.vGRALstArc.at(uiBoucle)));
        vGRALstArc.push_back(ptARCTmp);
    }
    for (uiBoucle = 0; uiBoucle < GRAParam.vGRALstSommet.size(); uiBoucle++) {
        ptSOMTmp = new PSommet<TData>(*(GRAParam.vGRALstSommet.at(uiBoucle)));
        vGRALstSommet.push_back(ptSOMTmp);
    }
}

/**************************************************************************************************************************
* METHODE : GRALireData
* *************************************************************************************************************************
* Entree: Rien
* Necessite : Rien
* Sortie: tGRAData, TData
* Entraine: Retournes les donnees du graphe
***************************************************************************************************************************
*/
template<typename TData> TData PGraphOrient<TData>::GRALireData() const { return tGRAData; }

/**************************************************************************************************************************
* METHODE : GRAModifierData
* *************************************************************************************************************************
* Entree: tNvData, les nouvelles donnees du graphe
* Necessite : Rien
* Sortie: Rien
* Entraine: Modifie les donnees du graphe par tNvData
***************************************************************************************************************************
*/
template<typename TData> void PGraphOrient<TData>::GRAModiferData(TData tNvData) { tGRAData = tNvData; }

/***************************************************************************************************************************
* METHODE : GRAAjouterSommet
* **************************************************************************************************************************
* Entree: ptSommet, un pointeur vers le sommet a ajouter
* Necessite : Rien
* Sortie: Rien
* Entraine: Ajoute le sommet au graphe oriente
****************************************************************************************************************************
*/
template<typename TData> void PGraphOrient<TData>::GRAAjouterSommet(PSommet<TData>* ptSommet) {
    if (this->GRASOMEstDansGraphe(ptSommet) == true) {
        return;
    }
    
    vGRALstSommet.push_back(ptSommet);
}

/***************************************************************************************************************************
* METHODE : GRASupprimerSommet
* **************************************************************************************************************************
* Entree: ptSommet, un pointeur vers un sommet
* Necessite : Rien
* Sortie: Rien
* Entraine: Supprimes le sommet du graphe oriente
****************************************************************************************************************************
*/
template<typename TData> void PGraphOrient<TData>::GRASupprimerSommet(PSommet<TData>* ptSommet) {
    unsigned int uiBoucle;

    // Verifier si le sommet est dans le graphe
    if (this->GRASOMEstDansGraphe(ptSommet) == false) {
        return;
    }

    for (uiBoucle = 0; uiBoucle < vGRALstArc.size(); uiBoucle++) {
        // Suppressions des arcs qui partent du sommet
        if (vGRALstArc.at(uiBoucle)->ARCLireIdDepart() == ptSommet->SOMLireId()) {
            vGRALstArc.erase(vGRALstArc.begin() + uiBoucle);
            uiBoucle--;
        // Suppressions des arcs arrivant au sommet
        } else if (vGRALstArc.at(uiBoucle)->ARCLireIdArrive() == ptSommet->SOMLireId()) {
            vGRALstArc.erase(vGRALstArc.begin() + uiBoucle);
            uiBoucle--;   
        }
    }

    // Supprimer le sommet de la liste des sommets
    for (uiBoucle = 0; uiBoucle < vGRALstSommet.size(); uiBoucle++) {
        if (*(vGRALstSommet.at(uiBoucle)) == ptSommet) {
            vGRALstSommet.erase(vGRALstSommet.begin() + uiBoucle);
            return;
        }
    }

    delete ptSommet;
}

/**************************************************************************************************************************
* METHODE : GRAAjouterArc()
* *************************************************************************************************************************
* Entree: ptArc, un pointeur vers un arc
* Necessite : Rien
* Sortie: Rien
* Entraine: Ajoute l'arc au graphe oriente
***************************************************************************************************************************
*/
template <typename TData> void PGraphOrient<TData>::GRAAjouterArc(PArc<TData>* ptArc) {
    if (this->GRAARCEstDansGraphe(ptArc) == true) {
        return;
    }
    // Verifier si les deux sommets de l'arc sont dans le graphe
    if (this->GRASOMEstDansGraphe(ptArc->ARCLireIdDepart()) == false && this->GRASOMEstDansGraphe(ptArc->ARCLireIdArrive()) == false) {
        cout << "Erreur : Arc non ajoute" << endl;
        cout << "Les sommets " << ptArc->ARCLireIdDepart() << " et " << ptArc->ARCLireIdArrive() << " n'existent pas dans le graphe." << endl;
        return;
    // Verifier si le sommet de depart est dans le graphe
    } else if (this->GRASOMEstDansGraphe(ptArc->ARCLireIdDepart()) == false) {
        cout << "Erreur : Arc non ajoute" << endl;
        cout << "Le sommet " << ptArc->ARCLireIdDepart() << " n'existe pas dans le graphe." << endl;
        return;
    // Verifier si le sommet de depart est dans le graphe
    } else if (this->GRASOMEstDansGraphe(ptArc->ARCLireIdArrive()) == false) {
        cout << "Erreur : Arc non ajoute" << endl;
        cout << "Le sommet " << ptArc->ARCLireIdArrive() << " n'existe pas dans le graphe." << endl;
        return;
    }

    vGRALstArc.push_back(ptArc);
}

/**************************************************************************************************************************
* METHODE : GRASupprimerArc()
* *************************************************************************************************************************
* Entree: ptArc, un pointeur vers un arc
* Necessite : Rien
* Sortie: Rien
* Entraine: Supprimes l'arc du graphe oriente
***************************************************************************************************************************
*/
template <typename TData> void PGraphOrient<TData>::GRASupprimerArc(PArc<TData>* ptArc) {
    unsigned int uiIndexSommet, uiIndexArc;
    // Verifier si l'arc est dans le graphe
    if (this->GRAARCEstDansGraphe(ptArc) == false) {
        return;
    }
    // Supprimer l'arc de la liste des arcs
    for (uiIndexArc = 0; uiIndexArc < vGRALstArc.size(); uiIndexArc++) {
        if (*(vGRALstArc.at(uiIndexArc)) == ptArc) {
            vGRALstArc.erase(vGRALstArc.begin() + uiIndexArc);
            return;
        }
    }
    for (uiIndexSommet = 0; uiIndexSommet < vGRALstSommet.size(); uiIndexSommet++) {
        // On supprime l'arc si il est dans la liste des arcs partant du sommet pour chacun des sommets
        if (vGRALstSommet.at(uiIndexSommet)->SOMEstDansLstPart(ptArc)) { 
            vGRALstSommet.at(uiIndexSommet)->SOMSupprimerArcPart(ptArc);
        }
        // On supprime l'arc si il est dans la liste des arcs arrivant au sommet pour chacun des sommets
        if (vGRALstSommet.at(uiIndexSommet)->SOMEstDansLstArrivant(ptArc)) {
            vGRALstSommet.at(uiIndexSommet)->SOMSupprimerArcArr(ptArc);
        }
    }

    delete ptArc;
}

/**************************************************************************************************************************
* METHODE : GRALireArc
* *************************************************************************************************************************
* Entree: uiPos, la position de l'arc a lire
* Necessite : Rien
* Sortie: Un pointeur vers l'arc a la position uiPos
* Entraine: Renvoie l'arc a la position iPos
***************************************************************************************************************************
*/
template <typename TData> PArc<TData>* PGraphOrient<TData>::GRALireArc(unsigned int uiPos)
{
    if (uiPos < vGRALstArc.size()) {
        return vGRALstArc.at(uiPos);
    }
    else {
        throw out_of_range("Position invalide dans la liste des arcs.");
    }
}

/**************************************************************************************************************************
* METHODE : GRALireArc
* *************************************************************************************************************************
* Entree: uiPos, la position de l'arc a lire
* Necessite : uiPos doit etre valide
* Sortie: Un pointeur vers l'arc a la position uiPos
* Entraine: Renvoie l'arc a la position uiPos
***************************************************************************************************************************
*/
template <typename TData> PSommet<TData>* PGraphOrient<TData>::GRALireSommet(unsigned int uiPos)
{
    if (uiPos < vGRALstSommet.size()) {
        return vGRALstSommet.at(uiPos);
    }
    else {
        throw out_of_range("Position invalide dans la liste des sommets.");
    }
}

/***************************************************************************************************************************
* METHODE : GRASOMEstDansGraphe
* **************************************************************************************************************************
* Entree : uiIdSommet, l'id du sommet
* Necessite : Rien
* Sortie : Booleen
* Entraine : Verifie si le sommet appartient au graphe oriente
* **************************************************************************************************************************
*/
template <typename TData> bool PGraphOrient<TData>::GRASOMEstDansGraphe(unsigned int uiIdSommet) {
    unsigned int uiBoucle;
    // Si le graphe est vide, on ne peut pas trouver le sommet
    if (vGRALstSommet.size() == 0) {
        return false;
    }
    // Sinon, on parcourt la liste des sommets
    for (uiBoucle = 0; uiBoucle < vGRALstSommet.size(); uiBoucle++) {
        if (vGRALstSommet.at(uiBoucle)->SOMLireId() == uiIdSommet) {
            return true;
        }
    }
    
    return false;
}

/***************************************************************************************************************************
* METHODE : GRASOMEstDansGraphe
* **************************************************************************************************************************
* Entree : ptSommet ,un pointeur un sommet
* Necessite : Rien
* Sortie : Booleen
* Entraine : Verifie si le sommet appartient au graphe oriente
* **************************************************************************************************************************
*/
template <typename TData> bool PGraphOrient<TData>::GRASOMEstDansGraphe(PSommet<TData>* ptSommet) {
    unsigned int uiBoucle;
    // Si le graphe est vide, on ne peut pas trouver le sommet
    if (vGRALstSommet.size() == 0) {
        return false;
    }
    // Sinon, on parcourt la liste des sommets
    for (uiBoucle = 0; uiBoucle < vGRALstSommet.size(); uiBoucle++) {
        if (*(vGRALstSommet.at(uiBoucle)) == ptSommet) {
            return true;
        }
    }
    return false;
}

/***************************************************************************************************************************
* METHODE : GRAARCEstDansGraphe
* **************************************************************************************************************************
* Entree : ptArc, un pointeur vers un arc
* Necessite : Rien
* Sortie : Booleen
* Entraine : Verifie si l'arc appartient au graphe
***************************************************************************************************************************
*/
template <typename TData> bool PGraphOrient<TData>::GRAARCEstDansGraphe(PArc<TData>* ptArc) {
    unsigned int uiBoucle;
    // Si le graphe est vide, on ne peut pas trouver l'arc
    if (vGRALstArc.size() == 0) {
        return false;
    }
    // Sinon, on parcourt la liste des arcs
    for (uiBoucle = 0; uiBoucle < vGRALstArc.size(); uiBoucle++) {
        if (*(vGRALstArc.at(uiBoucle)) == ptArc) {
            return true;
        }
    }
    return false;
}

/***************************************************************************************************************************
* METHODE : GRAInverser
* **************************************************************************************************************************
* Entree : Rien
* Necessite : Rien
* Sortie : Un pointeur vers une copie du graphe oriente mais qui est inverse
* Entraine : Inverse le graphe oriente, c'est à dire inverse tous ses arcs et ses sommets
* ***************************************************************************************************************************
*/
template<typename TData> PGraphOrient<TData>* PGraphOrient<TData>::GRAInverser() {
    unsigned int uiBoucle;
    if (vGRALstArc.size() == 0 || vGRALstSommet.size() == 0) {
        throw runtime_error("Le graphe est vide");
    }
    // On cree une copie du graphe oriente
    PGraphOrient<TData>* ptGRAInverse = new PGraphOrient<TData>(*this);

    // On inverse tous les arcs et sommets de la copie
    for (uiBoucle = 0; uiBoucle < vGRALstArc.size(); uiBoucle++) {
        ptGRAInverse->vGRALstArc.at(uiBoucle)->ARCInverser();
    }
    for (uiBoucle = 0; uiBoucle < vGRALstSommet.size(); uiBoucle++) {
        ptGRAInverse->vGRALstSommet.at(uiBoucle)->SOMInverser();
    }
    return ptGRAInverse;
}

/***************************************************************************************************************************
* METHODE : GRAAfficher
* **************************************************************************************************************************
* Entree : Rien
* Necessite : Rien
* Sortie : Rien
* Entraine : Affiches le graphe oriente dans la console
* ***************************************************************************************************************************
*/
template<typename TData> void PGraphOrient<TData>::GRAAfficher() {
    unsigned int uiBoucle;

    if (vGRALstArc.size() == 0 && vGRALstSommet.size() == 0) {
        throw runtime_error("Le graphe est vide");
    }

    cout << "=== Liste des sommets ===" << endl << endl;

    for (uiBoucle = 0; uiBoucle < vGRALstSommet.size(); uiBoucle++) {
        cout << "Sommet " << vGRALstSommet.at(uiBoucle)->SOMLireId() << ",";
        cout << endl;
    }
    cout << endl;
    cout << "==========================" << endl << endl;
    cout << "===== Liste des Arcs =====" << endl << endl;

    for (uiBoucle = 0; uiBoucle < vGRALstArc.size(); uiBoucle++) {
        vGRALstArc.at(uiBoucle)->ARCAfficher();    
    }
    cout << endl;
    cout << "==========================" << endl << endl;
}

/***************************************************************************************************************************
* METHODE : GRAFinaliser
* **************************************************************************************************************************
* Entree : Rien
* Necessite : Rien
* Sortie : Rien
* Entraine : Affiches le graphe oriente dans la console
* ***************************************************************************************************************************
*/
template<typename TData> void PGraphOrient<TData>::GRAFinaliser() {
    unsigned int uiIndexSommet, uiIndexArc;
    PArc<TData>* ptArc;
    PSommet<TData>* ptSommet;

    if (vGRALstArc.size() == 0 || vGRALstSommet.size() == 0) {
        throw runtime_error("Erreur : Graph vide");
    }

    for (uiIndexArc = 0; uiIndexArc < vGRALstArc.size(); uiIndexArc++) {
        ptArc = vGRALstArc.at(uiIndexArc);

        for (uiIndexSommet = 0; uiIndexSommet < vGRALstSommet.size(); uiIndexSommet++) {
            ptSommet = vGRALstSommet.at(uiIndexSommet);

            if (ptArc->ARCLireIdDepart() == ptSommet->SOMLireId()) {
                ptSommet->SOMAjouterArcPart(ptArc);
            }
            if (ptArc->ARCLireIdArrive() == ptSommet->SOMLireId()) {
                ptSommet->SOMAjouterArcArr(ptArc);
            }
        }
    }
}

/***************************************************************************************************************************
* METHODE : GRATailleLstArc
* **************************************************************************************************************************
* Entree : Rien
* Necessite : Rien
* Sortie : Naturel
* Entraine : Retournes la taille de la liste d'arcs
* ***************************************************************************************************************************
*/
template <typename TData> unsigned int PGraphOrient<TData>::GRATailleLstArc() const { return vGRALstArc.size(); }

/***************************************************************************************************************************
* METHODE : GRATailleLstSommet
* **************************************************************************************************************************
* Entree : Rien
* Necessite : Rien
* Sortie : Naturel
* Entraine : Retournes la taille de la liste de sommets
* **************************************************************************************************************************
*/
template <typename TData> unsigned int PGraphOrient<TData>::GRATailleLstSommet() const { return vGRALstSommet.size(); }

/***************************************************************************************************************************
* METHODE : GRACycleHamiltonien
* **************************************************************************************************************************
* Entree : Rien
* Necessite : Rien
* Sortie : Liste de sommets formant un cycle hamiltonien
* Entraine : Retournes un cycle hamiltonien du graphe oriente
* ***************************************************************************************************************************
*/
template<typename TData> vector<PSommet<TData>*> PGraphOrient<TData>::GRACycleHamiltonien(PSommet<TData>* ptSOMSource) const {
    vector<PSommet<TData>*> path;
    unsigned int uiBoucle;
    PSommet<TData>* ptSOMTmp, * ptSOMEloigne;
    set<PSommet<TData>*> setSommetaVisite;

    if (!this->GRASOMEstDansGraphe(ptSOMSource)) {
        cout << "Le Sommet source n'appartient pas au graph" << endl;
        return path;
    }

    // Trouver le sommet le plus éloigné du sommet source
    ptSOMEloigne = this->Dijkstra(ptSOMSource);

    // Initialiser la liste de sommets a visiter
    for (uiBoucle = 0; uiBoucle < vGRALstSommet.size(); uiBoucle++) {
        ptSOMTmp = vGRALstSommet.at(uiBoucle);
        if (ptSOMTmp != ptSOMSource && ptSOMTmp != ptSOMEloigne) {
            setSommetaVisite.insert(ptSOMTmp);
        }
    }

    path.push_back(ptSOMSource);
    path.push_back(ptSOMEloigne);

    while (path.size() < this->GRATailleLstSommet()) {
        for (uiBoucle = 0; uiBoucle < setSommetaVisite.size(); uiBoucle++) {
            ptSOMTmp = setSommetaVisite.at(uiBoucle);
        }
    }
}

/**************************************************************************************************************************
* METHODE : Dijkstra
* *************************************************************************************************************************
* Entree : ptSommetDepart, un pointeur vers le sommet de depart
* Necessite : Rien
* Sortie : Un pointeur vers le sommet le plus eloigne du sommet de depart
* Entraine : Retournes le sommet le plus eloigne du sommet de depart
* **************************************************************************************************************************
*/
template <typename TData> PSommet<TData>* PGraphOrient<TData>::Dijkstra(PSommet<TData>* ptSommetDepart) const {    
    priority_queue<PSommet<TData>*, vector<PSommet<TData>*>> qSommet;
    PSommet<TData>* ptSommetU, *ptSommetV, *ptSommetPlusEloigne;
    PArc<TData>* ptArc;
    TData tPoidsAccumule;
    unsigned int uiIndexArcPart, uiIndexSommet, uiBoucle;
    for (uiBoucle = 0; uiBoucle < vGRALstSommet.size(); uiBoucle++) {
        if (vGRALstSommet.at(uiBoucle) != ptSommetDepart) {
            vGRALstSommet.at(uiBoucle)->SOMModifierData(_Max_limit);
        }
    }

    ptSommetU = nullptr, ptSommetV = nullptr;
    ptArc = nullptr;
    ptSommetPlusEloigne = ptSommetDepart;
    ptSommetDepart->SOMModifierData(0);
    qSommet.push(ptSommetDepart);
    tPoidsAccumule = 0;

    
    // Tant que la file de priorité n'est pas vide
    while (!qSommet.empty()) {
        // Extraire le sommet avec la plus grande distance accumulée
        ptSommetU = qSommet.top();
        qSommet.pop();

        // Parcourir tous les arcs partant de ce sommet
        for (uiIndexArcPart = 0; uiIndexArcPart < ptSommetU->SOMLireTailleArcPartant(); uiIndexArcPart++) {
            ptArc = ptSommetU->SOMLireArcPart(uiIndexArcPart);

            // Trouver le sommet d'arrivée de l'arc
            for (uiIndexSommet = 0; uiIndexSommet < vGRALstSommet.size(); uiIndexSommet++) {
                if (ptArc->ARCLireIdArrive() == vGRALstSommet.at(uiIndexSommet)->SOMLireId()) {
                    ptSommetV = vGRALstSommet.at(uiIndexSommet);
                    break;
                }
            }

            // Si le sommet d'arrivée est trouvé
            if (ptSommetV != nullptr) {
                // Calculer le poids accumulé pour atteindre ce sommet
                tPoidsAccumule = ptSommetU->SOMLireData() + ptArc->ARCLireData();

                // Si le poids accumulé est inférieur à la distance actuelle du sommet d'arrivée
                if (tPoidsAccumule < ptSommetV->SOMLireData()) {
                    // Mettre à jour la distance pour atteindre ce sommet
                    ptSommetV->SOMModifierData(tPoidsAccumule);

                    // Ajouter le sommet d'arrivée à la file de priorité
                    qSommet.push(ptSommetV);
                }
            }
        }

        // Mettre à jour le sommet le plus éloigné si nécessaire
        if (ptSommetU->SOMLireData() > ptSommetPlusEloigne->SOMLireData()) {
            ptSommetPlusEloigne = ptSommetU;
        }
    }

    // Retourner le sommet le plus éloigné trouvé
    cout << ptSommetPlusEloigne->SOMLireData() << endl;
    return ptSommetPlusEloigne;
}

/***************************************************************************************************************************
* METHODE : GRAMaxData
* **************************************************************************************************************************
* Entree : ptSommet, un pointeur vers un sommet
*		   sLstSommet,  un set de sommets
* Necessite : Tout les sommets appartiennent au graph, 
*				ptSommet n'existe pas dans la liste de sommets donné en parametre
* Sortie : Rien
* Entraine : Calcul la data maximal entre ptSommet et chaque sommet de la liste,
*               met a jour la data de ptSommet pour qu'elle soit la plus grande
* **************************************************************************************************************************
*/
template <typename TData> void PGraphOrient<TData>::GRAMaxData(PSommet<TData>* ptSommet, set<PSommet<TData>*>& sLstSommet) {
    return;
}

