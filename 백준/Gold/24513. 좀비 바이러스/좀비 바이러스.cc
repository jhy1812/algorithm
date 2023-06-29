#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int N, M, h;

std::vector<int> virus(4);
std::vector<std::vector<int>> vil(1000, std::vector<int>(1000, 0));
std::vector<std::vector<int>> visited(1000, std::vector<int>(1000, -1));
std::vector<std::queue<std::pair<int, int>>> ov(2);
std::vector<std::queue<std::pair<int, int>>> tv(2);

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
			if (tmp == -1) {
				vil[i][j] = -1;
			}
			else if (tmp == 1) {
				ov[0].push(std::make_pair(i, j));
				vil[i][j] = 1;
				visited[i][j] = 0;
			}
			else if (tmp == 2) {
				tv[0].push(std::make_pair(i, j));
				vil[i][j] = 2;
				visited[i][j] = 0;
			}
			else {
				vil[i][j] = 0;
			}
		}
	}

	while (true) {
		while (!ov[h % 2].empty()) {
			int nowy = ov[h % 2].front().first;
			int nowx = ov[h % 2].front().second;
			ov[h % 2].pop();
			if (vil[nowy][nowx] == 3) {
				continue;
			}
			for (int i = 0; i < 4; i++) {
				int ny = nowy + dy[i];
				int nx = nowx + dx[i];
				if (0 <= ny && ny < N && 0 <= nx && nx < M) {
					if (vil[ny][nx] == 0) {
						visited[ny][nx] = visited[nowy][nowx] + 1;
						vil[ny][nx]++;
						ov[(h + 1) % 2].push(std::make_pair(ny, nx));
					}
				}
			}
		}
		while (!tv[h % 2].empty()) {
			int nowy = tv[h % 2].front().first;
			int nowx = tv[h % 2].front().second;
			tv[h % 2].pop();
			if (vil[nowy][nowx] == 3) {
				continue;
			}
			for (int i = 0; i < 4; i++) {
				int ny = nowy + dy[i];
				int nx = nowx + dx[i];
				if (0 <= ny && ny < N && 0 <= nx && nx < M) {
					if (vil[ny][nx] == 0) {
						vil[ny][nx] += 2;
						visited[ny][nx] = visited[nowy][nowx] + 1;
						tv[(h + 1) % 2].push(std::make_pair(ny, nx));
					}
					if (vil[ny][nx] == 1 && visited[ny][nx] == visited[nowy][nowx] + 1) {
						vil[ny][nx] += 2;
					}
				}
			}
		}
		if (ov[(h + 1) % 2].empty() && tv[(h + 1) % 2].empty()) {
			break;
		}
		h++;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (vil[i][j] == -1) {
				continue;
			}
			virus[vil[i][j]]++;
		}
	}

	for (int i = 1; i <= 3; i++) {
		std::cout << virus[i] << " ";
	}

	return 0;
}