#include <iostream>
#include <vector>
#include <algorithm>

int N, K;
std::vector<std::vector<int>>dp(2, std::vector<int>(1));

int main()
{
	std::cin >> N >> K;

	for (int i = 0; i < N; i++) {
		dp[0].push_back(0);
		dp[1].push_back(0);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				dp[i % 2][j] = 1;
			}
			else {
				dp[i % 2][j] = (dp[(i + 1) % 2][j - 1] + dp[(i + 1) % 2][j])%10007;
			}
		}
	}
	
	std::cout << dp[N % 2][K]%10007;

	return 0;
}