#include "BinFileBankData.h"
#include <fstream>
#include <string>
#include <vector>

void BinFileBankData::init()
{

	//Initialize filename variables
	try{
		//No equivalent "Properties" object for C++ -.-;
		//Substituting hardcoded values.
		bankFileName = "binCustRecords.dat";
		accountsFileName = "binAccts.dat";
	}
	catch(exception e)
	{
		throw e;
	}

	try
	{
		//Read all data
		ifstream file(bankFileName);
		custRecords = vector<CustomerRecord>();
		int recordSize = 16;
		string buffer;
		while(getline(file, buffer))
		{
			int custNum;
			int pin;
			int checking;
			int savings;
			file >> custNum;
			file >> pin;
			file >> checking;
			file >> savings;
			custRecords.push_back(CustomerRecord(custNum, pin, checking, savings));
		}
		file.close();
	}
	catch(exception e)
	{
		custRecords = vector<CustomerRecord>();
   		populateCustRecords();
	}

	try
	{
		//Read all data
		ifstream file(accountsFileName);
		accounts = vector<AccountRecord>();
		int recordSize = 12;
		string buffer;
		while(getline(file, buffer))
		{
			int accNum;
			double balance;
			file >> accNum;
			file >> balance;
			accounts.push_back(AccountRecord(accNum, balance));
		}
		file.close();
	}
	catch(exception e)
	{
		accounts = vector<AccountRecord>();
   		populateAccounts();
	}

}

void BinFileBankData::close()
{
	try
	{
		ofstream file = ofstream(bankFileName);
		int numRecords = custRecords.size();
		for(int i=0; i < numRecords; i++)
		{
			CustomerRecord record = custRecords[i];
			file << record.getCustNum();
			file << record.getPin();
			file << record.getChecking();
			file << record.getSavings();
		}
		file.close();

		file = ofstream(accountsFileName);
		numRecords = accounts.size();
		for(int i = 0; i < numRecords; i++)
		{
			AccountRecord record = accounts[i];
			file << record.getNumber();
			file << record.getBalance();
		}
		file.close();
	}
	catch(exception e)
	{
		throw e;
	}

}