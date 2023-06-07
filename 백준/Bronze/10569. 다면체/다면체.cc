#include <iostream>

int T;

int main()
{
    std::cin >> T;
    
    for (int i =0; i<T; i++){
        int v, e;
        std::cin >> v >> e;
        std::cout << e - v + 2 << "\n";
    }
    
    return 0;
}