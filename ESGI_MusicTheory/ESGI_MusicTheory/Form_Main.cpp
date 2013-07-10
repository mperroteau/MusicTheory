#include "Form_Main.h"
#include "Form_Parametres.h"
#include "Note.h"
#include "Instrument.h"
#include "Parametre.h"

using namespace ESGI_MusicTheory;
using namespace System::Windows::Forms;
using namespace std;

void Form_Main::StartTest(int arg_nbNotes, Parametre &_parametres)
		{
			int random_note;
			int nbcurrentnote = 0;
			Note currentnote;
			float min_frequence;
			float max_frequence;
			bool continu;
			int _nbNotes = arg_nbNotes;

			while (nbcurrentnote <= _nbNotes)
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
					cout << "\n" << "Test sur la note : " << currentNote.GetNom() << " " <<currentNote.GetOctave()<<  " - "<<currentNote.GetFrequence() << "\n";
					cn_name = currentNote.GetNom();

					
					
					while (continu == false)
					{
						continu = currentNote.Listen();
					}
					cout << "OK \n";
					nbcurrentnote ++;
					
				}
				
			}
		}

System::Void BT_RandomTest_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::Run(gcnew Form_Parametres);
	//Application::Run(gcnew Form_Parametres);
			 }

