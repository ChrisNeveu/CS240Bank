/*
Ryan Darge
CS 240 FALL 2011
BANK GUI CLIENT

The following documentation is meant primary for development maintenance
=========================================================================
Q: What is decimal used for? What is that I don't even?
A: Decimal is used to incrementially divide the value entered after the decimal mark,
   and is only used when making a withdrawal or deposit. It works like this:
   DECIMAL	| KEY ENTERED	| RESULT
   1			2				2
   1			3				23
   1->10		.				23
   10->100		3				23.3  (23   + 3/10)
   1000->1000	4				23.34 (23.3 + 4/100)
   Decimal is incremented every time a number is entered after the decimal key "." is entered
     >> See textIn_TextChanged() towards the bottom of the method declarations


Q: SOCKETS
A: Here's the lowdown:
	On connection, before receiving confirmation, the client sends two integers
		So Far:
			< custNum
			< custPin
	It expects to receive a confirmation at this point, -2 as an double for bad account details,
	-1 is reserved for socket errors. If the account is valid, send back the balance
		So Far:
			< custNum
			< custPin
			> balance, or -2 for error
	Next up come any possible chain of withdrawals or deposits. The client sends a character,
	'W' or 'D', for withdrawal or deposit, respectively, followed by the amount for said transaction.
	It expects a single int response, signifying whether or not the transaction is valid (1 = YES! 2 = Nope.)
		So Far: (Example transactions added)
			< custNum
			< custPin
			> 1000				Let's assume the balance is 1000.00

			< 'W'				Withdrawal
			< 200.00			of 200.00 
			> 1					Accepted!

			< 'D'				Deposit
			< 150.00			of 150.00
			> 1					Accepted!

			< 'W'				Withdrawal
			< 1000.00			of 1000.00?!
			> 2					Insufficient funds (950.00 Remaining)

	There aren't any close-socket procedures clientside that I can think of to add.
	
	I hope this wasn't a waste of time.
   -Ryan Darge
	ryan.darge@gmail.com
*/

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string>
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;	
	using namespace System::IO;
	using namespace System::Net;
	using namespace System::Net::Sockets;
	using namespace System::Threading;
	using namespace std;


namespace BankGui {

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
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button0;
	private: System::Windows::Forms::Button^  btnClear;
	private: System::Windows::Forms::TextBox^  textIn;


	private: System::Windows::Forms::Button^  btnBot;
	private: System::Windows::Forms::Button^  btnMid;
	private: System::Windows::Forms::Button^  btnTop;
	private: System::Windows::Forms::Button^  btnDot;
	private: System::Windows::Forms::TextBox^  textOut;



	private:
		//IO Members
		int input;
		int decimal;

		//Communication Members
		int port;
		int messageCount;
		IPAddress^ ipAddress;
		IPEndPoint^ ipEndpoint;
		Socket^ clientSocket;		
		NetworkStream^ netStream;
		BinaryReader^ br;
		BinaryWriter^ bw;

