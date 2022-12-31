#pragma once
#include <iostream>
#include <string>
#include "Account.h"

class Checking_Account : public Account {
private:
    double withdraw_fee = 1.5;
public:
    Checking_Account(std::string name = "Unnamed Checking Account", double balance = 0.0);
    //Flat fee of $1.50 evey withdraw
    virtual bool withdraw(double amount) override;
    virtual bool deposit(double amount) override;
    virtual bool find_account(std::string account_name) override;
    virtual void print(std::ostream& os) const override;
    virtual ~Checking_Account() = default;
};