#include <iostream>
#include <cmath>
#include <algorithm>

int T;
int x1, y, r1, x2, y2, r2;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> T;

	for (int i = 0; i < T; i++) {
		std::cin >> x1 >> y >> r1 >> x2 >> y2 >> r2;
		int d = (x1 - x2) * (x1 - x2) + (y - y2) * (y - y2);
		int summ = (r1 + r2) * (r1 + r2);
		int diff = (r1 - r2) * (r1 - r2);
		if (x1 == x2 && y == y2 && r1 == r2) {
			std::cout << -1 << "\n";
		}
		else if (d > summ) {
			std::cout << 0 << "\n";
		}
		else if (d == summ) {
			std::cout << 1 << "\n";
		}
		else if (d > diff && d < summ) {
			std::cout << 2 << "\n";
		}
		else if (d == diff) {
			std::cout << 1 << "\n";
		}
		else if (d < diff) {
			std::cout << 0 << "\n";
		}
	}

	return 0;
}