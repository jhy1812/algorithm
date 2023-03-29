#include <iostream>

using namespace std;

int N, cnt, maxx, flag;
int visited[101];
int arr[101];

void dfs(int now, int st, int lv) {
	visited[now] = 1;
	if (visited[arr[now]] == 1 && flag == 0) {
		if (arr[now] == st) {
			maxx += lv;
			flag = 1;
			return;
		}
		visited[now] = 0;
		return;
	}
	
	dfs(arr[now], st, lv+1);
	if (flag == 0) {
		visited[now] = 0;
		return;
	}
	
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= N; i++) {
		cnt = 0;
		if (i == arr[i]) {
			maxx += 1;
			visited[i] = 1;
			continue;
		}
		if (visited[i] == 0) {
			flag = 0;
			dfs(i, i, 1);
		}

	}
	cout << maxx << "\n";
	for (int i = 1; i <= N; i++) {
		if (maxx == 1 && visited[i] == 1) {
			cout << i;
			break;
		}
		else if (visited [i] == 1) {
			cout << i << "\n";
			maxx -= 1;
		}
	}
	return 0;
}