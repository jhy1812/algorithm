#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define MOD 1000000007

int k, n;
long long result = 1;
long long divv = 1;
long long p = MOD - 2;

int main()
{
	std::cin >> k >> n;

	for (int i = n + k; i >= n; i--) {
		result = (result * i) % MOD;
	}

	for (int i = 1; i <= k + 1; i++) {
		divv = (divv * i) % MOD;
	}

	while (p > 0) {
		if (p % 2 == 1) {
			result = (result * divv) % MOD;
		}
		p = p / 2;
		divv = (divv * divv) % MOD;
	}

	std::cout << result;

	return 0;
}