#include <iostream>
#include <algorithm>
#include <vector>

#define INF 100000000

int N;


std::vector<std::vector<int>> mat_mul(std::vector<std::vector<int>> a1, std::vector<std::vector<int>> a2) {
	std::vector<std::vector<int>> a3(N, std::vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp = 0;
			for (int k = 0; k < N; k++) {
				tmp += (a1[i][k] * a2[k][j]);
			}
			a3[i][j] = tmp;
		}
	}
	return a3;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	std::vector<std::vector<int>> arr(N, std::vector<int>(N, 0));
	std::vector<std::vector<int>> result(N, std::vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp;
			std::cin >> tmp;
			if (tmp == 0) {
				arr[i][j] = INF;
			}
			else {
				arr[i][j] = tmp;
			}
		}
	}
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				arr[i][j] = std::min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}
	

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == INF) {
				std::cout << 0 << " ";
			}
			else {
				std::cout << 1 << " ";
			}
		}
		std::cout << "\n";
	}

	return 0;
}