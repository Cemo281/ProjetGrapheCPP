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
	/*
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
	*/

	// Test de la classe PGraph
	PGraphOrient<int>* Graphe;
	Graphe = new PGraphOrient<int>();

	// Test de la classe PSommet
	// Création des sommets
	PSommet<int>* Sommet1 = new PSommet<int>(1);
	PSommet<int>* Sommet2 = new PSommet<int>(2);
	PSommet<int>* Sommet3 = new PSommet<int>(3);
	PSommet<int>* Sommet4 = new PSommet<int>(4);
	PSommet<int>* Sommet5 = new PSommet<int>(5);

	// Création des arcs
	PArc<int>* Arc1 = new PArc<int>(1, 2, 10);
	PArc<int>* Arc2 = new PArc<int>(1, 3, 15);
	PArc<int>* Arc3 = new PArc<int>(1, 4, 20);
	PArc<int>* Arc4 = new PArc<int>(4, 5, 25);

	// Ajout au graphe
	Graphe->GRAAjouterSommet(Sommet1);
	Graphe->GRAAjouterSommet(Sommet2);
	Graphe->GRAAjouterSommet(Sommet3);
	Graphe->GRAAjouterSommet(Sommet4);
	Graphe->GRAAjouterSommet(Sommet5);

	Graphe->GRAAjouterArc(Arc1);
	Graphe->GRAAjouterArc(Arc2);
	Graphe->GRAAjouterArc(Arc3);
	Graphe->GRAAjouterArc(Arc4);

	// 🔹 **Sommet le plus éloigné depuis `Sommet1`** → `Sommet5` (Poids total : **45**)

	// Affichage du graphe
	cout << "===== GRAPHE =====" << endl << endl;
	Graphe->GRAFinaliser();

	Graphe->GRAAfficher();

	// Test de la fonction de recherche du sommet le plus éloigné
	PSommet<int>* SommetMax = Graphe->Dijkstra(Sommet1);

	cout << "Sommet le plus éloigné du sommet 1 : " << SommetMax->SOMLireId() << endl;

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
