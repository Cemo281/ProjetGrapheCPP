#include "PGrapheOrient.h"

template <class T>PGrapheOrient<T>::PGrapheOrient() {
	vGROLstArc = new vector<T*>();
	vGROLstSommet = new vector<T*>();
}
template <class T>PGrapheOrient<T>::PGrapheOriant(const PGrapheOrient& GROParam){
	vGROLstArc = new vector<T*>();
	vGROLstSommet = new vector<T*>();
	for (int iBoucle = 0; iBoucle < GROParam.vGROLstArc->size(); iBoucle++) {
		vGROLstArc->push_back(GROParam.vGROLstArc->at(iBoucle));
	}
	for (int iBoucle = 0; iBoucle < GROParam.vGROLstSommet->size(); iBoucle++) {
		vGROLstSommet->push_back(GROParam.vGROLstSommet->at(iBoucle));
	}
}

template <class T> void PGrapheOrient<T>::GROAjouter(T* pT) {
    // Vérifie si l'élément est un arc
    CArc* pArc = dynamic_cast<CArc*>(pT);
    if (pArc != nullptr) {
        // Si c'est un arc, vérifie s'il est déjà dans le graphe
        if (GROARCEstDansGraphe(pArc)) {
            throw std::exception("Arc déjà dans le graphe");
        }
        vGROLstArc->push_back(pArc);
        return;
    }

    // Vérifie si l'élément est un sommet
    CSommet* pSommet = dynamic_cast<CSommet*>(pT);
    if (pSommet != nullptr) {
        // Si c'est un sommet, vérifie s'il est déjà dans le graphe
        if (GROSOMEstDansGraphe(pSommet)) {
            throw std::exception("Sommet déjà dans le graphe");
        }
        vGROLstSommet->push_back(pSommet);
        return;
    }

    // Si l'élément n'est ni un arc ni un sommet, lève une exception
    throw std::exception("Type non supporté pour l'ajout au graphe");
}


bool GROARCEstDansGraphe(CArc* pArc) {
	int iBoucle;

	for (iBoucle = 0; iBoucle < vGROLstArc->size(); iBoucle++) {
		if (vGROLstArc->at(iBoucle) == pArc) {
			return true;
		}
	}
	return false;
}

