#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Bank.h"
#include <string>

class FileManager {
private:
    std::string filename;

public:
    FileManager(std::string filename);
    void saveData(const Bank& bank);
    void loadData(Bank& bank);
};

#endif
