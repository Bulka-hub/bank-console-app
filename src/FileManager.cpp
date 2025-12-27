#include "FileManager.h"
#include <fstream>
#include <iostream>

FileManager::FileManager(std::string filename) : filename(filename) {}

void FileManager::saveData(const Bank& bank) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& acc : bank.getAccounts()) {
            file << acc.getId() << " " << acc.getName() << " " << acc.getBalance() << std::endl;
        }
        file.close();
        std::cout << "Данные успешно сохранены в " << filename << std::endl;
    }
    else {
        std::cout << "Ошибка открытия файла для записи!" << std::endl;
    }
}

void FileManager::loadData(Bank& bank) {
    std::ifstream file(filename);
    if (file.is_open()) {
        int id;
        std::string name;
        double balance;

        while (file >> id >> name >> balance) {
            bank.loadAccount(id, name, balance);
        }
        file.close();
        std::cout << "Данные загружены из " << filename << std::endl;
    }
    else {
        std::cout << "Файл сохранения не найден. Будет создан новый при выходе." << std::endl;
    }
}
