#include "Account.h"

Account::Account(std::string name, double balance)
    : name{ name }, balance{ balance } {
}

bool Account::deposit(double amount) {
    //Deposit cannot be negative
    if (amount < 0)
        return false;
    else {
        balance += amount;
        return true;
    }
}

bool Account::withdraw(double amount) {
    //Total balance cannot go into negative
    if (balance - amount >= 0) {
        balance -= amount;
        return true;
    }
    else
        return false;
}

bool Account::find_account(std::string account_name) {
    //Format account_name
    account_name[0] = toupper(account_name[0]);
    for (int i = 1; i < account_name.size(); i++)
        account_name[i] = tolower(account_name[i]);

    if (name == account_name) {
        return true;
    }
    else
        return false;
}

void Account::print(std::ostream& os) const {
    //Formatting
    os.precision(2);
    os << std::fixed;

    os << "[Account: " << name << ": " << balance << "]";
}