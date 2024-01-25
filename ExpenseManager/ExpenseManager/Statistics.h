#pragma once

#include <iostream>
#include "DataStatistics.h"
#include "DataHandler.h"
#include "ConvertStatistics.h"

namespace ExpenseManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/**
	 * @brief Klasa do obs³ugi okna wyœwietlaj¹cego miesiêczne statystyki konta
	*/

	public ref class Statistics : public System::Windows::Forms::Form {
	public:
		Statistics(void) {
			InitializeComponent();
		}

	protected:
		~Statistics() {
			if (components) {
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void) {
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->label1->Location = System::Drawing::Point(47, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(114, 23);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Total Income:";
			this->label1->Click += gcnew System::EventHandler(this, &Statistics::label1_Click);
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->label2->Location = System::Drawing::Point(29, 30);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(132, 24);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Total expenses:";
			this->label2->Click += gcnew System::EventHandler(this, &Statistics::label2_Click);
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label3->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->label3->Location = System::Drawing::Point(22, 75);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(139, 24);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Balanse change:";
			this->label3->Click += gcnew System::EventHandler(this, &Statistics::label3_Click);
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label4->Location = System::Drawing::Point(216, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(55, 23);
			this->label4->TabIndex = 4;
			this->label4->Text = L"label4";
			this->label4->Click += gcnew System::EventHandler(this, &Statistics::label4_Click);
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label5->Location = System::Drawing::Point(216, 30);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(55, 24);
			this->label5->TabIndex = 5;
			this->label5->Text = L"label5";
			this->label5->Click += gcnew System::EventHandler(this, &Statistics::label5_Click);
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label6->Location = System::Drawing::Point(216, 75);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(55, 24);
			this->label6->TabIndex = 6;
			this->label6->Text = L"label6";
			this->label6->Click += gcnew System::EventHandler(this, &Statistics::label6_Click);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50.61728F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				49.38272F)));
			this->tableLayoutPanel1->Controls->Add(this->label4, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->label2, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->label3, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->label6, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->label5, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->button1, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->button2, 1, 3);
			this->tableLayoutPanel1->Location = System::Drawing::Point(12, 60);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 4;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 36.53846F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 63.46154F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 52)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(324, 165);
			this->tableLayoutPanel1->TabIndex = 7;
			this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Statistics::tableLayoutPanel1_Paint);
			// 
			// label7
			// 
			this->label7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label7->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->label7->Location = System::Drawing::Point(49, 23);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(211, 33);
			this->label7->TabIndex = 8;
			this->label7->Text = L"Monthly summary";
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button1->Location = System::Drawing::Point(3, 115);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(158, 47);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Rounded";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Statistics::button1_Click);
			// 
			// button2
			// 
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button2->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button2->Location = System::Drawing::Point(167, 115);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(154, 47);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Not-rounded";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Statistics::button2_Click);
			// 
			// Statistics
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(348, 237);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"Statistics";
			this->Text = L"Statistics";
			this->Load += gcnew System::EventHandler(this, &Statistics::Statistics_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		/**
		 * @brief Wyœwietla komunikat informuj¹cy do czego s³u¿y to oknie
		 * Wczytuje dane o ³¹cznych miesiêcznych wydatkach, przychodach oraz bilansie do labelTextów
		*/

		private: System::Void Statistics_Load(System::Object^ sender, System::EventArgs^ e) {
			DataStatistics dataStatistics;
			dataStatistics.calculateEarningsAndLosses();
			DataHandler* dataHandler = new DataStatistics();
			dataHandler->DisplayAnnouncement();
			label4->Text = System::Convert::ToString(dataStatistics.getTotalEarnings());
			label5->Text = System::Convert::ToString(dataStatistics.getTotalLosses());
			label6->Text = System::Convert::ToString(dataStatistics.getTotalChange());
			delete dataHandler;
		}

		/**
		 * @brief Zamienia dane w labelBoxach na typ int
		*/

		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			ConvertStatistics<double> convertStatistics(System::Convert::ToDouble(label4->Text), System::Convert::ToDouble(label5->Text), System::Convert::ToDouble(label6->Text));
			label4->Text = System::Convert::ToString(convertStatistics.getIntegerIncome());
			label5->Text = System::Convert::ToString(convertStatistics.getIntegerExpense());
			label6->Text = System::Convert::ToString(convertStatistics.getIntegerChange());
		}

		/**
		 * @brief Wczytuje ponownie okno w celu ponownego wgrania danych w formacie double
		*/

		private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			Statistics_Load(sender, e);
		}

		private: System::Void chart1_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		}
};
}
