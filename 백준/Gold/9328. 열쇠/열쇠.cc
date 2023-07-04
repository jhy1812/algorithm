#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int T, h, w, result;
std::vector<std::string> mapp(100);

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> T;

	for (int tc = 0; tc < T; tc++) {
		std::cin >> h >> w;
		result = 0;
		for (int i = 0; i < h; i++) {
			std::string tmp;
			std::cin >> tmp;
			mapp[i] = tmp;
		}
		std::map<int, int> key;
		std::string tmp;
		std::cin >> tmp;
		if (tmp[0] - '0' != 0) {
			for (int i = 0; i<int(tmp.size()); i++) {
				key[tmp[i] - 'a'] = 1;
			}
		}

		std::queue<std::pair<int, int>> q;
		std::map<int, std::queue<std::pair<int, int>>> door;
		std::vector<std::vector<int>> visited(h, std::vector<int>(w, 0));

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
					if (mapp[i][j] == '.') {
						q.push(std::make_pair(i, j));
						visited[i][j] = 1;
					}
					else if (0 <= mapp[i][j] - 'a' && mapp[i][j] - 'a' <= 25) {
						key[mapp[i][j] - 'a'] = 1;
						q.push(std::make_pair(i, j));
						visited[i][j] = 1;
					}
					else if (0 <= mapp[i][j] - 'A' && mapp[i][j] - 'A' <= 25) {
						if (key[mapp[i][j] - 'A'] == 1) {
							visited[i][j] = 1;
							q.push(std::make_pair(i, j));
						}
						else {
							door[mapp[i][j] - 'A'].push(std::make_pair(i, j));
						}
					}
					else if (mapp[i][j] == '$') {
						result++;
						visited[i][j] = 1;
						q.push(std::make_pair(i, j));
					}
				}
			}
		}

		while (!q.empty()) {
			while (!q.empty()) {
				int nowy = q.front().first;
				int nowx = q.front().second;
				q.pop();
				for (int i = 0; i < 4; i++) {
					int ny = nowy + dy[i];
					int nx = nowx + dx[i];
					if (0 <= ny && ny < h && 0 <= nx && nx < w) {
						if (visited[ny][nx] == 0) {
							if (mapp[ny][nx] == '.') {
								visited[ny][nx] = 1;
								q.push(std::make_pair(ny, nx));
							}
							else if (0 <= mapp[ny][nx] - 'a' && mapp[ny][nx] - 'a' <= 25) {
								key[mapp[ny][nx] - 'a'] = 1;
								visited[ny][nx] = 1;
								q.push(std::make_pair(ny, nx));
							}
							else if (0 <= mapp[ny][nx] - 'A' && mapp[ny][nx] - 'A' <= 25) {
								if (key[mapp[ny][nx] - 'A'] == 1) {
									visited[ny][nx] = 1;
									q.push(std::make_pair(ny, nx));
								}
								else {
									door[mapp[ny][nx] - 'A'].push(std::make_pair(ny, nx));
								}
							}
							else if (mapp[ny][nx] == '$') {
								result++;
								visited[ny][nx] = 1;
								q.push(std::make_pair(ny, nx));
							}
						}
					}
				}
			}
			for (int i = 0; i<26; i++) {
				if (key[i] == 1) {
					while (!door[i].empty()) {
						q.push(door[i].front());
						visited[door[i].front().first][door[i].front().second] = 1;
						door[i].pop();
					}
				}
			}
		}

		std::cout << result << "\n";
	}

	return 0;
}