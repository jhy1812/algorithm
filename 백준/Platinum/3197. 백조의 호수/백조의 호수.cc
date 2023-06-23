//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//
//int dy[4] = { -1, 1, 0, 0 };
//int dx[4] = { 0, 0, -1, 1 };
//
//struct spot {
//	int num;
//	int day;
//
//	spot() { num = 0; day = 0; }
//	spot(int a, int b) : num(a), day(b) {}
//};
//
//struct cmp {
//	bool operator () (std::vector<int> x, std::vector<int> y) {
//		return x[2] > y[2];
//	}
//};
//
//int r, c, result, b1, b2;
//std::vector<std::pair<int, int>> goal;
//std::vector<std::vector<spot>> lake(1500, std::vector<spot>(1500));
//
//void bfs1(int y, int x, int num) {
//	std::queue<std::pair<int, int>> q;
//	q.push(std::make_pair(y, x));
//	lake[y][x].num = num;
//	while (!q.empty()) {
//		int nowy = q.front().first;
//		int nowx = q.front().second;
//		q.pop();
//		for (int i = 0; i < 4; i++) {
//			int ny = nowy + dy[i];
//			int nx = nowx + dx[i];
//			if (0 <= ny && ny < r && 0 <= nx && nx < c) {
//				if (lake[ny][nx].num == 0) {
//					lake[ny][nx].num = num;
//					q.push(std::make_pair(ny, nx));
//				}
//			}
//		}
//	}
//}
//
//void bfs2() {
//	std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, cmp>q;
//	for (int i = 0; i<int(goal.size()); i++) {
//		q.push({ goal[i].first, goal[i].second, 0 });
//		lake[goal[i].first][goal[i].second].day = 0;
//	}
//	while (!q.empty()) {
//		int nowy = q.top()[0];
//		int nowx = q.top()[1];
//		int nowd = q.top()[2];
//		q.pop();
//		for (int i = 0; i < 4; i++) {
//			int ny = nowy + dy[i];
//			int nx = nowx + dx[i];
//			if (0 <= ny && ny < r && 0 <= nx && nx < c) {
//				if (lake[ny][nx].day == -1) {
//					if (lake[ny][nx].num != -1) {
//						lake[ny][nx].day = nowd;
//					}
//					else if (lake[ny][nx].num == -1) {
//						lake[ny][nx].day = nowd + 1;
//					}
//					q.push({ny, nx, lake[ny][nx].day});
//				}
//			}
//		}
//	}
//}
//
//void bfs3(int y, int x) {
//	std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, cmp>q;
//	q.push({ y, x, 0 });
//	lake[y][x].num = -2;
//	while (!q.empty()) {
//		int nowy = q.top()[0];
//		int nowx = q.top()[1];
//		int nowd = q.top()[2];
//		q.pop();
//		for (int i = 0; i < 4; i++) {
//			int ny = nowy + dy[i];
//			int nx = nowx + dx[i];
//			if (0 <= ny && ny < r && 0 <= nx && nx < c) {
//				if (lake[ny][nx].num != -2) {
//					lake[ny][nx].num = -2;
//					if (lake[ny][nx].day < nowd) {
//						lake[ny][nx].day = nowd;
//					}
//					q.push({ ny, nx, lake[ny][nx].day });
//				}
//				if (ny == goal[1].first && nx == goal[1].second) {
//					return;
//				}
//			}
//		}
//	}
//}
//
//int main()
//{
//	std::ios_base::sync_with_stdio(false);
//	std::cin.tie(NULL);
//	std::cout.tie(NULL);
//
//	std::cin >> r >> c;
//
//	int cnt = 1;
//
//	for (int i = 0; i < r; i++) {
//		for (int j = 0; j < c; j++) {
//			char tmp;
//			std::cin >> tmp;
//			if (tmp == 'X') {
//				spot now = { -1, -1 };
//				lake[i][j] = now;
//			}
//			else if (tmp == '.') {
//				spot now = { 0, -1 };
//				lake[i][j] = now;
//
//			}
//			else if (tmp == 'L') {
//				spot now = { 0, -1 };
//				lake[i][j] = now;
//				goal.push_back(std::make_pair(i, j));
//				cnt += 1;
//			}
//		}
//	}
//
//	cnt = 1;
//
//	for (int i = 0; i < r; i++) {
//		for (int j = 0; j < c; j++) {
//			if (lake[i][j].num == 0) {
//				bfs1(i, j, cnt);
//				cnt += 1;
//				goal.push_back(std::make_pair(i, j));
//			}
//		}
//	}
//
//	bfs2();
//	bfs3(goal[0].first, goal[0].second);
//
//	std::cout << lake[goal[1].first][goal[1].second].day;
//
//	return 0;
//}

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