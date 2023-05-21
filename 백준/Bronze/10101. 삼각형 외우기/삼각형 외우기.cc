#include <iostream>

int a, b, c;

int main()
{
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;

	if (a + b + c != 180) {
		std::cout << "Error";
	}
	else if (a == 60 && b == 60 && c == 60) {
		std::cout << "Equilateral";
	}
	else if (a == b || b == c || a == c) {
		std::cout << "Isosceles";
	}
	else {
		std::cout << "Scalene";
	}

	return 0;
}