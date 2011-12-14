const int START = 1;
const int PIN = 2;
const int ACCOUNT = 3;
const int TRANSACT = 4;
const int CHECKING = 1;
const int SAVINGS = 2;

#pragma once






namespace ATMFrame(ATMInterface theATM) {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
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
	private: System::Windows::Forms::Button^  btn1;
	private: System::Windows::Forms::Button^  btn2;
	private: System::Windows::Forms::Button^  btn3;
	private: System::Windows::Forms::Button^  btn4;
	private: System::Windows::Forms::Button^  btn5;
	private: System::Windows::Forms::Button^  btn6;
	private: System::Windows::Forms::Button^  btn7;
	private: System::Windows::Forms::Button^  btn8;
	private: System::Windows::Forms::Button^  btn9;
	private: System::Windows::Forms::Button^  btn0;
	private: System::Windows::Forms::Button^  btnDot;
	private: System::Windows::Forms::Button^  btnCe;
	private: System::Windows::Forms::Label^  lblTel;


	private: System::Windows::Forms::Button^  btnTop;
	private: System::Windows::Forms::Button^  btnMid;
	private: System::Windows::Forms::Button^  btnBot;
	private: System::Windows::Forms::Label^  lblNum;
	private: double padnum;
	private: double dec;
	//private: ATMInterface theATM;
	private: int state;




