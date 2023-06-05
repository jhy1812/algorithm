#include <iostream>
#include <algorithm>
#include <cmath>

int a, b, c, maxx;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	while (true) {
		std::cin >> a >> b >> c;
		if (a == 0) {
			break;
		}
		maxx = std::max(a, std::max(b, c));
		if (maxx == a) {
			if (a >= b + c) {
				std::cout << "Invalid" << "\n";
				continue;
			}
		}
		if (maxx == b) {
			if (b >= a + c) {
				std::cout << "Invalid" << "\n";
				continue;
			}
		}
		if (maxx == c) {
			if (c >= a + b) {
				std::cout << "Invalid" << "\n";
				continue;
			}
		}
		if (a == b && b == c) {
			std::cout << "Equilateral" << "\n";
		}
		else if (a == b || b == c || a == c) {
			std::cout << "Isosceles" << "\n";
		}
		else {
			std::cout << "Scalene" << "\n";
		}
	}

	return 0;
}