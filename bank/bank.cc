#include<iostream>
#include<stdlib.h>
#include<stdio.h>

#include "account.h"
#include "bank.h"
#include<string>
#include<vector>

using namespace std;

Account::Account(string const& _owner): owner(_owner), balance(0){ }
string Account::getOwner(){ return this->owner;}
void Account::setBalance(double value){this->balance = value;}
double Account::getBalance(){return this->balance;}

Bank::Bank(){}

vector<Account> Bank::getAccounts(){return this->accounts;}

Account* Bank::getAccount(string const& owner){
    for(size_t i=0; i < this->accounts.size(); ++i)
      if (this->accounts[i].getOwner() == owner)
          return &this->accounts[i];
    return NULL;
}

void Bank::createAccount(string const& owner)
{
    if (!(this->getAccount(owner)))
        return;

    Account newAccount(owner);
    cout<< "account: " << &newAccount<<endl;
    this->accounts.push_back(newAccount);
}

void Bank::deposit(string owner, double value){
    Account* account = this->getAccount(owner);
    if (account)
        account->setBalance(account->getBalance() + value);
}

void Bank::withdraw(string owner, double value){
    Account* account = this->getAccount(owner);
    if (account && account->getBalance() >= value)
        account->setBalance(account->getBalance() - value);
}


