#include <iostream>
#include <vector>

#define MOD 1000000007

long long n;
std::vector<std::vector<long long>> mat(2, std::vector<long long>(2));
std::vector<std::vector<long long>> result(2, std::vector<long long>(2));

std::vector<std::vector<long long>> mat_mul(std::vector<std::vector<long long>> a1, std::vector<std::vector<long long>> a2) {
	std::vector<std::vector<long long>> a3(2, std::vector<long long>(2, 0));
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			long long tmp = 0;
			for (int k = 0; k < 2; k++) {
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
	std::cin >> n;

	mat = { {1, 1}, {1, 0} };
	result = { {1, 0}, {0, 1} };

	if (n%2 == 0) {
		n -= 1;
	}

	while (n > 0) {
		if (n % 2) {
			result = mat_mul(result, mat);
		}
		n = n / 2;
		mat = mat_mul(mat, mat);
	}

	std::cout << result[0][0];

	return 0;
}