		//Bank Related Members
		int custNum;
		int custPin;
		double balance;
		int state;		
			/*/Possible States
			1- Enter Customer Number
			2- Enter Customer Pin
			3- Connecting
			4- Select Option (Withdraw/Deposit)
			5- Enter Value to deposit
			6- Enter Value to withdraw
			7- Logged Out
			8- Withdraw Refused
			//*/

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
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->textIn = (gcnew System::Windows::Forms::TextBox());
			this->btnBot = (gcnew System::Windows::Forms::Button());
			this->btnMid = (gcnew System::Windows::Forms::Button());
			this->btnTop = (gcnew System::Windows::Forms::Button());
			this->textOut = (gcnew System::Windows::Forms::TextBox());
			this->btnDot = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 150);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(50, 50);
			this->button1->TabIndex = 0;
			this->button1->Text = L"1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(68, 150);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(50, 50);
			this->button2->TabIndex = 0;
			this->button2->Text = L"2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(124, 150);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(50, 50);
			this->button3->TabIndex = 0;
			this->button3->Text = L"3";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(12, 94);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(50, 50);
			this->button4->TabIndex = 0;
			this->button4->Text = L"4";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(68, 94);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(50, 50);
			this->button5->TabIndex = 0;
			this->button5->Text = L"5";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(124, 94);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(50, 50);
			this->button6->TabIndex = 0;
			this->button6->Text = L"6";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(12, 38);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(50, 50);
			this->button7->TabIndex = 0;
			this->button7->Text = L"7";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(68, 38);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(50, 50);
			this->button8->TabIndex = 0;
			this->button8->Text = L"8";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(124, 38);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(50, 50);
			this->button9->TabIndex = 0;
			this->button9->Text = L"9";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Form1::button9_Click);
			// 
			// button0
			// 
			this->button0->Location = System::Drawing::Point(68, 206);
			this->button0->Name = L"button0";
			this->button0->Size = System::Drawing::Size(50, 50);
			this->button0->TabIndex = 0;
			this->button0->Text = L"0";
			this->button0->UseVisualStyleBackColor = true;
			this->button0->Click += gcnew System::EventHandler(this, &Form1::button0_Click);
			// 
			// btnClear
			// 
			this->btnClear->Location = System::Drawing::Point(124, 206);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(50, 50);
			this->btnClear->TabIndex = 0;
			this->btnClear->Text = L"Clear";
			this->btnClear->UseVisualStyleBackColor = true;
			this->btnClear->Click += gcnew System::EventHandler(this, &Form1::btnClear_Click);
			// 
			// textIn
			// 
			this->textIn->Location = System::Drawing::Point(12, 12);
			this->textIn->Name = L"textIn";
			this->textIn->Size = System::Drawing::Size(161, 20);
			this->textIn->TabIndex = 1;
			this->textIn->TextChanged += gcnew System::EventHandler(this, &Form1::textIn_TextChanged);
			// 
			// btnBot
			// 
			this->btnBot->Location = System::Drawing::Point(180, 231);
			this->btnBot->Name = L"btnBot";
			this->btnBot->Size = System::Drawing::Size(166, 23);
			this->btnBot->TabIndex = 2;
			this->btnBot->Text = L"Bottom";
			this->btnBot->UseVisualStyleBackColor = true;
			this->btnBot->Click += gcnew System::EventHandler(this, &Form1::btnBot_Click);
			// 
			// btnMid
			// 
			this->btnMid->Location = System::Drawing::Point(180, 202);
			this->btnMid->Name = L"btnMid";
			this->btnMid->Size = System::Drawing::Size(166, 23);
			this->btnMid->TabIndex = 2;
			this->btnMid->Text = L"Middle";
			this->btnMid->UseVisualStyleBackColor = true;
			this->btnMid->Click += gcnew System::EventHandler(this, &Form1::btnMid_Click);
			// 
			// btnTop
			// 
			this->btnTop->Location = System::Drawing::Point(180, 173);
			this->btnTop->Name = L"btnTop";
			this->btnTop->Size = System::Drawing::Size(166, 23);
			this->btnTop->TabIndex = 2;
			this->btnTop->Text = L"Top";
			this->btnTop->UseVisualStyleBackColor = true;
			this->btnTop->Click += gcnew System::EventHandler(this, &Form1::btnTop_Click);
			// 
			// textOut
			// 
			this->textOut->Location = System::Drawing::Point(180, 12);
			this->textOut->Multiline = true;
			this->textOut->Name = L"textOut";
			this->textOut->Size = System::Drawing::Size(166, 155);
			this->textOut->TabIndex = 3;
			// 
			// btnDot
			// 
			this->btnDot->Location = System::Drawing::Point(12, 206);
			this->btnDot->Name = L"btnDot";
			this->btnDot->Size = System::Drawing::Size(50, 49);
			this->btnDot->TabIndex = 4;
			this->btnDot->Text = L".";
			this->btnDot->UseVisualStyleBackColor = true;
			this->btnDot->Click += gcnew System::EventHandler(this, &Form1::btnDot_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(358, 266);
			this->Controls->Add(this->btnDot);
			this->Controls->Add(this->textOut);
			this->Controls->Add(this->btnTop);
			this->Controls->Add(this->btnMid);
			this->Controls->Add(this->btnBot);
			this->Controls->Add(this->textIn);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->btnClear);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button0);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Bank Client";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 input = 0;
			 custNum = 0;
			 custPin = 0;
			 state = 1;
			 decimal = 1;
			 reload();
		}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 input = input * 10 + 1;
			 textIn->Text = textIn->Text + "1";
		}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 input = input * 10 + 2;
			 textIn->Text = textIn->Text + "2";
		}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 input = input * 10 + 3;
			 textIn->Text = textIn->Text + "3";
		}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 input = input * 10 + 4;
			 textIn->Text = textIn->Text + "4";
		}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 input = input * 10 + 5;
			 textIn->Text = textIn->Text + "5";
		}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
			 input = input * 10 + 6;
			 textIn->Text = textIn->Text + "6";
		}
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
			 input = input * 10 + 7;
			 textIn->Text = textIn->Text + "7";
		}
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
			 input = input * 10 + 8;
			 textIn->Text = textIn->Text + "8";
		}
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
			 input = input * 10 + 9;
			 textIn->Text = textIn->Text + "9";
		}
