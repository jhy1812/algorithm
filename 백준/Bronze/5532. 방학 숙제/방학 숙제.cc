#include <iostream>
#include <algorithm>

int main()
{
	int a, b, c, d, e;
	int s, g, holi;

	std::cin >> a >> b >> c >> d >> e;

	s = b / d;

	if (b%d != 0) {
		s += 1;
	}

	g = c / e;

	if (c%e != 0) {
		g += 1;
	}

	holi = std::max(s, g);

	std::cout << a - holi;

	return 0;
}