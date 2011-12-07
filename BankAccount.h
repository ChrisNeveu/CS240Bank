/*
 * A bank account has a balance that can be changed by
 * deposits and withdrawals.
 */
class BankAccount
{
	public:
		//Constructs a bank account with a given number.
		BankAccount(int anAccountNumber);
		//Deposits money into a bank account.
		virtual void deposit(double amount);
		//Withdraws money from a bank account.
		void withdraw(double amount);
		//Gets the balance of a bank account.
		virtual double getBalance();
		//Gets the account number of a bank account.
		int getNumber();
		//Makes a String representation of the account.
		String toString();

	protected:
		int accountNumber;
};

