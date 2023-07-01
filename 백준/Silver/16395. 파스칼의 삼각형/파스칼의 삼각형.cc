#include <iostream>
#include <algorithm>
#include <vector>

int n, k;
std::vector<std::vector<long long>> dp(31, std::vector<long long>(31));

int main()
{
	std::cin >> n >> k;
	
	dp[0][0] = 1;

	for (int i = 1; i < 31; i++) {
		dp[i][0] = 1;
		dp[i][i] = 1;
	}

	for (int i = 2; i < 31; i++) {
		for (int j = 1; j < i; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}

	std::cout << dp[n - 1][k - 1];

	return 0;
}