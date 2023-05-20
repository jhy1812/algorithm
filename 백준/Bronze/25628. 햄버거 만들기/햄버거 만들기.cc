#include <iostream>

int a, b;

int main()
{
    std::cin >> a >> b;
    
    a = a/2;
    if (a >= b){
        std::cout << b;
    }
    else {
        std::cout << a;
    }
    
    return 0;
}