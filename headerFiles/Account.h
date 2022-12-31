#pragma once
#include <iostream>
#include <string>
#include "I_Printable.h"

//Abstract class
class Account : public I_Printable {
private:
    //static constexpr const char* def_name = "Unnamed Account";
    //static constexpr double def_balance = 0.0;
protected:
    std::string name;
    double balance;
public:
    Account(std::string name = "Unnamed Account", double balance = 0.0);
    virtual bool deposit(double amount) = 0;
    virtual bool withdraw(double amount) = 0;
    virtual bool find_account(std::string account_name) = 0;
    virtual void print(std::ostream& os) const override;
    virtual ~Account() = default;
};