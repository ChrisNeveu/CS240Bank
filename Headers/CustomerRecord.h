
#include <iostream>
using namespace std;

class CustomerRecord
{
public:
	CustomerRecord(int aCustNum, int aPin, int aChecking, int aSavings);
	int getCustNum();
	int getPin();
	int getChecking();
	int getSavings();
private:
	int custNum;
	int pin;
	int checking;
	int savings;
};