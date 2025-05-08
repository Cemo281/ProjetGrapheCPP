#include "TArc.hpp"
#include "TSommet.hpp"
#include "TGraph.hpp"

using namespace std;

/**************************************************************************************************************************
* METHODE : GROAjouterArc
* *************************************************************************************************************************
* Entree: ptArc, un pointeur vers un arc
* Necessite : Rien
* Sortie: Rien
* Entraine: Ajoute l'arc au graphe non oriente et son inverse
***************************************************************************************************************************
*/
template <typename TData> void TGraph<TData>::GROAjouterArc(TArc<TData>* ptArc) {
	// Creer l'arc inverse
	TArc<TData>* ptArcInverse = new TArc<TData>(ptArc->ARCLireIdArrive(), ptArc->ARCLireIdDepart());

	// Ajoute l'arc au graphe non oriente
	TGraphOrient<TData>::GROAjouterArc(ptArc);	

	// Ajoute l'arc inverse au graphe non oriente
	TGraphOrient<TData>::GROAjouterArc(ptArcInverse);
}

/**************************************************************************************************************************
* METHODE : GROSupprimerArc
* **************************************************************************************************************************
* Entree: ptArc, Un pointeur vers un arc
* Necessite: Rien
* Sortie: Rien
* Entrainee: Supprime l'arc et son inverse du graphe non oriente
* **************************************************************************************************************************
*/
template <typename TData> void TGraph<TData>::GROSupprimerArc(TArc<TData>* ptArc) {
	TArc<TData>* ptArcInverse = new TArc<TData>(*ptArc);
	ptArcInverse->ARCInverser();

	// Supprime l'arc du graphe non oriente
	TGraphOrient<TData>::GROSupprimerArc(ptArc);

	// Supprime l'arc inverse du graphe oriente
	TGraphOrient<TData>::GROSupprimerArc(ptArcInverse);

	delete ptArcInverse;
}

/***************************************************************************************************************************
* METHODE : GROAfficher
* **************************************************************************************************************************
* Entree : Rien
* Necessite : Rien
* Sortie : Rien
* Entraine : Affiches le graphe non oriente dans la console
* ***************************************************************************************************************************
*/
template <typename TData> void TGraph<TData>::GROAfficher() {
	unsigned int uiBoucle = 0;

	if (this->GROTailleLstSommet() == 0 || this->GROTailleLstArc() == 0) {
		cout << "Le graphe est vide" << endl;
		return;
	}

	cout << "=== Liste des sommets ===" << endl << endl;
	for (uiBoucle = 0; uiBoucle < this->GROTailleLstSommet(); uiBoucle++) {
		this->GROLireSommet(uiBoucle)->SOMAfficher();
	}
	cout << endl;

	cout << "=== Liste des arcs ===" << endl << endl;
	for (uiBoucle = 0; uiBoucle < this->GROTailleLstArc(); uiBoucle++) {
		cout << "Arc " << this->GROLireArc(uiBoucle)->ARCLireIdDepart() << " -- " << this->GROLireArc(uiBoucle)->ARCLireIdArrive() << ": ";
		if (this->GROLireArc(uiBoucle)->ARCLireData() != nullptr) {
			cout << this->GROLireArc(uiBoucle)->ARCLireData() << endl;
		}
		cout << endl;
		uiBoucle++;
	}
}