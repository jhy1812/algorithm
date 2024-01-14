#include <iostream>
#include <algorithm>
#include <vector>

int N, stone;
int arr[2500];
int dp[2500][2];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		std::cin >> tmp;
		arr[i] = tmp;
	}

	dp[0][0] = 1;
	if (arr[0] <= arr[1]) {
		stone = arr[1] - arr[0];
	}
	else {
		stone = arr[1];
	}
	dp[0][1] = 1;

	for (int i = 1; i < N - 1; i++) {
		if (stone == 0) {
			dp[i][0] = dp[i - 1][1];
			dp[i][1] = dp[i - 1][1];
			stone = arr[i + 1];
		}
		else {
				dp[i][0] = std::min(dp[i - 1][0], dp[i - 1][1]) + 1;
			if (arr[i] == stone) {
				if (arr[i] <= arr[i + 1]) {
					dp[i][1] = std::min(dp[i - 1][0], dp[i - 1][1]) + 1;
					stone = arr[i + 1] - arr[i];
				}
				else {
					dp[i][1] = std::min(dp[i - 1][0], dp[i - 1][1]) + 1;
					stone = arr[i + 1];
				}
			}
			else {
				if (stone <= arr[i + 1]) {
					dp[i][1] = dp[i - 1][1] + 1;
					stone = arr[i + 1] - stone;
				}
				else {
					dp[i][1] = dp[i - 1][1] + 1;
					stone = arr[i + 1];
				}
			}
		}
	}

	if (stone == 0) {
		std::cout << std::min(dp[N - 2][0], dp[N - 2][1]);
	}
	else {
		std::cout << std::min(dp[N - 2][0], dp[N - 2][1]) + 1;
	}

	return 0;
}