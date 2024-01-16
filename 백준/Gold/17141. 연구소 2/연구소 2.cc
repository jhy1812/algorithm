#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int N, M, result, cnt;
std::vector<std::vector<int>> lab;
std::vector<std::pair<int, int>> spot;
std::vector<std::pair<int, int>> comb;

void bfs() {
	std::queue<std::pair<int, int>> q;
	std::vector<std::vector<int>> visited(N, std::vector<int>(N, -1));
	int count = 0;
	int t = 0;
	for (int i = 0; i < M; i++) {
		q.push(comb[i]);
		visited[comb[i].first][comb[i].second] = 0;
		count++;
	}

	while (!q.empty()) {
		int nowy = q.front().first;
		int nowx = q.front().second;
		q.pop();
		
		t = std::max(t, visited[nowy][nowx]);

		for (int i = 0; i < 4; i++) {
			int ny = nowy + dy[i];
			int nx = nowx + dx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < N) {
				if (visited[ny][nx] == -1 && lab[ny][nx] != 1) {
					visited[ny][nx] = visited[nowy][nowx] + 1;
					q.push(std::make_pair(ny, nx));
					count++;
				}
			}
		}
	}
	
	if (count == cnt) {
		result = std::min(result, t);
	}
}

void dfs(int lv, int st) {
	if (lv == M) {
		bfs();
		return;
	}

	for (int i = st; i < spot.size(); i++) {
		comb[lv] = spot[i];
		dfs(lv + 1, i + 1);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		lab.push_back({});
		for (int j = 0; j < N; j++) {
			int tmp;
			std::cin >> tmp;
			lab[i].push_back(tmp);
			if (tmp == 2) {
				spot.push_back(std::make_pair(i, j));
				cnt++;
			}
			if (tmp == 0) {
				cnt++;
			}
		}
	}

	comb.resize(M);
	result = 2501;
	dfs(0, 0);

	if (result == 2501) {
		std::cout << -1;
	}
	else {
		std::cout << result;
	}

	return 0;
}