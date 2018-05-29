#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

#include "account.h"
#include "bank.h"

using namespace std;

int main(int argc, char* argv[]) {
    Bank bank = Bank();
    bank.createAccount("igor");
    bank.createAccount("marcelo");
    cout << "accounts size: " << bank.getAccounts().size() << endl;

    return 0;
}
