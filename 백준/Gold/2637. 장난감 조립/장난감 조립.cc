#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, a, b, c;
vector<int>pre(101);
vector<int>post(101);
vector<int>result(101);
vector<vector<pair<int, int>>>arr(101, vector<pair<int, int>>());

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		arr[a].push_back(make_pair(b, c));
		pre[a] += 1;
		post[b] += 1;
	}

	queue<int>q;
	q.push(N);
	result[N] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i<int(arr[now].size()); i++) {
			post[arr[now][i].first] -= 1;
			result[arr[now][i].first] += result[now] * arr[now][i].second;
			if (post[arr[now][i].first] == 0 && pre[arr[now][i].first] != 0) {
				q.push(arr[now][i].first);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (pre[i] == 0) {
			cout << i << " " << result[i] << "\n";
		}
	}

	return 0;
}