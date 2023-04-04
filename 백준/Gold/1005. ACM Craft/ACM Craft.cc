#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int T, N, K, W, a, b, maxx;

int main()
{
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> K;
		vector<int>cost(N + 1);
		vector<int>order(N + 1);
		vector<int>used(N + 1);
		vector<vector<int>>arr(N + 1);

		queue<int>q;

		for (int i = 1; i <= N; i++) {
			cin >> cost[i];
		}
		for (int i = 0; i < K; i++) {
			cin >> a >> b;
			arr[a].push_back(b);
			order[b] += 1;
		}
		cin >> W;

		for (int i = 1; i <= N; i++) {
			if (order[i] == 0) {
				used[i] = cost[i];
				q.push(i);
			}
		}

		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (int i = 0; i< int(arr[now].size()); i++) {
				order[arr[now][i]] -= 1;
				used[arr[now][i]] = max(used[arr[now][i]], used[now] + cost[arr[now][i]]);
				maxx = max(maxx, used[arr[now][i]]);
				if (order[arr[now][i]] == 0) {
					q.push(arr[now][i]);
				}
			}
		}

		cout << used[W] << "\n";
	}

	return 0;
}