	protected: 



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
			this->btn1 = (gcnew System::Windows::Forms::Button());
			this->btn2 = (gcnew System::Windows::Forms::Button());
			this->btn3 = (gcnew System::Windows::Forms::Button());
			this->btn4 = (gcnew System::Windows::Forms::Button());
			this->btn5 = (gcnew System::Windows::Forms::Button());
			this->btn6 = (gcnew System::Windows::Forms::Button());
			this->btn7 = (gcnew System::Windows::Forms::Button());
			this->btn8 = (gcnew System::Windows::Forms::Button());
			this->btn9 = (gcnew System::Windows::Forms::Button());
			this->btn0 = (gcnew System::Windows::Forms::Button());
			this->btnDot = (gcnew System::Windows::Forms::Button());
			this->btnCe = (gcnew System::Windows::Forms::Button());
			this->lblTel = (gcnew System::Windows::Forms::Label());
			this->btnTop = (gcnew System::Windows::Forms::Button());
			this->btnMid = (gcnew System::Windows::Forms::Button());
			this->btnBot = (gcnew System::Windows::Forms::Button());
			this->lblNum = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btn1
			// 
			this->btn1->Location = System::Drawing::Point(15, 61);
			this->btn1->Name = L"btn1";
			this->btn1->Size = System::Drawing::Size(46, 31);
			this->btn1->TabIndex = 0;
			this->btn1->Text = L"1";
			this->btn1->UseVisualStyleBackColor = true;
			this->btn1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// btn2
			// 
			this->btn2->Location = System::Drawing::Point(67, 61);
			this->btn2->Name = L"btn2";
			this->btn2->Size = System::Drawing::Size(45, 31);
			this->btn2->TabIndex = 1;
			this->btn2->Text = L"2";
			this->btn2->UseVisualStyleBackColor = true;
			this->btn2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// btn3
			// 
			this->btn3->Location = System::Drawing::Point(118, 61);
			this->btn3->Name = L"btn3";
			this->btn3->Size = System::Drawing::Size(45, 31);
			this->btn3->TabIndex = 2;
			this->btn3->Text = L"3";
			this->btn3->UseVisualStyleBackColor = true;
			this->btn3->Click += gcnew System::EventHandler(this, &Form1::btn3_Click);
			// 
			// btn4
			// 
			this->btn4->Location = System::Drawing::Point(15, 98);
			this->btn4->Name = L"btn4";
			this->btn4->Size = System::Drawing::Size(46, 30);
			this->btn4->TabIndex = 3;
			this->btn4->Text = L"4";
			this->btn4->UseVisualStyleBackColor = true;
			this->btn4->Click += gcnew System::EventHandler(this, &Form1::btn4_Click);
			// 
			// btn5
			// 
			this->btn5->Location = System::Drawing::Point(67, 98);
			this->btn5->Name = L"btn5";
			this->btn5->Size = System::Drawing::Size(45, 30);
			this->btn5->TabIndex = 4;
			this->btn5->Text = L"5";
			this->btn5->UseVisualStyleBackColor = true;
			this->btn5->Click += gcnew System::EventHandler(this, &Form1::btn5_Click);
			// 
			// btn6
			// 
			this->btn6->Location = System::Drawing::Point(118, 98);
			this->btn6->Name = L"btn6";
			this->btn6->Size = System::Drawing::Size(44, 29);
			this->btn6->TabIndex = 5;
			this->btn6->Text = L"6";
			this->btn6->UseVisualStyleBackColor = true;
			this->btn6->Click += gcnew System::EventHandler(this, &Form1::btn6_Click);
			// 
			// btn7
			// 
			this->btn7->Location = System::Drawing::Point(15, 134);
			this->btn7->Name = L"btn7";
			this->btn7->Size = System::Drawing::Size(46, 29);
			this->btn7->TabIndex = 6;
			this->btn7->Text = L"7";
			this->btn7->UseVisualStyleBackColor = true;
			this->btn7->Click += gcnew System::EventHandler(this, &Form1::btn7_Click);
			// 
			// btn8
			// 
			this->btn8->Location = System::Drawing::Point(67, 134);
			this->btn8->Name = L"btn8";
			this->btn8->Size = System::Drawing::Size(45, 29);
			this->btn8->TabIndex = 7;
			this->btn8->Text = L"8";
			this->btn8->UseVisualStyleBackColor = true;
			this->btn8->Click += gcnew System::EventHandler(this, &Form1::btn8_Click);
			// 
			// btn9
			// 
			this->btn9->Location = System::Drawing::Point(117, 134);
			this->btn9->Name = L"btn9";
			this->btn9->Size = System::Drawing::Size(45, 29);
			this->btn9->TabIndex = 8;
			this->btn9->Text = L"9";
			this->btn9->UseVisualStyleBackColor = true;
			this->btn9->Click += gcnew System::EventHandler(this, &Form1::btn9_Click);
			// 
			// btn0
			// 
			this->btn0->Location = System::Drawing::Point(15, 169);
			this->btn0->Name = L"btn0";
			this->btn0->Size = System::Drawing::Size(46, 27);
			this->btn0->TabIndex = 9;
			this->btn0->Text = L"0";
			this->btn0->UseVisualStyleBackColor = true;
			this->btn0->Click += gcnew System::EventHandler(this, &Form1::btn0_Click);
			// 
			// btnDot
			// 
			this->btnDot->Location = System::Drawing::Point(67, 169);
			this->btnDot->Name = L"btnDot";
			this->btnDot->Size = System::Drawing::Size(45, 27);
			this->btnDot->TabIndex = 10;
			this->btnDot->Text = L".";
			this->btnDot->UseVisualStyleBackColor = true;
			this->btnDot->Click += gcnew System::EventHandler(this, &Form1::btnDot_Click);
			// 
			// btnCe
			// 
			this->btnCe->Location = System::Drawing::Point(117, 169);
			this->btnCe->Name = L"btnCe";
			this->btnCe->Size = System::Drawing::Size(45, 27);
			this->btnCe->TabIndex = 11;
			this->btnCe->Text = L"CE";
			this->btnCe->UseVisualStyleBackColor = true;
			this->btnCe->Click += gcnew System::EventHandler(this, &Form1::btnCe_Click);
			// 
			// lblTel
			// 
			this->lblTel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblTel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblTel->Location = System::Drawing::Point(181, 61);
			this->lblTel->Name = L"lblTel";
			this->lblTel->Size = System::Drawing::Size(157, 135);
			this->lblTel->TabIndex = 12;
			this->lblTel->Text = L"enter customer numer and press ok";
			// 
			// btnTop
			// 
			this->btnTop->Location = System::Drawing::Point(354, 61);
			this->btnTop->Name = L"btnTop";
			this->btnTop->Size = System::Drawing::Size(78, 31);
			this->btnTop->TabIndex = 13;
			this->btnTop->Text = L"ok";
			this->btnTop->UseVisualStyleBackColor = true;
			this->btnTop->Click += gcnew System::EventHandler(this, &Form1::btnTop_Click);
			// 
			// btnMid
			// 
			this->btnMid->Location = System::Drawing::Point(354, 98);
			this->btnMid->Name = L"btnMid";
			this->btnMid->Size = System::Drawing::Size(78, 29);
			this->btnMid->TabIndex = 14;
			this->btnMid->UseVisualStyleBackColor = true;
			this->btnMid->Click += gcnew System::EventHandler(this, &Form1::btnMid_Click);
			// 
			// btnBot
			// 
			this->btnBot->Location = System::Drawing::Point(354, 134);
			this->btnBot->Name = L"btnBot";
			this->btnBot->Size = System::Drawing::Size(78, 29);
			this->btnBot->TabIndex = 15;
			this->btnBot->Text = L"exit";
			this->btnBot->UseVisualStyleBackColor = true;
			this->btnBot->Click += gcnew System::EventHandler(this, &Form1::btnBot_Click);
			// 
			// lblNum
			// 
			this->lblNum->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblNum->Location = System::Drawing::Point(12, 9);
			this->lblNum->Name = L"lblNum";
			this->lblNum->Size = System::Drawing::Size(150, 37);
			this->lblNum->TabIndex = 16;
			this->lblNum->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(445, 247);
			this->Controls->Add(this->lblNum);
			this->Controls->Add(this->btnBot);
			this->Controls->Add(this->btnMid);
			this->Controls->Add(this->btnTop);
			this->Controls->Add(this->lblTel);
			this->Controls->Add(this->btnCe);
			this->Controls->Add(this->btnDot);
			this->Controls->Add(this->btn0);
			this->Controls->Add(this->btn9);
			this->Controls->Add(this->btn8);
			this->Controls->Add(this->btn7);
			this->Controls->Add(this->btn6);
			this->Controls->Add(this->btn5);
			this->Controls->Add(this->btn4);
			this->Controls->Add(this->btn3);
			this->Controls->Add(this->btn2);
			this->Controls->Add(this->btn1);
			this->Name = L"Form1";
			this->Text = L"Welcome to Bank";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 padnum = padnum * 10 + 1;
				 dec = dec * 10;
				 this->lblNum->Text = this->lblNum->Text + "1"; 
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 padnum = padnum * 10 + 2;
				 dec = dec * 10;
				 this->lblNum->Text = this->lblNum->Text + "2";
			 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				this->padnum = 0;
				this->dec = 0;
				this->lblNum->Text = " ";
				int state = this->theATM.getState();
				if (state == START){
					this->lblTel->Text = "Enter customer number and press OK.";
					this->btnTop->Text = "OK";
					this->btnMid->Text = "   ";
					this->btnBot->Text = "Exit";
				}
				else if (state == PIN){
					this->lblTel->Text = "Enter PIN and press OK";
					this->btnTop->Text = "OK";
					this->btnMid->Text = "   ";
					this->btnBot->Text = "   ";
				}
				else if (state == ACCOUNT){
						this->lblTel->Text = "select account";
					this->btnTop->Text = "checking";
					this->btnMid->Text = "savings";
					this->btnBot->Text = "cancel";
				}
				else if (state == TRANSACT){
				this->lblTel->Text = "Balance = "
                  + theATM.getBalance()
                  + "\nEnter amount and select transaction";
					this->btnTop->Text = "withdraw";
					this->btnMid->Text = "deposit";
					this->btnBot->Text = "cancel";
				}
			 }
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void btn3_Click(System::Object^  sender, System::EventArgs^  e) {
				 padnum = padnum * 10 + 3;
				 dec = dec * 10;
				 this->lblNum->Text = this->lblNum->Text + "3";
		 }
