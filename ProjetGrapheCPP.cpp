// ProjetGrapheCPP.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

using namespace std;

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "PArc.hpp"
#include "PSommet.hpp"
#include "PGraphOrient.hpp"
#include "PGraph.hpp"
#include <assert.h>
#include "CParser.hpp"
#include <exception>

int main(int argc, char* argv[])
{
	if (argc != 2) {
		cout << "Erreur : Aucun ou trop de fichier fourni" << endl;
		return 1;
	}
	ifstream FILE(argv[1]);

	cout << "Creation du graphe..." << endl << endl;

	CParser Parser;
	PGraphOrient<void*>* Graphe = Parser.ParseGraph(FILE);

	Graphe->GRAFinaliser();

	cout << "===== GRAPHE ORIENTE =====" << endl << endl;
	Graphe->GRAAfficher();
	
	cout << "Inversion du graphe..." << endl << endl;
	PGraphOrient<void*>* GrapheInverse = Graphe->GRAInverser();

	cout << "===== GRAPHE INVERSE =====" << endl << endl;
	GrapheInverse->GRAAfficher();

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
