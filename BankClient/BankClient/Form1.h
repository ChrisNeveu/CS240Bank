#pragma once

namespace BankClient {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  TextLog;
	protected: 

	private: System::Windows::Forms::TextBox^  textEntryBox;
	protected: 

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button0;
	private: System::Windows::Forms::Button^  buttonConnect;
	private: System::Windows::Forms::Button^  buttonEnter;

	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  printReceiptToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::Button^  buttonClear;
	private: System::Windows::Forms::Button^  buttonDisconnect;
	private: System::Windows::Forms::Button^  buttonExit;


	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->TextLog = (gcnew System::Windows::Forms::TextBox());
			this->textEntryBox = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button0 = (gcnew System::Windows::Forms::Button());
			this->buttonConnect = (gcnew System::Windows::Forms::Button());
			this->buttonEnter = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->printReceiptToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->buttonClear = (gcnew System::Windows::Forms::Button());
			this->buttonDisconnect = (gcnew System::Windows::Forms::Button());
			this->buttonExit = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// TextLog
			// 
			this->TextLog->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->TextLog->Location = System::Drawing::Point(239, 58);
			this->TextLog->Multiline = true;
			this->TextLog->Name = L"TextLog";
			this->TextLog->ReadOnly = true;
			this->TextLog->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->TextLog->Size = System::Drawing::Size(269, 257);
			this->TextLog->TabIndex = 0;
			// 
			// textEntryBox
			// 
			this->textEntryBox->Location = System::Drawing::Point(12, 27);
			this->textEntryBox->Name = L"textEntryBox";
			this->textEntryBox->Size = System::Drawing::Size(221, 20);
			this->textEntryBox->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(11, 190);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(70, 60);
			this->button1->TabIndex = 2;
			this->button1->Text = L"1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(87, 190);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(70, 60);
			this->button2->TabIndex = 2;
			this->button2->Text = L"2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(163, 190);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(70, 60);
			this->button3->TabIndex = 2;
			this->button3->Text = L"3";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(11, 124);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(70, 60);
			this->button4->TabIndex = 2;
			this->button4->Text = L"4";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(87, 124);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(70, 60);
			this->button5->TabIndex = 2;
			this->button5->Text = L"5";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(163, 124);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(70, 60);
			this->button6->TabIndex = 2;
			this->button6->Text = L"6";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(11, 58);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(70, 60);
			this->button7->TabIndex = 2;
			this->button7->Text = L"7";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(87, 58);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(70, 60);
			this->button8->TabIndex = 2;
			this->button8->Text = L"8";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(163, 58);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(70, 60);
			this->button9->TabIndex = 2;
			this->button9->Text = L"9";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Form1::button9_Click);
			// 
			// button0
			// 
			this->button0->Location = System::Drawing::Point(87, 255);
			this->button0->Name = L"button0";
			this->button0->Size = System::Drawing::Size(70, 60);
			this->button0->TabIndex = 2;
			this->button0->Text = L"0";
			this->button0->UseVisualStyleBackColor = true;
			this->button0->Click += gcnew System::EventHandler(this, &Form1::button0_Click);
			// 
			// buttonConnect
			// 
			this->buttonConnect->Location = System::Drawing::Point(239, 27);
			this->buttonConnect->Name = L"buttonConnect";
			this->buttonConnect->Size = System::Drawing::Size(90, 25);
			this->buttonConnect->TabIndex = 3;
			this->buttonConnect->Text = L"Connect";
			this->buttonConnect->UseVisualStyleBackColor = true;
			this->buttonConnect->Click += gcnew System::EventHandler(this, &Form1::buttonConnect_Click);
			// 
			// buttonEnter
			// 
			this->buttonEnter->Location = System::Drawing::Point(163, 255);
			this->buttonEnter->Name = L"buttonEnter";
			this->buttonEnter->Size = System::Drawing::Size(70, 59);
			this->buttonEnter->TabIndex = 3;
			this->buttonEnter->Text = L"Enter";
			this->buttonEnter->UseVisualStyleBackColor = true;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->fileToolStripMenuItem, 
				this->aboutToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(520, 24);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->printReceiptToolStripMenuItem, 
				this->exitToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// printReceiptToolStripMenuItem
			// 
			this->printReceiptToolStripMenuItem->Name = L"printReceiptToolStripMenuItem";
			this->printReceiptToolStripMenuItem->Size = System::Drawing::Size(141, 22);
			this->printReceiptToolStripMenuItem->Text = L"Print Receipt";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(141, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exitToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(52, 20);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::aboutToolStripMenuItem_Click);
			// 
			// buttonClear
			// 
			this->buttonClear->Location = System::Drawing::Point(11, 256);
			this->buttonClear->Name = L"buttonClear";
			this->buttonClear->Size = System::Drawing::Size(70, 59);
			this->buttonClear->TabIndex = 3;
			this->buttonClear->Text = L"Clear";
			this->buttonClear->UseVisualStyleBackColor = true;
			this->buttonClear->Click += gcnew System::EventHandler(this, &Form1::buttonClear_Click);
			// 
			// buttonDisconnect
			// 
			this->buttonDisconnect->Enabled = false;
			this->buttonDisconnect->Location = System::Drawing::Point(335, 27);
			this->buttonDisconnect->Name = L"buttonDisconnect";
			this->buttonDisconnect->Size = System::Drawing::Size(90, 25);
			this->buttonDisconnect->TabIndex = 3;
			this->buttonDisconnect->Text = L"Disconnect";
			this->buttonDisconnect->UseVisualStyleBackColor = true;
			this->buttonDisconnect->Click += gcnew System::EventHandler(this, &Form1::buttonDisconnect_Click);
			// 
			// buttonExit
			// 
			this->buttonExit->Location = System::Drawing::Point(431, 27);
			this->buttonExit->Name = L"buttonExit";
			this->buttonExit->Size = System::Drawing::Size(77, 25);
			this->buttonExit->TabIndex = 3;
			this->buttonExit->Text = L"Exit";
			this->buttonExit->UseVisualStyleBackColor = true;
			this->buttonExit->Click += gcnew System::EventHandler(this, &Form1::buttonExit_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(520, 320);
			this->ControlBox = false;
			this->Controls->Add(this->buttonClear);
			this->Controls->Add(this->buttonEnter);
			this->Controls->Add(this->buttonExit);
			this->Controls->Add(this->buttonDisconnect);
			this->Controls->Add(this->buttonConnect);
			this->Controls->Add(this->button0);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textEntryBox);
			this->Controls->Add(this->TextLog);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximumSize = System::Drawing::Size(536, 358);
			this->MinimumSize = System::Drawing::Size(536, 358);
			this->Name = L"Form1";
			this->Text = L"BankTech Client";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 TextLog->Text = "Press \"Connect\"...";
				 TextLog-> Select(0,0);

			 }

