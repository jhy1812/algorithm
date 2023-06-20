#include <iostream>
#include <algorithm>
#include <vector>

#define MOD 1000000000

long long N, K;
std::vector<std::vector<long long>>dp(402, std::vector<long long>(402));

int main()
{
	std::cin >> N >> K;

	for (int i = 1; i < 402; i++) {
		dp[i][0] = 1;
		dp[i][i] = 1;
	}

	for (int i = 2; i < 402; i++) {
		for (int j = 1; j < i; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
		}
	}

	std::cout << dp[N + K - 1][K - 1] % MOD;

	return 0;
}