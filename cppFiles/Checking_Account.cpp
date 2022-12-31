#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance)
    : Account{ name, balance } {
}

bool Checking_Account::withdraw(double amount) {
    //Add withdraw fee of $1.50 to amount
    amount += withdraw_fee;
    return Account::withdraw(amount);
}

bool Checking_Account::deposit(double amount) {
    return Account::deposit(amount);
}

bool Checking_Account::find_account(std::string account_name) {
    return Account::find_account(account_name);
}

void Checking_Account::print(std::ostream& os) const {
    os.precision(2);
    os << std::fixed;
    os << "[Checking_Account: " << name << ": " << balance << "]";
}