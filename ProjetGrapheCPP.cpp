// ProjetGrapheCPP.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "CArc.h"
#include "CSommet.h"
#include "PGrapheOrient.h"
#include <assert.h>

int main()
{	
	// Création d'un graphe orienté avec deux sommets et un arc 
  
	CSommet sommet1;
    assert(sommet1.SOMLireId() == 0); // Par défaut, l'ID devrait être 0

    // Test du constructeur avec ID
    CSommet sommet2(42);
    assert(sommet2.SOMLireId() == 42);

    // Test de la modification de l'ID
    sommet2.SOMModifierId(100);
    assert(sommet2.SOMLireId() == 100);

    // Création d'arcs pour les tests
    CArc* arc1 = new CArc();
    CArc* arc2 = new CArc();

	// Numéroter les arcs
	arc1->ARCModifierIdDepart(1);
	arc1->ARCModifierIdArrive(2);
	arc2->ARCModifierIdDepart(3);
	arc2->ARCModifierIdArrive(4);
	// Test de l'ajout d'arcs arrivants
	printf("Ajout d'un arc arrivant au sommet 1\n");
	sommet1.SOMAjouterArcArr(arc1);
	sommet1.SOMAjouterArcArr(arc2);

	sommet1.SOMAjouterArcPart(arc1);
	sommet1.SOMAjouterArcPart(arc2);
	// Test de la lecture des arcs arrivants
	assert(sommet1.SOMLireArcArrivant(0) == arc1);
	assert(sommet1.SOMLireArcArrivant(1) == arc2);
	// Test de la lecture des arcs partants
	assert(sommet1.SOMLireArcPartant(0) == arc1);
	assert(sommet1.SOMLireArcPartant(1) == arc2);

	// Test de EstDansLstPart
	assert(sommet1.EstDansLstPart(arc1) == true);
	assert(sommet1.EstDansLstPart(arc2) == true);

	// Test de EstDansLstArr
	assert(sommet1.EstDansLstArrivant(arc2) == true);
	assert(sommet1.EstDansLstArrivant(arc1) == true);

	printf("Tous les tests de CSommet ont réussi.\n");

	// test destruction d'un sommet
	sommet1.~CSommet();

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
