#include "BankData.h"
#include <fstream>
#include <string>
#include <vector>

/*
 * populates the customer
 * records and the accounts.
 */
void BinFileBankData::init()
{

	//Initialize filename variables
	try{
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

double BankData::getBalance(int accNum)
{
	for (int i = 0; i < accounts.size(); i++)
	{
		if (accounts[i].getNumber()==accNum)
		{
			return accounts[i].getBalance();
		}
	}
	return 0;
}

void BankData::setBalance(int accNum, double amount)
{
	for (int i = 0; i < accounts.size(); i++){
		if (accounts[i].getNumber()==accNum)
		{
			accounts[i].setBalance(amount);
		}
	}
}

/*
 * Populates the customer records array list.
 */
void Bankdata::populateCustRecords()
{
	cout << "Populating customer records" << endl << "acc pin checking savings" << endl;
	for (int i = 1; i < 10; i++)
	{
		custRecords.push_back(new CustomerRecord(i, i*1000 + 2*i%10*100 + 3*i%10*10 + 4*i%10, 100*i+1, 100*i+2));
		cout << (custRecords.get(i-1).getCustNum() << " "
		<< custRecords.get(i-1).getPin() << " "
		<< custRecords.get(i-1).getChecking() << " "
		<< custRecords.get(i-1).getSavings()) << endl;
	}

}

/*
 * Populates the accounts array list.
 */
void BankData::populateAccounts()
{
	cout << "Populating accounts" << endl << "acc balance" << endl;
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j<3; j++)
		{
			accounts.push_back(new Account(100*i+j,0));
			cout << 100*i+j << " " << 0 << endl;
		}
	}
}

vector<Customer> BankData::getCustRecords()
{
	return custRecords;
}
