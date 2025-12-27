#include "Account.h"

Account::Account(int id, std::string name, double balance)
    : id(id), name(name), balance(balance) {
}

int Account::getId() const { return id; }
std::string Account::getName() const { return name; }
double Account::getBalance() const { return balance; }

void Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        std::cout << "Баланс пополнен. Новый баланс: " << balance << std::endl;
    }
    else {
        std::cout << "Сумма должна быть положительной!" << std::endl;
    }
}

bool Account::withdraw(double amount) {
    if (amount > 0 && balance >= amount) {
        balance -= amount;
        std::cout << "Деньги сняты. Новый баланс: " << balance << std::endl;
        return true;
    }
    else {
        std::cout << "Недостаточно средств или неверная сумма!" << std::endl;
        return false;
    }
}

void Account::display() const {
    std::cout << "ID: " << id << " | Имя: " << name << " | Баланс: " << balance << std::endl;
}
