
#include "CustomerRecord.h"

CustomerRecord::CustomerRecord(int aCustNum, int aPin, int aChecking, int aSavings)
{
	custNum = aCustNum;
	pin = aPin;
	checking = aChecking;
	savings = aSavings;
}

int CustomerRecord::getCustNum()
{
	return custNum;
}

int CustomerRecord::getPin()
{
	return pin;
}

int CustomerRecord::getChecking()
{
	return checking;
}

int CustomerRecord::getSavings()
{
	return savings;
}