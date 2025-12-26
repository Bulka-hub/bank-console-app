#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <locale>

#include "FileManager.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <locale>

#include "FileManager.h"

using namespace std;

void saveAccounts(const vector<Account>& accounts) {
    ofstream file("accounts.txt");

    if (!file.is_open()) {
        cout << "Ошибка: не удалось открыть файл для записи\n";
        return;
    }

    for (const Account& acc : accounts) {
        file << acc.id << " " << acc.name << " " << acc.balance << endl;
    }

    file.close();
}

vector<Account> loadAccounts() {
    vector<Account> accounts;
    ifstream file("accounts.txt");

    if (!file.is_open()) {
        cout << "Файл не найден. Начинаем с пустого списка.\n";
        return accounts;
    }

    Account acc;
    while (file >> acc.id >> acc.name >> acc.balance) {
        accounts.push_back(acc);
    }

    file.close();
    return accounts;
}

int main() {
    setlocale(LC_ALL, "Russian");

    vector<Account> accounts = loadAccounts();

    if (accounts.empty()) {
        accounts.push_back({ 1, "Ivan", 1000 });
        accounts.push_back({ 2, "Anna", 500 });
        cout << "Созданы тестовые аккаунты\n";
    }

    cout << "\nСписок аккаунтов:\n";
    for (const Account& acc : accounts) {
        cout << "ID: " << acc.id
            << " | Имя: " << acc.name
            << " | Баланс: " << acc.balance << endl;
    }

    saveAccounts(accounts);

    cout << "\nДанные сохранены. Выход из программы.\n";
    return 0;
}
