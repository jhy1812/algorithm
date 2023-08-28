#include <iostream>
#include <algorithm>
#include <vector>
 
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0, 1, 0 };

int dyy[10][2] = { {0, 1}, {0, 0}, {1, 1}, {1, 2}, {0, 2}, {0, 1}, {0, 0}, {2, 1}, {3, 2}, {0, 1} };
int dxx[10][2] = { {1, 1}, {1, 1}, {2, 1}, {0, 0}, {0, 0}, {3, 1}, {3, 1}, {3, 1}, {0, 0}, {0, 0} };
int ds[9] = { 10, 7, 1, 2, 5, 10, 7, 1, 2 };

int N, result;
std::vector<std::vector<int>> mapp(500, std::vector<int>(500));

void bfs() {
	int cnt = 0;
	int r = N / 2;
	int c = N / 2;
	while (true) {
		for (int i = 0; i < cnt / 2 + 1; i++) {
			r += dy[cnt % 4];
			c += dx[cnt % 4];
			if (0 <= r && r < N && 0 <= c && c < N) {
				int summ = mapp[r][c];
				for (int j = 0; j < 10; j++) {
					int ny = r + dy[(cnt + dyy[j][0]) % 4] * dyy[j][1] + dy[(cnt + dxx[j][0]) % 4] * dxx[j][1];
					int nx = c + dx[(cnt + dyy[j][0]) % 4] * dyy[j][1] + dx[(cnt + dxx[j][0]) % 4] * dxx[j][1];
					int sand;
					if (j < 9) {
						sand = (mapp[r][c] * ds[j]) / 100;
						summ -= sand;
					}
					else {
						sand = summ;
					}
					if (0 <= ny && ny < N && 0 <= nx && nx < N) {
						mapp[ny][nx] += sand;
					}
					else {
						result += sand;
					}
				}
				mapp[r][c] = 0;
			}
			else {
				return;
			}
		}
		cnt++;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp;
			std::cin >> tmp;
			mapp[i][j] = tmp;
		}
	}

	bfs();

	std::cout << result;

	return 0;
}