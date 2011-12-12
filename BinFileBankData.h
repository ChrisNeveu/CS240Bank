
#include <iostream>
using namespace std;
#include "BankData.h"

class BinFileBankData : public BankData
{
public:
	void init();
	void close();
private:
	string bankFileName;
	string accountsFileName;
};