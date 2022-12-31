#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Savings_Account{ name, balance, int_rate }, num_withdrawals{ 0 } {

}

//Deposit $50 bonus when amount >= $5000
bool Trust_Account::deposit(double amount) {
    if (amount >= bonus_threshold)
        amount += bonus_amount;
    return Savings_Account::deposit(amount);
}

//Trust accounts get a max of 3 withdrawals each being a max of 20% of the account's value
bool Trust_Account::withdraw(double amount) {
    if (num_withdrawals >= max_withdrawals || (amount > balance * max_withdraw_percent))
        return false;
    else {
        ++num_withdrawals;
        return Savings_Account::withdraw(amount);
    }
}

bool Trust_Account::find_account(std::string account_name) {
    return Account::find_account(account_name);
};

void Trust_Account::print(std::ostream& os) const {
    os.precision(2);
    os << std::fixed;
    os << "[Trust Account: " << name << ": " << balance << ", " << int_rate
       << "%, withdrawals: " << num_withdrawals << "]";
}