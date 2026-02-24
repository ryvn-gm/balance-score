#include <balance_score/health.h>
#include <iostream>
#include <string>

int main() {
    std::cout << "balance-score SDK v" << balance_score::version() << "\n";
    std::cout << "healthy: " << (balance_score::healthy() ? "yes" : "no") << "\n";

    std::cout << "\nEnter a value (or 'quit' to exit):\n";
    std::string input;
    while (std::cout << "> " && std::getline(std::cin, input)) {
        if (input == "quit") break;
        std::cout << "received: " << input << "\n";
    }

    return 0;
}
