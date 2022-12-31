#include <iostream>
#include "../headerFiles/Account_Util.h"

//Utility helper functions called from menu functions
void display(const std::vector<Account*>& accounts) {
    std::cout << "\n=== Accounts ===========================================" << std::endl;
    for (const auto acc : accounts)
        std::cout << *acc << std::endl;
}

void find_account(std::vector<Account*>& accounts, std::string account_name) {
    bool found = false;
    std::cout << "\n=== Finding Account =================================" << std::endl;
    //Search for name
    for (auto acc : accounts) {
        if (acc->find_account(account_name)) {
            found = true;
            std::cout << "Account found: " << *acc << std::endl;
        }
    }
    if (found == false)
        std::cout << "No account found with that name." << std::endl;
}

void delete_account(std::vector<Account*>& accounts, std::string account_name) {
    bool found = false;
    std::cout << "\n=== Deleting Accounts =================================" << std::endl;
    //Search for name
    for (unsigned int i = 0; i < accounts.size(); i++) {
        if (accounts.at(i)->find_account(account_name)) {
            found = true;
            accounts.erase(std::remove(accounts.begin(), accounts.end(), accounts.at(i)), accounts.end());
            std::cout << "Deleted account " << account_name << std::endl;
        }
    }
    if (found == false)
        std::cout << "No account found with that name." << std::endl;
}

void deposit(std::vector<Account*>& accounts, std::string account_name, double amount) {
    bool found = false;
    int index = 0;
    std::cout << "\n=== Depositing =================================" << std::endl;
    //Search for name
    for (unsigned int i = 0; i < accounts.size(); i++) {
        if (accounts.at(i)->find_account(account_name)) {
            found = true;
            index = i;
            std::cout << "Account found: " << *accounts.at(i) << std::endl;
        }
    }
    //Name found, attempt to deposit
    if (found == true) {
        if (accounts.at(index)->deposit(amount)) {
            std::cout << "Deposited " << amount << " to " << *accounts.at(index) << std::endl;
        }
        else {
            std::cout << "Failed Deposit of " << amount << " to " << *accounts.at(index) << std::endl;
        }
    }
    //Name not found
    else {
        std::cout << "No account found with that name." << std::endl;
    }
}

void withdraw(std::vector<Account*>& accounts, std::string account_name, double amount) {
    bool found = false;
    int index = 0;
    std::cout << "\n=== Withdrawing =================================" << std::endl;
    //Search for name
    for (unsigned int i = 0; i < accounts.size(); i++) {
        if (accounts.at(i)->find_account(account_name)) {
            found = true;
            index = i;
            std::cout << "Account found: " << *accounts.at(i) << std::endl;
        }
    }
    //Name found, attempt to withdraw
    if (found == true) {
        if (accounts.at(index)->withdraw(amount)) {
            std::cout << "Withdrew " << amount << " from " << *accounts.at(index) << std::endl;
        }
        else {
            std::cout << "Failed withdrawl of " << amount << " to " << *accounts.at(index) << std::endl;
        }
    }
    //Name not found
    else {
        std::cout << "No account found with that name." << std::endl;
    }
}

// Menu functions
int print_main_menu() {
    std::cout << "\n==============================" << std::endl;
    std::cout << "    Please select an option   " << std::endl;
    std::cout << "==============================" << std::endl;
    std::cout << "(1) Display accounts" << std::endl;
    std::cout << "(2) Add account" << std::endl;
    std::cout << "(3) Delete account" << std::endl;
    std::cout << "(4) Find Account" << std::endl;
    std::cout << "(5) Deposit" << std::endl;
    std::cout << "(6) Withdraw" << std::endl;
    std::cout << "(7) Exit" << std::endl;
    int user_choice = 0;
    std::cin >> user_choice;

    return user_choice;
}

