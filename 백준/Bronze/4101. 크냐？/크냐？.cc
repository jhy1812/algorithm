#include <iostream>

int a, b;

int main()
{
    while(true){
        std::cin >> a >> b;
        if(a == 0 && b == 0){
            break;
        }
        if (a > b){
            std::cout << "Yes" << "\n";
        }
        else {
            std::cout << "No" << "\n";
        }
    }
    
    return 0;
}