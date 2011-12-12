#include <iostream>
using namespace std;

class AccountRecord
{
public:
	AccountRecord(int aNumber, double aBalance);
	void setBalance(double value);
	int getNumber();
	double getBalance();
private:
	int number;
	double balance;
	int checking;
	int savings;
};