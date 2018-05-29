#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "bank.h"

using namespace std;

int fuzzMe(const u_int8_t* data, size_t size){
    string str((char*)data, size);
    int s = (int) size;
    Bank bank = Bank();
    bank.createAccount(str);
    Account* a = bank.getAccount(str);
    bank.deposit(a->getOwner(), s/10);
    bank.withdraw(a->getOwner(), s);
    assert(a->getBalance() >= 0); // ok

    Account * b = bank.getAccount(str+'a'); // accessing null object
    assert(b->getBalance()) // should raise exception

    return 0;
}


extern "C" int LLVMFuzzerTestOneInput(const u_int8_t* data, size_t size){
    if (size < 5) return 0;
    fuzzMe(data, size);
    return 0;
}
