#include <iostream>
#include <string>

int cnt;
std::string k;

int main() {
    
    std::cin >> k;
    
    for (int i = 0; i < k.size(); i++)
    {
        if (k[i] == ',')
            cnt++;
    }
    std::cout << cnt + 1 << '\n';
}