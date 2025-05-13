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

	// Création d'un nouveau graphe orienté pour tester Dijkstra
	PGraphOrient<int>* NouveauGraphe = new PGraphOrient<int>();

	// Création des sommets
	PSommet<int>* S1 = new PSommet<int>(1);
	PSommet<int>* S2 = new PSommet<int>(2);
	PSommet<int>* S3 = new PSommet<int>(3);
	PSommet<int>* S4 = new PSommet<int>(4);
	PSommet<int>* S5 = new PSommet<int>(5);
	PSommet<int>* S6 = new PSommet<int>(6);

	// Création des arcs avec poids
	PArc<int>* A1 = new PArc<int>(1, 2, 5);
	PArc<int>* A2 = new PArc<int>(1, 3, 10);
	PArc<int>* A3 = new PArc<int>(2, 4, 2);
	PArc<int>* A4 = new PArc<int>(3, 4, 1);
	PArc<int>* A5 = new PArc<int>(4, 5, 3);
	PArc<int>* A6 = new PArc<int>(5, 6, 8);

	// Ajout des sommets au graphe
	NouveauGraphe->GRAAjouterSommet(S1);
	NouveauGraphe->GRAAjouterSommet(S2);
	NouveauGraphe->GRAAjouterSommet(S3);
	NouveauGraphe->GRAAjouterSommet(S4);
	NouveauGraphe->GRAAjouterSommet(S5);
	NouveauGraphe->GRAAjouterSommet(S6);

	// Ajout des arcs au graphe
	NouveauGraphe->GRAAjouterArc(A1);
	NouveauGraphe->GRAAjouterArc(A2);
	NouveauGraphe->GRAAjouterArc(A3);
	NouveauGraphe->GRAAjouterArc(A4);
	NouveauGraphe->GRAAjouterArc(A5);
	NouveauGraphe->GRAAjouterArc(A6);

	// Finalisation et affichage du graphe
	cout << "===== NOUVEAU GRAPHE =====" << endl << endl;
	NouveauGraphe->GRAFinaliser();
	NouveauGraphe->GRAAfficher();

	// Test de la fonction Dijkstra
	PSommet<int>* SommetEloigne = NouveauGraphe->Dijkstra(S1);

	cout << "Sommet le plus éloigné du sommet 1 : " << SommetEloigne->SOMLireId() << endl;

	// Nettoyage de la mémoire
	delete NouveauGraphe;

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
