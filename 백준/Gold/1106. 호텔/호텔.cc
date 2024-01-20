#include <iostream>
#include <algorithm>
#include <vector>

int C, N, result;
std::vector<int> dp(2001, 0);

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> C >> N;

	for (int i = 0; i < N; i++) {
		int a, b;
		std::cin >> a >> b;
		
		int cost = 0;
		for (int j = 1; j <= 2000; j++) {
			if (j % b == 0) {
				cost = j / b;
			}
			else {
				cost = j / b + 1;
			}
			if (j >= b) {
				if (dp[j] == 0) {
					dp[j] = a * cost;
				}
				else {
					dp[j] = std::min(dp[j], a * cost);
				}
			}
			if (j - b >= 0) {
				if (dp[j - b] != 0) {
					dp[j] = std::min(dp[j], dp[j - b] + a);
				}
			}
		}
	}
	result = 1000000;

	for (int i = C; i <= 2000; i++) {
		if (dp[i] == 0) {
			continue;
		}
		result = std::min(result, dp[i]);
	}

	std::cout << result;

	return 0;
}