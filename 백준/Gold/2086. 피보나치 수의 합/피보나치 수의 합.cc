#include <iostream>
#include <algorithm>
#include <vector>

#define MOD 1000000000;

long long a, b;
std::vector<std::vector<long long>>result(2, std::vector<long long>(2));
std::vector<std::vector<long long>>mat(2, std::vector<long long>(2));

std::vector<std::vector<long long>> mat_mul(std::vector<std::vector<long long>> a1, std::vector<std::vector<long long>> a2) {
	std::vector<std::vector<long long>> a3(2, std::vector<long long>(2, 0));
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			long long tmp = 0;
			for (int k = 0; k < 2; k++) {
				a1[i][k] = a1[i][k] % MOD;
				a2[i][k] = a2[i][k] % MOD;
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
	std::cin >> a >> b;

	b += 1;

	long long r1, r2;

	result[0][0] = 1;
	result[1][1] = 1;

	mat[0][0] = 1;
	mat[0][1] = 1;
	mat[1][0] = 1;

	while (a > 0) {
		if (a % 2 == 1) {
			result = mat_mul(result, mat);
		}
		a = a / 2;
		mat = mat_mul(mat, mat);
	}

	r1 = result[0][0];

	result[0][0] = 1;
	result[0][1] = 0;
	result[1][0] = 0;
	result[1][1] = 1;

	mat[0][0] = 1;
	mat[0][1] = 1;
	mat[1][0] = 1;
	mat[1][1] = 0;

	while (b > 0) {
		if (b % 2 == 1) {
			result = mat_mul(result, mat);
		}
		b = b / 2;
		mat = mat_mul(mat, mat);
	}

	r2 = result[0][0];

	if (r2 < r1) {
		r2 += MOD;
	}

	std::cout << (r2 - r1) % MOD;

	return 0;
}