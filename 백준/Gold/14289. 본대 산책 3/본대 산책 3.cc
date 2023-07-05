#include <iostream>
#include <algorithm>
#include <vector>

#define MOD 1000000007

int n, m, D;

std::vector<std::vector<long long>> mat_mul(std::vector<std::vector<long long>> a1, std::vector<std::vector<long long>> a2) {
	std::vector<std::vector<long long>> a3(n, std::vector<long long>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			long long tmp = 0;
			for (int k = 0; k < n; k++) {
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
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n >> m;

	std::vector<std::vector<long long>> result(n, std::vector<long long>(n, 0));
	std::vector<std::vector<long long>> mat(n, std::vector<long long>(n, 0));

	for (int i = 0; i < m; i++) {
		int a, b;
		std::cin >> a >> b;
		mat[a - 1][b - 1] = 1;
		mat[b - 1][a - 1] = 1;
	}

	std::cin >> D;

	for (int i = 0; i < n; i++) {
		result[i][i] = 1;
	}

	while (D > 0) {
		if (D % 2) {
			result = mat_mul(result, mat);
		}
		D = D / 2;
		mat = mat_mul(mat, mat);
	}

	std::cout << result[0][0];

	return 0;
}