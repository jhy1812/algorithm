#include <iostream>
#include <string>

int main()
{
    char s;
    
    std::cin >> s;
    
    if (s == 'S'){
        std::cout << "HIGHSCHOOL";
    }
    else if (s == 'C'){
        std::cout << "MASTER";
    }
    else if (s == '2'){
        std::cout << "0611";
    }
    else {
        std::cout << "CONTEST";
    }
    
    return 0;
}