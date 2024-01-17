#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

int T;
std::vector<long long> dp(3, 0);

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int i = 2;
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 5;

	while (true) {
		if (dp[i] >= INT_MAX) {
			break;
		}
		i++;
		dp.push_back(0);
		dp[i] = 4 * dp[i - 2] + dp[i - 1];
		for (int j = i - 3; j >= 0; j--) {
			if ((i - j) % 2 == 1) {
				dp[i] += 2 * dp[j];
			}
			else {
				dp[i] += 3 * dp[j];
			}
		}
	}

	std::cin >> T;

	for (int i = 0; i < T; i++) {
		int N;
		std::cin >> N;
		std::cout << dp[N] << "\n";
	}

	return 0;
}