private: System::Void button0_Click(System::Object^  sender, System::EventArgs^  e) {
			 input = input * 10 + 0;
			 textIn->Text = textIn->Text + "0";
		}
private: System::Void btnDot_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(decimal == 1)
				decimal = -1;
			 textIn->Text = textIn->Text + ".";
		}
private: System::Void btnClear_Click(System::Object^  sender, System::EventArgs^  e) {
			 /*Testing value of input
			 char* temp = new char[20];
			 temp = itoa(input, temp, 10);
			 textIn->Text = gcnew String(temp);
			 */
			 textIn->Text = "";
			 decimal = 1;
			 input = 0;
		}
private: System::Void btnTop_Click(System::Object^  sender, System::EventArgs^  e) {
						//EX:STATE DESCRIPTION       : TASK TO COMPLETE
						//EX:Logged Out				 : Close Frame
			if(state == 1) //Entering Customer Number: Submit
			{
				custNum = input;
				state = 2;
				 
				reload();
			}
			else if(state == 2)//Entering PIN: Submit
			{
				custPin = input;
				state = 3;

				reload();
				
				//Establish connection to server
				double confirmation = 0;
				try
				{
					port = 9999;
					messageCount = 3;
					ipAddress = Dns::GetHostEntry(Dns::GetHostName())->AddressList[0];
					ipEndpoint = gcnew IPEndPoint(ipAddress, port);
					clientSocket = gcnew Socket(ipAddress ->AddressFamily,
										SocketType::Stream, ProtocolType::Tcp); 
					clientSocket->Connect(ipEndpoint);
					netStream = gcnew NetworkStream(clientSocket);		
					br = gcnew BinaryReader(netStream);
					bw = gcnew BinaryWriter(netStream);			
					bw->Write(custNum);
					bw->Write(custPin);
					confirmation = br ->ReadDouble();
				}
				catch(SocketException^ e)
				{
					//textOut->Text = e->ToString();
					textOut->Text = "No connection could be made to the server."; 
					confirmation = -1;
					state = 7; 
					reload();
				}
				if(confirmation == -2) //If the server is reached and an invalid number or pin is found, receive -1
				{
					textOut->Text = "Invalid customer number or pin.";
					state = 7;
					reload();
				}			
				else if(confirmation >= 0) //confirmation should generally be the balance, to minimize data transfer
				{
					state = 4;
					balance = confirmation;
					reload();
				}
				else if(confirmation < -2) //Any unknown responses (negative) will be "caught" here
				{
					textOut->Text = "Invalid Response: ";
					//Print out response value
					char* temp = new char[20];
					temp = itoa(confirmation, temp, 10);
					textOut->Text = textOut->Text + gcnew String(temp);

					state = 7;
					reload();
				}

			}
			else if (state == 4) //Logged in: Goto Withdraw
			{
				state = 5;
				reload();
			}
			else if (state == 5) //Withdraw: Submit
			{
				bw->Write('W');			//W is for withdrawing
				//Convert input into a double
				double temp = input/decimal;
				bw->Write(temp);//bw->Write(input);
				int response = br->ReadInt32();
				if(response == 1) //Withdrawal Accepted
				{
					state = 4;
					balance = balance - input/(double)decimal;
				}
				else if(response == 2) //Withdrawal Refused, NSF
					state = 8;
				
				reload();
			}
			else if (state == 6) //Deposit: Submit
			{
				bw->Write('D');
				//Convert input into a double
				double temp = input/decimal;
				bw->Write(temp);
				int response = br->ReadInt32();
				if(response == 1) //Deposit Accepted
				{
					state = 4;
					balance = balance + input/(double)decimal;
				}
				else if(response == 2)	//Deposit Refused
					state = 7;
				reload();
			}
			else if (state == 7) //Error or logged out: Restart
			{
				state = 1;
				custNum = 0;
				custPin = 0;
				reload();
			}
			else if (state == 8) //NSF for withdrawal
			{
				state = 4;
				reload();
			}	
		}
