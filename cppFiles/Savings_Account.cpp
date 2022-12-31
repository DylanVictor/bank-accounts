#include "../headerFiles/Savings_Account.h"

Savings_Account::Savings_Account(std::string name, double balance, double int_rate)
    : Account{ name, balance }, int_rate{ int_rate } {
}

bool Savings_Account::deposit(double amount) {
    //Convert int_rate to percent and put it on amount
    amount += amount * (int_rate / 100);
    return Account::deposit(amount);
}

bool Savings_Account::withdraw(double amount) {
    return Account::withdraw(amount);
}

bool Savings_Account::find_account(std::string account_name) {
    return Account::find_account(account_name);
}

void Savings_Account::print(std::ostream& os) const {
    os.precision(2);
    os << std::fixed;
    os << "[Savings_Account: " << name << ": " << balance << ", " << int_rate << "]";
}
