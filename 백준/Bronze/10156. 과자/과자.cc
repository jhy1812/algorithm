#include <iostream>

int a, b, c;

int main()
{
	std::cin >> a >> b >> c;

	if (a * b < c) {
		std::cout << 0;
	}
	else {
		std::cout << a * b - c;
	}


	return 0;
}