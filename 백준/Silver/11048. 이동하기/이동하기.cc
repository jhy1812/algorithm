#include <iostream>
#include <algorithm>
#include <vector>

int N, M;
std::vector<std::vector<int>> candy;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		candy.push_back({});
		for (int j = 0; j < M; j++) {
			int tmp;
			std::cin >> tmp;
			candy[i].push_back(tmp);
		}
	}

	for (int i = 1; i < N; i++) {
		candy[i][0] += candy[i - 1][0];
	}

	for (int i = 1; i < M; i++) {
		candy[0][i] += candy[0][i - 1];
	}

	for (int i = 1; i < N; i++) {
		for (int j = 1; j < M; j++) {
			candy[i][j] += std::max(candy[i - 1][j], candy[i][j - 1]);
		}
	}

	std::cout << candy[N - 1][M - 1];

	return 0;
}