private: System::Void btn4_Click(System::Object^  sender, System::EventArgs^  e) {
				 padnum = padnum * 10 + 4;
				 dec = dec * 10;
				 this->lblNum->Text = this->lblNum->Text + "4";
		 }
private: System::Void btn5_Click(System::Object^  sender, System::EventArgs^  e) {
				 padnum = padnum * 10 + 5;
				 dec = dec * 10;
				 this->lblNum->Text = this->lblNum->Text + "5";
		 }
private: System::Void btn6_Click(System::Object^  sender, System::EventArgs^  e) {
				 padnum = padnum * 10 + 6;
				 dec = dec * 10;
				 this->lblNum->Text = this->lblNum->Text + "6";
		 }
private: System::Void btn7_Click(System::Object^  sender, System::EventArgs^  e) {
				 padnum = padnum * 10 + 7;
				 dec = dec * 10;
				 this->lblNum->Text = this->lblNum->Text + "7";
		 }
private: System::Void btn8_Click(System::Object^  sender, System::EventArgs^  e) {
				 padnum = padnum * 10 + 8;
				 dec = dec * 10;
				 this->lblNum->Text = this->lblNum->Text + "8";
		 }
private: System::Void btn9_Click(System::Object^  sender, System::EventArgs^  e) {
				 padnum = padnum * 10 + 9;
				 dec = dec * 10;
				 this->lblNum->Text = this->lblNum->Text + "9";
		 }
private: System::Void btn0_Click(System::Object^  sender, System::EventArgs^  e) {
 				 padnum = padnum * 10;
				 dec = dec * 10;
				 this->lblNum->Text = this->lblNum->Text + "0";
		 }
private: System::Void btnDot_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->dec == 0){
 				 dec = 10;
				 this->lblNum->Text = this->lblNum->Text + ".";
			 }
		 }
