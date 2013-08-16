#pragma once
#include "Form_Parametres.h"
#include "Form_RandomTest.h"
#include "Parametre.h"
#include "Note.h"
#include "Instrument.h"

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
	private: System::Windows::Forms::Button^  BT_Parametres;

	protected: 

	protected: 

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->BT_RandomTest = (gcnew System::Windows::Forms::Button());
			this->BT_Parametres = (gcnew System::Windows::Forms::Button());
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
			// BT_Parametres
			// 
			this->BT_Parametres->Location = System::Drawing::Point(53, 171);
			this->BT_Parametres->Name = L"BT_Parametres";
			this->BT_Parametres->Size = System::Drawing::Size(123, 38);
			this->BT_Parametres->TabIndex = 1;
			this->BT_Parametres->Text = L"Parametres";
			this->BT_Parametres->UseVisualStyleBackColor = true;
			this->BT_Parametres->Click += gcnew System::EventHandler(this, &Form_Main::BT_Parametres_Click);
			// 
			// Form_Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(495, 283);
			this->Controls->Add(this->BT_Parametres);
			this->Controls->Add(this->BT_RandomTest);
			this->Name = L"Form_Main";
			this->Text = L"Music Theory";
			this->ResumeLayout(false);

		}
#pragma endregion

	public : 
		void StartTest(int _nbNotes, Parametre &_parametres);
		void StartParametres();


private:System::Void BT_RandomTest_Click(System::Object^  sender, System::EventArgs^  e) {
			//Form_RandomTest^ form_rdt = gcnew Form_RandomTest();
			//form_rdt->Show();
			Instrument *i = new Instrument("Default", "Default", 261.6,523.2);
			
			Parametre *p = new Parametre(*i);

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
	//		string fichier_instrument;
	//ifstream f_instuments("Data/Instruments.csv"); 
	//string value;
	//list<Instrument> _Instruments;

	//	if (f_instuments)
	//	{
	//		string i_nom = "";
	//		string i_type = "";
	//		float i_note_basse = NULL;
	//		float i_note_haute = NULL;
	//	
	//		while ( getline( f_instuments, value ) )
	//		{
	//			char *sArr = new char[value.length()+1];
	//			strcpy(sArr, value.c_str());
	//			// Declare char pointer sPtr for the tokens.
	//			char *sPtr;
	//			// Get all the tokens with " " as delimiter.
	//			sPtr = strtok(sArr, ";");

	//			int i =1;	
 //
	//			// For all tokens.
	//			while(sPtr != NULL) 
	//			{
	//				if (i==1)
	//					i_nom = sPtr;
	//				else if (i==2)
	//					i_type = sPtr;
	//				else if (i==3)
	//					i_note_basse = atof(sPtr);
	//				else if (i==4)
	//					i_note_haute = atof(sPtr);

	//				
	//				// Go to the next word.
	//				sPtr = strtok(NULL, ";");

	//				i++;
	//			}
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
			StartTest(5, *p);

			
		
		
			
			
	}
	
	private: System::Void BT_Parametres_Click(System::Object^  sender, System::EventArgs^  e) {
			//Form_Parametres^ form_p = gcnew Form_Parametres();
			//form_p->Show();
				 StartParametres();


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
	};
}
