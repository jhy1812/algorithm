#include <iostream>

long long n, m;

int main()
{
	std::cin >> n >> m;

	if (n == m) {
		std::cout << 1;
	}
	else {
		std::cout << 0;
	}

	return 0;
}