#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <msclr/marshal_cppstd.h>
#include "AccountInfo.h"

namespace ExpenseManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/**
	 * @brief Klasa obs³uguj¹ca nowe okno s³u¿¹ce do usuwania wybranych wpisów
	*/

	public ref class DeleteData : public System::Windows::Forms::Form {
	public:
		DeleteData(void) {
			InitializeComponent();
		}

	protected:
		~DeleteData() {
			if (components) {
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ buttonDelete;
	private: System::Windows::Forms::TextBox^ textBoxId;
	private: System::Windows::Forms::Label^ labelId;
	private: System::Windows::Forms::Label^ labelTip;
	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void) {
			this->buttonDelete = (gcnew System::Windows::Forms::Button());
			this->textBoxId = (gcnew System::Windows::Forms::TextBox());
			this->labelId = (gcnew System::Windows::Forms::Label());
			this->labelTip = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// buttonDelete
			//
			this->buttonDelete->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonDelete->Location = System::Drawing::Point(86, 43);
			this->buttonDelete->Name = L"buttonDelete";
			this->buttonDelete->Size = System::Drawing::Size(103, 47);
			this->buttonDelete->TabIndex = 0;
			this->buttonDelete->Text = L"Delete";
			this->buttonDelete->UseVisualStyleBackColor = true;
			this->buttonDelete->Click += gcnew System::EventHandler(this, &DeleteData::buttonDelete_Click);
			// 
			// textBoxId
			// 
			this->textBoxId->Location = System::Drawing::Point(271, 68);
			this->textBoxId->Name = L"textBoxId";
			this->textBoxId->Size = System::Drawing::Size(100, 22);
			this->textBoxId->TabIndex = 1;
			this->textBoxId->TextChanged += gcnew System::EventHandler(this, &DeleteData::textBoxId_TextChanged);
			// 
			// labelId
			// 
			this->labelId->AutoSize = true;
			this->labelId->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelId->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->labelId->Location = System::Drawing::Point(273, 29);
			this->labelId->Name = L"labelId";
			this->labelId->Size = System::Drawing::Size(90, 24);
			this->labelId->TabIndex = 2;
			this->labelId->Text = L"ID number";
			this->labelId->Click += gcnew System::EventHandler(this, &DeleteData::labelId_Click);
			// 
			// labelTip
			// 
			this->labelTip->AutoSize = true;
			this->labelTip->Font = (gcnew System::Drawing::Font(L"Arial", 7.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->labelTip->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->labelTip->Location = System::Drawing::Point(13, 116);
			this->labelTip->Name = L"labelTip";
			this->labelTip->Size = System::Drawing::Size(357, 16);
			this->labelTip->TabIndex = 3;
			this->labelTip->Text = L"(Psst \"You can look for your ID number in show history\")";
			this->labelTip->Click += gcnew System::EventHandler(this, &DeleteData::labelTip_Click);
			// 
			// DeleteData
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(438, 154);
			this->Controls->Add(this->labelTip);
			this->Controls->Add(this->labelId);
			this->Controls->Add(this->textBoxId);
			this->Controls->Add(this->buttonDelete);
			this->Name = L"DeleteData";
			this->Text = L"DeleteData";
			this->Load += gcnew System::EventHandler(this, &DeleteData::DeleteData_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		/**
		 * @brief Obs³uga guzika Delete
		 * sprawdza poprawnoœæ wprowadzonych danych a nastêpnie przeszukuje plik z danymi w celu usuniêcia tych niechcianych
		 * @param "expenses.txt" - plik z danymi
		 * @param itemToDelete - wartoœæ z textBoxa Id
		 * @param lines - kontener przechowuj¹cy dane z pliku
		 * @param updatedLines - kontener z nowymi danymi do zapisu
		 * @param updatedValue - przychód/wydatek do uwzglêdnienia w saldzie przy usuwaniu wpisu
		*/

		private: System::Void buttonDelete_Click(System::Object^ sender, System::EventArgs^ e) {
			
			try {

				if (textBoxId->Text == "") {
					throw gcnew System::Exception("ID box is empty!");
				}

				int tmp;
				if (!Int32::TryParse(textBoxId->Text, tmp)) {
					throw gcnew System::Exception("Value box is empty or has a non-int element");
				}

				if (0 > tmp) {
					throw gcnew System::Exception("Negavite value in ID box");
				}

				std::string itemToDelete = msclr::interop::marshal_as<std::string>(textBoxId->Text);
				array<String^>^ lines = File::ReadAllLines("expenses.txt");
				std::vector<std::string> updatedLines;
				double updatedValue = 0;

				for each (String ^ line in lines) {
					array<String^>^ components = line->Split(',');

					if (!(components[0] == msclr::interop::marshal_as<String^>(itemToDelete))) {
						updatedLines.push_back(msclr::interop::marshal_as<std::string>(line));
					}
					else {
						updatedValue = System::Convert::ToDouble(components[3]);
					}
				}

				try {
					std::ofstream outputFile("expenses.txt");

					for (const auto& line : updatedLines) {
						outputFile << line << std::endl;
					}

					outputFile.close();
				}
				catch (const std::exception& ex) {
					std::cerr << "Error saving file: " << ex.what() << std::endl;
				}

				AccountInfo info;
				info.loadData("Saldo.bin", true);
				info.saveData("Saldo.bin", info.getSaldo(), -1 * (updatedValue));
			}

			catch (Exception^ ex) {
				MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		private: System::Void labelId_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void textBoxId_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void labelTip_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void DeleteData_Load(System::Object^ sender, System::EventArgs^ e) {
		}
};
}
