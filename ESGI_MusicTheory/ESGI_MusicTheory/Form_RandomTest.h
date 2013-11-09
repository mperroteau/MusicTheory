#pragma once
#include <sstream>
#include <iostream>

#include "Note.h"
#include "Parametre.h"


namespace ESGI_MusicTheory {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de Form_RandomTest
	/// </summary>
	public ref class Form_RandomTest : public System::Windows::Forms::Form
	{
	public:
		/*
		void StartTest(int _nbNotes, Parametre &_parametres)
		{
			int random_note;
			int nbcurrentnote = 0;
			Note currentnote;
			float min_frequence;
			float max_frequence;
			bool continu;

			//this->frm_nbnotes->Text = String::Format(L"{0}", _nbNotes);
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
					cn_name = currentNote.GetNom();
					//this->frm_thisnote->Text = L"{0}", currentNote.GetNom();
					//this->frm_nbnotecourante->Text = String::Format(L"{0}", nbcurrentnote);
					
					while (continu == false)
					{
						continu = currentNote.Listen();
					}
				}
				
			}
		}
		*/
		Form_RandomTest(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			
			//
			
			//StartTest(5, *p);
			

		}

		

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~Form_RandomTest()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Label^  label1;
	public: System::Windows::Forms::Label^  frm_thisnote;

	public: System::Windows::Forms::PictureBox^  frm_picturenote;
	public: System::Windows::Forms::Label^  frm_frequencecourante;
	public: System::Windows::Forms::Label^  frm_nbnotecourante;



	public: System::Windows::Forms::Label^  frm_nbnotes;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->frm_thisnote = (gcnew System::Windows::Forms::Label());
			this->frm_picturenote = (gcnew System::Windows::Forms::PictureBox());
			this->frm_frequencecourante = (gcnew System::Windows::Forms::Label());
			this->frm_nbnotecourante = (gcnew System::Windows::Forms::Label());
			this->frm_nbnotes = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->frm_picturenote))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(47, 50);
			this->label1->Name = "label1";
			this->label1->Size = System::Drawing::Size(36, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = "Note :";
			
			// 
			// frm_thisnote
			// 
			this->frm_thisnote->AutoSize = true;
			this->frm_thisnote->Location = System::Drawing::Point(106, 50);
			this->frm_thisnote->Name = "frm_thisnote";
			this->frm_thisnote->Size = System::Drawing::Size(90, 13);
			this->frm_thisnote->TabIndex = 1;
			this->frm_thisnote->Text = "frm_notecourante";
			// 
			// frm_picturenote
			// 
			this->frm_picturenote->Location = System::Drawing::Point(109, 81);
			this->frm_picturenote->Name = "frm_picturenote";
			this->frm_picturenote->Size = System::Drawing::Size(100, 50);
			this->frm_picturenote->TabIndex = 2;
			this->frm_picturenote->TabStop = false;
			// 
			// frm_frequencecourante
			// 
			this->frm_frequencecourante->AutoSize = true;
			this->frm_frequencecourante->Location = System::Drawing::Point(269, 50);
			this->frm_frequencecourante->Name = "frm_frequencecourante";
			this->frm_frequencecourante->Size = System::Drawing::Size(120, 13);
			this->frm_frequencecourante->TabIndex = 3;
			this->frm_frequencecourante->Text = "frm_frequence courante";
			// 
			// frm_nbnotecourante
			// 
			this->frm_nbnotecourante->AutoSize = true;
			this->frm_nbnotecourante->Location = System::Drawing::Point(50, 193);
			this->frm_nbnotecourante->Name = "frm_nbnotecourante";
			this->frm_nbnotecourante->Size = System::Drawing::Size(102, 13);
			this->frm_nbnotecourante->TabIndex = 4;
			this->frm_nbnotecourante->Text = "frm_nbnotecourante";
			// 
			// frm_nbnotes
			// 
			this->frm_nbnotes->AutoSize = true;
			this->frm_nbnotes->Location = System::Drawing::Point(92, 193);
			this->frm_nbnotes->Name = "frm_nbnotes";
			this->frm_nbnotes->Size = System::Drawing::Size(65, 13);
			this->frm_nbnotes->TabIndex = 5;
			this->frm_nbnotes->Text = "frm_nbnotes";
			// 
			// Form_RandomTest
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(473, 261);
			this->Controls->Add(this->frm_nbnotes);
			this->Controls->Add(this->frm_nbnotecourante);
			this->Controls->Add(this->frm_frequencecourante);
			this->Controls->Add(this->frm_picturenote);
			this->Controls->Add(this->frm_thisnote);
			this->Controls->Add(this->label1);
			this->Name = L"Form_RandomTest";
			this->Text = L"Quizz";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->frm_picturenote))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		/*public :
			void StartTest(int _nbNotes, Parametre &_parametres);
			void StartParametres();

			private:System::*/
	};
}
