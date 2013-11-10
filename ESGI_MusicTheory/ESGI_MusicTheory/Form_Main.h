#pragma once
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

#include "Form_RandomTest.h"
#include "Note.h"
#include "Instrument.h"
#include "Parametre.h"


namespace ESGI_MusicTheory {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de Form_Main
	/// </summary>
	public ref class Form_Main : public System::Windows::Forms::Form
	{
	public:
		Form_Main(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}


	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~Form_Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  BT_RandomTest;

	private: System::Windows::Forms::Label^  test;
	public: System::Windows::Forms::Label^  frm_nbnotes;
	private: 
	public: System::Windows::Forms::Label^  frm_nbnotecourante;
	public: System::Windows::Forms::Label^  frm_frequencecourante;
	public: System::Windows::Forms::PictureBox^  frm_picturenote;
	public: System::Windows::Forms::Label^  frm_thisnote;
	public: System::Windows::Forms::Label^  l_Note;

	public: 

	public: 
	private: System::Windows::Forms::ToolTip^  toolTip1;
	private: System::Windows::Forms::ComboBox^  instrumentSelector;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  par_nbnotes;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  status;

	private: System::ComponentModel::IContainer^  components;


	protected: 

	protected: 

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->BT_RandomTest = (gcnew System::Windows::Forms::Button());
			this->test = (gcnew System::Windows::Forms::Label());
			this->frm_nbnotes = (gcnew System::Windows::Forms::Label());
			this->frm_nbnotecourante = (gcnew System::Windows::Forms::Label());
			this->frm_frequencecourante = (gcnew System::Windows::Forms::Label());
			this->frm_picturenote = (gcnew System::Windows::Forms::PictureBox());
			this->frm_thisnote = (gcnew System::Windows::Forms::Label());
			this->l_Note = (gcnew System::Windows::Forms::Label());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->instrumentSelector = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->par_nbnotes = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->status = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->frm_picturenote))->BeginInit();
			this->SuspendLayout();
			// 
			// BT_RandomTest
			// 
			this->BT_RandomTest->Location = System::Drawing::Point(53, 65);
			this->BT_RandomTest->Name = L"BT_RandomTest";
			this->BT_RandomTest->Size = System::Drawing::Size(123, 38);
			this->BT_RandomTest->TabIndex = 0;
			this->BT_RandomTest->Text = L"Random Quizz";
			this->BT_RandomTest->UseVisualStyleBackColor = true;
			this->BT_RandomTest->Click += gcnew System::EventHandler(this, &Form_Main::BT_RandomTest_Click);
			// 
			// test
			// 
			this->test->AutoSize = true;
			this->test->Location = System::Drawing::Point(305, 89);
			this->test->Name = L"test";
			this->test->Size = System::Drawing::Size(0, 13);
			this->test->TabIndex = 2;
			// 
			// frm_nbnotes
			// 
			this->frm_nbnotes->AutoSize = true;
			this->frm_nbnotes->Location = System::Drawing::Point(291, 208);
			this->frm_nbnotes->Name = L"frm_nbnotes";
			this->frm_nbnotes->Size = System::Drawing::Size(0, 13);
			this->frm_nbnotes->TabIndex = 11;
			// 
			// frm_nbnotecourante
			// 
			this->frm_nbnotecourante->AutoSize = true;
			this->frm_nbnotecourante->Location = System::Drawing::Point(249, 208);
			this->frm_nbnotecourante->Name = L"frm_nbnotecourante";
			this->frm_nbnotecourante->Size = System::Drawing::Size(0, 13);
			this->frm_nbnotecourante->TabIndex = 10;
			// 
			// frm_frequencecourante
			// 
			this->frm_frequencecourante->AutoSize = true;
			this->frm_frequencecourante->Location = System::Drawing::Point(468, 65);
			this->frm_frequencecourante->Name = L"frm_frequencecourante";
			this->frm_frequencecourante->Size = System::Drawing::Size(0, 13);
			this->frm_frequencecourante->TabIndex = 9;
			// 
			// frm_picturenote
			// 
			this->frm_picturenote->ImageLocation = L"";
			this->frm_picturenote->Location = System::Drawing::Point(244, 96);
			this->frm_picturenote->Name = L"frm_picturenote";
			this->frm_picturenote->Size = System::Drawing::Size(164, 89);
			this->frm_picturenote->TabIndex = 8;
			this->frm_picturenote->TabStop = false;
			this->frm_picturenote->Click += gcnew System::EventHandler(this, &Form_Main::frm_picturenote_Click);
			// 
			// frm_thisnote
			// 
			this->frm_thisnote->AutoSize = true;
			this->frm_thisnote->Location = System::Drawing::Point(305, 65);
			this->frm_thisnote->Name = L"frm_thisnote";
			this->frm_thisnote->Size = System::Drawing::Size(0, 13);
			this->frm_thisnote->TabIndex = 7;
			// 
			// l_Note
			// 
			this->l_Note->AutoSize = true;
			this->l_Note->Location = System::Drawing::Point(246, 65);
			this->l_Note->Name = L"l_Note";
			this->l_Note->Size = System::Drawing::Size(0, 13);
			this->l_Note->TabIndex = 6;
			// 
			// instrumentSelector
			// 
			this->instrumentSelector->FormattingEnabled = true;
			this->instrumentSelector->Items->AddRange(gcnew cli::array< System::Object^  >(14) {L"Default", L"Piccolo", L"Grande Flute", 
				L"Flute Alto", L"Haubois", L"Cor Anglais", L"Clarinette", L"Clarinette basse", L"Basson", L"Contrebasson", L"Cor", L"Trompette", 
				L"Trombone", L"Tuba"});
			this->instrumentSelector->Location = System::Drawing::Point(53, 142);
			this->instrumentSelector->Name = L"instrumentSelector";
			this->instrumentSelector->Size = System::Drawing::Size(121, 21);
			this->instrumentSelector->TabIndex = 13;
			this->instrumentSelector->SelectedIndexChanged += gcnew System::EventHandler(this, &Form_Main::instrumentSelector_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(50, 121);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 13);
			this->label1->TabIndex = 14;
			this->label1->Text = L"Instrument";
			this->label1->Click += gcnew System::EventHandler(this, &Form_Main::label1_Click);
			// 
			// par_nbnotes
			// 
			this->par_nbnotes->Location = System::Drawing::Point(53, 206);
			this->par_nbnotes->Name = L"par_nbnotes";
			this->par_nbnotes->Size = System::Drawing::Size(100, 20);
			this->par_nbnotes->TabIndex = 15;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(53, 181);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(88, 13);
			this->label2->TabIndex = 16;
			this->label2->Text = L"Nombre de notes";
			this->label2->Click += gcnew System::EventHandler(this, &Form_Main::label2_Click);
			// 
			// status
			// 
			this->status->AutoSize = true;
			this->status->Location = System::Drawing::Point(246, 273);
			this->status->Name = L"status";
			this->status->Size = System::Drawing::Size(0, 13);
			this->status->TabIndex = 17;
			this->status->Click += gcnew System::EventHandler(this, &Form_Main::label3_Click);
			// 
			// Form_Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(528, 321);
			this->Controls->Add(this->status);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->par_nbnotes);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->instrumentSelector);
			this->Controls->Add(this->frm_nbnotes);
			this->Controls->Add(this->frm_nbnotecourante);
			this->Controls->Add(this->frm_frequencecourante);
			this->Controls->Add(this->frm_picturenote);
			this->Controls->Add(this->frm_thisnote);
			this->Controls->Add(this->l_Note);
			this->Controls->Add(this->test);
			this->Controls->Add(this->BT_RandomTest);
			this->Name = L"Form_Main";
			this->Text = L"Music Theory";
			this->Load += gcnew System::EventHandler(this, &Form_Main::Form_Main_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->frm_picturenote))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public : 
		void StartTest(int _nbNotes, Parametre &_parametres);
		void StartParametres();
		//void setCurrentFrequence(String^ _current)
		//{
		//	if (frm_frequencecourante->InvokeRequired)
		//		{
		//			// this executes on the worker thread
		//			frm_frequencecourante->Invoke (gcnew Action<String^>(this->setCurrentFrequence), _current);
		//			//frm_frequencecourante->Invoke(gcnew Action(setCurrentFrequence), _current);
		//			return;

		//		}  
		//	frm_frequencecourante->Text = _current; // this executes on the main thread
		//	frm_frequencecourante->Refresh();

		//}



