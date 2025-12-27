#include <iostream>
#include "Bank.h"
#include "FileManager.h"

void showMenu() {
    std::cout << "\n=== БАНКОВСКАЯ СИСТЕМА ===" << std::endl;
    std::cout << "1. Создать аккаунт" << std::endl;
    std::cout << "2. Показать все аккаунты" << std::endl;
    std::cout << "3. Пополнить баланс" << std::endl;
    std::cout << "4. Снять деньги" << std::endl;
    std::cout << "5. Перевести деньги" << std::endl;
    std::cout << "6. Сохранить и Выйти" << std::endl;
    std::cout << "Выберите действие: ";
}

int main() {
    setlocale(LC_CTYPE, "ru");
    Bank myBank;
    FileManager fileManager("accounts.txt");

    // Загрузка данных при старте
    fileManager.loadData(myBank);

    int choice;
    do {
        showMenu();
        std::cin >> choice;

        // Очистка потока на случай ввода букв вместо цифр
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }

        switch (choice) {
        case 1: {
            std::string name;
            double amount;
            std::cout << "Введите имя (одно слово): ";
            std::cin >> name;
            std::cout << "Начальный взнос: ";
            std::cin >> amount;
            myBank.createAccount(name, amount);
            break;
        }
        case 2:
            myBank.showAllAccounts();
            break;
        case 3: {
            int id;
            double amount;
            std::cout << "Введите ID аккаунта: ";
            std::cin >> id;
            Account* acc = myBank.findAccountById(id);
            if (acc) {
                std::cout << "Сумма пополнения: ";
                std::cin >> amount;
                acc->deposit(amount);
            }
            else {
                std::cout << "Аккаунт не найден!" << std::endl;
            }
            break;
        }
        case 4: {
            int id;
            double amount;
            std::cout << "Введите ID аккаунта: ";
            std::cin >> id;
            Account* acc = myBank.findAccountById(id);
            if (acc) {
                std::cout << "Сумма снятия: ";
                std::cin >> amount;
                acc->withdraw(amount);
            }
            else {
                std::cout << "Аккаунт не найден!" << std::endl;
            }
            break;
        }
        case 5: {
            int fromId, toId;
            double amount;
            std::cout << "Откуда (ID): ";
            std::cin >> fromId;
            std::cout << "Куда (ID): ";
            std::cin >> toId;
            std::cout << "Сумма: ";
            std::cin >> amount;
            myBank.transferMoney(fromId, toId, amount);
            break;
        }
        case 6:
            fileManager.saveData(myBank);
            std::cout << "До свидания!" << std::endl;
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
        }
    } while (choice != 6);

    return 0;
}
