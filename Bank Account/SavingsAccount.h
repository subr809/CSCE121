#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include <string>
#include <iostream>
#include <stdexcept>
#include "Account.h"

class SavingsAccount : public Account {
public:
    SavingsAccount(int accountNumber = 0, std::string name = "", double interestRate = 0.0);
    // FIXME (2 b) uncomment following line
    std::string getTypeName();
    void printDetails();
    void processInterest();
private:
    double interestRate;
};

#endif
