#pragma once
#include <sstream>

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
		Form_RandomTest(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			
			//
			Instrument *i = new Instrument("Default", "Default", 261.6,523.2);
			Parametre *p = new Parametre(*i);
			

		}

		void StartTest(int _nbNotes, Parametre &_parametres)
		{

			for(int i = 0; i <= _nbNotes; i++)
			{
				// créer un flux de sortie
				ostringstream _nbNotes_oss;
				// écrire un nombre dans le flux
				_nbNotes_oss << _nbNotes;
				// récupérer une chaîne de caractères
				string  _nbNotes_string = _nbNotes_oss.str();

				this-> nbnotecourante ->Text = "1";
				//this-> nbnotes -> Text -> _nbNotes_string;
				int note = rand() % 100;
				float note_haute = _parametres.getInstru().GetNote_haute();
				float note_basse = _parametres.getInstru().GetNote_basse();

				Note n =  n.getNoteById(note);

				if (n.GetFrequence() > note_basse && n.GetFrequence() < note_haute)
				{
					for (Note n : Notes)
					{
						if (note == n.GetId())
						{
							/*thisnote.value = n.GetNom();*/
							float current_frequence;
							bool b = false;
							while (b==false)
								
								current_frequence = n.Listen(); // Execute listen tant que 
								// if ... b = current_frequence
						}

					
					}
				}
			}

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
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  thisnote;
	private: System::Windows::Forms::PictureBox^  picturenote;
	private: System::Windows::Forms::Label^  frequence;
	private: System::Windows::Forms::Label^  nbnotecourante;
	private: System::Windows::Forms::Label^  nbnotes;
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
			this->thisnote = (gcnew System::Windows::Forms::Label());
			this->picturenote = (gcnew System::Windows::Forms::PictureBox());
			this->frequence = (gcnew System::Windows::Forms::Label());
			this->nbnotecourante = (gcnew System::Windows::Forms::Label());
			this->nbnotes = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picturenote))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(47, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(36, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Note :";
			this->label1->Click += gcnew System::EventHandler(this, &Form_RandomTest::label1_Click);
			// 
			// thisnote
			// 
			this->thisnote->AutoSize = true;
			this->thisnote->Location = System::Drawing::Point(106, 50);
			this->thisnote->Name = L"thisnote";
			this->thisnote->Size = System::Drawing::Size(70, 13);
			this->thisnote->TabIndex = 1;
			this->thisnote->Text = L"notecourante";
			// 
			// picturenote
			// 
			this->picturenote->Location = System::Drawing::Point(109, 81);
			this->picturenote->Name = L"picturenote";
			this->picturenote->Size = System::Drawing::Size(100, 50);
			this->picturenote->TabIndex = 2;
			this->picturenote->TabStop = false;
			// 
			// frequence
			// 
			this->frequence->AutoSize = true;
			this->frequence->Location = System::Drawing::Point(269, 50);
			this->frequence->Name = L"frequence";
			this->frequence->Size = System::Drawing::Size(100, 13);
			this->frequence->TabIndex = 3;
			this->frequence->Text = L"frequence courante";
			// 
			// nbnotecourante
			// 
			this->nbnotecourante->AutoSize = true;
			this->nbnotecourante->Location = System::Drawing::Point(50, 193);
			this->nbnotecourante->Name = L"nbnotecourante";
			this->nbnotecourante->Size = System::Drawing::Size(82, 13);
			this->nbnotecourante->TabIndex = 4;
			this->nbnotecourante->Text = L"nbnotecourante";
			// 
			// nbnotes
			// 
			this->nbnotes->AutoSize = true;
			this->nbnotes->Location = System::Drawing::Point(92, 193);
			this->nbnotes->Name = L"nbnotes";
			this->nbnotes->Size = System::Drawing::Size(45, 13);
			this->nbnotes->TabIndex = 5;
			this->nbnotes->Text = L"nbnotes";
			// 
			// Form_RandomTest
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(473, 261);
			this->Controls->Add(this->nbnotes);
			this->Controls->Add(this->nbnotecourante);
			this->Controls->Add(this->frequence);
			this->Controls->Add(this->picturenote);
			this->Controls->Add(this->thisnote);
			this->Controls->Add(this->label1);
			this->Name = L"Form_RandomTest";
			this->Text = L"Quizz";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picturenote))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }

			 //
	};
}
