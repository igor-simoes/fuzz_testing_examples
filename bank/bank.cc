#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <stdexcept>

#include "account.h"
#include "bank.h"

using namespace std;

Account::Account(string const& _owner): owner(_owner), balance(0){ }
string Account::getOwner(){ return this->owner;}
void Account::setBalance(double value){this->balance = value;}
double Account::getBalance(){return this->balance;}

Bank::Bank(){}

vector<Account> Bank::getAccounts(){return this->accounts;}

Account* Bank::getAccount(string const& owner)
{
    for(size_t i=0; i < this->accounts.size(); ++i)
      if (this->accounts[i].getOwner() == owner)
          return &this->accounts[i];
    return NULL;
}

void Bank::createAccount(string const& owner)
{
    if (this->getAccount(owner)) return;

    Account newAccount(owner);
    this->accounts.push_back(newAccount);
}

void Bank::deposit(string owner, double value){
    Account* account = this->getAccount(owner);

    // intentional bug. deposit on NULL object
    if (value > 0)
        account->setBalance(account->getBalance() + value);
}

void Bank::withdraw(string owner, double value){
    Account* account = this->getAccount(owner);

    if (!(account)) return;

    // bug will raise if (value > account.balance || value < 0)
    if (account->getBalance() > 0)
    {
        account->setBalance(account->getBalance() - value);
    }

    if (account->getBalance() < 0)
    {
        fprintf(stderr, "intentional bug: balance < 0\n");
        abort();
    }
}


