// ProjetGrapheCPP.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

using namespace std;

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "TArc.hpp"
#include "TSommet.hpp"
#include "TGrapheOrient.hpp"
#include <assert.h>
#include "CParser.hpp"
int main()
{	
	ifstream FILE("C:/Users/alice/OneDrive/Desktop/PARSER.txt");
	if (!FILE.is_open()) {
		cout << "Erreur d'ouverture du fichier." << endl;
		return 1;
	}
	CParser Parser;
	TGrapheOrient<void*>* Graphe = Parser.ParseGraph(FILE);

	Graphe->GROFinaliser();
	TGrapheOrient<void*>* GrapheInverse = Graphe->GROInverser();

	// Test suppression de sommet dans le graphe
	TSommet<void*>* ptSommet = Graphe->GROLireSommet(0);
	Graphe->GROSupprimerSommet(ptSommet);

	// Afficher Graphe après suppression
	Graphe->GROAfficher();

	delete GrapheInverse;
	delete Graphe;

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
