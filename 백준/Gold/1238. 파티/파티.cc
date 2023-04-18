#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define INF 1e9

int N, M, X, a, b, c;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> X;

	vector<vector<pair<int, int>>>go(N + 1, vector<pair<int, int>>());
	vector<vector<pair<int, int>>>come(N + 1, vector<pair<int, int>>());
	vector<int>go_dis(N + 1, INF);
	vector<int>come_dis(N + 1, INF);
	vector<int>result(N + 1);
	go_dis[X] = 0;
	come_dis[X] = 0;

	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		go[a].push_back(make_pair(b, c));
		come[b].push_back(make_pair(a, c));
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
	q.push(make_pair(0, X));

	while (!q.empty()) {
		int nowd = q.top().first;
		int nown = q.top().second;
		q.pop();
		for (int i = 0; i< int(go[nown].size()); i++) {
			if (go_dis[go[nown][i].first] > go_dis[nown] + go[nown][i].second) {
				go_dis[go[nown][i].first] = go_dis[nown] + go[nown][i].second;
				q.push(make_pair(go[nown][i].second, go[nown][i].first));
			}
		}
	}

	q.push(make_pair(0, X));

	while (!q.empty()) {
		int nowd = q.top().first;
		int nown = q.top().second;
		q.pop();
		for (int i = 0; i< int(come[nown].size()); i++) {
			if (come_dis[come[nown][i].first] > come_dis[nown] + come[nown][i].second) {
				come_dis[come[nown][i].first] = come_dis[nown] + come[nown][i].second;
				q.push(make_pair(come[nown][i].second, come[nown][i].first));
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		result[i] = go_dis[i] + come_dis[i];
	}

	int maxx = 0;

	for (int i = 1; i <= N; i++) {
		if (maxx < result[i]) {
			maxx = result[i];
		}
	}

	cout << maxx;

	return 0;
}