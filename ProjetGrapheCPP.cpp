// ProjetGrapheCPP.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "TArc.hpp"
#include "TSommet.hpp"
#include "TGrapheOrient.hpp"
#include <assert.h>

int main()
{    
    // Test Arc

	TArc<int> arc1(1, 2, 5);
	assert(arc1.ARCLireIdDepart() == 1);
	assert(arc1.ARCLireIdArrive() == 2);
	assert(arc1.ARCLireData() == 5);

	// Test Sommet
	TSommet<int>* sommet1 = new TSommet<int>();
	sommet1->SOMModifierId(1);
	sommet1->SOMModifierData(10);
	assert(sommet1->SOMLireId() == 1);
	assert(sommet1->SOMLireData() == 10);

	// Test Arc Partant
	TArc<int>* arcPartant = new TArc<int>(1, 2, 5);
	sommet1->SOMAjouterArcPart(arcPartant);	
	assert(sommet1->SOMEstDansLstPart(arcPartant) == true);

	// Test Arc Arrivant
	TArc<int>* arcArrivant = new TArc<int>(2, 1, 5);
	sommet1->SOMAjouterArcArr(arcArrivant);
	assert(sommet1->SOMEstDansLstArrivant(arcArrivant) == true);

	// Modification arc dans le sommet le modifie aussi dans le graphe
	TGrapheOrient<int> graphe;
	graphe.GROAjouterSommet(sommet1);
	graphe.GROAjouterArc(arcPartant);

	arcPartant->ARCModifierIdArrive(7);
	assert(graphe.GROLireSommet(0)->SOMLireId() == 1);
	assert(graphe.GROLireArc(0)->ARCLireIdArrive() == 7);

    // Verifie si l'arc est modifier dans sommet
	assert(sommet1->SOMLireArcPart(0)->ARCLireIdArrive() == 7);

    return 0;
}
// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
