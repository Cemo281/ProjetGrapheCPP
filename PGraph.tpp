#include "PArc.hpp"
#include "PSommet.hpp"
#include "PGraph.hpp"

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
template <typename TData> void PGraph<TData>::GROAjouterArc(PArc<TData>* ptArc) {
	// Creer l'arc inverse
	PArc<TData>* ptArcInverse = new PArc<TData>(ptArc->ARCLireIdArrive(), ptArc->ARCLireIdDepart());

	// Ajoute l'arc au graphe non oriente
	PGraphOrient<TData>::GROAjouterArc(ptArc);	

	// Ajoute l'arc inverse au graphe non oriente
	PGraphOrient<TData>::GROAjouterArc(ptArcInverse);
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
template <typename TData> void PGraph<TData>::GROSupprimerArc(PArc<TData>* ptArc) {
	PArc<TData>* ptArcInverse = new PArc<TData>(*ptArc);
	ptArcInverse->ARCInverser();

	// Supprime l'arc du graphe non oriente
	PGraphOrient<TData>::GROSupprimerArc(ptArc);

	// Supprime l'arc inverse du graphe oriente
	PGraphOrient<TData>::GROSupprimerArc(ptArcInverse);

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
template <typename TData> void PGraph<TData>::GROAfficher() {
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
		if (this->GROLireArc(uiBoucle)->ARCLireData() != 0) {
			cout << this->GROLireArc(uiBoucle)->ARCLireData();
		}
		else {
			cout << "";
		}
		cout << endl;
		uiBoucle++;
	}
}