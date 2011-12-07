#include "BankAccount.h"

//Constructs a bank account with a given number.
BankAccount::BankAccount(int anAccountNumber)
{
	accountNumber = anAccountNumber;
}

/*
 * Withdraws money from a bank account.
 * @param accountNumber the account number
 * @param amount the amount to withdraw
 */
void BankAccount::withdraw(double amount) throws WithdrawalException
{
	if (amount > getBalance())
	{
		throw new WithdrawalException(getBalance(),amount);
	}
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
String BankAccount::toString()
{
	return "account " + accountNumber;
}


