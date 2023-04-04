#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, a, b;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	vector<int>student(N + 1);
	vector<vector<int>>arr(N+1);
	vector<int>result;
	queue<int>q;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		arr[a].push_back(b);
		student[b] += 1;
	}

	for (int i = 1; i <= N; i++) {
		if (student[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		result.push_back(now);
		for (int i = 0; i<int(arr[now].size()); i++) {
			student[arr[now][i]] -= 1;
			if (student[arr[now][i]] == 0) {
				q.push(arr[now][i]);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << result[i] << " ";
	}


	return 0;
}