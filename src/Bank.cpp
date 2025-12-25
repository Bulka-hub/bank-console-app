#include "Bank.h"
#include <iostream> // Для вывода ошибок (опционально)

// Реализация создания аккаунта
void Bank::createAccount(int id, std::string name, double initialBalance) {
    // emplace_back создает объект сразу в векторе — это эффективно
    accounts.emplace_back(id, name, initialBalance);
}

// Реализация поиска
Account* Bank::findAccountById(int id) {
    // Пробегаем по вектору. Важно использовать auto& (ссылку),
    // чтобы работать с оригиналом, а не копией.
    for (auto& acc : accounts) {
        if (acc.getId() == id) {
            return &acc; // Возвращаем адрес найденного аккаунта
        }
    }
    return nullptr; // Если цикл прошел и ничего не нашлось
}

// Реализация перевода
bool Bank::transferMoney(int fromId, int toId, double amount) {
    // 1. Ищем обоих участников
    Account* sender = findAccountById(fromId);
    Account* receiver = findAccountById(toId);

    // 2. Проверяем, существуют ли они
    if (sender == nullptr || receiver == nullptr) {
        std::cout << "Error: One of the accounts was not found." << std::endl;
        return false;
    }

    // 3. Нельзя переводить самому себе
    if (fromId == toId) {
        std::cout << "Error: Cannot transfer to the same account." << std::endl;
        return false;
    }

    // 4. Пытаемся снять деньги у отправителя
    // Метод withdraw (из Account) сам проверит, хватает ли баланса
    if (sender->withdraw(amount)) {
        // Если снялось успешно, зачисляем получателю
        receiver->deposit(amount);
        return true;
    }

    // Если withdraw вернул false (недостаточно средств)
    return false;
}

// Реализация геттера для списка (для Role #4 - Файлы)
const std::vector<Account>& Bank::getAccounts() const {
    return accounts;
}
