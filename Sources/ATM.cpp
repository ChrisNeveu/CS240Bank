#include <iostream>
#include <string>
using namespace std;
#include "ATMInterface.h"

/**
   An ATM that accesses a bank.
*/





   /**
      Constructs an ATM for a given bank.
      @param aBank the bank to which this ATM connects
   */
ATMInterface::ATMInterface()
{
	currentCustomer == null;
    theBank = aBank;
    reset();
}

   /**
      Resets the ATM to the initial state.
   */
void ATMInterface::reset()
{
   customerNumber = -1;
   currentAccount = null;
   state = START;
}

   /**
      Sets the current customer number
      and sets state to PIN.
      (Precondition: state is START)
      @param number the customer number.
   */
void ATMInterface::setCustomerNumber(int number)
{
	if(state == START){
		customerNumber = number;
		state = PIN;
	}
}

   /**
      Finds customer in bank.
      If found sets state to ACCOUNT, else to START.
      (Precondition: state is PIN)
      @param pin the PIN of the current customer
   */
void ATMInterface::selectCustomer(int pin) {
	if (state == PIN){
		currentCustomer = theBank.findCustomer(customerNumber, pin);
		if (currentCustomer == null)
			state = START;
		else
			state = ACCOUNT;
	}
}

   /**
      Sets current account to checking or savings. Sets
      state to TRANSACT.
      (Precondition: state is ACCOUNT or TRANSACT)
      @param account one of CHECKING or SAVINGS
   */
void ATMInterface::selectAccount(int account) {
	if(state == ACCOUNT || state == TRANSACT){
		if (account == CHECKING)
			currentAccount = currentCustomer.getCheckingAccount();
		else
			currentAccount = currentCustomer.getSavingsAccount();
		state = TRANSACT;
	}
}

   /**
      Withdraws amount from current account.
      (Precondition: state is TRANSACT)
      @param value the amount to withdraw
   */
void ATMInterface::withdraw(double value) {
	if(state == TRANSACT)
   		currentAccount.withdraw(value);
}

   /**
      Deposits amount to current account.
      (Precondition: state is TRANSACT)
      @param value the amount to deposit
   */
void ATMInterface::deposit(double value) {
	if(state == TRANSACT){
		currentAccount.deposit(value);
	}
}

   /**
      Gets the balance of the current account.
      (Precondition: state is TRANSACT)
      @return the balance
   */
double ATMInterface::getBalance(){
	if(state == TRANSACT)
		return currentAccount.getBalance();
}

   /**
      Moves back to the previous state.
   */
void ATMInterface::back()
{
   if (state == TRANSACT)
      state = ACCOUNT;
   else if (state == ACCOUNT)
      state = PIN;
   else if (state == PIN)
      state = START;
}

   /**
      Gets the current state of this ATM.
      @return the current state
   */
int ATMInterface::getState()
{
   return state;
}

void ATMInterface::close(){
	theBank.close();
}


