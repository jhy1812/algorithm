#include <iostream>
#include <algorithm>

int x1, y, x2, y2, x3, y3;
int rx, ry;

int main()
{
	std::cin >> x1 >> y;
	std::cin >> x2 >> y2;
	std::cin >> x3 >> y3;

	if (x1 == x2) {
		rx = x3;
	}
	else if (x1 == x3) {
		rx = x2;
	}
	else {
		rx = x1;
	}

	if (y == y2) {
		ry = y3;
	}
	else if (y == y3) {
		ry = y2;
	}
	else {
		ry = y;
	}

	std::cout << rx << " " << ry;

	return 0;
}