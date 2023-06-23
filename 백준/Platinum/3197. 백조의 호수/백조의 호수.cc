#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int r, c, nday, flag;
int lake[1500][1500];
int visited[1500][1500];
std::vector<std::queue<std::pair<int, int>>>swan1(2, std::queue<std::pair<int, int>>());
std::vector<std::queue<std::pair<int, int>>>swan2(2, std::queue<std::pair<int, int>>());
std::vector<std::queue<std::pair<int, int>>>water(2, std::queue<std::pair<int, int>>());
//std::queue<std::pair<int, int>>ice;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			char tmp;
			std::cin >> tmp;
			if (tmp == 'X') {
				lake[i][j] = -1;
			}
			else if (tmp == '.') {
				lake[i][j] = 0;
				visited[i][j] = -1;
				water[nday%2].push(std::make_pair(i, j));
			}
			else {
				lake[i][j] = flag + 1;
				if (flag == 0) {
					swan1[nday%2].push(std::make_pair(i, j));
				}
				else {
					swan2[nday%2].push(std::make_pair(i, j));
				}
				visited[i][j] = 1;
				flag += 1;
			}
		}
	}

	flag = 0;

	while (1) {
		while (!swan1[nday%2].empty()) {
			int nowy = swan1[nday%2].front().first;
			int nowx = swan1[nday%2].front().second;
			swan1[nday%2].pop();
			for (int i = 0; i < 4; i++) {
				int ny = nowy + dy[i];
				int nx = nowx + dx[i];
				if (0 <= ny && ny < r && 0 <= nx && nx < c) {
					if (lake[ny][nx] == 2) {
						flag = 1; 
						break; 
					}
					if (visited[ny][nx] != 1) {
						visited[ny][nx] = 1;
						if (lake[ny][nx] == 0) {
							lake[ny][nx] = 1;
							swan1[nday%2].push(std::make_pair(ny, nx));
						}
						else if (lake[ny][nx] == -1) {
							lake[ny][nx] = 1;
							swan1[(nday + 1) % 2].push(std::make_pair(ny, nx));
						}
					}
				}
			}
		}
		if (flag == 1) {
			break;
		}
		while (!swan2[nday % 2].empty()) {
			int nowy = swan2[nday % 2].front().first;
			int nowx = swan2[nday % 2].front().second;
			swan2[nday % 2].pop();
			for (int i = 0; i < 4; i++) {
				int ny = nowy + dy[i];
				int nx = nowx + dx[i];
				if (0 <= ny && ny < r && 0 <= nx && nx < c) {
					if (visited[ny][nx] != 1) {
						visited[ny][nx] = 1;
						if (lake[ny][nx] == 0) {
							lake[ny][nx] = 2;
							swan2[nday % 2].push(std::make_pair(ny, nx));
						}
						else if (lake[ny][nx] == -1) {
							lake[ny][nx] = 2;
							swan2[(nday + 1) % 2].push(std::make_pair(ny, nx));
						}
					}
				}
			}
		}
		while (!water[nday%2].empty()) {
			int nowy = water[nday%2].front().first;
			int nowx = water[nday%2].front().second;
			water[nday%2].pop();
			if (visited[nowy][nowx] == 1) {
				continue;
			}
			visited[nowy][nowx] = -1;
			for (int i = 0; i < 4; i++) {
				int ny = nowy + dy[i];
				int nx = nowx + dx[i];
				if (0 <= ny && ny < r && 0 <= nx && nx < c) {
					if (visited[ny][nx] == 1) {
						continue;
					}
					if (visited[ny][nx] != -1) {
						visited[ny][nx] = -1;
						if (lake[ny][nx] == -1) {
							lake[ny][nx] = 0;
							water[(nday + 1) % 2].push(std::make_pair(ny, nx));
						}
					}
				}
			}
		}
		nday++;
	}

	std::cout << nday;

	return 0;
}