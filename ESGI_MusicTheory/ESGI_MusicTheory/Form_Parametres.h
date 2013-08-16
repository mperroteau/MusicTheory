#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <list>
#include <string>
#include <tchar.h>
#include <assert.h>
#include <fstream>
#include "Note.h"
#include "Instrument.h"
#include <fstream>
#include <sstream>

#pragma once

namespace ESGI_MusicTheory {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de Form_Parametres
	/// </summary>
	public ref class Form_Parametres : public System::Windows::Forms::Form
	{
	public:
		Form_Parametres(void)
		{
			InitializeComponent();
			//ifstream f_notes("Data/Instruments.csv"); 
			//string value;
			//list<Instrument> _Instruments;

			//ifstream f_instuments("Data/Instruments.csv"); 

			//if (f_instuments)
			//{
			//	string i_nom = "";
			//	string i_type = "";
			//	float i_note_basse = NULL;
			//	float i_note_haute = NULL;
		
			//	while (getline( f_instuments, value) )
			//	{
			//		char *sArr = new char[value.length()+1];
			//		strcpy(sArr, value.c_str());
			//		// Declare char pointer sPtr for the tokens.
			//		char *sPtr;
			//		// Get all the tokens with " " as delimiter.
			//		sPtr = strtok(sArr, ";");

			//		int i =1;	
 
			//		// For all tokens.
			//		while(sPtr != NULL) 
			//		{
			//			if (i==1)
			//				i_nom = sPtr;
			//			else if (i==2)
			//				i_type = sPtr;
			//			else if (i==3)
			//				i_note_basse = atof(sPtr);
			//			else if (i==4)
			//				i_note_haute = atof(sPtr);

			//		
			//			// Go to the next word.
			//			sPtr = strtok(NULL, ";");

			//			i++;
			//		}
			//		//Note *notecourante = new Note(n_id,n_nom,n_nom_2,n_octave,n_frequence,"", ""); //Le dernier champs étant l'image -> TO DO

			//		Instruments.push_back(Instrument(i_nom,i_type,i_note_basse,i_note_haute));
			//
			//
			//}

			//	f_instuments.close();
			//}


				comboBox_instument->Items->Add("Default");
				comboBox_instument->Items->Add("Piccolo");
				comboBox_instument->Items->Add("Grande Flute");
				comboBox_instument->Items->Add("Flute");
				comboBox_instument->Items->Add("Haubois");
				comboBox_instument->Items->Add("Cor Anglais");
				comboBox_instument->Items->Add("Clarinette");
				comboBox_instument->Items->Add("Clarinette basse");
				comboBox_instument->Items->Add("Basson");
				comboBox_instument->Items->Add("Contrebasson");
				comboBox_instument->Items->Add("Cor");
				comboBox_instument->Items->Add("Trompette");
				comboBox_instument->Items->Add("Trombone");
				comboBox_instument->Items->Add("Tuba");

				comboBox_level->Items->Add("1");
				comboBox_level->Items->Add("2");



			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~Form_Parametres()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::NotifyIcon^  notifyIcon1;
	private: System::Windows::Forms::ComboBox^  comboBox_instument;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  comboBox_level;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox_nb_elements;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  bttn_save_parametres;
	protected: 
	private: System::ComponentModel::IContainer^  components;

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
			this->notifyIcon1 = (gcnew System::Windows::Forms::NotifyIcon(this->components));
			this->comboBox_instument = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox_level = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox_nb_elements = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->bttn_save_parametres = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// notifyIcon1
			// 
			this->notifyIcon1->Text = L"notifyIcon1";
			this->notifyIcon1->Visible = true;
			// 
			// comboBox_instument
			// 
			this->comboBox_instument->FormattingEnabled = true;
			this->comboBox_instument->Location = System::Drawing::Point(84, 47);
			this->comboBox_instument->Name = L"comboBox_instument";
			this->comboBox_instument->Size = System::Drawing::Size(121, 21);
			this->comboBox_instument->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Instrument";
			// 
			// comboBox_level
			// 
			this->comboBox_level->FormattingEnabled = true;
			this->comboBox_level->Location = System::Drawing::Point(84, 88);
			this->comboBox_level->Name = L"comboBox_level";
			this->comboBox_level->Size = System::Drawing::Size(121, 21);
			this->comboBox_level->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 91);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(41, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Niveau";
			// 
			// textBox_nb_elements
			// 
			this->textBox_nb_elements->Location = System::Drawing::Point(133, 143);
			this->textBox_nb_elements->Name = L"textBox_nb_elements";
			this->textBox_nb_elements->Size = System::Drawing::Size(72, 20);
			this->textBox_nb_elements->TabIndex = 4;
			this->textBox_nb_elements->TextChanged += gcnew System::EventHandler(this, &Form_Parametres::textBox1_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 146);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(97, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Nombre d\'éléments";
			// 
			// bttn_save_parametres
			// 
			this->bttn_save_parametres->Location = System::Drawing::Point(15, 207);
			this->bttn_save_parametres->Name = L"bttn_save_parametres";
			this->bttn_save_parametres->Size = System::Drawing::Size(75, 23);
			this->bttn_save_parametres->TabIndex = 6;
			this->bttn_save_parametres->Text = L"Save";
			this->bttn_save_parametres->UseVisualStyleBackColor = true;
			this->bttn_save_parametres->Click += gcnew System::EventHandler(this, &Form_Parametres::bttn_save_parametres_Click);
			// 
			// Form_Parametres
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(244, 261);
			this->Controls->Add(this->bttn_save_parametres);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox_nb_elements);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->comboBox_level);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox_instument);
			this->Name = L"Form_Parametres";
			this->Text = L"Parametres";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void bttn_save_parametres_Click(System::Object^  sender, System::EventArgs^  e) {

			// StartParametres();
		 }
};
}
