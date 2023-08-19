#include <iostream>

int n;

int main()
{
	std::cin >> n;

	if (n % 8 == 1) {
		std::cout << 1;
	}
	else if (n % 8 == 2 || n % 8 == 0) {
		std::cout << 2;
	}
	else if (n % 8 == 3 || n % 8 == 7) {
		std::cout << 3;
	}
	else if (n % 8 == 4 || n % 8 == 6) {
		std::cout << 4;
	}
	else {
		std::cout << 5;
	}

	return 0;
}