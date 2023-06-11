#include <iostream>
#include <algorithm>

int n;

int main()
{
	std::cin >> n;

	if (n <= 1) {
		std::cout << n;
	}
	else {
		long long dp[10001] = { 0, };
		dp[1] = 1;
		for (int i = 2; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		std::cout << dp[n];
	}

	return 0;
}