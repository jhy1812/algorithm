#include <iostream>

int main()
{
    double d1, d2;
    std::cin >> d1;
    std::cin >> d2;
    
    std::cout << std::fixed;
    std::cout.precision(6);
    std::cout << (double)2*d1 + (double)2*3.141592*d2;
    
    return 0;
}