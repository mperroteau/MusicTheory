#include <stdio.h>
#include <string>
#include <tchar.h>
#include <iostream>
#include <assert.h>
#include <Windows.h>
#include <fstream>
#include "Note.h"
#include "Instrument.h"
#include "Form_Main.h"


using namespace ESGI_MusicTheory;
using namespace System::Windows::Forms;
using namespace std;


int main()
{
	/*Génération de la liste de notes à partir du csv*/

	//setNotes();
	
	for(Note n : Notes) //parcours de la liste
	{
		cout<< n.GetNom() << " - " << n.GetNom_2();
		cout<< " - "<<n.GetFrequence() << "\n";
	}

	/*Génération de la liste d'instruments à partir du csv

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
			//Note *notecourante = new Note(n_id,n_nom,n_nom_2,n_octave,n_frequence,"", ""); //Le dernier champs étant l'image -> TO DO

			Instruments.push_back(Instrument(i_nom,i_type,i_note_basse,i_note_haute));
			
			
	}

		f_instuments.close();
	}

	*/

		 for(Instrument i : Instruments)
			 cout<< i.GetNom() << " - " << printf("%f",i.GetNote_haute()) << "-"<<printf("%f",i.GetNote_basse()) <<"\n";


			
      
	Application::Run(gcnew Form_Main);
	/*Form_Parametres^ form = gcnew Form_Parametres();
			form->Show();*/
	
	return 0;
}

