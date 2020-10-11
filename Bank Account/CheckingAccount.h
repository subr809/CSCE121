#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include <string>
#include <iostream>
#include <stdexcept>
#include "Account.h"

class CheckingAccount : public Account {
public:
    CheckingAccount(int accountNumber = 0, std::string name = "");
    // FIXME (2 b) uncomment following line
    std::string getTypeName();
};


#endif
