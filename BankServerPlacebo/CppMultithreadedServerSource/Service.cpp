#pragma once
#include "stdafx.h"
using namespace System;
using namespace System::IO;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Threading;

public ref class Service{
	private: Socket^ serverSocket;
			 NetworkStream^ netStream;
			 BinaryReader^ br;
			 BinaryWriter^ bw;
	public: Service(Socket^ aSocket){
				serverSocket = aSocket;
				netStream = gcnew NetworkStream(serverSocket);
				br = gcnew BinaryReader(netStream);
				bw = gcnew BinaryWriter(netStream);
			}
			void DoService(){
				bw -> Write("Client connected.");
				try {
					int value1, value2;
					int result;
					while (true) //until end of input
					{
						value1 = br->ReadInt32();						
						value2 = br->ReadInt32();						
						result = value1 + value2;
						bw->Write(result);						
					}
				}
				catch (EndOfStreamException^ e){ //client finished
					netStream->Close();
				}
				
			}
};