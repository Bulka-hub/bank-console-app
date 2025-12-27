#include "Bank.h"
#include <iostream>

void Bank::createAccount(std::string name, double initialDeposit) {
    // Генерация простого ID: последний ID + 1, или 1 если пусто
    int newId = accounts.empty() ? 1 : accounts.back().getId() + 1;
    Account newAcc(newId, name, initialDeposit);
    accounts.push_back(newAcc);
    std::cout << "Аккаунт создан успешно! Ваш ID: " << newId << std::endl;
}

Account* Bank::findAccountById(int id) {
    for (auto& acc : accounts) {
        if (acc.getId() == id) {
            return &acc;
        }
    }
    return nullptr;
}

void Bank::transferMoney(int fromId, int toId, double amount) {
    Account* sender = findAccountById(fromId);
    Account* receiver = findAccountById(toId);

    if (!sender || !receiver) {
        std::cout << "Ошибка: Один из аккаунтов не найден." << std::endl;
        return;
    }

    if (sender->withdraw(amount)) {
        receiver->deposit(amount);
        std::cout << "Перевод успешно выполнен!" << std::endl;
    }
}

void Bank::showAllAccounts() const {
    std::cout << "--- Список всех аккаунтов ---" << std::endl;
    for (const auto& acc : accounts) {
        acc.display();
    }
}

const std::vector<Account>& Bank::getAccounts() const {
    return accounts;
}

void Bank::loadAccount(int id, std::string name, double balance) {
    accounts.emplace_back(id, name, balance);
}
