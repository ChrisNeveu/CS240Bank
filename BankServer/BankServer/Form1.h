#pragma once
//#include "Service.cpp"
#include "BankData.h"


namespace BankServer {

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

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	/// 'Resource File Name' property for the managed resource compiler tool
	/// associated with all .resx files this class depends on. Otherwise,
	/// the designers will not be able to interact properly with localized
	/// resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
		//friend ref class Service; // a managed type cannot
		//have any friend functions/classes/interfaces
		public:
		Form1(void)
		{
			InitializeComponent();

			//
			//TODO: Add the constructor code here
			//
			port = 9999;
			ipAddress = Dns::GetHostEntry(Dns::GetHostName())->AddressList[0];
			ipEndpoint = gcnew IPEndPoint(ipAddress, port);
			listenerSocket = gcnew Socket(ipAddress->AddressFamily,
											   SocketType::Stream, ProtocolType::Tcp);
			listenerSocket->Bind(ipEndpoint);

			// create a new thread to run the server
			serverThread = gcnew Thread(gcnew ThreadStart(this, &Form1::RunServer));
			serverThread->Start();

			update = false;
		}
        

		public:
			void RunServer()
			{
				stopRequested = false;
				listenerSocket->Listen(3); //up to 3 clients can wait for connection
				txtOut ->Text = txtOut ->Text
				+ "Server waiting for client connections.\n";
				int count = 1;
				listenerSocket ->Blocking = false;
				while (! stopRequested)
				{
					try
					{
						Socket^ serverSocket = listenerSocket->Accept();
						serverSocket ->Blocking = true;
						if (stopRequested) 
						{
							break;
						}
						txtOut ->Text = txtOut ->Text + "New connection accepted";
						Service^ service = gcnew Service(serverSocket, this);
						Thread^ childThread = gcnew Thread(gcnew ThreadStart(service, &Service::DoService));
						childThread->Name = "t" + count;
						//txtOut ->Text = txtOut ->Text + ", thread "
						// + childThread->Name + "\n";
						childThread->Start();
						count++;
					}
					catch(SocketException^ e){
						Thread::Sleep(200);
					}
				}
				//txtOut ->Text = txtOut ->Text +"Server stopped.\n";
				btnClose ->Enabled = true;
				btnStop ->Enabled = false;
				if(serverSocket != nullptr)
				{
					serverSocket->Shutdown(SocketShutdown::Both);
					serverSocket->Close();
				}
			} // end RunServer
			// inner class Service, so that it can write on form
			ref class Service
			{
				private: Socket^ serverSocket;
				Form1^ theForm;
				NetworkStream^ netStream;
				BinaryReader^ br;
				BinaryWriter^ bw;
				BankData* theBank;
				public: 
					Service(Socket^ aSocket, Form1^ form)
					{
						serverSocket = aSocket;
						theForm = form;
						netStream = gcnew NetworkStream(serverSocket);
						br = gcnew BinaryReader(netStream);
						bw = gcnew BinaryWriter(netStream);
					}
					void DoService()
					{
						String^ threadName = Thread::CurrentThread->Name;
						theBank->init();
						theBank->populateCustRecords();
						theBank->populateAccounts();
						int custNum = 0;
						int custPin = 0;
						Customer thisCustomer(-2, -2, -2, -2);
						while(thisCustomer.getCustNum()==-2)
						{
							custNum = br->ReadInt32();
							thisCustomer = theBank->findCustomer(custNum);
							if(thisCustomer.getCustNum()==-2)
							{
								bw -> Write(-2);
							}
						}
						while(thisCustomer.getPin()!=custPin)
						{
							custPin = br->ReadInt32();
						}
						BankAccount * thisChecking = &(thisCustomer.getCheckingAccount());
						double balance = thisChecking->getBalance();
						bw -> Write(balance);
						//bw -> Write(threadName + ": Client connected.");
						try {
							int value1;
							double value2;
							int result;
							while (true) //until end of input
							{
								value1 = br->ReadInt32();
								value2 = br->ReadDouble();
								//result = value1 + value2;
								//theForm->txtOut->Text = theForm->txtOut->Text + threadName + ": received: " + value1 + ", " + value2 + "; sending: " + result + "\n";
								if(value1 == 'D')
								{
									balance += value2;
									thisChecking->setBalance(balance + value2);
									bw->Write(1);
								}
								else if(value2 <= 2000 && value1 == 'W')
								{
									balance -= value2;
									thisChecking->setBalance(balance - value2);
									bw->Write(1);
								}
								else
								{
									bw->Write(2);
								}

							}
						}
						catch (EndOfStreamException^ e)
						{ 
							//client finished
							//theForm->txtOut->Text = theForm->txtOut->Text
							// +threadName + ": Client disconnected\n";
							netStream->Close();
							theBank->close();
						}

					} // end DoService
		}; // end class Service
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

		private:
			bool update;
			int port;
			IPAddress^ ipAddress;
			IPEndPoint^ ipEndpoint;
			Socket^ listenerSocket;
			Socket^ serverSocket;
			Thread^ serverThread;
			bool stopRequested; //to end the serverThread loop


		private: 
			System::Windows::Forms::Button^ btnStop;
		private: 
			System::Windows::Forms::Button^ btnClose;
		private: 
			System::Windows::Forms::RichTextBox^ txtOut;


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
			this->btnStop = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->txtOut = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			//
			// btnStop
			//
			this->btnStop->Location = System::Drawing::Point(3, 5);
			this->btnStop->Name = L"btnStop";
			this->btnStop->Size = System::Drawing::Size(102, 26);
			this->btnStop->TabIndex = 1;
			this->btnStop->Text = L"Stop Server";
			this->btnStop->UseVisualStyleBackColor = true;
			this->btnStop->Click += gcnew System::EventHandler(this, &Form1::btnStop_Click);
			//
			// btnClose
			//
			this->btnClose->Enabled = false;
			this->btnClose->Location = System::Drawing::Point(190, 5);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(99, 25);
			this->btnClose->TabIndex = 2;
			this->btnClose->Text = L"Close Window";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &Form1::btnClose_Click);
			//
			// txtOut
			//
			this->txtOut->Location = System::Drawing::Point(8, 36);
			this->txtOut->Name = L"txtOut";
			this->txtOut->Size = System::Drawing::Size(280, 426);
			this->txtOut->TabIndex = 3;
			this->txtOut->Text = L"";
			//
			// Form1
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(292, 464);
			this->ControlBox = false;
			this->Controls->Add(this->txtOut);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnStop);
			this->Name = L"Form1";
			this->Text = L"Server";
			this->ResumeLayout(false);

			}

		#pragma endregion
		private: 
			System::Void btnStop_Click(System::Object^ sender, System::EventArgs^ e)
			{
				stopRequested = true;
				btnStop ->Enabled = false;
						 txtOut ->Text = txtOut ->Text
				+"Stop request received.\n";
			}
		private: 
			System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e)
			{
				this ->Close();
			}
	};
}