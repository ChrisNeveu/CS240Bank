
#include "BankData.h"

double BankData::getBalance(int acctNum)
{
	for (vector<AccountRecord>::iterator itr = accounts.begin(); itr != accounts.end(); ++itr)
	{
		if(itr->getNumber() == acctNum)
			return itr->getBalance();
	}
	return 0;
}

void BankData::setBalance(int acctNum, double amt)
{
	for (vector<AccountRecord>::iterator itr = accounts.begin(); itr != accounts.end(); ++itr)
	{
		if(itr->getNumber() == acctNum)
			itr->setBalance(amt);
	}
}

void BankData::populateCustRecords()
{
	for(int i = 1; i< 10; i++)
	{
		custRecords.push_back(CustomerRecord(i,i*1000 + 2*i%10*100 + 3*i%10*10 + 4*i%10,100*i+1, 100*i+2));
		cout << custRecords[i-1].getCustNum()+" ";
		cout << custRecords[i-1].getPin()+" ";
		cout << custRecords[i-1].getChecking()+" ";
		cout << custRecords[i-1].getSavings();
	}
}

void BankData::populateAccounts()
{
	for(int i = 1; i < 10; i++)
		for(int j = 1; j < 3; j++)
		{
			accounts.push_back(AccountRecord(100*i+j,0));
		}
}

vector<CustomerRecord> BankData::getCustRecords()
{
	return custRecords;
}