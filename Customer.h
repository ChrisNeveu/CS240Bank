/*
 * A bank customer with a checking and savings account.
 */
class Customer
{
	public: 
		//Gets the checking account of this customer.
		BankAccount getCheckingAccount();
		//Gets the savings account of this customer.
		BankAccount getSavingsAccount();

	protected: 
		int customerNumber;
		BankAccount checkingAccount;
		BankAccount savingsAccount;
};