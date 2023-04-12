#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N = 5;
int cnt, cnts, cnty, check;
vector<vector<char>>jari(N, vector<char>(N));
vector<pair<int, int>>spot;
vector<vector<int>>visited(N, vector<int>(N));

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void bfs(int y, int x) {
	int checked[5][5] = { 0, };
	queue<pair<int, int>>q;
	q.push(make_pair(y, x));
	checked[y][x] = 1;
	check = 1;
	while (!q.empty()) {
		int nowy = q.front().first;
		int nowx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = nowy + dy[i];
			int nx = nowx + dx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < N) {
				if (visited[ny][nx] == 1 && checked[ny][nx] == 0) {
					checked[ny][nx] = 1;
					q.push(make_pair(ny, nx));
					check += 1;
				}
			}
		}
	}
}

void dfs(int st, int lv, int cnts, int cnty) {
	if (cnty >= 4) {
		return;
	}
	if (lv == 7) {
		check = 0;
		bfs(spot[st - 1].first, spot[st - 1].second);
		if (check == 7) {
			cnt += 1;
		}
		return;
	}
	for (int i = st; i < 25; i++) {
		if (jari[spot[i].first][spot[i].second] == 'S') {
			visited[spot[i].first][spot[i].second] = 1;
			dfs(i + 1, lv + 1, cnts + 1, cnty);
			visited[spot[i].first][spot[i].second] = 0;
		}
		else {
			visited[spot[i].first][spot[i].second] = 1;
			dfs(i + 1, lv + 1, cnts, cnty + 1);
			visited[spot[i].first][spot[i].second] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> jari[i][j];
			spot.push_back(make_pair(i, j));
		}
	}
	dfs(0, 0, 0, 0);

	cout << cnt;


	return 0;
}