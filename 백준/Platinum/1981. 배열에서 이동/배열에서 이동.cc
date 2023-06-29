#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int n, result, st, ed, minn, maxx;
std::vector<std::vector<int>> arr(201, std::vector<int>(201, 0));

bool bfs(int s, int e) {
	std::queue<std::pair<int, int>> q;
	std::vector<std::vector<int>> visited(n + 1, std::vector<int>(n + 1, 0));
	q.push(std::make_pair(1, 1));
	visited[1][1] = 1;
	while (!q.empty()) {
		int nowy = q.front().first;
		int nowx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = nowy + dy[i];
			int nx = nowx + dx[i];
			if (1 <= ny && ny <= n && 1 <= nx && nx <= n) {
				if (visited[ny][nx] == 0) {
					if (s <= arr[ny][nx] && arr[ny][nx] <= e) {
						visited[ny][nx] = 1;
						q.push(std::make_pair(ny, nx));
						if (ny == n && nx == n) {
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n;

	maxx = -1;
	minn = 300;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int tmp;
			std::cin >> tmp;
			arr[i][j] = tmp;
			if (minn > tmp) {
				minn = tmp;
			}
			if (maxx < tmp) {
				maxx = tmp;
			}
		}
	}

	st = 0;
	ed = maxx - minn;
	int mid = (st + ed) / 2;

	while (true) {
		int flag = 0;
		if (st > ed) {
			break;
		}
		for (int i = minn; i + mid <= maxx; i++) {
			if (i <= arr[1][1] && arr[1][1] <= i + mid) {
				if (bfs(i, i + mid)) {
					flag = 1;
					result = mid;
					break;
				}
				else {
					continue;
				}
			}
		}
		if (flag == 0) {
			st = mid + 1;
			mid = (st + ed) / 2;
		}
		else {
			ed = mid - 1;
			mid = (st + ed) / 2;
		}
	}

	std::cout << result;

	return 0;
}