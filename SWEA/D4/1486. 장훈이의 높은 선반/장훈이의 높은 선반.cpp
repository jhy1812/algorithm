#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int T, N, B, S, summ, opti;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> B;
		S = 0;
		int kiee[20] = { 0, };
		for (int i = 0; i < N; i++) {
			cin >> kiee[i];
			S += kiee[i];
		}
		opti = 300000;
		for (int i = 0; i < 1 << N; i++) {
			summ = 0;
			for (int j = 0; j < N; j++) {
				if (i & 1 << j) {
					summ += kiee[j];
				}
			}
			if (summ == B) {
				opti = summ;
				break;
			}
			if (summ > B && (summ - B) < (opti - B)) {
				opti = summ;
			}
		}
		cout << "#" << tc << " " << opti-B << "\n";
	}
}