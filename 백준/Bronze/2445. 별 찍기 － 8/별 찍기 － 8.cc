#include <iostream>

int main() {
	int n;
	std::cin >> n;

	for (int i = 1; i <= n; i++) {

		for (int j = i; j > 0; j--) {
			std::cout << "*";
		}

		for (int k = 2 * (n - i); k > 0; k--) {
			std::cout << " ";
		}

		for (int l = i; l > 0; l--) {
			std::cout << "*";
		}

		std::cout << std::endl;
	}

	for (int i = n - 1; i > 0; i--) {

		for (int j = i; j > 0; j--) {
			std::cout << "*";
		}

		for (int k = 2 * (n - i); k > 0; k--) {
			std::cout << " ";
		}

		for (int l = i; l > 0; l--) {
			std::cout << "*";
		}

		std::cout << std::endl;
	}

}