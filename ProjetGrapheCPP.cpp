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
#include "CParser.hpp"

int main(int argc, char* argv[])
{
	if (argc != 2) {
		cout << "Erreur : Aucun ou trop de fichier fourni" << endl;
		return 1;
	}

	ifstream FILE(argv[1]);

	cout << "Creation du graphe..." << endl << endl;

	CParser Parser;

	Parser.PARRecupType(FILE);

	if (Parser.PARLireType() == "entier") {
		cout << "===== GRAPHE ORIENTE =====" << endl << endl;
		PGraphOrient<unsigned int>* Graphe = Parser.PARGROEntierNS(FILE);
		Graphe->GROAfficher();
		Graphe->GROFinaliser();

		PGraphOrient<unsigned int>* GrapheInverse = Graphe->GROInverser();
		cout << "===== GRAPHE INVERSE =====" << endl << endl;
		GrapheInverse->GROAfficher();

		vector<PSommet<unsigned int>*> vec = Graphe->GROCycleHamiltonien(Graphe->GROLireSommet(0));

		delete GrapheInverse;
		delete Graphe;
	}
	else {
		cout << "===== GRAPHE ORIENTE =====" << endl << endl;
		PGraphOrient<void*>* Graphe = Parser.PARGrapheO(FILE);
		Graphe->GROAfficher();
		Graphe->GROFinaliser();

		PGraphOrient<void*>* GrapheInverse = Graphe->GROInverser();
		cout << "===== GRAPHE INVERSE =====" << endl << endl;
		GrapheInverse->GROAfficher();

		delete GrapheInverse;
		delete Graphe;
	}

	return 0;
}