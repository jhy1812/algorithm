#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define MOD 1000000007

long long N, K;
long long arr[1002][1002];
long long dp[1001];

int main()
{
	std::cin >> N >> K;

	dp[0] = N;

	for (int i = 1; i <= K + 1; i++) {
		arr[i][0] = 1;
		arr[i][i] = 1;
	}

	for (int i = 2; i <= K + 1; i++) {
		for (int j = 1; j <= i - 1; j++) {
			arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j]) % MOD;
		}
	}

	for (int i = 1; i <= K; i++) {
		long long p = i + 1;
		long long tmp = 1;
		long long mull = N + 1;
		while (p > 0) {
			if (p % 2 == 1) {
				tmp = (tmp * mull) % MOD;
			}
			p = p / 2;
			mull = (mull * mull) % MOD;
		}
		tmp -= 1;
		for (int j = 0; j <= i - 1; j++) {
			tmp -= (arr[i + 1][j] * dp[j]) % MOD;
			if (tmp < 0) {
				tmp += MOD;
			}
			else {
				tmp = tmp % MOD;
			}
		}
		mull = arr[i + 1][i];
		p = MOD - 2;
		while (p > 0) {
			if (p % 2 == 1) {
				tmp = (tmp * mull) % MOD;
			}
			p = p / 2;
			mull = (mull * mull) % MOD;
		}
		dp[i] = tmp % MOD;
	}

	std::cout << dp[K];

	return 0;
}