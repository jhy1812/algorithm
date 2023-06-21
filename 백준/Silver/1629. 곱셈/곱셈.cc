#include <iostream>
#include <algorithm>

long long a, b, c, result;

int main()
{
	std::cin >> a >> b >> c;

	result = 1;

	while (b > 0) {
		if (b % 2 == 1) {
			result = (result * a) % c;
		}
		b = b / 2;
		a = (a * a) % c;
	}

	std::cout << result;

	return 0;
}