#include <iostream>
#include <algorithm>

int a, b, c;

int main()
{
	std::cin >> a >> b;
	std::cin >> c;

	if (a + b >= 2 * c) {
		std::cout << a + b - 2 * c;
	}
	else {
		std::cout << a + b;
	}

	return 0;
}