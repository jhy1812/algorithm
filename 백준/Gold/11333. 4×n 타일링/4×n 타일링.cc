#include <iostream>
#include <algorithm>
#include <vector>

#define MOD 1000000007

int T;
std::vector<long long> dp(10001, 0);

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	dp[3] = 3;
	
	int cnt1 = 2;
	for (int i = 6; i <= 10000; i += 3) {
		dp[i] += 3 * dp[i - 3];
		if (i % 3 == 0) {
			dp[i] += 2 * cnt1;
			cnt1++;
		}
		int cnt2 = 2;
		for (int j = i - 6; j >= 0; j -= 3) {
			dp[i] += 2 * cnt2 * dp[j];
			dp[i] %= MOD;
			cnt2++;
		}
		dp[i] %= MOD;
	}

	std::cin >> T;

	for (int i = 0; i < T; i++) {
		int N;
		std::cin >> N;
		std::cout << dp[N] << "\n";
	}

	return 0;
}