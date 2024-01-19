#include <iostream>
#include <algorithm>
#include <vector>

int n, result;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n;

	while (n % 5 != 0) {
		n -= 2;
		result++;
		if (n < 2) {
			break;
		}
	}

	if (n < 2 && n != 0) {
		std::cout << -1;
	}
	else {
		std::cout << result + n / 5;
	}

	return 0;
}