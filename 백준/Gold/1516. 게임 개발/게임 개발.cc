#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
vector<int>cost(1);
vector<int>pre(1);
vector<int>result(1);
vector<vector<int>>arr(501, vector<int>(1));
queue<int>q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		int tmp;
		cin >> tmp;
		cost.push_back(tmp);
		pre.push_back(0);
		result.push_back(0);
		while (true) {
			int tmp;
			cin >> tmp;
			if (tmp == -1) {
				break;
			}
			pre[i] += 1;
			arr[tmp].push_back(i);
		}
	}

	for (int i = 1; i <= N; i++) {
		if (pre[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 1; i<int(arr[now].size()); i++) {
			pre[arr[now][i]] -= 1;
			result[arr[now][i]] = max(result[arr[now][i]], result[now] + cost[now]);
			if (pre[arr[now][i]] == 0) {
				q.push(arr[now][i]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << result[i] + cost[i] << "\n";
	}

	return 0;
}