// ProjetGrapheCPP.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "TArc.hpp"
#include "TSommet.hpp"
#include "TGrapheOrient.hpp"
#include <assert.h>

int main()
{    // Test de la classe TArc avec des arcs de type TArc<int>
    TSommet<int> sommet(1u, 10);
    TSommet<int> sommet2(2u, 20);
    TArc<int> arc1(1u, 2u, 30);

    // Test des  methodes de la classe TArc
    assert(arc1.ARCLireIdDepart() == 1u);
    assert(arc1.ARCLireIdArrive() == 2u);
    assert(arc1.ARCLireData() == 30);

    // Test de la classe TSommet avec des sommets de type TSommet<int>
    TSommet<int> sommet3(3u, 40);
    TSommet<int> sommet4(4u, 50);

    // Test des methodes de la classe TSommet
    assert(sommet3.SOMLireId() == 3u);
    assert(sommet3.SOMLireData() == 40);

    assert(sommet3.EstDansLstPart(arc1) == false); // Le sommet ne doit pas contenir l'arc1
    sommet3.SOMAjouterArcPart(arc1); // Ajout de l'arc au sommet
    assert(sommet3.EstDansLstPart(arc1) == true); // Le sommet doit contenir l'arc1

    std::cout << "Graphe orienté créé avec succès." << std::endl;
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
