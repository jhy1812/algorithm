#include <iostream>
#include <algorithm>

long long x1, y, x2, y2, x3, y3, x4, y4;

long long cross(long long a1, long long b1, long long a2, long long b2, long long a3, long long b3) {
	long long check = a1 * b2 + a2 * b3 + a3 * b1 - (a2 * b1 + a3 * b2 + a1 * b3);
	if (check < 0) {
		return -1;
	}
	else if (check > 0) {
		return 1;
	}
	return 0;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> x1 >> y >> x2 >> y2;
	std::cin >> x3 >> y3 >> x4 >> y4;

	if (x1 > x2) {
		long long tmp;
		long long tmp1;
		tmp = x1;
		tmp1 = y;
		x1 = x2;
		x2 = tmp;
		y = y2;
		y2 = tmp1;
	}
	if (x3 > x4) {
		long long tmp;
		long long tmp1;
		tmp = x3;
		tmp1 = y3;
		x3 = x4;
		x4 = tmp;
		y3 = y4;
		y4 = tmp1;
	}

	long long check1 = 0;
	long long check2 = 0;
	long long check3 = 0;
	long long check4 = 0;

	check1 = cross(x1, y, x2, y2, x3, y3);
	check2 = cross(x1, y, x2, y2, x4, y4);
	check3 = cross(x3, y3, x4, y4, x1, y);
	check4 = cross(x3, y3, x4, y4, x2, y2);

	if (check1 * check2 <= 0 && check3 * check4 <= 0) {
		if (check1 * check2 == 0 && check3 * check4 == 0) {
			if (x1 == x2 && x3 == x4) {
				if (y2 < y3 && y < y4 && y < y3 && y2 < y4) {
					std::cout << 0;
				}
				else if (y3 < y && y4 < y2 && y3 < y2 && y4 < y) {
					std::cout << 0;
				}
				else {
					std::cout << 1;
				}
			}
			else if (x2 < x3 || x4 < x1) {
				std::cout << 0;
			}
			else {
				std::cout << 1;
			}
		}
		else {
			std::cout << 1;
		}
	}
	else {
		std::cout << 0;
	}

	return 0;
}