#include <iostream>
#include <algorithm>

int a, b, c, d, e;

int main()
{
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	std::cin >> d;
	std::cin >> e;

	if (a < 0) {
		std::cout << -a * c + d + b * e;
	}
	else {
		std::cout << (b - a) * e;
	}

	return 0;
}