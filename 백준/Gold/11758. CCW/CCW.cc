#include <iostream>
#include <vector>
#include <algorithm>

long long x1, y, x2, y2, x3, y3;

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
	std::cin >> x1 >> y;
	std::cin >> x2 >> y2;
	std::cin >> x3 >> y3;

	long long result = cross(x1, y, x2, y2, x3, y3);

	std::cout << result;

	return 0;
}