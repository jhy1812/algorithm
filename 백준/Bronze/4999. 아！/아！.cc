#include <iostream>
#include <string>

int main()
{
    std::string a, b;
    
    std::cin >> a;
    std::cin >> b;
    
    if (int(a.size()) >= int(b.size())){
        std::cout << "go";
    }
    else {
        std::cout << "no";
    }
    
    return 0;
}