#include "Headers/BinFileBank.h"

BinFileBank::BinFileBank()
{
    BinFileBankData.init();
    custRecords = BinFileBankData.getCustRecords();
}

Customer BinFileBank::findCustomer(int custNum, int pin)
{
    for(int i = 0; i < custRecords.size(); i++)//CustomerRecord record: custRecords
    {
        if (custRecords[i].getCustNum() == custNum) // found a match
        {
            if (custRecords[i].getPin() == pin) // authenticated
            {
                return new BinFileCustomer(custNum, custRecords[i].getChecking(),custRecords[i].getSavings());
            }
        }
    }
    return null; // No match in the entire array list
}

void BinFileBank::close()
{
   BinFileBankData.close();
}
