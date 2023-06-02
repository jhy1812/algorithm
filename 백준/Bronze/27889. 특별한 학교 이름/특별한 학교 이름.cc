#include <iostream>
#include <string>

int main()
{
    std::string a;
    std::cin >> a;
    
    if (a == "NLCS"){
        std::cout << "North London Collegiate School";
    }
    else if (a == "BHA"){
        std::cout << "Branksome Hall Asia";
    }
    else if (a == "KIS"){
        std::cout << "Korea International School";
    }
    else {
        std::cout << "St. Johnsbury Academy";
    }
    
    return 0;
}