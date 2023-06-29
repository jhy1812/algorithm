#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int N, M;
std::vector<std::vector<int>> arr(100, std::vector<int>(100));
std::vector<std::vector<int>> visited(100, std::vector<int>(100, -1));

void bfs(int y, int x) {
	std::queue<std::pair<int, int>> q;
	q.push(std::make_pair(y, x));
	visited[y][x] = 0;
	while (!q.empty()) {
		int nowy = q.front().first;
		int nowx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = nowy + dy[i];
			int nx = nowx + dx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < M) {
				if (visited[ny][nx] == -1) {
					visited[ny][nx] = visited[nowy][nowx] + arr[ny][nx];
					q.push(std::make_pair(ny, nx));
				}
				else {
					if (visited[ny][nx] > visited[nowy][nowx] + arr[ny][nx]) {
						visited[ny][nx] = visited[nowy][nowx] + arr[ny][nx];
						q.push(std::make_pair(ny, nx));
					}
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

	std::cin >> M >> N;

	for (int i = 0; i < N; i++) {
		std::string tmp;
		std::cin >> tmp;
		for (int j = 0; j < M; j++) {
			arr[i][j] = tmp[j] - '0';
		}
	}
	
	bfs(0, 0);

	std::cout << visited[N - 1][M - 1];

	return 0;
}