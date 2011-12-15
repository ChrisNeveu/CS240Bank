#include <vector>
#include "Customer.h"

/*
* A bank contains a collection of customer records
* and a collection of bank accounts.
*/
class BankData
{
	public:
		void init();
		void close();
		double getBalance(int accNum);
		void setBalance(int accNum, double amount);
		void populateCustRecords();
		void populateAccounts();
		vector<Customer> getCustRecords();
	protected:
		vector<BankAccount> accounts;
		vector<Customer> custRecords;
		String bankFileName;
		String accountsFileName;
};
