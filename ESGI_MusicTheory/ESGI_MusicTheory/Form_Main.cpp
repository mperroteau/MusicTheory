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
#include <ctime>


#include "msclr\marshal_cppstd.h"


using namespace ESGI_MusicTheory;
using namespace System::Windows::Forms;
using namespace std;

//void Form_Main::setCurrentFrequence(float current)
//{
//	this->frm_frequencecourante->Text = current.ToString();
//}

double diffclock( clock_t clock1, clock_t clock2 ) {

        double diffticks = clock1 - clock2;
        double diffms    = diffticks / ( CLOCKS_PER_SEC / 1000 );

        return diffms;
    }

void Form_Main::StartTest(int arg_nbNotes, Parametre &_parametres)
		{
			int random_note;
			int nbcurrentnote = 0;
			Note currentnote;
			float min_frequence;
			float max_frequence;
			bool continu;
			int _nbNotes = arg_nbNotes;
			int goodnotes = 0;

			//Ajout d'un timer
			clock_t start = clock();

			this->l_Note->Text = "Note : ";
			this->l_Note->Refresh();
			this->frm_nbnotes->Text = "/ "+ _nbNotes.ToString();
			this->frm_nbnotes->Refresh();

			this->status->Text = "";
			this->status->Refresh();

			Note oldNote;

			while (nbcurrentnote < _nbNotes)
			{
				continu = false;
				random_note = rand() % 55; 
				Note currentNote = currentNote.getNoteById(random_note);
							
				min_frequence = _parametres.getInstru().GetNote_basse();
				max_frequence = _parametres.getInstru().GetNote_haute();

				std::string cn_name;
				

				float current_frequence = currentNote.GetFrequence();

				if ((current_frequence >= min_frequence && current_frequence <= max_frequence) && (oldNote.GetFrequence()!=current_frequence))
				{
					
					this->frm_nbnotecourante->Text = (nbcurrentnote+1).ToString();
					this->frm_nbnotecourante->Refresh();

					String^ _imagepath = gcnew String(currentNote.GetImage().c_str());
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
					this->frm_thisnote->Text = gcnew String(currentNote.GetNom().c_str())+" ("+currentNote.GetOctave().ToString()+")";
					this->frm_thisnote->Refresh();


					cout << "\n" << "Test sur la note : " << currentNote.GetNom() << " " <<currentNote.GetOctave()<<  " - "<<currentNote.GetFrequence() << "\n";
					cn_name = currentNote.GetNom();
		

					while (true)
					{
						//x1000
						if (tb_spernote->Text == "")
						{
							continu = currentNote.Listen();
						}
						else 
						{
							double sn = Convert::ToDouble(tb_spernote->Text);
							sn = sn*1000;
							continu = currentNote.Listen(sn);
						}

						if (continu == true)
						{
							goodnotes++;
							status->Text = "Bien joué !";
						}
						else 
							status->Text = "Trop tard ...";
						status->Refresh();
						break;
					}

					cout << "OK \n";
					nbcurrentnote ++;
					oldNote = currentNote;
					
				}
				
			}

			clock_t end = clock();

			this->frm_nbnotecourante->Text = (nbcurrentnote).ToString();
			this->frm_nbnotecourante->Refresh();
			this->status->Text = "Test terminé, nombre de bonnes notes : " + goodnotes.ToString() + " / " + _nbNotes.ToString();
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

