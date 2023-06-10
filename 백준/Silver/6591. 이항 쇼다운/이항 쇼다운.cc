#include <iostream>
#include <algorithm>

#define MOD 1000000007

int n, k;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	while (true) {
		std::cin >> n >> k;

		if (n == 0 && k == 0) {
			break;
		}
		if (k < n - k) {
			k = n - k;
		}
		long long result = 1;
		for (int i = n; i >= k + 1; i--) {
			result = result * i;
			result = result / (n - i + 1);
		}
		std::cout << result << "\n";
	}

	return 0;
}