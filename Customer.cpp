#include "Customer.h"

//Gets the checking account of this customer.
BankAccount Customer::getCheckingAccount()
{
	return checkingAccount;
}

//Gets the savings account of this customer.
BankAccount Customer::getSavingsAccount()
{
	return savingsAccount;
}