#ifndef BANK_H
#define BANK_H

#include "account.h"
#include <string>
#include <vector>

using namespace std;

class Bank {
    private:
        vector<Account> accounts;

    public:
        Bank();
        void createAccount(string const& owner);
        vector<Account> getAccounts();
        Account* getAccount(string const& owner);
        void deposit(string owner, double value);
        void withdraw(string owner, double value);
};

#endif // BANK_H

