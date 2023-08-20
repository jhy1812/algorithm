#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<int> arr;

int main()
{
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		std::cin >> tmp;
		arr.push_back(tmp);
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; i++) {
		std::cout << arr[i] << "\n";
	}

	return 0;
}