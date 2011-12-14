#include "Headers/BinFileBankData.h
#include <vector>

/*
 * A bank contains a collection of customer records
 * and a collection of bank accounts.
 */
class BinFileBank : public BankInterface
{
    public:
       /*
        * Constructs a bank and populates the customer
        * records and the accounts.
        */
        BinFileBank();
       /*
        * Finds a customer with a given number and
        * validates his pin.
        * @param custNum the customer number to find
        * @param pin the pin customer entered at the ATM
        * @return a Customer object with the given customer
        * number, or null if there is no account with the
        * given number and pin
        */
        Customer findCustomer(int custNum, int pin);
        void close()

    private:
        vector<CustomerRecord> custRecords;
        String bankFileName;
        String accountsFileName;
}
