#include <iostream>
#include <vector>

#define MOD 1000000007

int N;
long long result;
std::vector<std::vector<long long>> dp(1516, std::vector<long long>(1516));

int main()
{
	std::cin >> N;

	for (int i = 1; i <= N; i++) {
		dp[i][0] = 1;
		dp[i][i] = 1;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
		}
	}
	for (int i = 1; i <= N; i++) {
		if ((5 * i + N - i) % 3 == 0) {
			result += dp[N - 1][i - 1] % MOD;
			result %= MOD;
		}
	}
	std::cout << result;
	

	return 0;
}