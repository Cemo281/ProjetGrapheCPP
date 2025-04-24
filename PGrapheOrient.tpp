#include "PGrapheOrient.hpp"
#include "TArc.hpp"
#include "TSommet.hpp"

template <typename TData> void PGrapheOrient<TData>::GROAjouterArc(TArc<TData>& tArc) {
    vGROLstArc.push_back(tArc);
    return;
}

template <typename TData> void PGrapheOrient<TData>::GROAjouterSommet(TSommet<TData>& tSommet) {
    vGROLstSommet.push_back(tSommet);
    return;
}