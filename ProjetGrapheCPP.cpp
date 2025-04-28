// ProjetGrapheCPP.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "TArc.hpp"
#include "TSommet.hpp"
#include "TGrapheOrient.hpp"
#include <assert.h>

int main()
{    
    // Test InverserSommet()
    TArc<int>* arc1 = new TArc<int>(1, 2, 0);

    TSommet<int> sommet1(1, 100);

    sommet1.SOMAjouterArcPart(arc1);

    assert(sommet1.EstDansLstArrivant(arc1) == false);

    // Vérifier que les arcs partant sont maintenant arrivants et vice versa
    assert(sommet1.EstDansLstArrivant(arc1) == true);
    
    // Test Inverser Arc
	assert(arc1->ARCLireIdArrive() == 1);
	assert(arc1->ARCLireIdDepart() == 2);

	// Afficher les infos de l'arc
	std::cout << "Arc inversé : " << std::endl;
	std::cout << "Id de départ : " << arc1->ARCLireIdDepart() << std::endl;
	std::cout << "Id d'arrivée : " << arc1->ARCLireIdArrive() << std::endl;

	// Afficher le premier arc arrivant au sommet
	std::cout << "Premier arc arrivant au sommet : " << std::endl;

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
