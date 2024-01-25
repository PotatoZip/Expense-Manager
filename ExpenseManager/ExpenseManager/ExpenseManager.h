#pragma once

#include <iostream>
#include <msclr/marshal_cppstd.h>
#include "DataHandler.h"
#include "AccountInfo.h"
#include "ShowData.h"
#include "DeleteData.h"
#include "EditData.h"
#include "Statistics.h"

namespace ExpenseManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/**
	 * @brief Klasa bazowa wywo³uj¹ca aplikacjê, obs³uguj¹ca g³ówne okno programu
	 * @param backgroundImage - œcieszka do pliku z t³em dla aplikacji
	*/

	public ref class ExpenseManager : public System::Windows::Forms::Form {
	public:
		ExpenseManager(String^ backgroundImagePath) {
			InitializeComponent();

			if (backgroundImagePath != nullptr && System::IO::File::Exists(backgroundImagePath)) {
				this->BackgroundImage = System::Drawing::Image::FromFile(backgroundImagePath);
			}
		}

		/**
		 * @brief Funkcja aktualizuj¹ca informacje o stanie konta w g³ównym oknie
		 * @param "Id.bin" i "Saldo.bin" - œcieszki do plików z danymi
		*/

		void updateInfo() {
			AccountInfo info;
			info.loadData("Id.bin");
			info.loadData("Saldo.bin", true);
			labelSaldo2->Text = System::Convert::ToString(info.getSaldo());
			labelCount2->Text = System::Convert::ToString(info.getId());
		}

	protected:
		~ExpenseManager() {
			if (components) {
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ labelExpenseManager;
	private: System::Windows::Forms::Button^ buttonIncome;
	private: System::Windows::Forms::DateTimePicker^ dateTimePickerAdd;
	private: System::Windows::Forms::TextBox^ textBoxName;
	private: System::Windows::Forms::Label^ labelName;
	private: System::Windows::Forms::Label^ labelValue;
	private: System::Windows::Forms::Label^ labelDateAdd;
	private: System::Windows::Forms::Label^ labelNewExpense;
	private: System::Windows::Forms::TextBox^ textBoxValue;
	private: System::Windows::Forms::Label^ labelSaldo;
	private: System::Windows::Forms::Label^ labelCount;
	private: System::Windows::Forms::Label^ labelSaldo2;
	private: System::Windows::Forms::Label^ labelCount2;
	private: System::Windows::Forms::Button^ buttonShow;
	private: System::Windows::Forms::Button^ buttonEdit;
	private: System::Windows::Forms::Button^ buttonDelete;
	private: System::Windows::Forms::Button^ buttonStatistics;
	private: System::Windows::Forms::Label^ labelBasic;
	private: System::Windows::Forms::Label^ labelStatistics;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel3;
	private: System::Windows::Forms::Button^ buttonExpense;
	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void) {
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ExpenseManager::typeid));
			this->labelExpenseManager = (gcnew System::Windows::Forms::Label());
			this->labelNewExpense = (gcnew System::Windows::Forms::Label());
			this->buttonIncome = (gcnew System::Windows::Forms::Button());
			this->dateTimePickerAdd = (gcnew System::Windows::Forms::DateTimePicker());
			this->textBoxName = (gcnew System::Windows::Forms::TextBox());
			this->labelName = (gcnew System::Windows::Forms::Label());
			this->labelValue = (gcnew System::Windows::Forms::Label());
			this->labelDateAdd = (gcnew System::Windows::Forms::Label());
			this->textBoxValue = (gcnew System::Windows::Forms::TextBox());
			this->labelSaldo = (gcnew System::Windows::Forms::Label());
			this->labelCount = (gcnew System::Windows::Forms::Label());
			this->labelSaldo2 = (gcnew System::Windows::Forms::Label());
			this->labelCount2 = (gcnew System::Windows::Forms::Label());
			this->buttonShow = (gcnew System::Windows::Forms::Button());
			this->buttonEdit = (gcnew System::Windows::Forms::Button());
			this->buttonDelete = (gcnew System::Windows::Forms::Button());
			this->buttonStatistics = (gcnew System::Windows::Forms::Button());
			this->labelBasic = (gcnew System::Windows::Forms::Label());
			this->labelStatistics = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->buttonExpense = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// labelExpenseManager
			// 
			this->labelExpenseManager->AutoSize = true;
			this->labelExpenseManager->Font = (gcnew System::Drawing::Font(L"Arial", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelExpenseManager->ForeColor = System::Drawing::Color::RoyalBlue;
			this->labelExpenseManager->Location = System::Drawing::Point(22, 46);
			this->labelExpenseManager->Name = L"labelExpenseManager";
			this->labelExpenseManager->Size = System::Drawing::Size(450, 59);
			this->labelExpenseManager->TabIndex = 0;
			this->labelExpenseManager->Text = L"Expense Manager";
			this->labelExpenseManager->Click += gcnew System::EventHandler(this, &ExpenseManager::labelExpenseManager_Click);
			// 
			// labelNewExpense
			// 
			this->labelNewExpense->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelNewExpense->AutoSize = true;
			this->labelNewExpense->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelNewExpense->ForeColor = System::Drawing::SystemColors::InactiveBorder;
			this->labelNewExpense->Location = System::Drawing::Point(46, 8);
			this->labelNewExpense->Name = L"labelNewExpense";
			this->labelNewExpense->Size = System::Drawing::Size(114, 33);
			this->labelNewExpense->TabIndex = 1;
			this->labelNewExpense->Text = L"Add New";
			this->labelNewExpense->Click += gcnew System::EventHandler(this, &ExpenseManager::labelNewExpense_Click);
			// 
			// buttonIncome
			// 
			this->buttonIncome->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonIncome->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonIncome->Location = System::Drawing::Point(52, 55);
			this->buttonIncome->Name = L"buttonIncome";
			this->buttonIncome->Size = System::Drawing::Size(103, 40);
			this->buttonIncome->TabIndex = 2;
			this->buttonIncome->Text = L"Income";
			this->buttonIncome->UseVisualStyleBackColor = true;
			this->buttonIncome->Click += gcnew System::EventHandler(this, &ExpenseManager::buttonIncome_Click);
			// 
			// dateTimePickerAdd
			// 
			this->dateTimePickerAdd->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->dateTimePickerAdd->Location = System::Drawing::Point(669, 64);
			this->dateTimePickerAdd->Name = L"dateTimePickerAdd";
			this->dateTimePickerAdd->Size = System::Drawing::Size(200, 22);
			this->dateTimePickerAdd->TabIndex = 3;
			this->dateTimePickerAdd->ValueChanged += gcnew System::EventHandler(this, &ExpenseManager::dateTimePickerAdd_ValueChanged);
			// 
			// textBoxName
			// 
			this->textBoxName->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBoxName->Location = System::Drawing::Point(272, 64);
			this->textBoxName->Name = L"textBoxName";
			this->textBoxName->Size = System::Drawing::Size(100, 22);
			this->textBoxName->TabIndex = 5;
			this->textBoxName->TextChanged += gcnew System::EventHandler(this, &ExpenseManager::textBoxName_TextChanged);
			// 
			// labelName
			// 
			this->labelName->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelName->AutoSize = true;
			this->labelName->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelName->ForeColor = System::Drawing::SystemColors::InactiveBorder;
			this->labelName->Location = System::Drawing::Point(295, 13);
			this->labelName->Name = L"labelName";
			this->labelName->Size = System::Drawing::Size(54, 24);
			this->labelName->TabIndex = 6;
			this->labelName->Text = L"Name";
			this->labelName->Click += gcnew System::EventHandler(this, &ExpenseManager::labelName_Click);
			// 
			// labelValue
			// 
			this->labelValue->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelValue->AutoSize = true;
			this->labelValue->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelValue->ForeColor = System::Drawing::SystemColors::InactiveBorder;
			this->labelValue->Location = System::Drawing::Point(518, 13);
			this->labelValue->Name = L"labelValue";
			this->labelValue->Size = System::Drawing::Size(53, 24);
			this->labelValue->TabIndex = 7;
			this->labelValue->Text = L"Value";
			this->labelValue->Click += gcnew System::EventHandler(this, &ExpenseManager::labelValue_Click);
			// 
			// labelDateAdd
			// 
			this->labelDateAdd->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelDateAdd->AutoSize = true;
			this->labelDateAdd->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelDateAdd->ForeColor = System::Drawing::SystemColors::InactiveBorder;
			this->labelDateAdd->Location = System::Drawing::Point(747, 13);
			this->labelDateAdd->Name = L"labelDateAdd";
			this->labelDateAdd->Size = System::Drawing::Size(45, 24);
			this->labelDateAdd->TabIndex = 8;
			this->labelDateAdd->Text = L"Date";
			this->labelDateAdd->Click += gcnew System::EventHandler(this, &ExpenseManager::labelDateAdd_Click);
			// 
			// textBoxValue
			// 
			this->textBoxValue->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBoxValue->Location = System::Drawing::Point(495, 64);
			this->textBoxValue->Name = L"textBoxValue";
			this->textBoxValue->Size = System::Drawing::Size(100, 22);
			this->textBoxValue->TabIndex = 9;
			this->textBoxValue->TextChanged += gcnew System::EventHandler(this, &ExpenseManager::textBoxValue_TextChanged);
			// 
			// labelSaldo
			// 
			this->labelSaldo->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelSaldo->AutoSize = true;
			this->labelSaldo->BackColor = System::Drawing::Color::Transparent;
			this->labelSaldo->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelSaldo->ForeColor = System::Drawing::SystemColors::InactiveBorder;
			this->labelSaldo->Location = System::Drawing::Point(11, 13);
			this->labelSaldo->Name = L"labelSaldo";
			this->labelSaldo->Size = System::Drawing::Size(117, 24);
			this->labelSaldo->TabIndex = 10;
			this->labelSaldo->Text = L"Current Saldo";
			this->labelSaldo->Click += gcnew System::EventHandler(this, &ExpenseManager::labelSaldo_Click);
			// 
			// labelCount
			// 
			this->labelCount->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelCount->AutoSize = true;
			this->labelCount->BackColor = System::Drawing::Color::Transparent;
			this->labelCount->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelCount->ForeColor = System::Drawing::SystemColors::InactiveBorder;
			this->labelCount->Location = System::Drawing::Point(183, 13);
			this->labelCount->Name = L"labelCount";
			this->labelCount->Size = System::Drawing::Size(60, 24);
			this->labelCount->TabIndex = 11;
			this->labelCount->Text = L"Added";
			this->labelCount->Click += gcnew System::EventHandler(this, &ExpenseManager::labelCount_Click);
			// 
			// labelSaldo2
			// 
			this->labelSaldo2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelSaldo2->AutoSize = true;
			this->labelSaldo2->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelSaldo2->ForeColor = System::Drawing::SystemColors::InactiveBorder;
			this->labelSaldo2->Location = System::Drawing::Point(69, 63);
			this->labelSaldo2->Name = L"labelSaldo2";
			this->labelSaldo2->Size = System::Drawing::Size(0, 23);
			this->labelSaldo2->TabIndex = 13;
			this->labelSaldo2->Click += gcnew System::EventHandler(this, &ExpenseManager::labelSaldo2_Click);
			// 
			// labelCount2
			// 
			this->labelCount2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelCount2->AutoSize = true;
			this->labelCount2->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelCount2->ForeColor = System::Drawing::SystemColors::InactiveBorder;
			this->labelCount2->Location = System::Drawing::Point(213, 63);
			this->labelCount2->Name = L"labelCount2";
			this->labelCount2->Size = System::Drawing::Size(0, 23);
			this->labelCount2->TabIndex = 14;
			this->labelCount2->Click += gcnew System::EventHandler(this, &ExpenseManager::labelCount2_Click);
			// 
			// buttonShow
			// 
			this->buttonShow->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonShow->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonShow->Location = System::Drawing::Point(13, 22);
			this->buttonShow->Name = L"buttonShow";
			this->buttonShow->Size = System::Drawing::Size(135, 56);
			this->buttonShow->TabIndex = 15;
			this->buttonShow->Text = L"Show History";
			this->buttonShow->UseVisualStyleBackColor = true;
			this->buttonShow->Click += gcnew System::EventHandler(this, &ExpenseManager::buttonShow_Click);
			// 
			// buttonEdit
			// 
			this->buttonEdit->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonEdit->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonEdit->Location = System::Drawing::Point(186, 22);
			this->buttonEdit->Name = L"buttonEdit";
			this->buttonEdit->Size = System::Drawing::Size(135, 56);
			this->buttonEdit->TabIndex = 16;
			this->buttonEdit->Text = L"Edit";
			this->buttonEdit->UseVisualStyleBackColor = true;
			this->buttonEdit->Click += gcnew System::EventHandler(this, &ExpenseManager::buttonEdit_Click);
			// 
			// buttonDelete
			// 
			this->buttonDelete->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonDelete->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonDelete->Location = System::Drawing::Point(364, 22);
			this->buttonDelete->Name = L"buttonDelete";
			this->buttonDelete->Size = System::Drawing::Size(135, 56);
			this->buttonDelete->TabIndex = 17;
			this->buttonDelete->Text = L"Delete";
			this->buttonDelete->UseVisualStyleBackColor = true;
			this->buttonDelete->Click += gcnew System::EventHandler(this, &ExpenseManager::buttonDelete_Click);
			// 
			// buttonStatistics
			// 
			this->buttonStatistics->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->buttonStatistics->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonStatistics->Location = System::Drawing::Point(763, 446);
			this->buttonStatistics->Name = L"buttonStatistics";
			this->buttonStatistics->Size = System::Drawing::Size(135, 78);
			this->buttonStatistics->TabIndex = 18;
			this->buttonStatistics->Text = L"Monthly Summary";
			this->buttonStatistics->UseVisualStyleBackColor = true;
			this->buttonStatistics->Click += gcnew System::EventHandler(this, &ExpenseManager::buttonStatistics_Click);
			// 
			// labelBasic
			// 
			this->labelBasic->AutoSize = true;
			this->labelBasic->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelBasic->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->labelBasic->Location = System::Drawing::Point(172, 387);
			this->labelBasic->Name = L"labelBasic";
			this->labelBasic->Size = System::Drawing::Size(205, 33);
			this->labelBasic->TabIndex = 19;
			this->labelBasic->Text = L"Basic Operations";
			this->labelBasic->Click += gcnew System::EventHandler(this, &ExpenseManager::labelBasic_Click);
			// 
			// labelStatistics
			// 
			this->labelStatistics->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->labelStatistics->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelStatistics->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->labelStatistics->Location = System::Drawing::Point(763, 387);
			this->labelStatistics->Name = L"labelStatistics";
			this->labelStatistics->Size = System::Drawing::Size(118, 33);
			this->labelStatistics->TabIndex = 20;
			this->labelStatistics->Text = L"Statistics";
			this->labelStatistics->Click += gcnew System::EventHandler(this, &ExpenseManager::labelStatistics_Click);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->BackColor = System::Drawing::Color::Transparent;
			this->tableLayoutPanel1->ColumnCount = 4;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				47.33333F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				52.66667F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				216)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				232)));
			this->tableLayoutPanel1->Controls->Add(this->labelNewExpense, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->buttonIncome, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->labelName, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->textBoxName, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->labelValue, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->textBoxValue, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->dateTimePickerAdd, 3, 1);
			this->tableLayoutPanel1->Controls->Add(this->labelDateAdd, 3, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(12, 178);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(886, 100);
			this->tableLayoutPanel1->TabIndex = 21;
			this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &ExpenseManager::tableLayoutPanel1_Paint);
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 3;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				46.76056F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				53.23944F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				171)));
			this->tableLayoutPanel2->Controls->Add(this->buttonShow, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->buttonEdit, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->buttonDelete, 2, 0);
			this->tableLayoutPanel2->Location = System::Drawing::Point(12, 435);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(518, 100);
			this->tableLayoutPanel2->TabIndex = 22;
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->BackColor = System::Drawing::Color::Transparent;
			this->tableLayoutPanel3->ColumnCount = 2;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				48.47328F)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				51.52672F)));
			this->tableLayoutPanel3->Controls->Add(this->labelSaldo, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->labelCount, 1, 0);
			this->tableLayoutPanel3->Controls->Add(this->labelSaldo2, 0, 1);
			this->tableLayoutPanel3->Controls->Add(this->labelCount2, 1, 1);
			this->tableLayoutPanel3->Location = System::Drawing::Point(585, 30);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 2;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(287, 100);
			this->tableLayoutPanel3->TabIndex = 23;
			this->tableLayoutPanel3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &ExpenseManager::tableLayoutPanel3_Paint);
			// 
			// buttonExpense
			// 
			this->buttonExpense->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonExpense->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonExpense->Location = System::Drawing::Point(63, 284);
			this->buttonExpense->Name = L"buttonExpense";
			this->buttonExpense->Size = System::Drawing::Size(103, 40);
			this->buttonExpense->TabIndex = 24;
			this->buttonExpense->Text = L"Expense";
			this->buttonExpense->UseVisualStyleBackColor = true;
			this->buttonExpense->Click += gcnew System::EventHandler(this, &ExpenseManager::buttonExpense_Click);
			// 
			// ExpenseManager
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(910, 579);
			this->Controls->Add(this->buttonExpense);
			this->Controls->Add(this->tableLayoutPanel3);
			this->Controls->Add(this->tableLayoutPanel2);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->labelStatistics);
			this->Controls->Add(this->buttonStatistics);
			this->Controls->Add(this->labelBasic);
			this->Controls->Add(this->labelExpenseManager);
			this->DoubleBuffered = true;
			this->Name = L"ExpenseManager";
			this->Text = L"ExpenseManager";
			this->Load += gcnew System::EventHandler(this, &ExpenseManager::ExpenseManager_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private: System::Void ExpenseManager_Load(System::Object^ sender, System::EventArgs^ e) {
			updateInfo();
		}
		
		/**
		 * @brief Funkcja obs³uguj¹ca dzia³anie guzika Income
		 * sprawdza poprawnoœæ wprowadzanych danych a nastêpnie przekazuje informacje o dochodzie do innych klas
		 * @param "extenses.txt" - plik z parametrami wydatku/przychodu
		 * @param tmp - zmienna tymczasowa przechowuj¹ca wartoœæ z textBoxa
		*/

		private: System::Void buttonIncome_Click(System::Object^ sender, System::EventArgs^ e) {
			updateInfo();
			
			DataHandler dataHandler;
			AccountInfo info;

			try {

				if (textBoxName->Text == "") {
					throw gcnew System::Exception("Name box is empty!");
				}

				if (textBoxValue->Text->Contains(",")) {
					throw gcnew System::Exception("Value box cannot contain a comma (',') use ('.') instead");
				}

				double tmp;
				if (!Double::TryParse(textBoxValue->Text, tmp)) {
					throw gcnew System::Exception("Value box is empty or has a non-double element");
				}

				if (0 > tmp) {
					throw gcnew System::Exception("Negavite value in value box");
				}

				dataHandler.setId(System::Convert::ToInt32(labelCount2->Text));
				dataHandler.setName(msclr::interop::marshal_as<std::string>(textBoxName->Text));
				dataHandler.setAmount(System::Convert::ToDouble(textBoxValue->Text));
				dataHandler.setDate(msclr::interop::marshal_as<std::string>(dateTimePickerAdd->Text));
				dataHandler.saveDate("expenses.txt");

				info.saveData("Id.bin", System::Convert::ToInt32(labelCount2->Text));
				info.saveData("Saldo.bin", System::Convert::ToDouble(labelSaldo2->Text), System::Convert::ToDouble(textBoxValue->Text));
			}

			catch (Exception^ ex) {
				MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			
			updateInfo();
		}
	
		/**
		* @brief Funkcja obs³uguj¹ca dzia³anie guzika Expense
		* sprawdza poprawnoœæ wprowadzanych danych a nastêpnie przekazuje informcaje o wydatku do innych klas
		* @param "extenses.txt" - plik z parametrami wydatku/przychodu
		* @param tmp - zmienna tymczasowa przechowuj¹ca wartoœæ z textBoxa
		*/

   		private: System::Void buttonExpense_Click(System::Object^ sender, System::EventArgs^ e) {
			updateInfo();
			
			DataHandler dataHandler;
			AccountInfo info;

			try {

				if (textBoxName->Text == "") {
					MessageBox::Show("Name box is empty!");
				}

				double tmp;
				if (!Double::TryParse(textBoxValue->Text, tmp)) {
					throw gcnew System::Exception("Value box is empty or has a non-double element");
				}

				if (textBoxValue->Text->Contains(",")) {
					throw gcnew System::Exception("Value box cannot contain a comma (',') use ('.') instead");
				}

				if (0 > tmp) {
					throw gcnew System::Exception("Negavite value in value box");
				}

				dataHandler.setId(System::Convert::ToInt32(labelCount2->Text));
				dataHandler.setName(msclr::interop::marshal_as<std::string>(textBoxName->Text));
				dataHandler.setAmount(-1 * (System::Convert::ToDouble(textBoxValue->Text)));
				dataHandler.setDate(msclr::interop::marshal_as<std::string>(dateTimePickerAdd->Text));
				dataHandler.saveDate("expenses.txt");

				info.saveData("Id.bin", System::Convert::ToInt32(labelCount2->Text));
				info.saveData("Saldo.bin", System::Convert::ToDouble(labelSaldo2->Text), -1 * (System::Convert::ToDouble(textBoxValue->Text)));
			}
			
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}

			updateInfo();
		}

		/**
		 * @brief Funkcja wywo³uj¹ca okno z histori¹ wpisów
		*/

		private: System::Void buttonShow_Click(System::Object^ sender, System::EventArgs^ e) {
			ShowData^ showData = gcnew ShowData();
			showData->ShowDialog();
		}

		/**
		* @brief Funkcja wywo³uj¹ca okno do edycji wpisów
		*/

		private: System::Void buttonEdit_Click(System::Object^ sender, System::EventArgs^ e) {
			EditData^ editData = gcnew EditData();
			editData->ShowDialog();
		}

		/**
		* @brief Funkcja wywo³uj¹ca okno do usuwania wpisów
		*/

		private: System::Void buttonDelete_Click(System::Object^ sender, System::EventArgs^ e) {
			DeleteData^ deleteData = gcnew DeleteData();
			deleteData->ShowDialog();
		}

		/**
		* @brief Funkcja wywo³uj¹ca okno ukazuj¹ce statystyki miesiêczne
		*/

		private: System::Void buttonStatistics_Click(System::Object^ sender, System::EventArgs^ e) {
			Statistics^ statistics = gcnew Statistics();
			statistics->ShowDialog();
		}

		private: System::Void textBoxName_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void dateTimePickerAdd_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void labelName_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void labelValue_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void labelDateAdd_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void textBoxValue_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void labelSaldo_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void labelSaldo2_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void labelCount2_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void labelCount_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void numericUpDownAdd_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void labelExpenseManager_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void labelNewExpense_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void labelBasic_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void labelStatistics_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		}
		private: System::Void tableLayoutPanel3_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		}
	};
}
