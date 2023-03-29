#include <iostream>
#include <algorithm>

using namespace std;

int kill(int y, int x, int arr[][15], int M) {
	int summ = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			summ += arr[y + i][x + j];
		}
	}
	return summ;
}

int main()
{
	int T, N, M, summ, maxx;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M;
		maxx = 0;
		summ = 0;
		int mapp[15][15] = { 0, };
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> mapp[i][j];
			}
		}
		for (int i = 0; i < N - M + 1; i++) {
			for (int j = 0; j < N - M + 1; j++) {
				summ = kill(i, j, mapp, M);
				if (maxx < summ) {
					maxx = summ;
				}
			}
		}
		cout << "#" << tc << " " << maxx << "\n";
	}
}

