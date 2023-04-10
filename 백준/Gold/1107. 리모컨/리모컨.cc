#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

int N, M, minn, cnt;
vector<int>btn(10);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int tmp;
		cin >> tmp;
		btn[tmp] += 1;
	}

	minn = 100 - N;
	minn = abs(minn);

	if (M == 10 || minn <= 1) {
		cout << minn;
	}
	else {
		int flag = 0;
		int small = N;
		int big = N;
		while (true) {
			if (flag == 1) {
				break;
			}
			int check = 100000;
			int sjari = 1;
			int bjari = 1;
			for (int i = 6; i>=1; i--){
				if (big / check >= 1 && bjari == 1) {
					bjari = i;
				}
				if (small / check >= 1) {
					sjari = i;
					break;
				}
				check = check / 10;
			}
			int scheck = int(pow(10, sjari - 1));
			int sflag = 0;
			int stmp = small;
			if (small >= 0) {
				for (int i = sjari - 1; i >= 0; i--) {
					if (btn[stmp / scheck] == 1) {
						sflag += 1;
						break;
					}
					stmp = stmp - (stmp / scheck) * scheck;
					scheck = scheck / 10;
				}
			}
			if (sflag == 0 && small >= 0) {
				int tmp = small - N;
				if (minn > sjari + abs(tmp)) {
					minn = sjari + abs(tmp);
				}
				break;
			}
			int bcheck = int(pow(10, bjari - 1));
			int bflag = 0;
			int btmp = big;
			for (int i = bjari - 1; i >= 0; i--) {
				if (btn[btmp / bcheck] == 1) {
					bflag += 1;
					break;
				}
				btmp = btmp - (btmp / bcheck) * bcheck;
				bcheck = bcheck / 10;
			}
			if (bflag == 0) {
				int tmp = big - N;
				if (minn > bjari + abs(tmp)) {
					minn = bjari + abs(tmp);
				}
				break;
			}
			big += 1;
			small -= 1;
		}
		cout << minn;
	}

	return 0;
}