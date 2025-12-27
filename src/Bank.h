#ifndef BANK_H
#define BANK_H

#include <vector>
#include "Account.h"

class Bank {
private:
    std::vector<Account> accounts;

public:
    void createAccount(std::string name, double initialDeposit);
    Account* findAccountById(int id);
    void transferMoney(int fromId, int toId, double amount);
    void showAllAccounts() const;

    // Для работы с файлами
    const std::vector<Account>& getAccounts() const;
    void loadAccount(int id, std::string name, double balance);
};

#endif
