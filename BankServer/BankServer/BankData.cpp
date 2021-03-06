#include "BankData.h"
#include <fstream>
#include <string>


using namespace std;

/*
 * populates the customer
 * records and the accounts.
 */
void BankData::init()
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
		ifstream file("binCustRecords.dat");
		custRecords = vector<Customer>();
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
			custRecords.push_back(Customer(custNum, pin, checking, savings));
		}
		file.close();
	}
	catch(exception e)
	{
		custRecords = vector<Customer>();
   		populateCustRecords();
	}

	try
	{
		//Read all data
		ifstream file("binAccts.dat");
		accounts = vector<BankAccount>();
		int recordSize = 12;
		string buffer;
		while(getline(file, buffer))
		{
			int accNum;
			double balance;
			file >> accNum;
			file >> balance;
			accounts.push_back(BankAccount(accNum, balance));
		}
		file.close();
	}
	catch(exception e)
	{
		accounts = vector<BankAccount>();
   		populateAccounts();
	}

}

void BankData::close()
{
	try
	{
		ofstream file("binCustRecords.dat");
		int numRecords = custRecords.size();
		for(int i=0; i < numRecords; i++)
		{
			Customer record = custRecords[i];
			file << record.getCustNum();
			file << record.getPin();
			file << record.getChecking();
			file << record.getSavings();
		}
		file.close();

		ofstream afile("binAccts.dat");
		numRecords = accounts.size();
		for(int i = 0; i < numRecords; i++)
		{
			BankAccount record = accounts[i];
			afile << record.getNumber();
			afile << record.getBalance();
		}
		afile.close();
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
void BankData::populateCustRecords()
{
	//cout << "Populating customer records" << endl << "acc pin checking savings" << endl;
	for (int i = 1; i < 10; i++)
	{
		custRecords.push_back(Customer(i, i*1000 + 2*i%10*100 + 3*i%10*10 + 4*i%10, 100*i+1, 100*i+2));
		cout << custRecords[i-1].getCustNum() << " "
		<< custRecords[i-1].getPin() << " "
		<< custRecords[i-1].getChecking() << " "
		<< custRecords[i-1].getSavings() << endl;
	}

}

/*
 * Populates the accounts array list.
 */
void BankData::populateAccounts()
{
	//cout << "Populating accounts" << endl << "acc balance" << endl;
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j<3; j++)
		{
			accounts.push_back(BankAccount(100*i+j,0));
			cout << 100*i+j << " " << 0 << endl;
		}
	}
}

vector<Customer> BankData::getCustRecords()
{
	return custRecords;
}

Customer BankData::findCustomer(int accNum)
{
	for (int i = 0; i < custRecords.size(); i++)
	{
		if(custRecords[i].getCustNum()==accNum)
		{
			return custRecords[i];
		}
	}
	Customer notFound(-2, -2, -2, -2);
	return notFound;
}