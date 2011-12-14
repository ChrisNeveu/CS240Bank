#ifndef ATMInterface
#define ATMInterface

/**
   An ATM that accesses a bank.
*/

const int START = 1;
const int PIN = 2;
const int ACCOUNT = 3;
const int TRANSACT = 4;
const int CHECKING = 1;
const int SAVINGS = 2;



class ATMinterface
{
public:
	ATMInterface();

   /**
      Resets the ATM to the initial state.
   */
   void reset();

   /**
      Sets the current customer number
      and sets state to PIN.
      (Precondition: state is START)
      @param number the customer number.
   */
   void setCustomerNumber(int number);

   /**
      Finds customer in bank.
      If found sets state to ACCOUNT, else to START.
      (Precondition: state is PIN)
      @param pin the PIN of the current customer
   */
   void selectCustomer(int pin);

   /**
      Sets current account to checking or savings. Sets
      state to TRANSACT.
      (Precondition: state is ACCOUNT or TRANSACT)
      @param account one of CHECKING or SAVINGS
   */
   void selectAccount(int account);

   /**
      Withdraws amount from current account.
      (Precondition: state is TRANSACT)
      @param value the amount to withdraw
   */
   void withdraw(double value);

   /**
      Deposits amount to current account.
      (Precondition: state is TRANSACT)
      @param value the amount to deposit
   */
   void deposit(double value);
   /**
      Gets the balance of the current account.
      (Precondition: state is TRANSACT)
      @return the balance
   */
   double getBalance();
   /**
      Moves back to the previous state.
   */
   void back();

   /**
      Gets the current state of this ATM.
      @return the current state
   */
   int getState();

   void close();



private:
   int state;
   int customerNumber;
   Customer currentCustomer;
   BankAccount currentAccount;
   BankInterface theBank;



}




};
#endif