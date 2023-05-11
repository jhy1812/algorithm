#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<int>price(1);
std::vector<std::vector<int>>dp(2, std::vector<int>(1));

int main()
{
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		std::cin >> tmp;
		price.push_back(tmp);
		dp[0].push_back(0);
		dp[1].push_back(0);
	}

	for (int i = 1; i <= N; i++) {
		dp[1][i] = price[1] * i;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (j - i >= 0) {
				dp[i % 2][j] = std::max(dp[i % 2][j - i] + price[i], dp[(i + 1) % 2][j]);
			}
			else {
				dp[i % 2][j] = dp[(i + 1) % 2][j];
			}
		}
	}

	std::cout << dp[N % 2][N];

	return 0;
}