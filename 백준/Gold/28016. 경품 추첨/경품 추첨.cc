#include <iostream>
#include <vector>
#include <algorithm>

int dy[3] = { 1, 1, 1 };
int dx[3] = { -1, 0, 1 };

int N, M, left, right, cnt, idx;
double maxx;
std::vector<std::vector<double>>result;
std::vector<std::vector<int>>arr;

void dfs(int x, int lv, double perc) {
	if (lv == N) {
		return;
	}
	if (arr[lv + 1][x] == 0) {

	}
}

int main()
{
	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		result.push_back({});
		arr.push_back({});
		for (int j = 0; j < M; j++) {
			int tmp;
			std::cin >> tmp;
			if (tmp == 2) {
				result[i].push_back(1);
			}
			else {
				result[i].push_back(0);
			}
			arr[i].push_back(tmp);
		}
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M; j++) {
			left = 0;
			right = 0;
			cnt = 0;
			if (result[i][j] > 0) {
				if (arr[i + 1][j] == 1) {
					if (arr[i + 1][j - 1] == 0 && arr[i][j - 1] == 0) {
						left = 1;
						cnt += 1;
					}
					if (arr[i + 1][j + 1] == 0 && arr[i][j + 1] == 0) {
						right = 1;
						cnt += 1;
					}
					if (left == 1) {
						result[i + 1][j - 1] += (double)(result[i][j] / 2);
					}
					if (right == 1) {
						result[i + 1][j + 1] += (double)(result[i][j] / 2);
					}
				}
				else {
					result[i + 1][j] += result[i][j];
				}
			}
		}
	}

	for (int i = 0; i < M; i++) {
		if (result[N - 1][i] > maxx) {
			maxx = result[N - 1][i];
			idx = i;
		}
	}

	if (maxx == 0) {
		std::cout << -1;
	}
	else {
		std::cout << idx;
	}

	return 0;
}