#include <iostream>
#include <algorithm>
#include <cmath>

#define MOD 1000000007

int N, M;
int p = MOD - 2;
long long result = 1;
long long divv = 1;

int main()
{
	std::cin >> N >> M;

	for (int i = N; i > M; i--) {
		result = (result * i) % MOD;
	}

	for (int i = 1; i <= (N - M); i++) {
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