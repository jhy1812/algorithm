#include <iostream>

using namespace std;

int T, minn;
int cost[4];
int sce[12];

void dfs(int st, int summ) {
	if (st >= 12) {
		if (minn > summ) {
			minn = summ;
		}
		return;
	}
	if (sce[st] == 0) {
		dfs(st + 1, summ);
	}
	else {
		for (int i = 0; i < 3; i++) {
			if (i == 0) {
				dfs(st + 1, summ + sce[st] * cost[i]);
			}
			else if (i == 1) {
				dfs(st + 1, summ + cost[i]);
			}
			else {
				dfs(st + 3, summ + cost[i]);
			}
		}
	}
	
}

int main()
{
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		minn = 1e8;
		for (int i = 0; i < 4; i++) {
			cin >> cost[i];
		}
		for (int i = 0; i < 12; i++) {
			cin >> sce[i];
		}
		dfs(0, 0);
		if (minn > cost[3]) {
			cout << "#" << tc << " " << cost[3] << "\n";
		}
		else {
			cout << "#" << tc << " " << minn << "\n";
		}

	}
	return 0;
}