#pragma once
#include <vector>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"


// Utility helper functions called from menu functions
void display(const std::vector<Account*>& accounts);
void find_account(std::vector<Account*>& accounts, std::string account_name);
void delete_account(std::vector<Account*>& accounts, std::string account_name);
void deposit(std::vector<Account*>& accounts, std::string account_name, double amount);
void withdraw(std::vector<Account*>& accounts, std::string account_name, double amount);

// Menu functions
int print_main_menu();
int menu_account_type();
void display_account_type(int, std::vector<Account*>&, std::vector<Account*>&, std::vector<Account*>&);
void add_account_type(int, std::vector<Account*>&, std::vector<Account*>&, std::vector<Account*>&);
void delete_account_type(int, std::vector<Account*>&, std::vector<Account*>&, std::vector<Account*>&);
void find_account_type(int, std::vector<Account*>&, std::vector<Account*>&, std::vector<Account*>&);
void deposit_account_type(int, std::vector<Account*>&, std::vector<Account*>&, std::vector<Account*>&);
void withdraw_account_type(int, std::vector<Account*>&, std::vector<Account*>&, std::vector<Account*>&);
std::string get_account_name();
bool check_for_unique_name(std::vector<Account*>& accounts, std::string account_name);