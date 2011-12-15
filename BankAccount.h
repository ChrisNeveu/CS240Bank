/*
 * A bank account has a balance that can be changed by
 * deposits and withdrawals.
 */
class BankAccount
{
	public:
		BankAccount(int anAccountNumber);
		void deposit(double amount);
		void withdraw(double amount);
		double getBalance();
		void setBalance(double value);
		int getNumber();
		string toString();
	
		protected:
			int accountNumber;
			double balance;
			int checking;
			int savings;

};

