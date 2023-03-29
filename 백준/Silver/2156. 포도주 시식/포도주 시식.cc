#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int sul[10000] = { 0, };
	for (int i = 0; i < n; i++) {
		cin >> sul[i];
	}
	if (n == 1) {
		cout << sul[0];
	}
	else if (n == 2) {
		cout << sul[0] + sul[1];
	}
	else {
		int dp[10000][3] = { 0, };
		dp[0][1] = sul[0];
		dp[0][2] = sul[0];
		dp[1][0] = sul[0];
		dp[1][1] = sul[1];
		dp[1][2] = sul[0] + sul[1];
		for (int i = 2; i < n; i++) {
			dp[i][2] = dp[i - 1][1] + sul[i];
			int masyou = max(max(dp[i - 1][0], dp[i - 1][2]),dp[i-1][1]);
			dp[i][0] = masyou;
			dp[i][1] = dp[i-1][0] + sul[i];
		}
		int maxx = max(max(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);
		cout << maxx;
	}
	return 0;
}