#include <iostream>
#include <algorithm>
#include <cmath>

int a, b, c, maxx;

int main()
{
	while (true) {
		std::cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) {
			break;
		}
		maxx = std::max(std::max(a, b), c);
		if (maxx == a) {
			if (std::pow(maxx, 2) == std::pow(b, 2) + std::pow(c, 2)) {
				std::cout << "right" << "\n";
			}
			else {
				std::cout << "wrong" << "\n";
			}
		}
		else if (maxx == b) {
			if (std::pow(maxx, 2) == std::pow(a, 2) + std::pow(c, 2)) {
				std::cout << "right" << "\n";
			}
			else {
				std::cout << "wrong" << "\n";
			}
		}
		else {
			if (std::pow(maxx, 2) == std::pow(a, 2) + std::pow(b, 2)) {
				std::cout << "right" << "\n";
			}
			else {
				std::cout << "wrong" << "\n";
			}
		}
	}


	return 0;
}