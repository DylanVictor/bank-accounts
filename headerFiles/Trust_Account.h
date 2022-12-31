#pragma once
#include "Savings_Account.h"

class Trust_Account : public Savings_Account {
private:
    double bonus_amount = 50.0;
    double bonus_threshold = 5000.0;
    int max_withdrawals = 3;
    double max_withdraw_percent = 0.2;
protected:
    int num_withdrawals;
public:
    Trust_Account(std::string name = "Unnamed Trust Account", double balance = 0.0, double int_rate = 0.0);
    //Deposit $50 bonus when amount >= $5000
    virtual bool deposit(double amount) override;
    //Trust accounts get a max of 3 withdrawals each being a max of 20% of the account's value
    virtual bool withdraw(double amount) override;
    virtual bool find_account(std::string account_name) override;
    virtual void print(std::ostream& os) const override;
    virtual ~Trust_Account() = default;
};