#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <assert.h>

#include "account.h"
#include "bank.h"

using namespace std;

int main(int argc, char* argv[]) {
    Bank bank = Bank();
    bank.createAccount("igor");
    bank.createAccount("marcelo");

    assert(bank.getAccounts().size() == 2);
    Account* a = bank.getAccount("igor");
    assert(a!=NULL);
    assert(a->getBalance() == 0);
    bank.deposit("igor", 50);
    bank.deposit("igor", 50.0);
    bank.withdraw("igor", 10);
    assert(a->getBalance() == 90);
    bank.withdraw("igor", 200);
    assert(a->getBalance() == 90);
    bank.withdraw("igor", 90);
    assert(a->getBalance() == 0);

    bank.withdraw("igor", -10);
    assert(a->getBalance() == 0 && "BUG");

    return 0;
}
