#include <iostream>
#include <algorithm>
#include <vector>

int N, K;
std::vector<int> arr;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> K;

	arr.resize(N + 1, 0);

	for (int i = 0; i < K; i++) {
		int I, T;
		std::cin >> I >> T;
		for (int j = arr.size() - 1; j >= 0; j--) {
			if (arr[j] != 0 || j == 0) {
				if (j + T <= N) {
					arr[j + T] = std::max(arr[j + T], arr[j] + I);
				}
			}
		}
	}

	int result = 0;

	for (int i = 0; i < arr.size(); i++) {
		result = std::max(result, arr[i]);
	}

	std::cout << result;

	return 0;
}