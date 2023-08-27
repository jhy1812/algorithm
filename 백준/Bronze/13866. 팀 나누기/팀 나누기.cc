#include <iostream>
#include <cstdlib>

int A, B, C, D;

int main(){
    std::cin >> A >> B >> C >> D;
    
    std::cout << abs((A + D) - (B + C));
    
    return 0;
}