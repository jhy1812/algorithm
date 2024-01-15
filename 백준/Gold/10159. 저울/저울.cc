#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

int N, M;
std::vector<int> results(101, 0);
std::vector<std::vector<int>> arr(101, std::vector<int>(101, 0));

void bfs(int st) {
	std::queue<int> q;
	std::vector<int> visited(101, 0);
	q.push(st);
	visited[st] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < arr[now].size(); i++) {
			if (visited[arr[now][i]] == 0) {
				visited[arr[now][i]] = 1;
				q.push(arr[now][i]);
				results[st]++;
				results[arr[now][i]]++;
			}
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	std::cin >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		std::cin >> a >> b;
		arr[a].push_back(b);
	}

	for (int i = 1; i <= N; i++) {
		bfs(i);
	}

	for (int i = 1; i <= N; i++) {
		std::cout << N - results[i] << "\n";
	}

	return 0;
}