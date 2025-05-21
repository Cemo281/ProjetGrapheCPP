#include "PArc.hpp"
#include "PSommet.hpp"
#include "PGraphOrient.hpp"
#include <queue>
#include <set>
#include <limits>
#include <algorithm>
#include <map>

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
template<typename TData> PGraphOrient<TData>::PGraphOrient(const PGraphOrient<TData>& GROParam)
{
    unsigned int uiIndex;

    PArc<TData>* ptARCTmp;
    PSommet<TData>* ptSOMTmp;

    tGROData = GROParam.tGROData;

    for (uiIndex = 0; uiIndex < GROParam.vGROLstArc.size(); uiIndex++) {
        ptARCTmp = new PArc<TData>(*(GROParam.vGROLstArc.at(uiIndex)));
        vGROLstArc.push_back(ptARCTmp);
    }
    for (uiIndex = 0; uiIndex < GROParam.vGROLstSommet.size(); uiIndex++) {
        ptSOMTmp = new PSommet<TData>(*(GROParam.vGROLstSommet.at(uiIndex)));
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
template<typename TData> TData PGraphOrient<TData>::GROLireData() const { return tGROData; }

/**************************************************************************************************************************
* METHODE : GROModifierData
* *************************************************************************************************************************
* Entree: tNvData, les nouvelles donnees du graphe
* Necessite : Rien
* Sortie: Rien
* Entraine: Modifie les donnees du graphe par tNvData
***************************************************************************************************************************
*/
template<typename TData> void PGraphOrient<TData>::GROModiferData(TData tNvData) { tGROData = tNvData; }

/***************************************************************************************************************************
* METHODE : GROAjouterSommet
* **************************************************************************************************************************
* Entree: ptSommet, un pointeur vers le sommet a ajouter
* Necessite : Rien
* Sortie: Rien
* Entraine: Ajoute le sommet au graphe oriente
****************************************************************************************************************************
*/
template<typename TData> void PGraphOrient<TData>::GROAjouterSommet(PSommet<TData>* ptSommet) {
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
template<typename TData> void PGraphOrient<TData>::GROSupprimerSommet(PSommet<TData>* ptSommet) {
    unsigned int uiIndex;

    // Verifier si le sommet est dans le graphe
    if (this->GROSOMEstDansGraphe(ptSommet) == false) {
        return;
    }

    for (uiIndex = 0; uiIndex < vGROLstArc.size(); uiIndex++) {
        // Suppressions des arcs qui partent du sommet
        if (vGROLstArc.at(uiIndex)->ARCLireIdDepart() == ptSommet->SOMLireId()) {
            vGROLstArc.erase(vGROLstArc.begin() + uiIndex);
            uiIndex--;
        // Suppressions des arcs arrivant au sommet
        } else if (vGROLstArc.at(uiIndex)->ARCLireIdArrive() == ptSommet->SOMLireId()) {
            vGROLstArc.erase(vGROLstArc.begin() + uiIndex);
            uiIndex--;   
        }
    }

    // Supprimer le sommet de la liste des sommets
    for (uiIndex = 0; uiIndex < vGROLstSommet.size(); uiIndex++) {
        if (*(vGROLstSommet.at(uiIndex)) == ptSommet) {
            vGROLstSommet.erase(vGROLstSommet.begin() + uiIndex);
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
template <typename TData> void PGraphOrient<TData>::GROAjouterArc(PArc<TData>* ptArc) {
    if (this->GROARCEstDansGraphe(ptArc) == true) {
        return;
    }
    // Verifier si les deux sommets de l'arc sont dans le graphe
    if (this->GROSOMEstDansGraphe(ptArc->ARCLireIdDepart()) == false && this->GROSOMEstDansGraphe(ptArc->ARCLireIdArrive()) == false) {
        cout << "Erreur : Arc non ajoute" << endl;
        cout << "Les sommets " << ptArc->ARCLireIdDepart() << " et " << ptArc->ARCLireIdArrive() << " n'existent pas dans le graphe." << endl;
        return;
    // Verifier si le sommet de depart est dans le graphe
    } else if (this->GROSOMEstDansGraphe(ptArc->ARCLireIdDepart()) == false) {
        cout << "Erreur : Arc non ajoute" << endl;
        cout << "Le sommet " << ptArc->ARCLireIdDepart() << " n'existe pas dans le graphe." << endl;
        return;
    // Verifier si le sommet de depart est dans le graphe
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
template <typename TData> void PGraphOrient<TData>::GROSupprimerArc(PArc<TData>* ptArc) {
    unsigned int uiIndexSommet, uiIndexArc;
    // Verifier si l'arc est dans le graphe
    if (this->GROARCEstDansGraphe(ptArc) == false) {
        return;
    }
    // Supprimer l'arc de la liste des arcs
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
template <typename TData> PArc<TData>* PGraphOrient<TData>::GROLireArc(unsigned int uiPos)
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
template <typename TData> PSommet<TData>* PGraphOrient<TData>::GROLireSommet(unsigned int uiPos)
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
template <typename TData> bool PGraphOrient<TData>::GROSOMEstDansGraphe(unsigned int uiIdSommet) const {
    unsigned int uiIndex;
    // Si le graphe est vide, on ne peut pas trouver le sommet
    if (vGROLstSommet.size() == 0) {
        return false;
    }
    // Sinon, on parcourt la liste des sommets
    for (uiIndex = 0; uiIndex < vGROLstSommet.size(); uiIndex++) {
        if (vGROLstSommet.at(uiIndex)->SOMLireId() == uiIdSommet) {
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
template <typename TData> bool PGraphOrient<TData>::GROSOMEstDansGraphe(PSommet<TData>* ptSommet) const {
    unsigned int uiIndex;
    // Si le graphe est vide, on ne peut pas trouver le sommet
    if (vGROLstSommet.size() == 0) {
        return false;
    }
    // Sinon, on parcourt la liste des sommets
    for (uiIndex = 0; uiIndex < vGROLstSommet.size(); uiIndex++) {
        if (*(vGROLstSommet.at(uiIndex)) == ptSommet) {
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
template <typename TData> bool PGraphOrient<TData>::GROARCEstDansGraphe(PArc<TData>* ptArc) {
    unsigned int uiIndex;
    // Si le graphe est vide, on ne peut pas trouver l'arc
    if (vGROLstArc.size() == 0) {
        return false;
    }
    // Sinon, on parcourt la liste des arcs
    for (uiIndex = 0; uiIndex < vGROLstArc.size(); uiIndex++) {
        if (*(vGROLstArc.at(uiIndex)) == ptArc) {
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
template<typename TData> PGraphOrient<TData>* PGraphOrient<TData>::GROInverser() {
    unsigned int uiIndex;

    if (vGROLstArc.size() == 0 || vGROLstSommet.size() == 0) {
        throw runtime_error("Le graphe est vide");
    }
    // On cree une copie du graphe oriente
    PGraphOrient<TData>* ptGROInverse = new PGraphOrient<TData>(*this);

    cout << "Inversion du graphe..." << endl << endl;
    // On inverse tous les arcs et sommets de la copie
    for (uiIndex = 0; uiIndex < vGROLstArc.size(); uiIndex++) {
        ptGROInverse->vGROLstArc.at(uiIndex)->ARCInverser();
    }
    for (uiIndex = 0; uiIndex < vGROLstSommet.size(); uiIndex++) {
        ptGROInverse->vGROLstSommet.at(uiIndex)->SOMInverser();
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
template<typename TData> void PGraphOrient<TData>::GROAfficher() {
    unsigned int uiIndex;

    if (vGROLstArc.size() == 0 && vGROLstSommet.size() == 0) {
        throw runtime_error("Le graphe est vide");
    }

    cout << "=== Liste des sommets ===" << endl << endl;

    for (uiIndex = 0; uiIndex < vGROLstSommet.size(); uiIndex++) {
        cout << "Sommet " << vGROLstSommet.at(uiIndex)->SOMLireId() << ",";
        cout << endl;
    }
    cout << endl;
    cout << "==========================" << endl << endl;
    cout << "===== Liste des Arcs =====" << endl << endl;

    for (uiIndex = 0; uiIndex < vGROLstArc.size(); uiIndex++) {
        vGROLstArc.at(uiIndex)->ARCAfficher();    
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
template<typename TData> void PGraphOrient<TData>::GROFinaliser() {
    unsigned int uiIndexSommet, uiIndexArc;
    PArc<TData>* ptArc;
    PSommet<TData>* ptSommet;

    if (vGROLstArc.size() == 0 || vGROLstSommet.size() == 0) {
        cout << "Graph vide" << endl;
        throw runtime_error("Erreur : Graph vide");
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

/***************************************************************************************************************************
* METHODE : GROTailleLstArc
* **************************************************************************************************************************
* Entree : Rien
* Necessite : Rien
* Sortie : Naturel
* Entraine : Retournes la taille de la liste d'arcs
* ***************************************************************************************************************************
*/
template <typename TData> unsigned int PGraphOrient<TData>::GROTailleLstArc() const { return vGROLstArc.size(); }

/***************************************************************************************************************************
* METHODE : GROTailleLstSommet
* **************************************************************************************************************************
* Entree : Rien
* Necessite : Rien
* Sortie : Naturel
* Entraine : Retournes la taille de la liste de sommets
* **************************************************************************************************************************
*/
template <typename TData> unsigned int PGraphOrient<TData>::GROTailleLstSommet() const { return vGROLstSommet.size(); }

/***************************************************************************************************************************
* METHODE : GROCycleHamiltonien
* **************************************************************************************************************************
* Entree : ptSOMSource, un pointeur vers le sommet de départ du cycle.
* Necessite : - Les arcs doivent être pondéré.
*             - Le graph ne doit pas possèder de sommets, d'arcs ou d'ensembles d'arcs isolé. Il doit être unifié.
*                   Un graph non unifié = pas de cycle hamiltonien
* Sortie : Un vector contenant les sommets formant le cycle hamiltonien.
* Entraine : Creer et retournes un vector contenant le cycle hamiltonien du graph partant de ptSOMSource
* ***************************************************************************************************************************
*/
template<typename TData> vector<PSommet<TData>*> PGraphOrient<TData>::GROCycleHamiltonien(PSommet<TData>* ptSOMSource) {
    vector<PSommet<TData>*> path; // Vecteur pour stocker le chemin du cycle hamiltonien
    vector<PSommet<TData>*> vSOMRestant; // Vecteur pour stocker les sommet qui sont pas dans path
    unsigned int uiIndex, uiIndexPath, uiIndexArc, uiIndexInsertion;

    // Variables pour les coûts et distances
    TData tMaxDist, tMinDist, tMinCout, tCout;
    TData w_ik, w_kj, w_ij;

    // Pointeurs pour les sommets utilisés dans l'algorithme
    PSommet<TData>* ptSOMPlusEloigne,* pSOMRestant;
    PSommet<TData>* pSOMPath;
    PSommet<TData>* pSOMI,* pSOMJ,* pSOMK;

    PArc<TData>* ptArc;

    unsigned int uiBestI;

    if (vGROLstArc.size() == 0 || vGROLstSommet.size() == 0) {
        cout << "Erreur : Graph vide" << endl;
        throw runtime_error("Erreur : Graph vide");
    }

    // Vérifier que le sommet source appartient au graphe
    if (!this->GROSOMEstDansGraphe(ptSOMSource->SOMLireId())) {
        cout << "Le Sommet source n'appartient pas au graphe" << endl;
        return path;
    }

    // Trouver le sommet le plus éloigné du sommet source (utilise Dijkstra)
    ptSOMPlusEloigne = this->Dijkstra(ptSOMSource);
    if (ptSOMPlusEloigne == nullptr || ptSOMPlusEloigne == ptSOMSource) {
        cout << "Impossible de trouver un sommet le plus éloigné du sommet source." << endl;
        return path;
    }

    cout << ptSOMPlusEloigne->SOMLireId() << endl;

    // Initialiser le chemin avec le cycle s -> plus éloigné -> s
    path.push_back(ptSOMSource);
    path.push_back(ptSOMPlusEloigne);
    path.push_back(ptSOMSource);

    // Initialiser la liste des sommets restants à insérer (tous sauf source et le plus éloigné)
    for (uiIndex = 0; uiIndex < vGROLstSommet.size(); ++uiIndex) {
        pSOMRestant = vGROLstSommet.at(uiIndex);
        if (pSOMRestant != ptSOMSource && pSOMRestant != ptSOMPlusEloigne) {
            vSOMRestant.push_back(pSOMRestant);
        }
    }

    // Tant qu'il reste des sommets à insérer dans le cycle
    while (!vSOMRestant.empty()) {
        tMaxDist = std::numeric_limits<TData>::lowest();
        pSOMK = nullptr;

        // Chercher le sommet restant le plus éloigné du chemin actuel
        for (uiIndex = 0; uiIndex < vSOMRestant.size(); ++uiIndex) {
            pSOMRestant = vSOMRestant.at(uiIndex);
            tMinDist = std::numeric_limits<TData>::max();

            // Pour chaque sommet du chemin, calculer la distance minimale depuis le sommet restant
            for (uiIndexPath = 0; uiIndexPath < path.size(); ++uiIndexPath) {
                pSOMPath = path.at(uiIndexPath);
                if (pSOMPath == ptSOMSource) continue; // ignorer le doublon de fermeture

                for (uiIndexArc = 0; uiIndexArc < vGROLstArc.size(); ++uiIndexArc) {
                    ptArc = vGROLstArc.at(uiIndexArc);
                    if (ptArc->ARCLireIdDepart() == pSOMRestant->SOMLireId() && ptArc->ARCLireIdArrive() == pSOMPath->SOMLireId()) {
                        if (ptArc->ARCLireData() < tMinDist) { tMinDist = ptArc->ARCLireData(); }
                    }
                }
            }
            // Sélectionner le sommet le plus éloigné (distance minimale la plus grande)
            if (tMinDist != std::numeric_limits<TData>::max() && tMinDist > tMaxDist) {
                tMaxDist = tMinDist;
                pSOMK = pSOMRestant;
            }

        }

        uiBestI = 0;
        tMinCout = std::numeric_limits<TData>::max();
        bool insertionPossible = false;

        // Chercher la meilleure position d'insertion pour minimiser le coût du cycle
        for (uiIndexInsertion = 0; uiIndexInsertion < path.size() - 1; ++uiIndexInsertion) {
            pSOMI = path[uiIndexInsertion];
            pSOMJ = path[uiIndexInsertion + 1];

            w_ik = std::numeric_limits<TData>::max();
            w_kj = std::numeric_limits<TData>::max();
            w_ij = std::numeric_limits<TData>::max();
            // Chercher les poids des arcs nécessaires pour l'insertion
            for (uiIndexArc = 0; uiIndexArc < vGROLstArc.size(); ++uiIndexArc) {
                ptArc = vGROLstArc.at(uiIndexArc);
                if (ptArc->ARCLireIdDepart() == pSOMI->SOMLireId() && ptArc->ARCLireIdArrive() == pSOMK->SOMLireId()) {
                    w_ik = ptArc->ARCLireData();
                }
                if (ptArc->ARCLireIdDepart() == pSOMK->SOMLireId() && ptArc->ARCLireIdArrive() == pSOMJ->SOMLireId()) {
                    w_kj = ptArc->ARCLireData();
                }
                if (ptArc->ARCLireIdDepart() == pSOMI->SOMLireId() && ptArc->ARCLireIdArrive() == pSOMJ->SOMLireId()) {
                    w_ij = ptArc->ARCLireData();
                }
            }
            // Vérifie que les arcs nécessaires pour l'insertion existent (i->k et k->j)
            if (w_ik != std::numeric_limits<TData>::max() && w_kj != std::numeric_limits<TData>::max()) {
                insertionPossible = true;
                // Si l'arc direct i->j n'existe pas, le coût d'insertion est simplement la somme des deux nouveaux arcs
                if (w_ij == std::numeric_limits<TData>::max()) {
                    tCout = w_ik + w_kj;
                } else {
                    // Sinon, on retire le coût de l'arc direct i->j (qui sera remplacé par i->k et k->j)
                    tCout = w_ik + w_kj - w_ij;
                }
                // Si ce coût d'insertion est le plus faible trouvé jusqu'à présent, on mémorise la position
                if (tCout < tMinCout) {
                    tMinCout = tCout;
                    uiBestI = uiIndexInsertion;
                }
            }
        }

        // Insérer le sommet sélectionné à la meilleure position
        path.insert(path.begin() + uiBestI + 1, pSOMK);
        // Retirer ce sommet de la liste des sommets restants
        for (uiIndexPath = 0; uiIndexPath < vSOMRestant.size(); ++uiIndexPath) {
            if (vSOMRestant.at(uiIndexPath) == pSOMK) {
                vSOMRestant.erase(vSOMRestant.begin() + uiIndexPath);
                break;
            }
        }
    }

    // Vérification finale : s'assurer que le cycle est valide (tous les arcs existent)
    for (uiIndex = 0; uiIndex < path.size() - 1; ++uiIndex) {
        bool bArcExiste = false;
        for (uiIndexArc = 0; uiIndexArc < vGROLstArc.size(); ++uiIndexArc) {
            ptArc = vGROLstArc.at(uiIndexArc);
            if (ptArc->ARCLireIdDepart() == path[uiIndex]->SOMLireId() && ptArc->ARCLireIdArrive() == path[uiIndex + 1]->SOMLireId()) {
                bArcExiste = true;
                break;
            }
        }
        if (!bArcExiste) {
            cout << "Aucun cycle hamiltonien n'existe dans ce graphe (cycle incomplet)." << endl;
            path.clear();
            return path;
        }
    }

    // Affichage du cycle hamiltonien trouvé
    cout << "Cycle Hamiltonien : ";
    for (uiIndex = 0; uiIndex < path.size(); ++uiIndex) {
        cout << path.at(uiIndex)->SOMLireId() << " ";
    }
    cout << endl;
    return path;
}

/**************************************************************************************************************************
* METHODE : Dijkstra
* *************************************************************************************************************************
* Entree : ptSommetDepart, un pointeur vers le sommet de depart
* Necessite : Les arcs doivent être pondéré.
* Sortie : Un pointeur vers le sommet le plus eloigne du sommet de depart
* Entraine : Retournes le sommet le plus eloigne du sommet de depart
* **************************************************************************************************************************
*/
template <typename TData> PSommet<TData>* PGraphOrient<TData>::Dijkstra(PSommet<TData>* ptSommetDepart) const {    
    priority_queue<PSommet<TData>*, vector<PSommet<TData>*>> qSommet;
    PSommet<TData>* ptSommetU, *ptSommetV, *ptSommetPlusEloigne;
    PArc<TData>* ptArc;
    TData tPoidsAccumule;
    unsigned int uiIndexArcPart, uiIndexSommet, uiIndex;

    // Initialisation de tout les sommets avec la valeur maximal
    for (uiIndex = 0; uiIndex < vGROLstSommet.size(); uiIndex++) {
        if (vGROLstSommet.at(uiIndex) != ptSommetDepart) {
            vGROLstSommet.at(uiIndex)->SOMModifierData(numeric_limits<TData>::max());
        }
    }
    // Initialisation des variables
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
            for (uiIndexSommet = 0; uiIndexSommet < vGROLstSommet.size(); uiIndexSommet++) {
                if (ptArc->ARCLireIdArrive() == vGROLstSommet.at(uiIndexSommet)->SOMLireId()) {
                    ptSommetV = vGROLstSommet.at(uiIndexSommet);
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

    // Retourner le sommet le plus éloigné
    return ptSommetPlusEloigne;
}

/**************************************************************************************************************************
* OPERATEUR : operator=
* *************************************************************************************************************************
* Entree: GROParam, le graphe oriente à copier
* Necessite : Rien
* Sortie: Référence sur *this
* Entraine: Affecte le contenu d'un graphe oriente à un autre
***************************************************************************************************************************
*/
template<typename TData>
PGraphOrient<TData>& PGraphOrient<TData>::operator=(const PGraphOrient<TData>& GROParam)
{
    unsigned int uiIndex;

    if (this == &GROParam) {
        return *this;
    }

    // Libérer la mémoire des arcs existants
    for (uiIndex = 0; uiIndex < vGROLstArc.size(); ++uiIndex) {
        delete vGROLstArc[uiIndex];
    }
    vGROLstArc.clear();

    // Libérer la mémoire des sommets existants
    for (uiIndex = 0; uiIndex < vGROLstSommet.size(); ++uiIndex) {
        delete vGROLstSommet[uiIndex];
    }
    vGROLstSommet.clear();

    // Copier les données du graphe
    tGROData = GROParam.tGROData;

    // Copier les arcs
    for (uiIndex = 0; uiIndex < GROParam.vGROLstArc.size(); ++uiIndex) {
        vGROLstArc.push_back(new PArc<TData>(*(GROParam.vGROLstArc.at(uiIndex))));
    }

    // Copier les sommets
    for (uiIndex = 0; uiIndex < GROParam.vGROLstSommet.size(); ++uiIndex) {
        vGROLstSommet.push_back(new PSommet<TData>(*(GROParam.vGROLstSommet.at(uiIndex))));
    }

    return *this;
}