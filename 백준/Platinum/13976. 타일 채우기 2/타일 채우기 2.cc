#include <iostream>
#include <algorithm>
#include <vector>

#define MOD 1000000007

long long N;
std::vector<std::vector<long long>> result(2, std::vector<long long>(2));  
std::vector<std::vector<long long>> mat(2, std::vector<long long>(2));

std::vector<std::vector<long long>> mat_mul(std::vector<std::vector<long long>> a1, std::vector<std::vector<long long>> a2) {
	std::vector<std::vector<long long>> a3(2, std::vector<long long>(2, 0));
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			long long tmp = 0;
			for (int k = 0; k < 2; k++) {
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
	std::cin >> N;
	result = { {11, 3}, {3, 1} };
	mat = { {4, 1}, {-1, 0} };
	if (N % 2 == 0) {
		N = N / 2;
		while (N > 0) {
			if (N % 2) {
				result = mat_mul(result, mat);
			}
			N /= 2;
			mat = mat_mul(mat, mat);
		}
		if (result[1][1] < 0) {
			std::cout << MOD + result[1][1];
		}
		else {
			std::cout << result[1][1];
		}
	}
	else {
		std::cout << 0;
	}

	return 0;
}