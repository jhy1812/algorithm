#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int M, N;
int arr[1000001];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> M >> N;

	arr[1] = 1;

	for (int i = 2; i < sqrt(N) + 1; i++) {
		if (arr[i] == 1) {
			continue;
		}
		for (int j = 2 * i; j <= N; j += i) {
			arr[j] = 1;
		}
	}

	for (int i = M; i <= N; i++) {
		if (arr[i] == 0) {
			std::cout << i << "\n";
		}
	}

	return 0;
}