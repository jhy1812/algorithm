#include <iostream>
#include <algorithm>
#include <vector>

#define MOD 9901;

int N;
std::vector<std::vector<int>> dp(100001, std::vector<int>(3, 0));

int main()
{
	std::cin >> N;

	dp[1][0] = 1;
	dp[1][1] = 1;
	dp[1][2] = 1;

	for (int i = 2; i <= N; i++) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
	}

	std::cout << (dp[N][0] + dp[N][1] + dp[N][2]) % MOD;

	return 0;
}