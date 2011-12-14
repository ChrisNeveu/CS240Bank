#ifndef ATMViewer
#define ATMViewer


class ATMViewer
{
public:

   void main(String[] args);
   ATMViewer();


private:
	ATMInterface theATM;
	BankInterface theBank;

}
#endif