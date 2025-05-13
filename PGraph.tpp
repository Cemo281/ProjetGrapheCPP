#include "PArc.hpp"
#include "PSommet.hpp"
#include "PGraph.hpp"

using namespace std;

/**************************************************************************************************************************
* METHODE : GRAAjouterArc
* *************************************************************************************************************************
* Entree: ptArc, un pointeur vers un arc
* Necessite : Rien
* Sortie: Rien
* Entraine: Ajoute l'arc au graphe non oriente et son inverse
***************************************************************************************************************************
*/
template <typename TData> void PGraph<TData>::GRAAjouterArc(PArc<TData>* ptArc) {
	// Creer l'arc inverse
	PArc<TData>* ptArcInverse = new PArc<TData>(ptArc->ARCLireIdArrive(), ptArc->ARCLireIdDepart());

	// Ajoute l'arc au graphe non oriente
	PGraphOrient<TData>::GRAAjouterArc(ptArc);	

	// Ajoute l'arc inverse au graphe non oriente
	PGraphOrient<TData>::GRAAjouterArc(ptArcInverse);
}

/**************************************************************************************************************************
* METHODE : GRASupprimerArc
* **************************************************************************************************************************
* Entree: ptArc, Un pointeur vers un arc
* Necessite: Rien
* Sortie: Rien
* Entrainee: Supprime l'arc et son inverse du graphe non oriente
* **************************************************************************************************************************
*/
template <typename TData> void PGraph<TData>::GRASupprimerArc(PArc<TData>* ptArc) {
	PArc<TData>* ptArcInverse = new PArc<TData>(*ptArc);
	ptArcInverse->ARCInverser();

	// Supprime l'arc du graphe non oriente
	PGraphOrient<TData>::GRASupprimerArc(ptArc);

	// Supprime l'arc inverse du graphe oriente
	PGraphOrient<TData>::GRASupprimerArc(ptArcInverse);

	delete ptArcInverse;
}

/***************************************************************************************************************************
* METHODE : GRAAfficher
* **************************************************************************************************************************
* Entree : Rien
* Necessite : Rien
* Sortie : Rien
* Entraine : Affiches le graphe non oriente dans la console
* ***************************************************************************************************************************
*/
template <typename TData> void PGraph<TData>::GRAAfficher() {
	unsigned int uiBoucle = 0;

	if (this->GRATailleLstSommet() == 0 || this->GRATailleLstArc() == 0) {
		cout << "Le graphe est vide" << endl;
		return;
	}

	cout << "=== Liste des sommets ===" << endl << endl;
	for (uiBoucle = 0; uiBoucle < this->GRATailleLstSommet(); uiBoucle++) {
		this->GRALireSommet(uiBoucle)->SOMAfficher();
	}
	cout << endl;

	cout << "=== Liste des arcs ===" << endl << endl;
	for (uiBoucle = 0; uiBoucle < this->GRATailleLstArc(); uiBoucle++) {
		cout << "Arc " << this->GRALireArc(uiBoucle)->ARCLireIdDepart() << " -- " << this->GRALireArc(uiBoucle)->ARCLireIdArrive() << ": ";
		if (this->GRALireArc(uiBoucle)->ARCLireData() != 0) {
			cout << this->GRALireArc(uiBoucle)->ARCLireData();
		}
		else {
			cout << "";
		}
		cout << endl;
		uiBoucle++;
	}
}