private:System::Void BT_RandomTest_Click(System::Object^  sender, System::EventArgs^  e) {
			//Form_RandomTest^ form_rdt = gcnew Form_RandomTest();
			//form_rdt->Show();
			//Instrument *i = new Instrument();
			//getinstrument
			/*Instrument *i = new Instrument("Default", "Default", static_cast<float>(261.6),static_cast<float>(523.2));			
			Parametre *p = new Parametre(*i);*/

	//		string fichier_instrument;
	//	ifstream f_parametres("Data/Parametres.csv"); 
	//	string value;

	//	if (f_parametres)
	//	{
	//		string p_nom = "";
	//		int p_level;
	//		int p_nbnotes;

	//	
	//		while ( getline( f_parametres, value ) )
	//		{
	//			char *sArr = new char[value.length()+1];
	//			strcpy(sArr, value.c_str());
	//			// Déclare un pointeur char
	//			char *sPtr;
	//			// Donne le delimiter
	//			sPtr = strtok(sArr, ";");

	//			int i =1;	
 //
	//			// Pour toute chaine entre ;
	//			while(sPtr != NULL) 
	//			{
	//				if (i==1)
	//					p_nom = sPtr;
	//				else if (i==2)
	//					p_level = atoi(sPtr);
	//				else if (i==3)
	//					p_nbnotes = atoi(sPtr);
	//			
	//				
	//				// Aller jusqu'au prochain mot
	//				sPtr = strtok(NULL, ";");

	//				i++;
	//			}			
	//		
	//		
	//	}
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
	String^ _instrumentSelector = (instrumentSelector->Text);

	for (Instrument i : _Instruments)
	{
		String^ _instrumentName = gcnew String(i.GetNom().c_str());
		if (_instrumentName == _instrumentSelector)
		{
			//!!!normalement *i
			Parametre *p = new Parametre(i);
			int _nbnote = Convert::ToInt32(par_nbnotes->Text);
			StartTest(_nbnote, *p);
		}
	}
	//			//Note *notecourante = new Note(n_id,n_nom,n_nom_2,n_octave,n_frequence,"", ""); //Le dernier champs étant l'image -> TO DO

	//			_Instruments.push_back(Instrument(i_nom,i_type,i_note_basse,i_note_haute));
	//		
	//		
	//	}
	//		

	//		f_instuments.close();
	//	}
	//	//Instrument inst_param;
	//	Parametre *p=new Parametre();
	//	for (Instrument i : _Instruments)
	//	{
	//		if (i.GetNom() == "p_nom")
	//			p = new Parametre(i,p_level,p_nbnotes);

	//	}
	//	f_parametres.close();

			/*for (int i = 0; i < 5; i++)
			{
				test->Text = i.ToString();
				test->Refresh();
			}
			*/

			//for (int i = 0; i < 5; i++)
			//{
			//	String^ t = "hello";
			//	l_Note->Text = t;  
			//}

			//StartTest(5, *p);			
			
	}
	
	private: System::Void BT_Parametres_Click(System::Object^  sender, System::EventArgs^  e) {
			//Form_Parametres^ form_p = gcnew Form_Parametres();
			//form_p->Show();
				 //StartParametres();


		//ofstream fichier("Parametres.csv", ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert
  //
  //      if(fichier)
  //      {
		//	fichier.clear;
			//int Index = comboBox_instument->SelectedIndex;
			/*Object^ selectedInstrument = comboBox_instument->SelectedItem;
		   			
			Object^ selectedNiveau = comboBox_level->SelectedItem;
			Object^ nb_notes = textBox_nb_elements->Text;
			
			System::String^ instrument = selectedInstrument->ToString();
			System::String^ niveau = comboBox_level->ToString();
			System::String^ nb_notes = nb_notes->ToString();

			string instru = instrument;
			fichier << &instrument << ";"<< &niveau << ";"<<&nb_notes;*/
       /* }
        else
                cerr << "Impossible d'ouvrir le fichier !" << endl;
      
		 }

			 }*/
			 }
	private: System::Void Form_Main_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void instrumentSelector_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void frm_picturenote_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
