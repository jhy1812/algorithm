#include <iostream>
#include <algorithm>
#include <vector>

long long N;

int main()
{
	std::cin >> N;

	int n = 0;

	while (true) {
		if (1 + (n * (12 + (n - 1) * 6)) / 2 >= N) {
			break;
		}
		n++;
	}

	std::cout << n + 1;

	return 0;
}