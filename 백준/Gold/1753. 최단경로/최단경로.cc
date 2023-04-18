#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define INF 1e9

int v, e, st, a, b, c;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> v >> e;
	cin >> st;
	vector<int>result(v + 1, INF);
	result[st] = 0;
	vector<vector<pair<int, int>>>arr(v+1);
	vector<int>visited(v + 1);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>>q;
	q.push(make_pair(0, st));

	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		arr[a].push_back(make_pair(b, c));
	}

	while (!q.empty()) {
		int now_dis = q.top().first;
		int now_node = q.top().second;
		q.pop();
		if (visited[now_node] == 1) {
			continue;
		}
		visited[now_node] = 1;
		for (int i = 0; i < int(arr[now_node].size()); i++) {
			if (result[arr[now_node][i].first] > result[now_node] + arr[now_node][i].second) {
				result[arr[now_node][i].first] = result[now_node] + arr[now_node][i].second;
				q.push(make_pair(result[arr[now_node][i].first], arr[now_node][i].first));
			}
		}
	}
	for (int i = 1; i <= v; i++) {
		if (visited[i] == 0) {
			cout << "INF" << "\n";
			continue;
		}
		cout << result[i] << "\n";
	}

	return 0;
}