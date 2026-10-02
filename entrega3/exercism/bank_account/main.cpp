#include <iostream>
#include "bank_account.h"

int main() {
    Bankaccount::Bankaccount account;
    account.open();
    account.deposit(100);
    account.withdraw(30);
    std::cout << "Saldo actual: " << account.balance() << std::endl;
    account.close();
    return 0;
}
