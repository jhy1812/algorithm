#include <iostream>
#include <vector>

#define MOD 1000000007

long long D;
std::vector<std::vector<long long>> path(8, std::vector<long long>(8));
std::vector<std::vector<long long>> result(8, std::vector<long long>(8));

std::vector<std::vector<long long>> mat_mul(std::vector<std::vector<long long>> a1, std::vector<std::vector<long long>> a2) {
	std::vector<std::vector<long long>> a3(8, std::vector<long long>(8));
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			long long tmp = 0;
			for (int k = 0; k < 8; k++) {
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
	std::cin >> D;

		
	path = {{0, 1, 1, 0, 0, 0, 0, 0},
			{1, 0, 1, 1, 0, 0, 0, 0},
			{1, 1, 0, 1, 1, 0, 0, 0},
			{0, 1, 1, 0, 1, 1, 0, 0},
			{0, 0, 1, 1, 0, 1, 1, 0},
			{0, 0, 0, 1, 1, 0, 0, 1},
			{0, 0, 0, 0, 1, 0, 0, 1},
			{0, 0, 0, 0, 0, 1, 1, 0} };

	for (int i = 0; i < 8; i++) {
		result[i][i] = 1;
	}

	while (D > 0) {
		if (D % 2) {
			result = mat_mul(result, path);
		}
		D = D / 2;
		path = mat_mul(path, path);
	}

	std::cout << result[0][0];

	return 0;
}