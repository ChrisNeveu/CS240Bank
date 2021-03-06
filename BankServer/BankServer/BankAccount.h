//#ifndef BANKACCOUNT_H
//#define BANKACCOUNT_H

#include <string>
#include <sstream>
//#include "Customer.h"

using namespace std;

/*
 * A bank account has a balance that can be changed by
 * deposits and withdrawals.
 */
class BankAccount
{
	public:
		BankAccount(){};
		BankAccount(int anAccountNumber);
		BankAccount(int anAccountNumber, double initbalance);
		void deposit(double amount);
		void withdraw(double amount);
		double getBalance();
		void setBalance(double value);
		void setNumber(int accNum);
		int getNumber();
		string toString();

		protected:
			int accountNumber;
			double balance;
			int checking;
			int savings;

};

//#endif
