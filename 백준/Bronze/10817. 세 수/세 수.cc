#include <iostream>
#include <algorithm>

int a, b, c;

int main()
{
    std::cin >> a >> b >> c;
    
    if (a >= b && b >= c){
        std::cout << b;
    }
    else if (b >= a && a >= c){
        std::cout << a;
    }
    else if (a >= c && c >= b){
        std::cout << c;
    }
    else if (c >= b && b >= a){
        std::cout << b;
    }
    else if (c >= a && a >= b){
        std::cout << a;
    }
    else if (b >= c && c >= a){
        std::cout << c;
    }
    
    return 0;
}