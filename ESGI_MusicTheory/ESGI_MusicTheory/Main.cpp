#include <stdio.h>
#include <string>
#include <tchar.h>
#include <iostream>
#include <assert.h>
#include "Form_Main.h"
#include <Windows.h>
#include <fstream>
#include "Note.h"

using namespace ESGI_MusicTheory;
using namespace System::Windows::Forms;
using namespace std;


int main()
{

	//Lire les fichiers CSV et créer des objets depuis ces données
		//Ajouter les notes
		//Ajouter les instrument
		//Ajouter les paramètres
		//Ajouter les scores

	// le constructeur de ifstream permet d'ouvrir un fichier en lecture

	//Faire une fonction qui charge l'ensemble des données dans le main / ou données par données
	//Début du chargement du fichier notes

	ifstream f_notes("Data/Notes.csv"); 
	string value;

	if (f_notes)
	{
		int n_id = NULL;
		string n_nom = "";
		string n_nom_2 = "";
		int n_octave = NULL;
		float n_frequence = NULL;
		
		while ( getline( f_notes, value ) )
		{
			char *sArr = new char[value.length()+1];
			strcpy(sArr, value.c_str());
			// Declare char pointer sPtr for the tokens.
			char *sPtr;
			// Get all the tokens with " " as delimiter.
			sPtr = strtok(sArr, ";");

			int i =1;	
 
			// For all tokens.
			while(sPtr != NULL) 
			{
				if (i==1)
					n_id = atoi(sPtr);
				else if (i==2)
					n_nom = sPtr;
				else if (i==3)
					n_nom_2 = sPtr;
				else if (i==4)
					n_octave = atoi(sPtr);
				else if (i==5)
					n_frequence = atof(sPtr);
					
				// Go to the next word.
				sPtr = strtok(NULL, ";");

				i++;
			}
			new Note(n_id,n_nom,n_nom_2,n_octave,n_frequence,""); //Le dernier champs étant l'image -> TO DO
			//Insérer toutes les images du programme dans un dossier avec pour nom l'id de la note
			//+ "_" pour les dièses et bémoles

			//Insérer l'ensemble des instruments dans une liste ou collection d'objets
			//Insérer les scores
			//Insérer les paramètres
	}

		f_notes.close();
		//Fin du chargement du fichier Notes
		
		// Enregistrer tous les éléments dans une liste ou une collection et le faire passer entre les classes 
		// ou / et WindowsForms
		

	Application::Run(gcnew Form_Main);

	}
	return 0;
}
