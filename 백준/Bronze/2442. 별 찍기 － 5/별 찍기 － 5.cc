#include <iostream>

int main()
{
    int N;
    
    std::cin >> N;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N + i; j++){
            if (j < N - i - 1){
                std::cout << " ";
            }
            else {
                std::cout << "*";
            }
        }
        std::cout << "\n";
    }
    
    return 0;
}