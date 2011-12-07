#include "BinFileBankAccount.h"

/*
* Constructs a bank account and gets the ballance
* from ObjectFileBankData.
* @param anAccountNumber the account number for this account
*/
BinFileBankAccount::BinFileBankAccount(int anAccountNumber)
{
	super(anAccountNumber);
	balance = BinFileBankData.getBalance(accountNumber);
}

/*
* Deposits money into the bank account.
* @param amount the amount to deposit
*/
void BinFileBankAccount::deposit(double amount)
{
	balance = BinFileBankData.getBalance(accountNumber) + amount;
	BinFileBankData.setBalance(accountNumber, balance);
}

/*
* Withdraws money from the bank account.
* @param amount the amount to withdraw
*/
void BinFileBankAccount::withdraw(double amount)
{
	super.withdraw(amount);
	balance = BinFileBankData.getBalance(accountNumber) - amount;
	BinFileBankData.setBalance(accountNumber, balance);
}

/*
* Gets the current balance of the bank account.
* @return the current balance
*/
double BinFileBankAccount::getBalance()
{
	return BinFileBankData.getBalance(accountNumber);
}