private: System::Void btnMid_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(state == 4) //Logged in: Deposit
			 {
				 state = 6;
				 reload();
			 }
			 else if(state == 5) //Deposit: Cancel
			 {
				 state = 4;
				 reload();
			 }
			 else if(state == 6) //Withdraw: Cancel
			 {
				 state = 4;
				 reload();
			 }
			 
		}
private: System::Void btnBot_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(state > 2) //If we have connected to the server...probably should disconnect
			 {
				 clientSocket->Shutdown(SocketShutdown::Both);		 
				 clientSocket->Close();
				 netStream->Close();
				 textOut->Text = "Client disconnected";  		 
				 state = 7;
				 reload();
			 }
			 this->Close();
		}
private: System::Void reload(){

			 //Clear temporary storage
			 textIn ->UseSystemPasswordChar = false;
			 btnDot ->Enabled = false;
			 input = 0;
			 decimal = 1;
			 textIn ->Text = "";
			 button1 -> Enabled = true;
			 button2 -> Enabled = true;
			 button3 -> Enabled = true;
			 button4 -> Enabled = true;
			 button5 -> Enabled = true;
			 button6 -> Enabled = true;
			 button7 -> Enabled = true;
			 button8 -> Enabled = true;
			 button9 -> Enabled = true;
			 button0 -> Enabled = true;
			 btnDot->Enabled = true;
			 btnClear->Enabled = true;

			 //Update labels
			 if(state == 1)  //Login Screen - Entering customer number
			 {
				 textOut ->Text = "Enter your bank account number; \nPress enter to continue";
				 textIn ->Text = "";
				 btnTop ->Text = "Enter";
				 btnMid ->Text = "";
				 btnBot ->Text = "Exit";
			 }
			 if(state == 2) //Login Screen - Entering PIN number
			 {
				 textOut ->Text = "Enter your bank PIN number; \nPress enter to login";
				 textIn ->Text = "";
				 textIn ->UseSystemPasswordChar = true;
				 btnTop ->Text = "Enter";
				 btnMid ->Text = "";
				 btnBot ->Text = "Exit";
			 }
			 if(state == 3) //Attempting to connect to server
			 {
				 textOut ->Text = "Attempting to establish \nconnection to server...";
				 textIn -> Text = "";
			 }
			 if(state == 4) //Logged In Screen
			 {
				 char* temp = new char[20];
				 temp = itoa((int)balance, temp, 10);
				 //textOut->Text = textOut->Text + gcnew String(temp);
				 textOut ->Text = ("Connection Established.\r\nCurrent Balance:" + gcnew String(temp));
				 btnTop -> Text = "Withdraw";
				 btnMid -> Text = "Deposit";
				 btnBot -> Text = "Exit";
				 button1 -> Enabled = false;
				 button2 -> Enabled = false;
				 button3 -> Enabled = false;
				 button4 -> Enabled = false;
				 button5 -> Enabled = false;
				 button6 -> Enabled = false;
				 button7 -> Enabled = false;
				 button8 -> Enabled = false;
				 button9 -> Enabled = false;
				 button0 -> Enabled = false;
				 btnDot->Enabled = false;
				 btnClear->Enabled = false;
			 }
			 if(state == 6) //Deposit 
			 {
				 textOut ->Text = "Enter amount to deposit\r\nPress enter to submit";
				 btnDot ->Enabled = true;
				 btnTop -> Text = "Submit";
				 btnMid -> Text = "Cancel";
				 btnBot -> Text = "Exit";
			 }
			 if(state == 5) //Withdraw
			 {
				 textOut ->Text = "Enter amount to withdraw\r\nPress enter to submit";
				 btnDot ->Enabled = true;
				 btnTop -> Text = "Submit";
				 btnMid -> Text = "Cancel";
				 btnBot -> Text = "Exit";
			 }
			 if(state == 7) //Error Screen (textOut updated at time of error, see btnTop for most situations)
			 {
				 btnTop -> Text = "Restart";
				 btnMid -> Text = "";
				 btnBot -> Text = "Exit";
			 }
			 if(state == 8) //NSF ERROR Screen - Occurs when not enough funds are available for withdrawal.
			 {
				 textOut -> Text = "Error: Insufficient Funds\r\nSelect an option from below";
				 state = 4;
				 btnTop -> Text = "Withdraw";
				 btnMid -> Text = "Deposit";
				 btnBot -> Text = "Exit";				 
			 }
		}
private: System::Void textIn_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(decimal == -1)
				 decimal = 10;
			 else if(decimal >= 10)
				 decimal = decimal * 10;
		}
};
}

