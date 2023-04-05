#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, n, cnt, flag;
vector<int>arrow(100001);
vector<int>visited(100001);

void dfs(int now, int st, int lv) {
	if (now == arrow[now]) {
		flag = 1;
		cnt -= 1;
		return;
	}
	if (arrow[now] == st) {
		cnt -= lv;
		flag = 1;
		return;
	}
	if (visited[arrow[now]] == 0) {
		visited[arrow[now]] = 1;
		dfs(arrow[now], st, lv + 1);
		if (flag == 0) {
			visited[arrow[now]] = 0;
		}
	}
}

int main()
{
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> n;
		cnt = n;

		for (int i = 1; i <= n; i++) {
			cin >> arrow[i];
			visited[i] = 0;
		}

		for (int i = 1; i <= n; i++) {
			if (visited[i] == 0) {
				visited[i] = 1;
				flag = 0;
				dfs(i, i, 1);
			}
		}

		cout << cnt << "\n";
	}

	return 0;
}