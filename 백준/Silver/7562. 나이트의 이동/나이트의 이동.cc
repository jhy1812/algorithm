#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

int dy[8] = { -2, -2, -1, 1, 2, 2, 1, -1 };
int dx[8] = { -1, 1, 2, 2, 1, -1, -2, -2 };

int T, N, sty, stx, edy, edx;

std::vector<std::vector<int>> visited(300, std::vector<int>(300, -1));


void bfs(int y, int x) {
	std::queue<std::pair<int, int>> q;
	q.push(std::make_pair(y, x));
	visited[y][x] = 0;
	while (!q.empty()) {
		int nowy = q.front().first;
		int nowx = q.front().second;
		q.pop();
		if (nowy == edy && nowx == edx) {
			return;
		}
		for (int i = 0; i < 8; i++) {
			int ny = nowy + dy[i];
			int nx = nowx + dx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < N) {
				if (visited[ny][nx] == -1) {
					visited[ny][nx] = visited[nowy][nowx] + 1;
					q.push(std::make_pair(ny, nx));
				}
			}
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> T;

	for (int tc = 0; tc < T; tc++) {
		std::cin >> N;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visited[i][j] = -1;
			}
		}


		std::cin >> sty >> stx;
		std::cin >> edy >> edx;

		bfs(sty, stx);

		std::cout << visited[edy][edx] << "\n";
	}

	return 0;
}