#include <iostream>
#include <string>

int main() {
    std::string text;
    while (getline(std::cin, text)) {
        std::cout << text << "\n";
    }
}