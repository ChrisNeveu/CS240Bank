/**
   This is the interface for all Bank classes.
*/
class BankInterface {

	public:
        virtual ~BankInterface() {}
        virtual Customer findCustomer(int customerNumber, int pin);
        virtual void close();

};
