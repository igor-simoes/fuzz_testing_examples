#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <stdint.h>
#include <stddef.h>
#include <string>
#include <assert.h>

#include "bank.h"

using namespace std;

void bugNullObject(Bank bank, string str)
{
    // accessing null object
    Account * b = bank.getAccount(str+str);
    b->getBalance(); // bug appears
}

void bugWithdrawNegativeValue(Bank bank, string str, double negativeValue)
{
    double balance = bank.getAccount(str)->getBalance();
    bank.withdraw(str, negativeValue);
    double newBalance = bank.getAccount(str)->getBalance();
    if(balance != newBalance) // bug appears
    {
        fprintf(stderr,"#####\n>>> BUG: should not exec withdraw with negative value. Balance expected: %f, got %f\n#####\n", balance, newBalance);
        abort();
    }
}

bool fuzzMe(const u_int8_t* data, size_t size)
{
    string str((char*)data, size); // converting data to string
    double value = (double) size; // converting size_t to double

    int random = rand() % 20 - 10; // random an Integer btw -10 and 10
    double negativeValue = -1 * value;

    Bank bank = Bank();
    bank.createAccount(str);
    Account* account = bank.getAccount(str);
    assert(account->getOwner() == str);

    // can deposit any positive value
    bank.deposit(account->getOwner(), value);
    assert(account->getBalance() == value);

    // cannot deposit negative value
    bank.deposit(account->getOwner(), negativeValue);
    assert(account->getBalance() == value);

    // can withdraw if value > 0 && value <= account.balance
    bank.withdraw(account->getOwner(), value-1);
    assert(account->getBalance() == 1);

//    bugNullObject(bank,str);
//    bugWithdrawNegativeValue(bank, str, negativeValue);

    return 0;
}


extern "C" int LLVMFuzzerTestOneInput(const u_int8_t* data, size_t size){
    if (size < 2) return 0;
    fuzzMe(data, size);
    return 0;
}
