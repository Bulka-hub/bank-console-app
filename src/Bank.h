#pragma once
#include <vector>
#include <string>
#include "Account.h"

class Bank {
private:
    // Хранилище всех аккаунтов. Приватное, чтобы защитить данные.
    std::vector<Account> accounts;

public:
    // Метод создания нового аккаунта
    void createAccount(int id, std::string name, double initialBalance);

    // Метод поиска аккаунта по ID.
    // Возвращает указатель (Account*), чтобы мы могли менять найденный объект.
    // Если не найден — вернет nullptr.
    Account* findAccountById(int id);

    // Перевод денег между счетами
    bool transferMoney(int fromId, int toId, double amount);

    // Вспомогательный метод: получить весь список (понадобится для сохранения в файл)
    // const и & означают, что мы даем посмотреть, но не копируем и не даем менять список
    const std::vector<Account>& getAccounts() const;
};