private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
private: System::Void buttonConnect_Click(System::Object^  sender, System::EventArgs^  e) {
			 TextLog-> Text = TextLog->Text + "\r\nAttempting to connect to the server...";
			 TextLog-> Select(0,0);
			 buttonConnect->Enabled = false;

			 //Connection Code

			 buttonDisconnect->Enabled = true;
		 }
private: System::Void buttonDisconnect_Click(System::Object^  sender, System::EventArgs^  e) {
			 TextLog-> Text = TextLog->Text + "\r\nClosing connection to the server...";
			 TextLog-> Select(0,0);
			 buttonDisconnect->Enabled = false;

			 //Disconnection Code

			 buttonConnect->Enabled = true;
		 }
private: System::Void buttonExit_Click(System::Object^  sender, System::EventArgs^  e) {

			 //Disconnect and Exit

			 TextLog-> Text = TextLog->Text + "\r\nShutting down BankTech Client...";
			 TextLog-> Select(0,0);
			 this->Close();
		 }
private: System::Void button0_Click(System::Object^  sender, System::EventArgs^  e) {
			 textEntryBox -> Text = textEntryBox-> Text + "0";
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 textEntryBox -> Text = textEntryBox-> Text + "1";
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 textEntryBox -> Text = textEntryBox-> Text + "2";
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 textEntryBox -> Text = textEntryBox-> Text + "3";
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 textEntryBox -> Text = textEntryBox-> Text + "4";
		}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 textEntryBox -> Text = textEntryBox-> Text + "5";
		 }
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
			 textEntryBox -> Text = textEntryBox-> Text + "6";
		 }
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
			 textEntryBox -> Text = textEntryBox-> Text + "7";
		 }
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
			 textEntryBox -> Text = textEntryBox-> Text + "8";
		 }
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
			 textEntryBox -> Text = textEntryBox-> Text + "9";
		 }
private: System::Void buttonClear_Click(System::Object^  sender, System::EventArgs^  e) {
			 textEntryBox -> Text = "";
		 }
private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 MessageBox::Show(
				"BankTech Solutions: Client Software\n"+
				"Form designed for CS 240 - Fall 2011\n"+
				"Authors: Ryan Darge,\n"+
				"Last Revised: Nov 28, 2011\n",
				"About BankTech Solutions", MessageBoxButtons::OK, 
				MessageBoxIcon::Information);
		 }
};
}

