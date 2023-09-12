#include <iostream>
#include <vector>
#include <algorithm>

int N, K;
std::vector<int> arr;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int tmp;
		std::cin >> tmp;
		arr.push_back(tmp);
	}

	std::sort(arr.begin(), arr.end());

	std::cout << arr[K - 1];
	
	return 0;
}