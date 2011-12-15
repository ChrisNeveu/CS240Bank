#include "Customer.h"

Customer::Customer(int custNum, int pinNum, int checking, int savings)
{
	customerNumber = custNum;
	pin = pinNum;
	checkingAccount.setNumber(checking);
	savingsAccount.setNumber(savings);
}

/*
 * Gets the checking account of this customer.
 * @return the checkingAccount
 */
BankAccount Customer::getCheckingAccount()
{
	return checkingAccount;
}

/*
 * Gets the savings account of this customer.
 * @return the savingsAccount
 */
BankAccount Customer::getSavingsAccount()
{
	return savingsAccount;
}

/*
 * Gets the Pin Number of this customer.
 * @return the pin
 */
int Customer::getPin()
{
	return pin;
}

/*
 * Gets the Customer Number of this customer.
 * @return the custNum
 */
int Customer::getCustNum()
{
	return customerNumber;
}

int Customer::getChecking()
{
	return checkingAccount.getNumber();
}
int Customer::getSavings()
{
	return savingsAccount.getNumber();
}
