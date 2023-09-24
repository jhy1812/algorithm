#include <iostream>
#include <algorithm>
#include <vector>

int N;
std::vector<int> arr(10001);

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		std::cin >> tmp;
		arr[tmp]++;
	}

	for (int i = 1; i <= 10000; i++) {
		for (int j = 1; j <= arr[i]; j++) {
			std::cout << i << "\n";
		}
	}

	return 0;
}