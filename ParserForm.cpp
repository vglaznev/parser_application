#include "ParserForm.h"

using namespace ParserApplication;

void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ParserApplication::ParserForm app;
	Application::Run(% app);
}

System::Void ParserApplication::ParserForm::checkButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::string codeLine = msclr::interop::marshal_as<std::string>(inputBox->Text);
	outputBox->Clear();
	if (codeLine == "") {
		outputBox->Text = "Ошибка! Строка не была введена.";
	}
	else {
		FiniteStateMachine analyzer;
		analyzer.run(codeLine, outputBox);
	}
	return System::Void();
}

System::Void ParserApplication::ParserForm::contextMenuStrip1_Opening(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e)
{
	return System::Void();
}

System::Void ParserApplication::ParserForm::outputBox_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}


System::Void ParserApplication::ParserForm::оПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Программа предназначена для проверки конструкций вида <идентификатор> = <идентификатор_функции>(<целочисленный_аргумент>); на соответствие синтаксическим нормам языка С++.", "О программе");
	return System::Void();
}

System::Void ParserApplication::ParserForm::inputBox_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
