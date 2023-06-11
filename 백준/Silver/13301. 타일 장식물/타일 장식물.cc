#include <iostream>

int N;
long long dp[81];

int main()
{
	std::cin >> N;

	dp[0] = 2;
	dp[1] = 4;

	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	std::cout << dp[N];

	return 0;
}