#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, cnt;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vector<int>dp(N + 1);
	
	for (int i = 2; i <= N; i++) {
		int tmp = i;
		dp[tmp] = dp[tmp - 1] + 1;
		if (tmp % 2 == 0 && tmp / 2 >= 1) {
			dp[tmp] = min(dp[tmp / 2] + 1, dp[tmp]);
		}
		if (tmp % 3 == 0 && tmp / 3 >= 1) {
			dp[tmp] = min(dp[tmp / 3] + 1, dp[tmp]);
		}
	}


	cout << dp[N] << "\n";
	cnt = dp[N];
	int result = N;

	while (true) {
		cout << result << " ";
		if (result == 1) {
			break;
		}
		if (dp[result] == dp[result - 1] + 1) {
			result -= 1;
		}
		else if (result % 2 == 0) {
			if (dp[result] == dp[result / 2] + 1) {
				result = result / 2;
			}
			else if ((result % 3) == 0) {
				if (dp[result] == dp[int(result / 3)] + 1) {
					result = int(result / 3);
				}
			}
		}
		else if ((result % 3) == 0) {
			if (dp[result] == dp[int(result / 3)] + 1) {
				result = int(result / 3);
			}
		}
	}

	return 0;
}