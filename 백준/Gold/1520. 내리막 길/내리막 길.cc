#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int N, M;
std::vector<std::vector<int>>mapp(500, std::vector<int>(500));
std::vector<std::vector<int>>dp(500, std::vector<int>(500, -1));

int dfs(int y, int x) {

	if (dp[y][x] != -1) {
		return dp[y][x];
	}
	
	if (y == N - 1 && x == M - 1) {
		return 1;
	}

	dp[y][x] = 0;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (0 <= ny && ny < N && 0 <= nx && nx < M) {
			if (mapp[ny][nx] < mapp[y][x]) {
				dp[y][x] += dfs(ny, nx);
			}
		}
	}
	return dp[y][x];
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int tmp;
			std::cin >> tmp;
			mapp[i][j] = tmp;
		}
	}

	dfs(0, 0);

	std::cout << dp[0][0];

	return 0;
}