#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "BankAccount.h"

/*
 * A bank customer with a checking and savings account.
 */
class Customer
{
	public:
		Customer(int custNum, int pin, int checking, int savings);
		BankAccount getCheckingAccount();
		BankAccount getSavingsAccount();
		int getCustNum();
		int getPin();
		int getChecking();
		int getSavings();
	protected:
		int customerNumber;
		int pin;
		BankAccount checkingAccount;
		BankAccount savingsAccount;
};

#endif