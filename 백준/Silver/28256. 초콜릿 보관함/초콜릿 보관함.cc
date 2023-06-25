#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int dy[4] = { -1, 1, 0 ,0 };
int dx[4] = { 0, 0, -1, 1 };

int T, cnt;
std::vector<std::string>box(3);
std::vector<std::vector<int>>visited(3, std::vector<int>(3, 0));

void dfs(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (0 <= ny && ny < 3 && 0 <= nx && nx < 3) {
			if (visited[ny][nx] == 0) {
				if (box[ny][nx] == 'O') {
					cnt += 1;
					dfs(ny, nx);
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

	std::cin >> T;

	for (int tc = 0; tc < T; tc++) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				visited[i][j] = 0;
			}
		}
		std::vector<int> result;
		visited[1][1] = 1;
		for (int i = 0; i < 3; i++) {
			std::string tmp;
			std::cin >> tmp;
			box[i] = tmp;
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (visited[i][j] == 0 && box[i][j] == 'O') {
					cnt = 1;
					dfs(i, j);
					result.push_back(cnt);
				}
			}
		}
		int N;
		std::vector<int>check;
		std::cin >> N;
		for (int i = 0; i < N; i++) {
			int tmp;
			std::cin >> tmp;
			check.push_back(tmp);
		}
		if (int(check.size()) != int(result.size())) {
			std::cout << 0 << "\n";
			continue;
		}
		int flag = 0;
		sort(result.begin(), result.end());
		for (int i = 0; i < N; i++) {
			if (result[i] != check[i]) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			std::cout << 0 << "\n";
		}
		else {
			std::cout << 1 << "\n";
		}
	}

	return 0;
}