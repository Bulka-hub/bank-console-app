#include <iostream>
#include "Bank.h"
using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");
    int choice;
    do {
        std::cout << "\n=== Banking Application ===\n";
        std::cout << "1. Create Account\n";
        std::cout << "2. View Balance\n";
        std::cout << "3. Deposit Money\n";
        std::cout << "4. Withdraw Money\n";
        std::cout << "5. Transfer Money\n";
        std::cout << "6. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::cout << "Creating a new account...\n";
            break;
        }
        case 2: {
            std::cout << "Viewing account balance...\n";
            break;
        }
        case 3: {
            std::cout << "Depositing money...\n";
            break;
        }
        case 4: {
            std::cout << "Withdrawing money...\n";
            break;
        }
        case 5: {
            std::cout << "Transferring money...\n";
            break;
        }
        case 6: {
            std::cout << "Thank you for using our banking app!\n";
            break;
        }
        default:
            std::cout << "Invalid option. Please try again.\n";
        }

    } while (choice != 6);

    std::cout << "Press Enter to exit...";
    std::cin.ignore();
    std::cin.get();
    return 0;
}
