#include <iostream>
#include <vector>
#include <algorithm>

int n, k;
std::vector<int>dp(10001, 10001);

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int tmp;
		std::cin >> tmp;
		for (int j = 1; j <= k; j++) {
			if (j % tmp == 0) {
				dp[j] = std::min(dp[j], j / tmp);
			}
			if (j - tmp >= 1) {
				dp[j] = std::min(dp[j], dp[j - tmp] + 1);
			}
		}
	}

	if (dp[k] == 10001) {
		std::cout << -1;
	}
	else {
		std::cout << dp[k];
	}

	return 0;
}