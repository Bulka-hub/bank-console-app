#pragma once
#include <vector>
#include <string>

struct Account {
    int id;
    std::string name;
    double balance;
};

void saveAccounts(const std::vector<Account>& accounts);
std::vector<Account> loadAccounts();
