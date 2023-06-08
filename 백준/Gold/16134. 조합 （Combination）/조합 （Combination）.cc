#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define MOD 1000000007

int N, R;
long long result = 1;
long long divv = 1;
long long p = MOD - 2;

int main()
{
	std::cin >> N >> R;

	for (int i = N; i >= R + 1; i--) {
		result = (result * i) % MOD;
	}

	for (int i = 1; i <= N - R; i++) {
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