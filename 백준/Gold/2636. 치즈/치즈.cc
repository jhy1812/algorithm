#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int N, M, h, result;
std::vector<std::vector<int>> cheese(100, std::vector<int>(100));
std::vector<std::vector<int>> visited(100, std::vector<int>(100, -1));
std::vector<std::queue<std::pair<int, int>>> q(2, std::queue<std::pair<int, int>>());

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
			cheese[i][j] = tmp;
		}
	}

	q[0].push(std::make_pair(0, 0));
	h = -1;

	visited[0][0] = 0;
	
	while (!q[0].empty() || !q[1].empty()) {
		h++;
		while (!q[h%2].empty()) {
			int nowy = q[h % 2].front().first;
			int nowx = q[h % 2].front().second;
			q[h % 2].pop();
			for (int i = 0; i < 4; i++) {
				int ny = nowy + dy[i];
				int nx = nowx + dx[i];
				if (0 <= ny && ny < N && 0 <= nx && nx < M) {
					if (visited[ny][nx] == -1 && cheese[ny][nx] == 0) {
						visited[ny][nx] = visited[nowy][nowx];
						q[h % 2].push(std::make_pair(ny, nx));
					}
					else if (visited[ny][nx] == -1 && cheese[ny][nx] == 1) {
						visited[ny][nx] = visited[nowy][nowx] + 1;
						q[(h + 1) % 2].push(std::make_pair(ny, nx));
					}
				}
			}
		}
		
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == h && cheese[i][j] == 1) {
				result++;
			}
		}
	}

	std::cout << h << "\n" << result;

	return 0;
}