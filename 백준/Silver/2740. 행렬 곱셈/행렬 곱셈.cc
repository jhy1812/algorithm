#include <iostream>
#include <vector>

int N, M, K;
std::vector<std::vector<int>> A(100, std::vector<int>(100));
std::vector<std::vector<int>> B(100, std::vector<int>(100));
std::vector<std::vector<int>> result(100, std::vector<int>(100));

std::vector<std::vector<int>> mat_mul(std::vector<std::vector<int>> a1, std::vector<std::vector<int>> a2) {
	std::vector<std::vector<int>> a3(N, std::vector<int>(K, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			int tmp = 0;
			for (int k = 0; k < M; k++) {
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

	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int tmp;
			std::cin >> tmp;
			A[i][j] = tmp;
		}
	}

	std::cin >> M >> K;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			int tmp;
			std::cin >> tmp;
			B[i][j] = tmp;
		}
	}

	result = mat_mul(A, B);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			std::cout << result[i][j] << " ";
		}
		std::cout << "\n";
	}

	return 0;
}