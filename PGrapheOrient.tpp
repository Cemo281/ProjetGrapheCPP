#include "PGrapheOrient.hpp"
#include "TArc.hpp"
#include "TSommet.hpp"

template <class TData> void PGrapheOrient<TData>::GROAjouterArc(TArc<TData>& tArc) {
    vGROLstArc.push_back(tArc);
    return;
}

template <class TData> void PGrapheOrient<TData>::GROAjouterSommet(TSommet<TData>& tSommet) {
    vGROLstSommet.push_back(tSommet);
    return;
}

