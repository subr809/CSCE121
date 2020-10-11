#ifndef BANK_H
#define BANK_H

#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include "Account.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"

class Bank {
public:
    void addCheckingAccount(int accountNumber, std::string name);
    void addSavingsAccount(int accountNumber, std::string name, double interestRate);
    void printAccounts();
    void printAccount(int accountNumber);
    Account* getAccount(int accountNumber);
    void makeDeposit(int accountNumber, double amount);
    void doWithdrawl(int accountNumber, double amount);
private:
    std::vector<Account*> accounts;
};


#endif
