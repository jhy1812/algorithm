#include <iostream>

long long a, b;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> a >> b;

	if (a > b) {
		long long tmp = a;
		a = b;
		b = tmp;
	}

	if (a == b) {
		std::cout << 0;
	}
	else {
		std::cout << b - a - 1 << "\n";
	}

	for (int i = a + 1; i < b; i++) {
		std::cout << i << " ";
	}

	return 0;
}