#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<string>
using namespace std;

class Account {
    private:
        string owner;
        double balance;
    public:
        Account(string const& owner);
        void setOwner();
        string getOwner();
        double getBalance();
        void setBalance(double value);
};

#endif // ACCOUNT_H
