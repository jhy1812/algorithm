#include <iostream>
#include <algorithm>
#include <vector>

#define MOD 1000000007

int M, N, K;
long long result;
std::vector<long long>arr(4000001, 1);

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	for (int i = 1; i <= 4000000; i++) {
		arr[i] = (arr[i - 1] * i) % MOD;
	}

	std::cin >> M;

	for (int i = 0; i < M; i++) {
		std::cin >> N >> K;
		result = arr[N];
		long long divv = (arr[K] * arr[N - K]) % MOD;
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