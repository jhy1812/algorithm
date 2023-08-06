#include <iostream>
#include <algorithm>
#include <vector>

#define MOD 998244353

int T;
std::vector<long long> result(3);
std::vector<std::vector<long long>> mat(3, std::vector<long long>(3));

std::vector<long long> mat_mul(std::vector<long long> a1, std::vector<std::vector<long long>> a2) {
	std::vector<long long> a3(3, 0);
	for (int i = 0; i < 3; i++) {
		long long tmp = 0;
		for (int j = 0; j < 3; j++) {
			tmp += (a1[j] * a2[j][i]) % MOD;
			tmp %= MOD;
		}
		a3[i] = tmp;
	}
	return a3;
}

std::vector<std::vector<long long>> mat_mul2(std::vector<std::vector<long long>> a1, std::vector<std::vector<long long>> a2) {
	std::vector<std::vector<long long>> a3(3, std::vector<long long>(3, 0));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			long long tmp = 0;
			for (int k = 0; k < 3; k++) {
				tmp += (a1[i][k] * a2[k][j]) % MOD;
				tmp %= MOD;
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

	std::cin >> T;

	for (int tc = 0; tc < T; tc++) {
		long long N;
		std::cin >> N;
		result = { 1, 1, 1 };
		mat = { {0, 1, 0}, {1, 0, 1}, {1, 0, 0} };
		N -= 1;
		while (N > 0) {
			if (N % 2) {
				result = mat_mul(result, mat);
			}
			N /= 2;
			mat = mat_mul2(mat, mat);
		}
		std::cout << result[2] << "\n";
	}

	return 0;
}