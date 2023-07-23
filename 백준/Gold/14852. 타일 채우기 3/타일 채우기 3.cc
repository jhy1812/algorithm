#include <iostream>
#include <algorithm>

#define MOD 1000000007

int N;
long long dp[1000001][2];

int main()
{
	std::cin >> N;

	dp[0][0] = 1;
	dp[1][0] = 2;
	dp[2][0] = 7;
	dp[3][0] = 22;
	dp[0][1] = 1;
	dp[1][1] = 2;
	dp[2][1] = 8;
	dp[3][1] = 24;

	for (int i = 4; i <= N; i++) {
		dp[i][0] = (dp[i-4][1] * 2 + dp[i - 3][1] * 2 + dp[i - 2][0] * 3 + dp[i - 1][0] * 2) % MOD;
		dp[i][1] = (dp[i][0] + dp[i - 2][1]) % MOD;
	}

	std::cout << dp[N][0];

	return 0;
}