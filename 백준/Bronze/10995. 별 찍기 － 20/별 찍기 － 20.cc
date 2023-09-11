#include <iostream>
    
int N;

int main() 
{
    std::cin >> N;

    for(int i = 0; i < N; i++) {
        if(i % 2 == 1) {
            std::cout << " ";
        }
    
        for(int j = 0; j < N; j++) {
            std::cout << "* ";
        }
        std::cout << "\n";
    }
}