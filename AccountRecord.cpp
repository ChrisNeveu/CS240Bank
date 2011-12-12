
#include "AccountRecord.h"

AccountRecord::AccountRecord(int aNumber, double aBalance)
{
	number = aNumber;
	balance = aBalance;
}

void AccountRecord::setBalance(double value)
{
	balance = value;
}

int AccountRecord::getNumber()
{
	return number;
}

double AccountRecord::getBalance()
{
	return balance;
}