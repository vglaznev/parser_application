#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <Windows.h>
#include <msclr/marshal_cppstd.h>
#include "FiniteStateMachine.h"

namespace ParserApplication {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	
	public ref class ParserForm : public System::Windows::Forms::Form
	{
	public:
		ParserForm(void)
		{
			InitializeComponent();
			
		}

	protected:
		
		~ParserForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ íàñòðîéêèToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ îÏðîãðàììåToolStripMenuItem;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ inputBox;
	private: System::Windows::Forms::Button^ checkButton;
	private: System::Windows::Forms::TextBox^ outputBox;


	private: System::ComponentModel::IContainer^ components;

	private:
		

#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->íàñòðîéêèToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->îÏðîãðàììåToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->inputBox = (gcnew System::Windows::Forms::TextBox());
			this->checkButton = (gcnew System::Windows::Forms::Button());
			this->outputBox = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::Menu;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->íàñòðîéêèToolStripMenuItem,
					this->îÏðîãðàììåToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(626, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// îÏðîãðàììåToolStripMenuItem
			// 
			this->îÏðîãðàììåToolStripMenuItem->Name = L"îÏðîãðàììåToolStripMenuItem";
			this->îÏðîãðàììåToolStripMenuItem->Size = System::Drawing::Size(94, 20);
			this->îÏðîãðàììåToolStripMenuItem->Text = L"Î ïðîãðàììå";
			this->îÏðîãðàììåToolStripMenuItem->Click += gcnew System::EventHandler(this, &ParserForm::îÏðîãðàììåToolStripMenuItem_Click);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			this->contextMenuStrip1->Opening += gcnew System::ComponentModel::CancelEventHandler(this, &ParserForm::contextMenuStrip1_Opening);
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Consolas", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(13, 37);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(601, 30);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Ââåäèòå ñèíòàñè÷åñêóþ êîíñòðóêöèþ äëÿ àíàëèçà:";
			this->label1->Click += gcnew System::EventHandler(this, &ParserForm::label1_Click);
			// 
			// inputBox
			// 
			this->inputBox->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->inputBox->Location = System::Drawing::Point(17, 81);
			this->inputBox->Multiline = true;
			this->inputBox->Name = L"inputBox";
			this->inputBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->inputBox->Size = System::Drawing::Size(597, 90);
			this->inputBox->TabIndex = 3;
			this->inputBox->TextChanged += gcnew System::EventHandler(this, &ParserForm::inputBox_TextChanged);
			// 
			// checkButton
			// 
			this->checkButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->checkButton->Location = System::Drawing::Point(539, 190);
			this->checkButton->Name = L"checkButton";
			this->checkButton->Size = System::Drawing::Size(75, 23);
			this->checkButton->TabIndex = 4;
			this->checkButton->Text = L"Ïðîâåðèòü";
			this->checkButton->UseVisualStyleBackColor = true;
			this->checkButton->Click += gcnew System::EventHandler(this, &ParserForm::checkButton_Click);
			// 
			// outputBox
			// 
			this->outputBox->AcceptsReturn = true;
			this->outputBox->AcceptsTab = true;
			this->outputBox->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->outputBox->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->outputBox->Location = System::Drawing::Point(17, 258);
			this->outputBox->Multiline = true;
			this->outputBox->Name = L"outputBox";
			this->outputBox->ReadOnly = true;
			this->outputBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->outputBox->Size = System::Drawing::Size(597, 90);
			this->outputBox->TabIndex = 6;
			this->outputBox->WordWrap = false;
			this->outputBox->TextChanged += gcnew System::EventHandler(this, &ParserForm::outputBox_TextChanged);
			// 
			// ParserForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(626, 387);
			this->Controls->Add(this->outputBox);
			this->Controls->Add(this->checkButton);
			this->Controls->Add(this->inputBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"ParserForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Ïðèëîæåíèå";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void checkButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void contextMenuStrip1_Opening(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e);
private: System::Void outputBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void îÏðîãðàììåToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void inputBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
