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
			//Note *notecourante = new Note(n_id,n_nom,n_nom_2,n_octave,n_frequence,"", ""); //Le dernier champs �tant l'image -> TO DO
			Notes.push_back(Note(n_id,n_nom,n_nom_2,n_octave,n_frequence,"", ""));
			
			//notes.push_back()

			//Ins�rer toutes les images du programme dans un dossier avec pour nom l'id de la note
			//+ "_" pour les di�ses et b�moles

			//Ins�rer l'ensemble des instruments dans une liste ou collection d'objets
			//Ins�rer les scores
			//Ins�rer les param�tres
	}

		f_notes.close();
	}
	return Notes;

}

static list<Note> Notes;
static list<Instrument> Instruments;

int main()
{
	//Lire les fichiers CSV et cr�er des objets depuis ces donn�es
		//Ajouter les notes
		//Ajouter les instrument
		//Ajouter les param�tres
		//Ajouter les scores

	// le constructeur de ifstream permet d'ouvrir un fichier en lecture

	//Faire une fonction qui charge l'ensemble des donn�es dans le main / ou donn�es par donn�es
	//D�but du chargement du fichier notes


	
	//static list<Note> Notes; // Liste de notes
	//static list<Instrument> Instruments;

	/*G�n�ration de la liste de notes � partir du csv*/

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
			//Note *notecourante = new Note(n_id,n_nom,n_nom_2,n_octave,n_frequence,"", ""); //Le dernier champs �tant l'image -> TO DO
			Notes.push_back(Note(n_id,n_nom,n_nom_2,n_octave,n_frequence,"", ""));
			
			
	}

		f_notes.close();
	}


	/*G�n�ration de la liste d'instruments � partir du csv*/

	ifstream f_instuments("Data/Instruments.csv"); 

	if (f_instuments)
	{
				string i_nom = "";
		string i_type = "";
		float i_note_basse = NULL;
		float i_note_haute = NULL;
		
		while ( getline( f_instuments, value ) )
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
					i_nom = sPtr;
				else if (i==2)
					i_type = sPtr;
				else if (i==3)
					i_note_basse = atof(sPtr);
				else if (i==4)
					i_note_haute = atof(sPtr);

					
				// Go to the next word.
				sPtr = strtok(NULL, ";");

				i++;
			}
			//Note *notecourante = new Note(n_id,n_nom,n_nom_2,n_octave,n_frequence,"", ""); //Le dernier champs �tant l'image -> TO DO
			Instruments.push_back(Instrument(i_nom,i_type,i_note_basse,i_note_haute));
			
			
	}

		f_instuments.close();
	}

	
		 for(Note n : Notes) //parcours de la liste
		 {
			 cout<< n.GetNom() << " - " << n.GetNom_2();
			 cout<< " - "<<n.GetFrequence() << "\n";
		 }

		 for(Instrument i : Instruments)
			 cout<< i.GetNom() <<"\n";
      

		//Ins�rer les instruments

		

	Application::Run(gcnew Form_Main);

	
	return 0;
}

