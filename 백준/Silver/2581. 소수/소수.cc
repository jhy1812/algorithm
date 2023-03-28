#include <iostream>
#include <string>
using namespace std;

int main()
{
	int M, N, cnt, summ, flag, minn;
	cin >> M;
	cin >> N;
	summ = 0;
	minn = 100000;
	for (int i = M; i <= N; i++) {
		cnt = 0;
		flag = 0;
		for (int j = 1; j <= (i / 2); j++) {
			if (i % j == 0) {
				cnt += 1;
			}

			if (cnt >= 2) {
				flag = 1;
				break;
			}
		}
		if (cnt <= 1 && i != 1) {
			summ += i;
			if (minn > i) {
				minn = i;
			}
		}
	}
	if (summ == 0) {
		cout << -1;
	}
	else {
		cout << summ << "\n" << minn;
	}
}