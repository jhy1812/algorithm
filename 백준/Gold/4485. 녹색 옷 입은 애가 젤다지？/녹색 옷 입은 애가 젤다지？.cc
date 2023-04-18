#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define INF 1e9;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int T, N, tc;
vector<vector<int>>mapp(125, vector<int>(125));
vector<vector<int>>visited(125, vector<int>(125, -1));

void bfs(int y, int x) {
	queue<pair<int, int>>q;
	q.push(make_pair(y, x));
	visited[y][x] = mapp[y][x];
	while (!q.empty()) {
		int nowy = q.front().first;
		int nowx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = nowy + dy[i];
			int nx = nowx + dx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < N) {
				if (visited[ny][nx] == -1) {
					visited[ny][nx] = mapp[ny][nx] + visited[nowy][nowx];
					q.push(make_pair(ny, nx));
				}
				else if (visited[ny][nx] > mapp[ny][nx] + visited[nowy][nowx]) {
					visited[ny][nx] = mapp[ny][nx] + visited[nowy][nowx];
					q.push(make_pair(ny, nx));
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		tc += 1;
		cin >> N;
		if (N == 0) {
			break;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int tmp; 
				cin >> tmp;
				mapp[i][j] = tmp;
				visited[i][j] = -1;
			}
		}

		bfs(0, 0);
		cout << "Problem " << tc << ": " << visited[N - 1][N - 1] << "\n";
	}

	return 0;
}