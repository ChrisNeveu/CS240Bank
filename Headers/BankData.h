#include <iostream>
#include <vector>
#include "AccountRecord.h"
#include "CustomerRecord.h"
using namespace std;

class BankData
{
public:
	static void init();
	static void close();
	static double getBalance(int accNum);
	static void setBalance(int accNum, double amount);
	static void populateCustRecords();
	static void populateAccounts();
	static vector<CustomerRecord> getCustRecords();
protected:
	static vector<AccountRecord> accounts;
	static vector<CustomerRecord> custRecords;
};