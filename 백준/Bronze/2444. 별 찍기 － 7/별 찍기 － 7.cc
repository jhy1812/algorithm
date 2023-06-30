#include <iostream>
#include <algorithm>

int N;

int main()
{
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = N - i - 1; j > 0; j--) {
			std::cout << " ";
		}
		for (int j = 0; j < 2 * (i + 1) - 1; j++) {
			std::cout << "*";
		}
		std::cout << "\n";
	}

	for (int i = N - 1; i > 0; i--) {
		for (int j = N - i; j > 0; j--) {
			std::cout << " ";
		}
		for (int j = 0; j < 2 * (i) - 1; j++) {
			std::cout << "*";
		}
		
		std::cout << "\n";
	}

	return 0;
}