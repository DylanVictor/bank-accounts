#pragma once
#include "Account.h"

class Savings_Account : public Account {
private:
protected:
    double int_rate;
public:
    Savings_Account(std::string name = "Unnamed Savings Account", double balance = 0.0, double int_rate = 0.0);
    //int_rate percent is added to each deposit amount
    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;
    virtual bool find_account(std::string account_name) override;
    virtual void print(std::ostream& os) const override;
    virtual ~Savings_Account() = default;
};
