#include <iostream>
#include <vector>
#include <algorithm>

int N, M, minn;
std::vector<std::vector<int>>score(501, std::vector<int>(501));
std::vector<std::vector<int>>dp(501, std::vector<int>(501));

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> N >> M;
	minn = 1000000000;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int tmp;
			std::cin >> tmp;
			score[i][j] = tmp;
		}
	}

	for (int i = 0; i < M; i++) {
		dp[0][i] = score[0][i];
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int check = 1000000000;
			for (int k = 0; k < M; k++) {
				if (k != j) {
					if (dp[i-1][k] < check) {
						check = dp[i - 1][k];
					}
				}
			}
			dp[i][j] = score[i][j] + check;
		}
	}

	for (int i = 0; i < M; i++) {
		if (dp[N - 1][i] < minn) {
			minn = dp[N - 1][i];
		}
	}

	std::cout << minn;

	return 0;
}