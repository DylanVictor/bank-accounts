#include <iostream>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

int main() {
    std::cout.precision(2);
    //3 vectors of accounts
    std::vector<Account*> checking_accounts;
    std::vector<Account*> savings_accounts;
    std::vector<Account*> trust_accounts;

    //Default objects
    Account* default_chk1 = new Checking_Account("Liam", 10000);
    Account* default_chk2 = new Checking_Account("Lara");
    Account* default_chk3 = new Checking_Account();
    Account* default_svg1 = new Savings_Account("Matt", 1000, 5);
    Account* default_svg2 = new Savings_Account("Marisha");
    Account* default_svg3 = new Savings_Account();
    Account* default_trs1 = new Trust_Account("Sam", 20000, 7);
    Account* default_trs2 = new Trust_Account("Travis");
    Account* default_trs3 = new Trust_Account();

    //Put default objects into the 3 vectors
    checking_accounts = { default_chk1, default_chk2, default_chk3 };
    savings_accounts = { default_svg1, default_svg2, default_svg3 };
    trust_accounts = { default_trs1, default_trs2, default_trs3 };

    //Menu
    std::cout << "==============================" << std::endl;
    std::cout << " Welcome to your online bank  ";
    int user_choice = 0;
    do {
        user_choice = print_main_menu();

        switch (user_choice) {
        case 1:
            std::cout << "\n\n\n=== Displaying an account ==========" << std::endl;
            user_choice = menu_account_type();
            display_account_type(user_choice, checking_accounts, savings_accounts, trust_accounts);
            break;
        case 2:
            std::cout << "\n\n\n=== Adding an account ==============" << std::endl;
            user_choice = menu_account_type();
            add_account_type(user_choice, checking_accounts, savings_accounts, trust_accounts);
            break;
        case 3:
            std::cout << "\n\n\n=== Deleting Account ===============" << std::endl;
            user_choice = menu_account_type();
            delete_account_type(user_choice, checking_accounts, savings_accounts, trust_accounts);
            break;
        case 4:
            std::cout << "\n\n\n=== Finding Account ================" << std::endl;
            user_choice = menu_account_type();
            find_account_type(user_choice, checking_accounts, savings_accounts, trust_accounts);
            break;
        case 5:
            std::cout << "\n\n\n=== Depositing into account ========" << std::endl;
            user_choice = menu_account_type();
            deposit_account_type(user_choice, checking_accounts, savings_accounts, trust_accounts);
            break;
        case 6:
        {
            std::cout << "\n\n\n=== Withdrawing from account =======" << std::endl;
            user_choice = menu_account_type();
            withdraw_account_type(user_choice, checking_accounts, savings_accounts, trust_accounts);
            break;
        }
        case 7:
        {
            std::cout << "\n\n\nExiting application...\n";
            break;
        default:
            std::cout << "\n\n\nInvalid input";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        }
    } while (user_choice != 7);

    delete default_chk1;
    delete default_chk2;
    delete default_svg1;
    delete default_svg2;
    delete default_trs1;
    delete default_trs2;
    return 0;
}