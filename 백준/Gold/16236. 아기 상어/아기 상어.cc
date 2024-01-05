#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

struct info {
	int y;
	int x;
	int dis;
};

struct cmp {
	bool operator()(info a, info b) {
		if (a.dis == b.dis) {
			if (a.y == b.y) {
				return a.x > b.x;
			}
			return a.y > b.y;
		}
		return a.dis > b.dis;
	}
};

int dy[4] = { -1, 0, 0, 1 };
int dx[4] = { 0, -1, 1, 0 };

int N, shark, sec, sy, sx, eat;
std::vector<std::vector<int>> space;

bool bfs(int y, int x, std::priority_queue<info, std::vector<info>, cmp>& fish) {
	std::queue<std::pair<int, int>> q;
	std::vector<std::vector<int>> visited(N, std::vector<int>(N, -1));
	q.push(std::make_pair(y, x));
	visited[y][x] = 0;
	int flag = 0;
	while (!q.empty()) {
		int nowy = q.front().first;
		int nowx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = nowy + dy[i];
			int nx = nowx + dx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < N) {
				if (space[ny][nx] < shark && space[ny][nx] != 0) {
					if (visited[ny][nx] == -1) {
						visited[ny][nx] = visited[nowy][nowx] + 1;
						info tmp;
						tmp.y = ny;
						tmp.x = nx;
						tmp.dis = visited[ny][nx];
						fish.push(tmp);
						flag = 1;
					}
				}
				else if (space[ny][nx] == shark || space[ny][nx] == 0) {
					if (visited[ny][nx] == -1) {
						visited[ny][nx] = visited[nowy][nowx] + 1;
						q.push(std::make_pair(ny, nx));
					}
				}
			}
		}
	}
	if (flag) {
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	shark = 2;

	for (int i = 0; i < N; i++) {
		space.push_back({});
		for (int j = 0; j < N; j++) {
			int tmp;
			std::cin >> tmp;
			space[i].push_back(tmp);
			if (tmp == 9) {
				sy = i;
				sx = j;
			}
		}
	}

	while (true) {
		std::priority_queue<info, std::vector<info>, cmp> check;
		if (bfs(sy, sx, check)) {
			space[sy][sx] = 0;
			sec += check.top().dis;
			sy = check.top().y;
			sx = check.top().x;
			eat++;
			if (shark == eat) {
				shark++;
				eat = 0;
			}
			space[sy][sx] = 9;
		}
		else {
			break;
		}
	}

	std::cout << sec;

	return 0;
}