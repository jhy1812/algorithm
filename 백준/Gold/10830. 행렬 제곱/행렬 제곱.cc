#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define MOD 1000

long long N, B;
std::vector<std::vector<long long>>mat(5, std::vector<long long>(5));
std::vector<std::vector<long long>>result(5, std::vector<long long>(5));

std::vector<std::vector<long long>> mat_mul(std::vector<std::vector<long long>> a1, std::vector<std::vector<long long>> a2) {
	std::vector<std::vector<long long>>a3(5, std::vector<long long>(5));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			long long tmp = 0;
			for (int k = 0; k < N; k++) {
				tmp += (a1[i][k] * a2[k][j]) % MOD;
			}
			a3[i][j] = tmp % MOD;
		}
	}
	return a3;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> B;

	for (int i = 0; i < N; i++) {
		result[i][i] = 1;
		for (int j = 0; j < N; j++) {
			int tmp;
			std::cin >> tmp;
			mat[i][j] = tmp;
		}
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
			std::cout << result[i][j] % MOD << " ";
		}
		std::cout << "\n";
	}

	return 0;
}