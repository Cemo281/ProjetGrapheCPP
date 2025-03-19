#pragma once
class PGrapheOrient
{
	/****************************************************
	   * Patron de Classe :PGrapheOrient
	   * **************************************************
	   * ROLE :
	   * **************************************************
	   * VERSION : 1.0
	   * AUTEUR : ELAOULA KHAOULA
	   * DATE : 18/03/2025
	   * *************************************************
	   * INCLUSIONS EXTERNES :
	   */

	   /* TYPES:
	   * Pas de type particulier de déclaré
	   */

	   /* Variables :
	   * Pas de variable globale de déclarée
	   */
	template<class T> class PGraphOrient
	{
		//Attributs:

	private:
		std::vector<T> LISArc //liste des Arcs
			T* LISSommet //liste des Sommets
			//Constructeurs et destructeurs:
	public:
		PGrapheOrient() { LISArc = NULL, LISSommet = NULL };

		PgrapheOrient(const PCgraphOrient& GROParam);

		~PgrapheOrient();

		//Méthodes:

		/**************************************************************************************************************************
		*GROAjouterArc()
		* **************************************************************************************************************************
		* Entrée: Rien
		* Necéssite : Rien
		* Sortie: Rien
		* Entraine:Ajoute un arc au graphe
		****************************************************************************************************************************/
		void AjouterArc();

		/***************************************************************************************************************************
		*GROModifierArc()
		* **************************************************************************************************************************
		* Entrée: Rien
		* Necéssite :Rien
		* Sortie: Rien
		* Entraine: Modifier un arc existant dans le graphe
		*****************************************************************************************************************************/
		void GROModifierArc();

		/***************************************************************************************************************************
		*GROAjouterSommet()
		* **************************************************************************************************************************
		* Entrée:Un pointeur vers un sommet (CSommet*)
		* Necéssite : Un sommet valide
		* Sortie: Rien
		* Entraine:Ajoute un sommet au graphe
		*****************************************************************************************************************************/
		void GROAjouterSommet(CSommet* Som)


	}
#include"PGrapheOrient.th"

};