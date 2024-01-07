#include <iostream>
#include <algorithm>
#include <vector>

int n;
std::vector<std::vector<long long>> dp(31, std::vector<long long>(3, 0));

int main()
{
	std::cin >> n;

	dp[0][0] = 1;

	for (int i = 1; i <= n; i++) {
		dp[i][0] += dp[i - 1][0] - 2 * dp[i - 1][1] + 2 * dp[i - 1][2];
		dp[i][1] += dp[i - 1][0] + dp[i - 1][1];
		dp[i][2] += -1 * dp[i - 1][0] + dp[i - 1][2];
	}

	std::cout << dp[n][0] + dp[n][1] + dp[n][2];

	return 0;
}