int menu_account_type() {
    std::cout << "====================================" << std::endl;
    std::cout << "   Please select an account type" << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "(1) Checking Account" << std::endl;
    std::cout << "(2) Savings Account" << std::endl;
    std::cout << "(3) Trust Account" << std::endl;
    int user_choice = 0;
    std::cin >> user_choice;

    return user_choice;
}

void display_account_type(int user_choice, std::vector<Account*>& checking_accounts, std::vector<Account*>& savings_accounts, std::vector<Account*>& trust_accounts) {
    switch (user_choice) {
    case 1:
        display(checking_accounts);
        break;
    case 2:
        display(savings_accounts);
        break;
    case 3:
        display(trust_accounts);
        break;
    default:
        std::cout << "Invalid input." << std::endl;
    }
}

void add_account_type(int user_choice, std::vector<Account*>& checking_accounts, std::vector<Account*>& savings_accounts, std::vector<Account*>& trust_accounts) {
    std::string account_name = "";
    switch (user_choice) {
    case 1:
    {
        std::cout << "===== Adding Checking Account =====" << std::endl;
        //Get account name
        bool unique = false;
        do {
            account_name = get_account_name();
            account_name[0] = toupper(account_name[0]);
            for (int i = 1; i < account_name.size(); i++)
                account_name[i] = tolower(account_name[i]);

            unique = check_for_unique_name(checking_accounts, account_name);
            if (unique == false) {
                std::cout << "Name in each checking account must be unique." << std::endl;
            }
        } while (unique == false);

        //Get account balance
        double balance = 0.0;
        bool valid_balance = false;
        do {
            std::cout << "Balance: ";
            if (std::cin >> balance) {
                valid_balance = true;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else {
                std::cout << "Invalid input for balance. " << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (valid_balance == false);

        //Add account object to vector
        Account* chk = new Checking_Account{ account_name , balance };
        checking_accounts.push_back(chk);
        std::cout << "Account added." << std::endl;
    }
    break;
    case 2:
    {
        std::cout << "===== Adding Savings Account =====" << std::endl;
        //Get account name
        bool unique = false;
        do {
            account_name = get_account_name();
            account_name[0] = toupper(account_name[0]);
            for (int i = 1; i < account_name.size(); i++)
                account_name[i] = tolower(account_name[i]);

            unique = check_for_unique_name(savings_accounts, account_name);
            if (unique == false) {
                std::cout << "Name in each savings account must be unique." << std::endl;
            }
        } while (unique == false);

        //Get account balance
        double balance = 0.0;
        bool valid_balance = false;
        do {
            std::cout << "Balance: ";
            if (std::cin >> balance) {
                valid_balance = true;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else {
                std::cout << "Invalid input for balance. " << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (valid_balance == false);

        //Get account interest rate
        double int_rate = 0.0;
        bool valid_int_rate = false;
        do {
            std::cout << "Interest rate: ";
            if (std::cin >> int_rate) {
                valid_int_rate = true;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else {
                std::cout << "Invalid input for interest rate. " << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (valid_int_rate == false);

        //Add account object to vector
        Account* svg = new Savings_Account{ account_name , balance , int_rate };
        savings_accounts.push_back(svg);
        std::cout << "Account added." << std::endl;
    }
    break;
    case 3:
    {
        std::cout << "===== Adding Trust Account =====" << std::endl;
        bool unique = false;
        do {
            account_name = get_account_name();
            account_name[0] = toupper(account_name[0]);
            for (int i = 1; i < account_name.size(); i++)
                account_name[i] = tolower(account_name[i]);

            unique = check_for_unique_name(trust_accounts, account_name);
            if (unique == false) {
                std::cout << "Name in each trust account must be unique." << std::endl;
            }
        } while (unique == false);

        //Get account balance
        double balance = 0.0;
        bool valid_balance = false;
        do {
            std::cout << "Balance: ";
            if (std::cin >> balance) {
                valid_balance = true;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else {
                std::cout << "Invalid input for balance. " << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (valid_balance == false);

        //Get account interest rate
        double int_rate = 0.0;
        bool valid_int_rate = false;
        do {
            std::cout << "Interest rate: ";
            if (std::cin >> int_rate) {
                valid_int_rate = true;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else {
                std::cout << "Invalid input for interest rate. " << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (valid_int_rate == false);

        //Add account object to vector
        Account* trs = new Trust_Account{ account_name , balance , int_rate };
        trust_accounts.push_back(trs);
        std::cout << "Account added." << std::endl;
    }
    break;
    default:
        std::cout << "Invalid input.";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void delete_account_type(int user_choice, std::vector<Account*>& checking_accounts, std::vector<Account*>& savings_accounts, std::vector<Account*>& trust_accounts) {
    std::string account_name = "";
    switch (user_choice) {
    case 1:
        account_name = get_account_name();
        delete_account(checking_accounts, account_name);
        break;
    case 2:
        account_name = get_account_name();
        delete_account(savings_accounts, account_name);
        break;
    case 3:
        account_name = get_account_name();
        delete_account(trust_accounts, account_name);
        break;
    default:
        std::cout << "Error in delete_account_type" << std::endl;
    }
}

void find_account_type(int user_choice, std::vector<Account*>& checking_accounts, std::vector<Account*>& savings_accounts, std::vector<Account*>& trust_accounts) {
    std::string account_name = "";
    switch (user_choice) {
    case 1:
        account_name = get_account_name();
        find_account(checking_accounts, account_name);
        break;
    case 2:
        account_name = get_account_name();
        find_account(savings_accounts, account_name);
        break;
    case 3:
        account_name = get_account_name();
        find_account(trust_accounts, account_name);
        break;
    default:
        std::cout << "Invalid input." << std::endl;
    }
}

void deposit_account_type(int user_choice, std::vector<Account*>& checking_accounts, std::vector<Account*>& savings_accounts, std::vector<Account*>& trust_accounts) {
    std::string account_name = "";
    double amount = 0.0;
    switch (user_choice) {
    case 1:
        account_name = get_account_name();
        std::cout << "Deposit amount: ";
        std::cin >> amount;
        deposit(checking_accounts, account_name, amount);
        break;
    case 2:
        account_name = get_account_name();
        std::cout << "Deposit amount: ";
        std::cin >> amount;
        deposit(savings_accounts, account_name, amount);
        break;
    case 3:
        account_name = get_account_name();
        std::cout << "Deposit amount: ";
        std::cin >> amount;
        deposit(trust_accounts, account_name, amount);
        break;
    default:
        std::cout << "Invalid input." << std::endl;
    }
}

void withdraw_account_type(int user_choice, std::vector<Account*>& checking_accounts, std::vector<Account*>& savings_accounts, std::vector<Account*>& trust_accounts) {
    std::string account_name = "";
    double amount = 0.0;
    switch (user_choice) {
    case 1:
        account_name = get_account_name();
        std::cout << "Withdraw amount: ";
        std::cin >> amount;
        withdraw(checking_accounts, account_name, amount);
        break;
    case 2:
        account_name = get_account_name();
        std::cout << "Withdraw amount: ";
        std::cin >> amount;
        withdraw(savings_accounts, account_name, amount);
        break;
    case 3:
        account_name = get_account_name();
        std::cout << "Withdraw amount: ";
        std::cin >> amount;
        withdraw(trust_accounts, account_name, amount);
        break;
    default:
        std::cout << "Invalid input." << std::endl;
    }
}

std::string get_account_name() {
    std::string account_name;
    std::cout << "Account name: ";
    std::cin >> account_name;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return account_name;
}

bool check_for_unique_name(std::vector<Account*>& accounts, std::string account_name) {
    bool found = false;

    for (auto acc : accounts) {
        if (acc->find_account(account_name)) {
            found = true;
        }
    }
    if (found == false)
        return true;
    else
        return false;
}

