#include "Form_Main.h"
#include "Note.h"
#include "Instrument.h"
#include "Parametre.h"

#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <list>
#include <string>
#include <tchar.h>
#include <assert.h>
#include <fstream>
#include <conio.h>
#include <math.h>

#include "msclr\marshal_cppstd.h"


using namespace ESGI_MusicTheory;
using namespace System::Windows::Forms;
using namespace std;

//void Form_Main::setCurrentFrequence(float current)
//{
//	this->frm_frequencecourante->Text = current.ToString();
//}

void Form_Main::StartTest(int arg_nbNotes, Parametre &_parametres)
		{
			int random_note;
			int nbcurrentnote = 0;
			Note currentnote;
			float min_frequence;
			float max_frequence;
			bool continu;
			int _nbNotes = arg_nbNotes;


			this->l_Note->Text = "Note : ";
			this->l_Note->Refresh();
			this->frm_nbnotes->Text = "/ "+ _nbNotes.ToString();
			this->frm_nbnotes->Refresh();

			this->status->Text = "";
			this->status->Refresh();

			while (nbcurrentnote < _nbNotes)
			{
				continu = false;
				random_note = rand() % 97; 
				Note currentNote = currentNote.getNoteById(random_note);
				

				
				min_frequence = _parametres.getInstru().GetNote_basse();
				max_frequence = _parametres.getInstru().GetNote_haute();

				std::string cn_name;
				

				float current_frequence = currentNote.GetFrequence();
				

				if (current_frequence >= min_frequence && current_frequence <= max_frequence)
				{
					
					this->frm_nbnotecourante->Text = (nbcurrentnote+1).ToString();
					this->frm_nbnotecourante->Refresh();

					String^ _imagepath = gcnew String(currentNote.GetImage().c_str());
					//this->frm_picturenote->Load(_imagepath);
					if (_imagepath == "")
					{
						this->frm_picturenote->Image = nullptr;
						this->frm_picturenote->Refresh();
					}
					else
					{
						this->frm_picturenote->Image = Image::FromFile(_imagepath);
						this->frm_picturenote->Refresh();
					}
					//Convertit un string "normal" afin de pouvoir l'afficher dans le label
					this->frm_thisnote->Text = gcnew String(currentNote.GetNom().c_str());
					this->frm_thisnote->Refresh();

					//timer
					/*
					System::Threading::TimerCallback^ tcb = gcnew System::Threading::TimerCallback(
					Timer^ stateTimer = gcnew Timer(tcb, autoEvent, 1000, 250);*/

					cout << "\n" << "Test sur la note : " << currentNote.GetNom() << " " <<currentNote.GetOctave()<<  " - "<<currentNote.GetFrequence() << "\n";
					cn_name = currentNote.GetNom();

					
					
					while (continu == false)
					{
						//Faire le random dans le while et n'utiliser le listen que pour lire dans le micro
						//Faire toutes les vérifications ici afin de povoir
						//continu = currentNote.Listen();
						continu = currentNote.Listen();
						
					}

					/*si timer faire en fonction du timer*/
					cout << "OK \n";
					nbcurrentnote ++;
					
				}
				
			}

			this->frm_nbnotecourante->Text = (nbcurrentnote).ToString();
			this->frm_nbnotecourante->Refresh();
			this->status->Text = "Test terminé";
			this->status->Refresh();

		}

void Form_Main::StartParametres()
{
	string fichier_instrument;
	ifstream f_instuments("Data/Instruments.csv"); 
	string value;
	list<Instrument> _Instruments;

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
						i_note_basse = static_cast<float>(atof(sPtr));
					else if (i==4)
						i_note_haute = static_cast<float>(atof(sPtr));


					
					// Go to the next word.
					sPtr = strtok(NULL, ";");

					i++;
				}
				//Note *notecourante = new Note(n_id,n_nom,n_nom_2,n_octave,n_frequence,"", ""); //Le dernier champs étant l'image -> TO DO

				_Instruments.push_back(Instrument(i_nom,i_type,i_note_basse,i_note_haute));
			
			
		}
			

			f_instuments.close();
		}

		int it = 1;
		for (Instrument i : _Instruments)
		{
			cout << it << " "<< i.GetNom() << "\n";
			it++;
		}

		cout << "\n" << "Selectionner l'instrument" << "\n";
		int instrument_id;
		cin >> instrument_id;

		it  =0;
		for (Instrument i : _Instruments)
		{
			if (it==instrument_id)
			{
				fichier_instrument = i.GetNom();
				break;
			}
			it++;
		}
		string strNiveau;
		string strIteration;
		cout<<"\n"<< "Selectionner le niveau (/10)"<<"\n";
		
		cin >> strNiveau;

		cout<<"\n"<< "Selectionner le nombre de notes"<<"\n";
		cin >> strIteration;

		

		ofstream fichier("Data/Parametres.csv", ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert
  
        if(fichier)
        {
			fichier.clear();
			
			fichier << fichier_instrument << ";"<< strNiveau << ";"<<strIteration;
			cout<<"\n"<<"Parametres enregistres"<<"\n";
        }
        else
                cerr << "Impossible d'ouvrir le fichier !" << endl;
      
}

System::Void BT_RandomTest_Click(System::Object^  sender, System::EventArgs^  e) {
	//Application::Run(gcnew Form_Parametres);
			 }

