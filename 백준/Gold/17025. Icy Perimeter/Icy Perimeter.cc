#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

int dy[4] = { -1, 1, 0,0 };
int dx[4] = { 0, 0, -1, 1 };

int N, area, around;
std::vector<std::string> ice;
std::vector<std::vector<int>> visited;

void bfs(int y, int x) {
	std::queue<std::pair<int, int>> q;
	q.push(std::make_pair(y, x));
	visited[y][x] = 1;
	
	int tmp_area = 0;
	int tmp_round = 0;

	while (!q.empty()) {
		int nowy = q.front().first;
		int nowx = q.front().second;
		q.pop();
		tmp_area++;
		for (int i = 0; i < 4; i++) {
			int ny = nowy + dy[i];
			int nx = nowx + dx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < N) {
				if (ice[ny][nx] == '.') {
					tmp_round++;
				}
				else {
					if (visited[ny][nx] == 0) {
						visited[ny][nx] = 1;
						q.push(std::make_pair(ny, nx));
					}
				}
			}
			else {
				tmp_round++;
			}
		}
	}

	if (tmp_area > area) {
		area = tmp_area;
		around = tmp_round;
	}
	else if (tmp_area == area) {
		around = std::min(around, tmp_round);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::string tmp;
		std::cin >> tmp;
		ice.push_back(tmp);
		visited.push_back({});
		for (int j = 0; j < N; j++) {
			visited[i].push_back(0);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (ice[i][j] == '#') {
				if (visited[i][j] == 0) {
					bfs(i, j);
				}
			}
		}
	}

	std::cout << area << " " << around;

	return 0;
}