private: System::Void btnCe_Click(System::Object^  sender, System::EventArgs^  e) {
				 padnum = 0;
				 dec = 0;
				 this->lblNum->Text = " ";
		 }
private: System::Void btnTop_Click(System::Object^  sender, System::EventArgs^  e) {
   

		 int state = theATM.getState();
         if (state == START)
            theATM.setCustomerNumber((int) padnum);
         else if (state == PIN)
            theATM.selectCustomer((int) padnum);
         else if (state == ACCOUNT)
            theATM.selectAccount(CHECKING);
         else if (state == TRANSACT){
            theATM.withdraw(padnum));
            theATM.back();
         }
		 // reload form
		 {
				this->padnum = 0;
				this->dec = 0;
				this->lblNum->Text = " ";
				int state = this->theATM.getState();
				if (state == START){
					this->lblTel->Text = "Enter customer number and press OK.";
					this->btnTop->Text = "OK";
					this->btnMid->Text = "   ";
					this->btnBot->Text = "Exit";
				}
				else if (state == PIN){
					this->lblTel->Text = "Enter PIN and press OK";
					this->btnTop->Text = "OK";
					this->btnMid->Text = "   ";
					this->btnBot->Text = "   ";
				}
				else if (state == ACCOUNT){
						this->lblTel->Text = "select account";
					this->btnTop->Text = "checking";
					this->btnMid->Text = "savings";
					this->btnBot->Text = "cancel";
				}
				else if (state == TRANSACT){
				this->lblTel->Text = "Balance = "
                  + theATM.getBalance()
                  + "\nEnter amount and select transaction";
					this->btnTop->Text = "withdraw";
					this->btnMid->Text = "deposit";
					this->btnBot->Text = "cancel";
				}
			 }
   }
		 }
private: System::Void btnMid_Click(System::Object^  sender, System::EventArgs^  e) {


         int state = theATM.getState();
         if (state == ACCOUNT)
            theATM.selectAccount(SAVINGS);
         else if (state == TRANSACT){
            theATM.deposit(padnum);
            theATM.back();
         }


         //reload form
		 {
				this->padnum = 0;
				this->dec = 0;
				this->lblNum->Text = " ";
				int state = this->theATM.getState();
				if (state == START){
					this->lblTel->Text = "Enter customer number and press OK.";
					this->btnTop->Text = "OK";
					this->btnMid->Text = "   ";
					this->btnBot->Text = "Exit";
				}
				else if (state == PIN){
					this->lblTel->Text = "Enter PIN and press OK";
					this->btnTop->Text = "OK";
					this->btnMid->Text = "   ";
					this->btnBot->Text = "   ";
				}
				else if (state == ACCOUNT){
						this->lblTel->Text = "select account";
					this->btnTop->Text = "checking";
					this->btnMid->Text = "savings";
					this->btnBot->Text = "cancel";
				}
				else if (state == TRANSACT){
				this->lblTel->Text = "Balance = "
                  + theATM.getBalance()
                  + "\nEnter amount and select transaction";
					this->btnTop->Text = "withdraw";
					this->btnMid->Text = "deposit";
					this->btnBot->Text = "cancel";
				}
			 }
      }
		 }
private: System::Void btnBot_Click(System::Object^  sender, System::EventArgs^  e) {


         int state = theATM.getState();
         if (state == ACCOUNT)
            theATM.reset();
         else if (state == TRANSACT)
            theATM.back();
         else if (state == START){
			 theATM.close();
			 this -> Close();
		     
		 }
         //reload form
		 {
				this->padnum = 0;
				this->dec = 0;
				this->lblNum->Text = " ";
				int state = this->theATM.getState();
				if (state == START){
					this->lblTel->Text = "Enter customer number and press OK.";
					this->btnTop->Text = "OK";
					this->btnMid->Text = "   ";
					this->btnBot->Text = "Exit";
				}
				else if (state == PIN){
					this->lblTel->Text = "Enter PIN and press OK";
					this->btnTop->Text = "OK";
					this->btnMid->Text = "   ";
					this->btnBot->Text = "   ";
				}
				else if (state == ACCOUNT){
						this->lblTel->Text = "select account";
					this->btnTop->Text = "checking";
					this->btnMid->Text = "savings";
					this->btnBot->Text = "cancel";
				}
				else if (state == TRANSACT){
				this->lblTel->Text = "Balance = "
                  + theATM.getBalance()
                  + "\nEnter amount and select transaction";
					this->btnTop->Text = "withdraw";
					this->btnMid->Text = "deposit";
					this->btnBot->Text = "cancel";
				}
			 }


		 }
};


