#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int T, R, C, maxBreak, area;
std::vector<std::vector<int>> garden(1002, std::vector<int>(1002, 0));
std::vector<std::vector<int>> visited(1002, std::vector<int>(1002, 0));

void bfs(int y, int x, std::vector<std::vector<int>>& check) {
	std::queue<std::pair<int, int>> q1;
	std::queue<std::pair<int, int>> q2;
	check[y][x] = 0;
	q1.push(std::make_pair(y, x));
	while (!q1.empty() || !q2.empty()) {
		while (!q1.empty()) {
			int nowy = q1.front().first;
			int nowx = q1.front().second;
			q1.pop();
			for (int i = 0; i < 4; i++) {
				int ny = nowy + dy[i];
				int nx = nowx + dx[i];
				if (0 <= ny && ny <= R + 1 && 0 <= nx && nx <= C + 1) {
					if (check[ny][nx] == -1) {
						if (garden[ny][nx] == 1) {
							q2.push(std::make_pair(ny, nx));
							check[ny][nx] = check[nowy][nowx] + 1;
						}
						else {
							q1.push(std::make_pair(ny, nx));
							check[ny][nx] = check[nowy][nowx];
						}
					}
					else {
						if (garden[ny][nx] == 1) {
							if (check[ny][nx] > check[nowy][nowx] + 1) {
								q2.push(std::make_pair(ny, nx));
								check[ny][nx] = check[nowy][nowx] + 1;
							}
						}
						else {
							if (check[ny][nx] > check[nowy][nowx]) {
								q1.push(std::make_pair(ny, nx));
								check[ny][nx] = check[nowy][nowx];
							}
						}
					}
				}
			}
		}

		while (!q2.empty() && q1.empty()) {
			int nowy = q2.front().first;
			int nowx = q2.front().second;
			q2.pop();

			for (int i = 0; i < 4; i++) {
				int ny = nowy + dy[i];
				int nx = nowx + dx[i];
				if (0 <= ny && ny <= R + 1 && 0 <= nx && nx <= C + 1) {
					if (check[ny][nx] == -1) {
						if (garden[ny][nx] == 1) {
							check[ny][nx] = check[nowy][nowx] + 1;
							q2.push(std::make_pair(ny, nx));
						}
						else {
							check[ny][nx] = check[nowy][nowx];
							q1.push(std::make_pair(ny, nx));
						}
					}
					else {
						if (garden[ny][nx] == 1) {
							if (check[ny][nx] > check[nowy][nowx] + 1) {
								q2.push(std::make_pair(ny, nx));
								check[ny][nx] = check[nowy][nowx] + 1;
							}
						}
						else {
							if (check[ny][nx] > check[nowy][nowx]) {
								q1.push(std::make_pair(ny, nx));
								check[ny][nx] = check[nowy][nowx];
							}
						}
					}
				}
			}
		}
	}
}

int get_result(int y, int x) {
	std::queue<std::pair<int, int>> q;
	q.push(std::make_pair(y, x));
	visited[y][x] = 1;
	int ret = 0;
	while (!q.empty()) {
		int nowy = q.front().first;
		int nowx = q.front().second;
		q.pop();
		ret++;
		for (int i = 0; i < 4; i++) {
			int ny = nowy + dy[i];
			int nx = nowx + dx[i];
			if (1 <= ny && ny <= R && 1 <= nx && nx <= C) {
				if (garden[ny][nx] == 0 && visited[ny][nx] == 0) {
					q.push(std::make_pair(ny, nx));
					visited[ny][nx] = 1;
				}
			}
		}
	}

	return ret;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		std::cin >> R >> C;
		std::vector<std::vector<int>> bk(1002, std::vector<int>(1002, -1));
		maxBreak = 0;
		area = 0;

		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				int tmp;
				std::cin >> tmp;
				garden[i][j] = tmp;
				visited[i][j] = 0;
			}
		}

		for (int i = 0; i <= R + 1; i++) {
			garden[i][0] = 0;
			garden[i][C + 1] = 0;
		}

		for (int i = 0; i <= C + 1; i++) {
			garden[0][i] = 0;
			garden[R + 1][i] = 0;
		}

		bfs(0, 0, bk);

		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (bk[i][j] > maxBreak && garden[i][j] == 0 && visited[i][j] == 0) {
					area = 0;
					maxBreak = bk[i][j];
					area = get_result(i, j);
				}
				else if (bk[i][j] == maxBreak && garden[i][j] == 0 && visited[i][j] == 0) {
					area += get_result(i, j);
				}
			}
		}

		
		std::cout << maxBreak << " " << area << "\n";
	}

	return 0;
}