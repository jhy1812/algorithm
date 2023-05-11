#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int N;
std::vector<int>arr(1);

int main()
{
	std::cin >> N;

	for (int i = 1; i <= N; i++) {
		arr.push_back(i);
	}

	for (int i = 2; i<int(std::sqrt(N) + 1); i++) {
		for (int j = 2; j <= N; j++) {
			if (j - int(pow(i, 2)) >= 0) {
				arr[j] = std::min(arr[j], arr[j - int(pow(i, 2))] + 1);
			}
		}
	}

	std::cout << arr[N];

	return 0;
}