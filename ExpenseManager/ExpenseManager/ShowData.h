#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

namespace ExpenseManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Globalization;

	/**
	 * @brief Klasa obs³uguj¹ca okno wyœwietlaj¹ce historiê wpisów
	 * wyœwietla wszystkie dodane wpisy b¹dŸ te w zadanym okresie czasowym
	*/

	public ref class ShowData : public System::Windows::Forms::Form {
	public:
		ShowData(void) {
			InitializeComponent();
		}

	protected:
		~ShowData() {
			if (components) {
				delete components;
			}
		}

	private: System::Windows::Forms::ListBox^ listBox;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Label^ labelTo;
	private: System::Windows::Forms::Label^ labelFrom;
	private: System::Windows::Forms::Label^ labelShow2;
	private: System::Windows::Forms::Button^ buttonShow2;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker2;
	private: System::Windows::Forms::Button^ buttonShow1;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::Label^ labelShow1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ labelDate;
	private: System::Windows::Forms::Label^ labelName;
	private: System::Windows::Forms::Label^ labelValue;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::Label^ label2;
	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void) {

			this->listBox = (gcnew System::Windows::Forms::ListBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->labelShow2 = (gcnew System::Windows::Forms::Label());
			this->buttonShow2 = (gcnew System::Windows::Forms::Button());
			this->labelFrom = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->labelTo = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->buttonShow1 = (gcnew System::Windows::Forms::Button());
			this->labelShow1 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->labelDate = (gcnew System::Windows::Forms::Label());
			this->labelName = (gcnew System::Windows::Forms::Label());
			this->labelValue = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// listBox
			// 
			this->listBox->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->listBox->FormattingEnabled = true;
			this->listBox->ItemHeight = 23;
			this->listBox->Location = System::Drawing::Point(12, 177);
			this->listBox->Name = L"listBox";
			this->listBox->Size = System::Drawing::Size(903, 487);
			this->listBox->TabIndex = 0;
			this->listBox->SelectedIndexChanged += gcnew System::EventHandler(this, &ShowData::listBox_SelectedIndexChanged);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				42.85714F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				57.14286F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				222)));
			this->tableLayoutPanel1->Controls->Add(this->labelShow2, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->buttonShow2, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->labelFrom, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->dateTimePicker2, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->labelTo, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->dateTimePicker1, 2, 1);
			this->tableLayoutPanel1->Location = System::Drawing::Point(317, 23);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(601, 86);
			this->tableLayoutPanel1->TabIndex = 6;
			this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &ShowData::tableLayoutPanel1_Paint);
			// 
			// labelShow2
			// 
			this->labelShow2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelShow2->AutoSize = true;
			this->labelShow2->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelShow2->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->labelShow2->Location = System::Drawing::Point(19, 8);
			this->labelShow2->Name = L"labelShow2";
			this->labelShow2->Size = System::Drawing::Size(123, 27);
			this->labelShow2->TabIndex = 6;
			this->labelShow2->Text = L"Select range";
			this->labelShow2->Click += gcnew System::EventHandler(this, &ShowData::labelShow2_Click);
			// 
			// buttonShow2
			// 
			this->buttonShow2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonShow2->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonShow2->Location = System::Drawing::Point(7, 46);
			this->buttonShow2->Name = L"buttonShow2";
			this->buttonShow2->Size = System::Drawing::Size(148, 37);
			this->buttonShow2->TabIndex = 2;
			this->buttonShow2->Text = L"Display";
			this->buttonShow2->UseVisualStyleBackColor = true;
			this->buttonShow2->Click += gcnew System::EventHandler(this, &ShowData::buttonShow2_Click);
			// 
			// labelFrom
			// 
			this->labelFrom->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelFrom->AutoSize = true;
			this->labelFrom->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelFrom->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->labelFrom->Location = System::Drawing::Point(237, 8);
			this->labelFrom->Name = L"labelFrom";
			this->labelFrom->Size = System::Drawing::Size(66, 27);
			this->labelFrom->TabIndex = 7;
			this->labelFrom->Text = L"From:";
			this->labelFrom->Click += gcnew System::EventHandler(this, &ShowData::labelFrom_Click);
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->dateTimePicker2->Location = System::Drawing::Point(170, 53);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(200, 22);
			this->dateTimePicker2->TabIndex = 4;
			this->dateTimePicker2->ValueChanged += gcnew System::EventHandler(this, &ShowData::dateTimePicker2_ValueChanged);
			// 
			// labelTo
			// 
			this->labelTo->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelTo->AutoSize = true;
			this->labelTo->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelTo->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->labelTo->Location = System::Drawing::Point(468, 8);
			this->labelTo->Name = L"labelTo";
			this->labelTo->Size = System::Drawing::Size(42, 27);
			this->labelTo->TabIndex = 8;
			this->labelTo->Text = L"To:";
			this->labelTo->Click += gcnew System::EventHandler(this, &ShowData::labelTo_Click);
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->dateTimePicker1->Location = System::Drawing::Point(389, 53);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 22);
			this->dateTimePicker1->TabIndex = 3;
			this->dateTimePicker1->ValueChanged += gcnew System::EventHandler(this, &ShowData::dateTimePicker1_ValueChanged);
			// 
			// buttonShow1
			// 
			this->buttonShow1->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->buttonShow1->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonShow1->Location = System::Drawing::Point(23, 69);
			this->buttonShow1->Name = L"buttonShow1";
			this->buttonShow1->Size = System::Drawing::Size(159, 37);
			this->buttonShow1->TabIndex = 1;
			this->buttonShow1->Text = L"Display";
			this->buttonShow1->UseVisualStyleBackColor = true;
			this->buttonShow1->Click += gcnew System::EventHandler(this, &ShowData::buttonShow1_Click);
			// 
			// labelShow1
			// 
			this->labelShow1->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->labelShow1->AutoSize = true;
			this->labelShow1->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelShow1->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->labelShow1->Location = System::Drawing::Point(51, 31);
			this->labelShow1->Name = L"labelShow1";
			this->labelShow1->Size = System::Drawing::Size(93, 27);
			this->labelShow1->TabIndex = 5;
			this->labelShow1->Text = L"Show All";
			this->labelShow1->Click += gcnew System::EventHandler(this, &ShowData::labelShow1_Click);
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->label1->Location = System::Drawing::Point(232, 57);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(31, 27);
			this->label1->TabIndex = 7;
			this->label1->Text = L"or";
			this->label1->Click += gcnew System::EventHandler(this, &ShowData::label1_Click);
			// 
			// labelDate
			// 
			this->labelDate->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelDate->AutoSize = true;
			this->labelDate->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->labelDate->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelDate->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->labelDate->Location = System::Drawing::Point(128, 5);
			this->labelDate->Name = L"labelDate";
			this->labelDate->Size = System::Drawing::Size(45, 24);
			this->labelDate->TabIndex = 8;
			this->labelDate->Text = L"Date";
			this->labelDate->Click += gcnew System::EventHandler(this, &ShowData::labelDate_Click);
			// 
			// labelName
			// 
			this->labelName->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelName->AutoSize = true;
			this->labelName->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->labelName->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelName->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->labelName->Location = System::Drawing::Point(279, 5);
			this->labelName->Name = L"labelName";
			this->labelName->Size = System::Drawing::Size(54, 24);
			this->labelName->TabIndex = 9;
			this->labelName->Text = L"Name";
			this->labelName->Click += gcnew System::EventHandler(this, &ShowData::labelName_Click);
			// 
			// labelValue
			// 
			this->labelValue->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelValue->AutoSize = true;
			this->labelValue->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->labelValue->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelValue->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->labelValue->Location = System::Drawing::Point(392, 5);
			this->labelValue->Name = L"labelValue";
			this->labelValue->Size = System::Drawing::Size(138, 24);
			this->labelValue->TabIndex = 10;
			this->labelValue->Text = L"Expense/Income";
			this->labelValue->Click += gcnew System::EventHandler(this, &ShowData::labelValue_Click);
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 4;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				162)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				149)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				160)));
			this->tableLayoutPanel2->Controls->Add(this->label2, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->labelValue, 3, 0);
			this->tableLayoutPanel2->Controls->Add(this->labelName, 2, 0);
			this->tableLayoutPanel2->Controls->Add(this->labelDate, 1, 0);
			this->tableLayoutPanel2->Location = System::Drawing::Point(12, 136);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(541, 35);
			this->tableLayoutPanel2->TabIndex = 11;
			this->tableLayoutPanel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &ShowData::tableLayoutPanel2_Paint);
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->label2->Location = System::Drawing::Point(22, 5);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(26, 24);
			this->label2->TabIndex = 12;
			this->label2->Text = L"ID";
			this->label2->Click += gcnew System::EventHandler(this, &ShowData::label2_Click);
			// 
			// ShowData
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(930, 675);
			this->Controls->Add(this->tableLayoutPanel2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->listBox);
			this->Controls->Add(this->labelShow1);
			this->Controls->Add(this->buttonShow1);
			this->Name = L"ShowData";
			this->Text = L"ShowData";
			this->Load += gcnew System::EventHandler(this, &ShowData::ShowData_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		/**
		 * @brief Wyœwietla wszystkie dodane wpisy wczytuj¹c dane z pliku txt
		 * @param lines - kontener na dane wczytane z pliku txt
		 * @param components - kontener na elementy ka¿dej lini danych
		 * @param formattedLine - linia formatowanego tekstu u³o¿onego z elementów w components
		*/

		private: System::Void buttonShow1_Click(System::Object^ sender, System::EventArgs^ e) {
			listBox->Items->Clear();

			try {

				array<String^>^ lines = File::ReadAllLines("expenses.txt");

				for each (String ^ line in lines) {
					array<String^>^ components = line->Split(',');

					if (components->Length == 4) {
						int id;

						if (Int32::TryParse(components[0], id)) {
							String^ formattedLine = String::Format("{0,-5} {1,-20} {2,-15} {3}", id, components[1], components[2], components[3]);
							listBox->Items->Add(formattedLine);
						}
						else {
							MessageBox::Show("Error parsing ID: " + components[0], "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
						}
					}
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error reading file: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		/**
		 * @brief Wyœwietla wpisy z zadanego przedzia³u czasowego pobieraj¹c je z pliku txt
		 * @param startDate - data rozpoczynaj¹ca zakres wpisów
		 * @param endDate - data koñcz¹ca zakres wpisów
		 * @param lines - kontener na wczytane linie danych z pliku txt
		 * @param components - kontener na elementy ka¿dej lini danych
		 * @param entryDate - data aktualnie sprawdzanej lini danych
		 * @param formattedLine - linia formatowanego tekstu u³o¿onego z elementów w components
		*/

		private: System::Void buttonShow2_Click(System::Object^ sender, System::EventArgs^ e) {
			listBox->Items->Clear();

			try {

				DateTime startDate = dateTimePicker2->Value;
				DateTime endDate = dateTimePicker1->Value;
				array<String^>^ lines = File::ReadAllLines("expenses.txt");

				for each (String ^ line in lines) {
					array<String^>^ components = line->Split(',');

					if (components->Length == 4) {
						int id;

						if (Int32::TryParse(components[0], id)) {
							DateTime entryDate;

							if (DateTime::TryParseExact(components[1], "d MMMM yyyy", CultureInfo::InvariantCulture, DateTimeStyles::None, entryDate)) {
								if ((entryDate >= startDate) && (entryDate <= endDate)) {
									String^ formattedLine = String::Format("{0,-5} {1,-20} {2,-15} {3}", id, components[1], components[2], components[3]);
									listBox->Items->Add(formattedLine);
								}
							}
							else {
								MessageBox::Show("Error parsing date: " + components[1], "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
							}
						}
						else {
							MessageBox::Show("Error parsing ID: " + components[0], "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
						}
					}
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error reading file: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		private: System::Void listBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		}
		private: System::Void labelShow1_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void labelShow2_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void labelFrom_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void dateTimePicker2_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void labelTo_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void dateTimePicker1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void ShowData_Load(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void labelDate_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void labelName_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void labelValue_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void tableLayoutPanel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		}
		private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
		}
	};
}
