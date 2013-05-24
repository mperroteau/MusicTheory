#pragma once

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
			this->SuspendLayout();
			// 
			// BT_RandomTest
			// 
			this->BT_RandomTest->Location = System::Drawing::Point(47, 48);
			this->BT_RandomTest->Name = L"BT_RandomTest";
			this->BT_RandomTest->Size = System::Drawing::Size(123, 38);
			this->BT_RandomTest->TabIndex = 0;
			this->BT_RandomTest->Text = L"Effectuer un test ";
			this->BT_RandomTest->UseVisualStyleBackColor = true;
			this->BT_RandomTest->Click += gcnew System::EventHandler(this, &Form_Main::BT_RandomTest_Click);
			// 
			// Form_Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->BT_RandomTest);
			this->Name = L"Form_Main";
			this->Text = L"Form_Main";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void BT_RandomTest_Click(System::Object^  sender, System::EventArgs^  e) {

			 }
	};
}
