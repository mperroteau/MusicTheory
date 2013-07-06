#include "Form_RandomTest.h"
#include "Parametre.h"
#include "Instrument.h"
#include "Note.h"



//void Form_RandomTest::StartTest(int _nbNotes, Parametre &_parametres)
//{
//	int random_note;
//	int nbcurrentnote = 0;
//	Note currentnote;
//	float min_frequence;
//	float max_frequence;
//	bool continu;
//
//	//this->frm_nbnotes->Text = String::Format(L"{0}", _nbNotes);
//	while (nbcurrentnote <= _nbNotes)
//	{
//		continu = false;
//		random_note = rand() % 97; 
//		Note currentNote = currentNote.getNoteById(random_note);
//		min_frequence = _parametres.getInstru().GetNote_basse();
//		max_frequence = _parametres.getInstru().GetNote_haute();
//
//		std::string cn_name;
//
//		if (currentNote.GetFrequence() >= min_frequence && currentNote.GetFrequence() <= max_frequence)
//		{
//			cn_name = currentNote.GetNom();
//			//this->frm_thisnote->Text = L"{0}", currentNote.GetNom();
//			//this->frm_nbnotecourante->Text = String::Format(L"{0}", nbcurrentnote);
//					
//
//
//			while (continu == false)
//			{
//				continu = currentNote.Listen();
//			}
//		}
//				
//	}
//
//}