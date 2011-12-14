#include <iostream>
#include <string>
using namespace std;
#include "ATMViewer.h"


ATMViewer::ATMViewer()
{
	BankInterface theBank = new BinFileBank();
	ATMInterface theATM = new ATMInterface(theBank);

}

void ATMViewer::main(String[] args);
{
   BankInterface theBank = new BinFileBank();
   ATMInterface theATM = new ATMInterface(theBank);
   ATMFrame(theATM);
}