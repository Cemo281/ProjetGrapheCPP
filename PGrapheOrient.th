#include "PGrapheOrient.h"

template <class T>PGrapheOrient<T>::PGrapheOrient() {
	
}
template <class T>PGrapheOrient<T>::PGrapheOriant(const PGrapheOrient& GROParam){
	
}

void template <class T>PGrapheOrient<T>::GROAjouterArc(CArc* pArc) { 
	if (ARCEstDansGraphe(pArc)) {
		exception e("Arc deja dans le graphe");
		throw e;
	}
	vGROLstArc.push_back(pArc); 
}

bool GROARCEstDansGraphe(CArc* pArc) {
	int iBoucle;

	for (iBoucle = 0; iBoucle < vGROLstArc; iBoucle++) {
		if (vGROLstArc[iBoucle] == pArc) {
			return true;
		}
	}
	return false;
}

