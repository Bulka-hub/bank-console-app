#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <iostream>

class Account {
private:
    int id;
    std::string name;
    double balance;

public:
    // Конструктор
    Account(int id, std::string name, double balance);

    // Геттеры
    int getId() const;
    std::string getName() const;
    double getBalance() const;

    // Операции
    void deposit(double amount);
    bool withdraw(double amount);
    void display() const;
};

#endif
