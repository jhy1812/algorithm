#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, a, b, c, st, ed, result_time, result_num;
queue<int>q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	vector<vector<pair<int, int>>>go(n + 1, vector<pair<int, int>>(1));
	vector<vector<pair<int, int>>>come(n + 1, vector<pair<int, int>>(1));
	vector<int>pre(n + 1);
	vector<int> dis(n + 1);

	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		go[a].push_back(make_pair(b, c));
		come[b].push_back(make_pair(a, c));
		pre[b] += 1;
	}

	cin >> st >> ed;

	q.push(st);

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 1; i < int(go[now].size()); i++) {
			pre[go[now][i].first] -= 1;
			dis[go[now][i].first] = max(dis[go[now][i].first], dis[now] + go[now][i].second);
			if (pre[go[now][i].first] == 0) {
				q.push(go[now][i].first);
			}
		}
	}

	result_time = dis[ed];
	vector<int>visited(n + 1);

	q.push(ed);
	visited[ed] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 1; i<int(come[now].size()); i++) {
			if (dis[come[now][i].first] + come[now][i].second == dis[now]) {
				result_num += 1;
				if (visited[come[now][i].first] == 0) {
					visited[come[now][i].first] = 1;
					q.push(come[now][i].first);
				}
			}
		}
	}

	cout << result_time << "\n" << result_num;

	return 0;
}