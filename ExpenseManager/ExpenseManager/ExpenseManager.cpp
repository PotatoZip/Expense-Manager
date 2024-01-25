#include "ExpenseManager.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

void main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();

	String^ backgroundImagePath = (args->Length > 0) ? args[0] : nullptr;
	ExpenseManager::ExpenseManager frm(backgroundImagePath);
	Application::Run(% frm);
}