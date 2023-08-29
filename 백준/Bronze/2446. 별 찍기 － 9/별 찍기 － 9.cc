#include <iostream>

int n;

int main() {
    std::cin >> n;

    for (int i = 0; i < n; i++){
       for (int j = 0; j < i; j++) {
            std::cout << " ";
       }
       for (int j = 0; j < 2 * (n - i) - 1; j++) {
            std::cout << "*";            
       }
       std::cout << "\n";
   }
    
   for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 2; j++) {
            std::cout << " ";            
        }
        for (int j = 0; j < 2 * (i + 1) + 1; j++) {
            std::cout << "*";            
        }
        std::cout << "\n";
   }   
   return 0;
}