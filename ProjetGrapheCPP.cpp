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
    TArc<int> arc1(1, 2, 5);
    TArc<int> arc2(2, 3, 10);
    TArc<int> arc3(3, 4, 15);
    TArc<int> arc4(4, 5, 20);

    TSommet<int> sommet1(1, 100);

    sommet1.SOMAjouterArcPart(arc1);
    sommet1.SOMAjouterArcPart(arc2);
    sommet1.SOMAjouterArcPart(arc3);

    sommet1.SOMAjouterArcArr(arc4);

    // Inverser les arcs du sommet1
    sommet1.InverserSommet();

    // Vérifier que les arcs partant sont maintenant arrivants et vice versa
    assert(sommet1.EstDansLstArrivant(arc1) == true);
    assert(sommet1.EstDansLstArrivant(arc2) == true);
    assert(sommet1.EstDansLstArrivant(arc3) == true);
    assert(sommet1.EstDansLstPart(arc4) == true);
    
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
