#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
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

	public ref class EditData : public System::Windows::Forms::Form {
	public:
		EditData(void) {
			InitializeComponent();
		}

	protected:
		~EditData() {
			if (components) {
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBoxId;
	private: System::Windows::Forms::TextBox^ textBoxName;
	private: System::Windows::Forms::TextBox^ textBoxValue;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void) {
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBoxId = (gcnew System::Windows::Forms::TextBox());
			this->textBoxName = (gcnew System::Windows::Forms::TextBox());
			this->textBoxValue = (gcnew System::Windows::Forms::TextBox());
			this->dateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->label2->Location = System::Drawing::Point(189, 12);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(90, 24);
			this->label2->TabIndex = 1;
			this->label2->Text = L"ID number";
			this->label2->Click += gcnew System::EventHandler(this, &EditData::label2_Click);
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label3->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->label3->Location = System::Drawing::Point(29, 13);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(93, 24);
			this->label3->TabIndex = 2;
			this->label3->Text = L"New Name";
			this->label3->Click += gcnew System::EventHandler(this, &EditData::label3_Click);
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label4->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->label4->Location = System::Drawing::Point(187, 13);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(90, 24);
			this->label4->TabIndex = 3;
			this->label4->Text = L"new Value";
			this->label4->Click += gcnew System::EventHandler(this, &EditData::label4_Click);
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label5->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->label5->Location = System::Drawing::Point(378, 13);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(84, 24);
			this->label5->TabIndex = 4;
			this->label5->Text = L"New Date";
			this->label5->Click += gcnew System::EventHandler(this, &EditData::label5_Click);
			// 
			// textBoxId
			// 
			this->textBoxId->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBoxId->Location = System::Drawing::Point(184, 63);
			this->textBoxId->Name = L"textBoxId";
			this->textBoxId->Size = System::Drawing::Size(100, 22);
			this->textBoxId->TabIndex = 5;
			this->textBoxId->TextChanged += gcnew System::EventHandler(this, &EditData::textBox1_TextChanged);
			// 
			// textBoxName
			// 
			this->textBoxName->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBoxName->Location = System::Drawing::Point(25, 64);
			this->textBoxName->Name = L"textBoxName";
			this->textBoxName->Size = System::Drawing::Size(100, 22);
			this->textBoxName->TabIndex = 6;
			this->textBoxName->TextChanged += gcnew System::EventHandler(this, &EditData::textBox2_TextChanged);
			// 
			// textBoxValue
			// 
			this->textBoxValue->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBoxValue->Location = System::Drawing::Point(182, 64);
			this->textBoxValue->Name = L"textBoxValue";
			this->textBoxValue->Size = System::Drawing::Size(100, 22);
			this->textBoxValue->TabIndex = 7;
			this->textBoxValue->TextChanged += gcnew System::EventHandler(this, &EditData::textBox3_TextChanged);
			// 
			// dateTimePicker
			// 
			this->dateTimePicker->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->dateTimePicker->Location = System::Drawing::Point(320, 64);
			this->dateTimePicker->Name = L"dateTimePicker";
			this->dateTimePicker->Size = System::Drawing::Size(200, 22);
			this->dateTimePicker->TabIndex = 8;
			this->dateTimePicker->ValueChanged += gcnew System::EventHandler(this, &EditData::dateTimePicker1_ValueChanged);
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button1->Location = System::Drawing::Point(22, 51);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(107, 46);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Edit";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &EditData::button1_Click);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				48.26498F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				51.73502F)));
			this->tableLayoutPanel1->Controls->Add(this->label2, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->button1, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->textBoxId, 1, 1);
			this->tableLayoutPanel1->Location = System::Drawing::Point(12, 12);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 48)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 52)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(317, 100);
			this->tableLayoutPanel1->TabIndex = 10;
			this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &EditData::tableLayoutPanel1_Paint);
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 3;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				47.94953F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				52.05047F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				212)));
			this->tableLayoutPanel2->Controls->Add(this->label3, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->label4, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->textBoxValue, 1, 1);
			this->tableLayoutPanel2->Controls->Add(this->dateTimePicker, 2, 1);
			this->tableLayoutPanel2->Controls->Add(this->textBoxName, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->label5, 2, 0);
			this->tableLayoutPanel2->Location = System::Drawing::Point(12, 146);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(527, 100);
			this->tableLayoutPanel2->TabIndex = 11;
			this->tableLayoutPanel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &EditData::tableLayoutPanel2_Paint);
			// 
			// EditData
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(580, 271);
			this->Controls->Add(this->tableLayoutPanel2);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"EditData";
			this->Text = L"EditData";
			this->Load += gcnew System::EventHandler(this, &EditData::EditData_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			
			try {

				if (textBoxName->Text == "") {
					throw gcnew System::Exception("Name box is empty!");
				}

				double tmp;
				if (!Double::TryParse(textBoxValue->Text, tmp)) {
					throw gcnew System::Exception("Value box is empty or has a non-double element");
				}

				if (textBoxValue->Text->Contains(",")) {
					throw gcnew System::Exception("Value box cannot contain a comma (',') use ('.') instead");
				}

				if (textBoxId->Text == "") {
					throw gcnew System::Exception("ID box is empty!");
				}

				int tmp2;
				if (!Int32::TryParse(textBoxId->Text, tmp2)) {
					throw gcnew System::Exception("ID box is empty or has a non-int element");
				}

				std::string itemToEdit = msclr::interop::marshal_as<std::string>(textBoxId->Text);
				array<String^>^ lines = File::ReadAllLines("expenses.txt");
				std::vector<std::string> updatedLines;

				double newValue = System::Convert::ToDouble(textBoxValue->Text);
				double oldValue;

				for each (String ^ line in lines) {
					array<String^>^ components = line->Split(',');

					if (!(components[0] == msclr::interop::marshal_as<String^>(itemToEdit))) {
						updatedLines.push_back(msclr::interop::marshal_as<std::string>(line));
					}
					else {
						String^ newId = textBoxId->Text;
						String^ newName = textBoxName->Text;
						String^ newValue = textBoxValue->Text;
						String^ newDate = dateTimePicker->Text;
						oldValue = System::Convert::ToDouble(components[3]);

						String^ newLine = String::Format("{0},{1},{2},{3}", newId, newDate, newName, newValue);
						updatedLines.push_back(msclr::interop::marshal_as<std::string>(newLine));
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
				info.saveData("Saldo.bin", info.getSaldo(), newValue - oldValue);
			}

			catch (Exception^ ex) {
				MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		}
		private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void dateTimePicker1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void tableLayoutPanel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		}
		private: System::Void EditData_Load(System::Object^ sender, System::EventArgs^ e) {
		}
};
}
