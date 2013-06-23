#include <stdio.h>
#include <string>
#include <tchar.h>
#include <iostream>
#include <assert.h>
#include "Form_Main.h"
#include <Windows.h>
#include <fstream>
#include "Note.h"
#include "Instrument.h"
#include <vector>

using namespace ESGI_MusicTheory;
using namespace System::Windows::Forms;
using namespace std;

list<Note> setNotes(list<Note>& Notes)
{
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
			//Note *notecourante = new Note(n_id,n_nom,n_nom_2,n_octave,n_frequence,"", ""); //Le dernier champs étant l'image -> TO DO
			Notes.push_back(Note(n_id,n_nom,n_nom_2,n_octave,n_frequence,"", ""));
			
			//notes.push_back()

			//Insérer toutes les images du programme dans un dossier avec pour nom l'id de la note
			//+ "_" pour les dièses et bémoles

			//Insérer l'ensemble des instruments dans une liste ou collection d'objets
			//Insérer les scores
			//Insérer les paramètres
	}

		f_notes.close();
	}
	return Notes;

}

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


	
	list<Note> Notes; // Liste de notes
	list<Instrument> Instruments;

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
			//Note *notecourante = new Note(n_id,n_nom,n_nom_2,n_octave,n_frequence,"", ""); //Le dernier champs étant l'image -> TO DO
			Notes.push_back(Note(n_id,n_nom,n_nom_2,n_octave,n_frequence,"", ""));
			
			
	}

		f_notes.close();
	}

		 for(Note n : Notes) //parcours de la liste
			 cout<< n.GetFrequence() << "\n";
      

		//Insérer les instruments

		

	Application::Run(gcnew Form_Main);

	
	return 0;
}

