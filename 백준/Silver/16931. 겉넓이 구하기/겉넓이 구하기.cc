#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

int dy[4] = { 1, 0 };
int dx[4] = { 0, 1 };

int N, M, result;
std::vector<std::vector<int>>arr(102, std::vector<int>(102));

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int tmp;
			std::cin >> tmp;
			arr[i][j] = tmp;
		}
	}

	result += 2 * N * M;

	for (int i = 0; i <= N+1; i++) {
		for (int j = 0; j <= M+1; j++) {
			for (int m = 0; m < 2; m++) {
				int ny = i + dy[m];
				int nx = j + dx[m];
				if (0 <= ny && ny <= N+1 && 0 <= nx && nx <= M+1) {
					result += std::abs(arr[i][j] - arr[ny][nx]);
				}
			}
		}
	}

	std::cout << result;

	return 0;
}