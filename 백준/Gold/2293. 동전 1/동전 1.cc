#include <iostream>
#include <vector>
#include <algorithm>

int n, k;
std::vector<int>coin(1);
std::vector<std::vector<int>>dp(2, std::vector<int>(1));

int main()
{
	std::cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int tmp;
		std::cin >> tmp;
		coin.push_back(tmp);
	}

	dp[0][0] = 1;
	dp[1][0] = 1;

	for (int i = 0; i < k; i++) {
		dp[0].push_back(0);
		dp[1].push_back(0);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j - coin[i] >= 0) {
				dp[i % 2][j] = dp[(i + 1) % 2][j] + dp[(i % 2)][j - coin[i]];
			}
			else {
				dp[i % 2][j] = dp[(i + 1) % 2][j];
			}
		}
	}

	std::cout << dp[n % 2][k];

	return 0;
}