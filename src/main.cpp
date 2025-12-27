#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include "Bank.h"
#include "FileManager.h"

// ---------- маленькие хелперы для ввода ----------
int inputInt(const std::string& prompt) {
    int val;
    while (true) {
        std::cout << prompt;
        if (std::cin >> val) return val;
        std::cout << "Нужно целое число!\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

double inputDouble(const std::string& prompt) {
    double val;
    while (true) {
        std::cout << prompt;
        if (std::cin >> val && val >= 0) return val;
        std::cout << "Нужно положительное число!\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

std::string inputString(const std::string& prompt) {
    std::cout << prompt;
    std::string s;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, s);
    return s;
}

// ---------- сами операции ----------
void createAccount(Bank& b) {
    int id = inputInt("ID для нового аккаунта: ");
    std::string name = inputString("Имя владельца: ");
    double start = inputDouble("Начальный баланс: ");
    b.createAccount(id, name, start);
    std::cout << "✅ Аккаунт создан.\n";
}

void showBalance(const Bank& b) {
    int id = inputInt("ID аккаунта: ");
    if (auto* a = b.findAccountById(id))
        std::cout << "Баланс: " << a->getBalance() << "\n";
    else
        std::cout << "❌ Аккаунт не найден.\n";
}

void deposit(Bank& b) {
    int id = inputInt("ID аккаунта: ");
    if (auto* a = b.findAccountById(id)) {
        double sum = inputDouble("Сумма пополнения: ");
        a->deposit(sum);
        std::cout << "✅ Новый баланс: " << a->getBalance() << "\n";
    }
    else
        std::cout << "❌ Аккаунт не найден.\n";
}

void withdraw(Bank& b) {
    int id = inputInt("ID аккаунта: ");
    if (auto* a = b.findAccountById(id)) {
        double sum = inputDouble("Сумма снятия: ");
        if (a->withdraw(sum))
            std::cout << "✅ Новый баланс: " << a->getBalance() << "\n";
        else
            std::cout << "❌ Недостаточно средств.\n";
    }
    else
        std::cout << "❌ Аккаунт не найден.\n";
}

void transfer(Bank& b) {
    int from = inputInt("ID отправителя: ");
    int to = inputInt("ID получателя: ");
    double sum = inputDouble("Сумма перевода: ");
    if (b.transferMoney(from, to, sum))
        std::cout << "✅ Перевод выполнен.\n";
    else
        std::cout << "❌ Перевод не удался (проверьте ID и баланс).\n";
}

void listAll(const Bank& b) {
    const auto& accs = b.getAccounts();
    if (accs.empty()) {
        std::cout << "Список пуст.\n";
        return;
    }
    for (const auto& a : accs)
        std::cout << "ID:" << a.getId()
        << "  Имя:" << a.getName()
        << "  Баланс:" << a.getBalance() << "\n";
}

// ---------- main ----------
int main() {
    Bank bank;

    /* загрузка при старте */
    auto loaded = loadAccounts();
    for (const auto& rec : loaded)
        bank.createAccount(rec.id, rec.name, rec.balance);

    while (true) {
        std::cout << "\n--- МЕНЮ ---\n"
            << "1. Создать аккаунт\n"
            << "2. Показать баланс\n"
            << "3. Пополнить счёт\n"
            << "4. Снять деньги\n"
            << "5. Перевести деньги\n"
            << "6. Показать все аккаунты\n"
            << "0. Выход и сохранение\n"
            << "Выбор: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (choice) {
        case 1: createAccount(bank); break;
        case 2: showBalance(bank); break;
        case 3: deposit(bank); break;
        case 4: withdraw(bank); break;
        case 5: transfer(bank); break;
        case 6: listAll(bank); break;
        case 0:
            saveAccounts(bank.getAccounts());
            std::cout << "Данные сохранены. До свидания!\n";
            return 0;
        default: std::cout << "Неверный пункт.\n";
        }
    }
}