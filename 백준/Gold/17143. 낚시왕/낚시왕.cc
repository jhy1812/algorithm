#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int R, C, M, r, c, s, d, z, summ;

int main()
{
	cin >> R >> C >> M;
	
	vector<int>qgi(M + 1);
	vector<pair<int, int>>v(M + 1);
	vector<pair<int, int>>spot(M + 1);
	vector<vector<int>>mapp(R + 1, vector<int>(C + 1));

	for (int i = 1; i < M + 1; i++) {
		cin >> r >> c >> s >> d >> z;
		mapp[r][c] = i;
		qgi[i] = z;
		if (d == 1 || d == 2) {
			s = s % (2 * R - 2);
		}
		else {
			s = s % (2 * C - 2);
		}
		v[i] = make_pair(s, d);
		spot[i] = make_pair(r, c);
	}

	for (int i = 1; i <= C; i++) {
		for (int j = 1; j <= R; j++) {
			if (mapp[j][i] > 0) {
				summ += qgi[mapp[j][i]];
				spot[mapp[j][i]].first = -1;
				mapp[j][i] = 0;
				break;
			}
		}
		
		for (int j = 1; j<M+1; j++) {
			if (spot[j].first == -1) {
				continue;
			}
			if (mapp[spot[j].first][spot[j].second] == j) {
				mapp[spot[j].first][spot[j].second] = 0;
			}
			if (v[j].second == 1) {
				spot[j].first -= v[j].first;
				if (spot[j].first < 1) {
					spot[j].first = -(spot[j].first - 2);
					v[j].second = 2;
					if (spot[j].first > R) {
						spot[j].first = R - (spot[j].first - R);
						v[j].second = 1;
					}
				}
			}
			else if (v[j].second == 2) {
				spot[j].first += v[j].first;
				if (spot[j].first > R) {
					spot[j].first = R - (spot[j].first - R);
					v[j].second = 1;
					if (spot[j].first < 1) {
						spot[j].first = -(spot[j].first - 2);
						v[j].second = 2;
					}
				}
			}
			else if (v[j].second == 3) {
				spot[j].second += v[j].first;
				if (spot[j].second > C) {
					spot[j].second = C - (spot[j].second - C);
					v[j].second = 4;
					if (spot[j].second < 1) {
						spot[j].second = -(spot[j].second - 2);
						v[j].second = 3;
					}
				}
			}
			else if (v[j].second == 4) {
				spot[j].second -= v[j].first;
				if (spot[j].second < 1) {
					spot[j].second = -(spot[j].second - 2);
					v[j].second = 3;
					if (spot[j].second > C) {
						spot[j].second = C - (spot[j].second - C);
						v[j].second = 4;
					}
				}
			}
			if (mapp[spot[j].first][spot[j].second] == 0 || mapp[spot[j].first][spot[j].second] >= j) {
				mapp[spot[j].first][spot[j].second] = j;
			}
			else {
				if (qgi[mapp[spot[j].first][spot[j].second]] < qgi[j]) {
					spot[mapp[spot[j].first][spot[j].second]].first = -1;
					mapp[spot[j].first][spot[j].second] = j;
				}
				else {
					spot[j].first = -1;
				}
			}

		}
	}

	cout << summ;

	return 0;
}