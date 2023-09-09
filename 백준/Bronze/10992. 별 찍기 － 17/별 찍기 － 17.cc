#include <iostream>

int n;

int main() {
	std::cin >> n;
    
	for (int i = 1; i <= n; i++) {
		if (i == n) {
            for (int i = 1; i <= 2 * n - 1; i++) {
                std::cout << "*";             
            }
        }
		else {
			for (int j = n - i; j > 0; j--) {
                std::cout << " "; 
            } 
			std::cout << "*";
			if (i != 1) {
				for (int j = 1; j <= (i - 1) * 2 - 1; j++) { 
                    std::cout << " "; 
                }
				std::cout << "*";
			}
		}
		std::cout << "\n";
	}
    
	return 0;
}