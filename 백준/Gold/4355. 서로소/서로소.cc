#include <iostream>
#include <algorithm>
#include <cmath>

long long n, result;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	while (true) {
		std::cin >> n;
		if (n == 0) {
			break;
		}
		if (n == 1) {
			std::cout << 0 << "\n";
			continue;
		}
		long long lim = int(sqrt(n)) + 1;
		result = n;
		for (int i = 2; i <= lim; i++) {
			if (n % i == 0) {
				while (true) {
					if (n % i != 0) {
						break;
					}
					n = n / i;
				}
				result = result / i;
				result *= (i - 1);
			}
		}
		if (n != 1) {
			result = result / n;
			result *= (n - 1);
		}
		std::cout << result << "\n";
	}

	return 0;
}