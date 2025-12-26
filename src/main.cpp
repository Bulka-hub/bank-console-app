#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Bank.h"
#include "UI.h"

using namespace std;

void saveAccountsToFile(const Bank& bank) {
    ofstream file("accounts.txt");
    if (!file.is_open()) {
        cout << "Предупреждение: не удалось сохранить данные.\n";
        return;
    }

    const auto& accounts = bank.getAccounts();
    for (const auto& acc : accounts) {
        file << acc.getId() << " " << acc.getName() << " " << acc.getBalance() << "\n";
    }
    file.close();
}

void loadAccountsFromFile(Bank& bank) {
    ifstream file("accounts.txt");
    if (!file.is_open()) {
        cout << "Файл accounts.txt не найден. Создаём новый.\n";
        return;
    }

    int id;
    string name;
    double balance;

    while (file >> id >> name >> balance) {
        bank.createAccount(id, name, balance);
    }
    file.close();
}

int main() {
    setlocale(LC_ALL, "Russian");

    Bank bank;
    loadAccountsFromFile(bank);

    ConsoleUI ui(bank);
    ui.showMainMenu();

    saveAccountsToFile(bank);
    cout << "Данные сохранены. До свидания!\n";

    return 0;
}
