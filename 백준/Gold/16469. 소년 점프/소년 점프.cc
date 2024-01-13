#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int R, C, cnt, mt;
std::vector<std::string> maze;
std::vector<std::vector<int>> sec;
std::vector<std::vector<int>> visited;

void bfs(int y, int x, int b, int st) {
	std::queue<std::pair<int, int>> q;
	std::vector<std::vector<int>> tsec(R, std::vector<int>(C, 0));
	q.push(std::make_pair(y, x));
	visited[y][x]++;
	sec[y][x] = 0;
	while (!q.empty()) {
		int nowy = q.front().first;
		int nowx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = nowy + dy[i];
			int nx = nowx + dx[i];
			if (0 <= ny && ny < R && 0 <= nx && nx < C) {
				if (visited[ny][nx] == b - 1) {
					if (maze[ny][nx] == '0') {
						visited[ny][nx]++;
						q.push(std::make_pair(ny, nx));
						tsec[ny][nx] = tsec[nowy][nowx] + 1;
						sec[ny][nx] = std::max(sec[ny][nx], tsec[ny][nx]);
					}
				}
			}
		}
	}
	sec[y][x] = st;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> R >> C;

	for (int i = 0; i < R; i++) {
		std::string tmp;
		std::cin >> tmp;
		maze.push_back(tmp);
		sec.push_back({});
		visited.push_back({});
		for (int j = 0; j < C; j++) {
			sec[i].push_back(0);
			visited[i].push_back(0);
		}
	}

	for (int i = 1; i <= 3; i++) {
		int yy, xx;
		std::cin >> yy >> xx;
		if (visited[yy - 1][xx - 1] != i - 1) {
			continue;
		}
		bfs(yy - 1, xx - 1, i, sec[yy - 1][xx - 1]);
	}

	mt = 10001;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (visited[i][j] == 3) {
				if (mt > sec[i][j]) {
					cnt = 1;
					mt = sec[i][j];
				}
				else if (mt == sec[i][j]) {
					cnt++;
				}
			}
		}
	}

	if (mt == 10001) {
		std::cout << -1;
	}
	else {
		std::cout << mt << "\n" << cnt;
	}

	return 0;
}