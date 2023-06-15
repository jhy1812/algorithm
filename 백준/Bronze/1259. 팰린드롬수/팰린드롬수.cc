#include <iostream>
#include <string>

std::string s;
std::string rs;

int main()
{
    while (true) {
        std::cin >> s;
        if (s == "0") {
            break;
        }
        rs = "";
        for (int i = int(s.size()) - 1; i >= 0; i--) {
            rs += s[i];
        }
        if (s == rs) {
            std::cout << "yes" << "\n";
        }
        else {
            std::cout << "no" << "\n";
        }
    }
    return 0;
}