#include <iostream>
#include <vector>
#include <algorithm>

int N, M;
std::vector<std::vector<int>>arr(1025, std::vector<int>(1025));
std::vector<std::vector<int>>dp(1025, std::vector<int>(1025));

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int tmp;
			std::cin >> tmp;
			arr[i][j] = tmp;
		}
	}
	
	dp[1][1] = arr[1][1];

	for (int i = 2; i <= N; i++) {
		dp[i][1] = dp[i - 1][1] + arr[i][1];
		dp[1][i] = dp[1][i - 1] + arr[1][i];
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 2; j <= N; j++) {
			dp[i][j] = arr[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}

	for (int i = 0; i < M; i++) {
		int a, b, c, d;
		std::cin >> a >> b >> c >> d;
		std::cout << dp[c][d] - dp[c][b - 1] - dp[a - 1][d] + dp[a - 1][b - 1] << "\n";
	}

	return 0;
}