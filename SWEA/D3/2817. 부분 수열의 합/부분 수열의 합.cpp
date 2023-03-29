#include <iostream>

using namespace std;

int T, N, K, cnt;
int arr[20];

void dfs(int st, int summ) {
	if (summ > K) {
		return;
	}
	if (summ == K) {
		cnt += 1;
		return;
	}
	if (st >= N) {
		return;
	}
	for (int i = st; i < N; i++) {
		dfs(i + 1, summ + arr[i]);
	}
}

int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> K;
		cnt = 0;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		dfs(0, 0);
		cout << "#" << tc << " " << cnt << "\n";
	}
	return 0;
}