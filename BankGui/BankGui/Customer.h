#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "BankAccount.h"

/*
 * A bank customer with a checking and savings account.
 */
class Customer
{
	public:
		BankAccount getCheckingAccount();
		BankAccount getSavingsAccount();
	protected:
		int customerNumber;
		int pin;
		BankAccount checkingAccount;
		BankAccount savingsAccount;
};

#endif
