#include <iostream>

using namespace std;

long long N, all, part1, part2, part3, result;
long long dp[200][10];


int main()
{
	cin >> N;
	long long div = 1000000000;
	if (N == 1) {
		cout << 0;
	}
	else {
		for (int i = 1; i < 10; i++) {
			dp[1][i] = 1;
		}
		for (int i = 2; i <= N; i++) {
			for (int j = 0; j < 10; j++) {
				if (j - 1 >= 0) {
					dp[i][j] += dp[i - 1][j - 1]%div;
				}
				if (j + 1 < 10) {
					dp[i][j] += dp[i - 1][j + 1]%div;
				}
			}
		}
		for (int i = 0; i < 10; i++) {
			all += dp[N][i];
		}
		all = all;

		for (int i = 2; i <= N; i++) {
			for (int j = 0; j < 9; j++) {
				dp[i][j] = 0;
				if (j - 1 >= 0) {
					dp[i][j] += dp[i - 1][j - 1]%div;
				}
				if (j + 1 < 9) {
					dp[i][j] += dp[i - 1][j + 1]%div;
				}
			}
		}
		for (int i = 0; i < 9; i++) {
			part1 += dp[N][i]%div;
		}
		part1 = part1%div;
		
		for (int i = 2; i <= N; i++) {
			for (int j = 1; j < 10; j++) {
				dp[i][j] = 0;
				if (j - 1 >= 1) {
					dp[i][j] += dp[i - 1][j - 1]%div;
				}
				if (j + 1 < 10) {
					dp[i][j] += dp[i - 1][j + 1]%div;
				}
			}
		}
		for (int i = 1; i < 10; i++) {
			part2 += dp[N][i]%div;
		}
		part2 = part2%div;

		for (int i = 2; i <= N; i++) {
			for (int j = 1; j < 9; j++) {
				dp[i][j] = 0;
				if (j - 1 >= 1) {
					dp[i][j] += dp[i - 1][j - 1]%div;
				}
				if (j + 1 < 9) {
					dp[i][j] += dp[i - 1][j + 1]%div;
				}
			}
		}

		for (int i = 1; i < 9; i++) {
			part3 += dp[N][i]%div;
		}
		part3 = part3%div;

		result = (all - part1 - part2 + part3) % div;
		cout << result;
	}
	return 0;
}