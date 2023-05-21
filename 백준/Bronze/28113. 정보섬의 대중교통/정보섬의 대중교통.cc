#include <iostream>

int n, a, b;

int main()
{
	std::cin >> n >> a >> b;

	if (n >= b) {
		if (n > a) {
			std::cout << "Bus";
		}
		else if (n == a) {
			std::cout << "Anything";
		}
		else {
			std::cout << "Subway";
		}
	}
	else {
		if (b > a) {
			std::cout << "Bus";
		}
		else if (b == a) {
			std::cout << "Anything";
		}
		else {
			std::cout << "Subway";
		}
	}

	return 0;
}