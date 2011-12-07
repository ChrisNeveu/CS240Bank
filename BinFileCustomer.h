/*
 * A bank customer with a checking and savings account.
 */
class BinFileCustomer : public Customer
{
	public: 
		/*
		 * Constructs a customer with a given number and PIN.
		 * @param aCustomerNumber the customer number
		 * @param checkingAccountNumber the checking account number
		 * @param savingsAccountNumber the savings account number
		 */
		BinFileCustomer(int aCustomerNumber, int checkingAccountNumber, int savingsAccountNumber)
		{
			customerNumber = aCustomerNumber;
			checkingAccount = new BinFileBankAccount(checkingAccountNumber);
			savingsAccount = new BinFileBankAccount(savingsAccountNumber);
		}
};
