#include "Customer.h"

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
	return custNum;
}
