/*
 * A bank account has a balance that can be changed by
 * deposits and withdrawals.
 */
class BinFileBankAccount : public BankAccount
{
	public:
		//Constructs a bank account and gets the balance from ObjectFileBankData.
		BinFileBankAccount(int anAccountNumber);
		//Deposits money into the bank account.
		void deposit(double amount);
		//Withdraws money from the bank account.
		void withdraw(double amount);
		//Gets the current balance of the bank account.
		double getBalance();

	private:
		double balance;

};
