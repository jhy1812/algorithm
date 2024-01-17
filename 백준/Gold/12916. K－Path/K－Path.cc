#include <iostream>
#include <algorithm>
#include <vector>

#define MOD 1000000007;

int N, K, ret;
std::vector<std::vector<long long>> result;
std::vector<std::vector<long long>> arr;

std::vector<std::vector<long long>> mat_mul(std::vector<std::vector<long long>> a1, std::vector<std::vector<long long>> a2) {
	std::vector<std::vector<long long>> a3(N, std::vector<long long>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			long long tmp = 0;
			for (int k = 0; k < N; k++) {
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

	std::cin >> N >> K;

	for (int i = 0; i < N; i++) {
		arr.push_back({});
		result.push_back({});
		for (int j = 0; j < N; j++) {
			long long tmp;
			std::cin >> tmp;
			arr[i].push_back(tmp);
			result[i].push_back(0);
		}
		result[i][i] = 1;
	}

	while (K > 0) {
		if (K % 2) {
			result = mat_mul(result, arr);
		}
		K /= 2;
		arr = mat_mul(arr, arr);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ret += result[i][j];
			ret %= MOD;
		}
	}

	std::cout << ret;

	return 0;
}