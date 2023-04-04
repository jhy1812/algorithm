#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M, a, b;

	cin >> N >> M;

	vector<int>prob(N + 1);
	vector<int>result;
	vector<vector<int>>arr(N+1);
	priority_queue<int, vector<int>, greater<int>>q;


	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		arr[a].push_back(b);
		prob[b] += 1;
	}

	for (int i = 1; i <= N; i++) {
		if (prob[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int now = q.top();
		result.push_back(now);
		q.pop();
		for (int i = 0; i<int(arr[now].size()); i++) {
			prob[arr[now][i]] -= 1;
			if (prob[arr[now][i]] == 0) {
				q.push(arr[now][i]);
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		cout << result[i] << " ";
	}

	return 0;
}