#include "BankAccount.h"
/*
 * Constructs a bank account with a given number.
 * @param anAccountNumber the account number
 */
BankAccount::BankAccount(int anAccountNumber)
{
	accountNumber = anAccountNumber;
}

/*
 * Deposits money into a bank account.
 * @param accountNumber the account number
 * @param amount the amount to deposit
 */
void BankAccount::deposit(double amount)
{
	setBalance(getBalance()+amount);
}

/*
 * Withdraws money from a bank account.
 * @param accountNumber the account number
 * @param amount the amount to withdraw
 */

void BankAccount::withdraw(double amount)
{
	if (amount > getBalance())
	{
		//Show error
	}
}

/*
 * Gets the balance of a bank account.
 * @return the account balance
 */
double BankAccount::getBalance()
{
	return balance;
}

/*
 * Sets the balance of a bank account.
 * @param value is the new balance of the bank account.
 */
void BankAccount::setBalance(double value)
{
	balance = value;
}

/*
 * Gets the account number of a bank account.
 * @return the account number
 */
int BankAccount::getNumber()
{
	return accountNumber;
}

/*
 * Makes a String representation of the account.
 * @return the String representation of the account
 */
string BankAccount::toString()
{
	return "account " + accountNumber;
}

