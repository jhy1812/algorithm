#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define MOD 1000;

long long N, B;
std::vector<std::vector<long long>>mat;

std::vector<std::vector<long long>> mat_mul(std::vector<std::vector<long long>> a1, std::vector<std::vector<long long>> a2) {
	std::vector<std::vector<long long >>a3(2 * N, std::vector<long long>(2 * N, 0));
	for (int i = 0; i < 2 * N; i++) {
		for (int j = 0; j < 2 * N; j++) {
			long long tmp = 0;
			for (int k = 0; k < 2 * N; k++) {
				tmp += (a1[i][k] * a2[k][j]) % MOD;
				tmp = tmp % MOD;
			}
			a3[i][j] = tmp;
		}
	}

	return a3;
}

int main()
{
	std::cin >> N >> B;

	for (int i = 0; i < 2 * N; i++) {
		mat.push_back({});
		for (int j = 0; j < 2 * N; j++) {
			mat[i].push_back(0);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			long long tmp;
			std::cin >> tmp;
			mat[i][j] = tmp;
			mat[N + i][j] = tmp;
		}
		mat[N + i][N + i] = 1;
	}

	std::vector<std::vector<long long>>result(2 * N, std::vector<long long>(2 * N, 0));

	for (int i = 0; i < 2 * N; i++) {
		result[i][i] = 1;
	}

	while (B > 0) {
		if (B % 2 == 1) {
			result = mat_mul(result, mat);
		}
		B = B / 2;
		mat = mat_mul(mat, mat);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cout << result[N + i][j] << " ";
		}
		std::cout << "\n";
	}

	return 0;
}