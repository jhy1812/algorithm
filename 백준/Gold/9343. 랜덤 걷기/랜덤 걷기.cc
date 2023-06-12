#include <iostream>
#include <vector>
#include <cmath>

#define MOD 1000000007

int T, N;
long long result;
long long arr[2000001];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	arr[0] = 1;
	arr[1] = 1;

	for (int i = 2; i <= 2000000; i++) {
		arr[i] = (i * arr[i - 1]) % MOD;
	}

	std::cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		std::cin >> N;
		result = arr[2 * N];
		long long divv = (arr[N + 1] * arr[N]) % MOD;
		long long p = MOD - 2;
		while (p > 0) {
			if (p % 2 == 1) {
				result = (result * divv) % MOD;
			}
			p = p / 2;
			divv = (divv * divv) % MOD;
		}
		std::cout << result << "\n";
	}

	return 0;
}