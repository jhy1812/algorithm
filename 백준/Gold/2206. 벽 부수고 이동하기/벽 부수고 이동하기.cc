#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int N, M;
std::vector<std::vector<int>> mapp(1000, std::vector<int>(1000));
std::vector<std::vector<int>> visited(1000, std::vector<int>(1000, -1));
std::vector<std::pair<int, int>> st;

void bfs(int y, int x) {
	std::queue<std::pair<int, int>> q;
	std::queue<std::pair<int, int>> q2;
	q.push(std::make_pair(y, x));
	visited[y][x] = 1;
	while (!q.empty()) {
		int nowy = q.front().first;
		int nowx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = nowy + dy[i];
			int nx = nowx + dx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < M) {
				if (visited[ny][nx] == -1 && mapp[ny][nx] == 0) {
					visited[ny][nx] = visited[nowy][nowx] + 1;
					q.push(std::make_pair(ny, nx));
				}
				else if (visited[ny][nx] == -1 && mapp[ny][nx] == 1) {
					visited[ny][nx] = visited[nowy][nowx] + 1;
					q2.push(std::make_pair(ny, nx));
				}
			}
		}
	}
	while (!q2.empty()) {
		int nowy = q2.front().first;
		int nowx = q2.front().second;
		q2.pop();
		for (int i = 0; i < 4; i++) {
			int ny = nowy + dy[i];
			int nx = nowx + dx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < M) {
				if (visited[ny][nx] == -1 && mapp[ny][nx] == 0) {
					visited[ny][nx] = visited[nowy][nowx] + 1;
					q2.push(std::make_pair(ny, nx));
				}
				else if (mapp[ny][nx] == 0 && visited[ny][nx] > visited[nowy][nowx] + 1) {
					visited[ny][nx] = visited[nowy][nowx] + 1;
					q2.push(std::make_pair(ny, nx));
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

	std::cin >> N >> M;

	st.push_back(std::make_pair(0, 0));

	for (int i = 0; i < N; i++) {
		std::string tmp;
		std::cin >> tmp;
		for (int j = 0; j < M; j++) {
			mapp[i][j] = tmp[j] - '0';
			if (mapp[i][j] == 1) {
				st.push_back(std::make_pair(i, j));
			}
		}
	}

	bfs(0, 0);

	std::cout << visited[N - 1][M - 1];

	return 0;
}