#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>

int N, result;
std::vector<std::pair<int, int>>arr;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		std::cin >> tmp;
		arr.push_back(std::make_pair(tmp, i));
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; i++) {
		if (result < arr[i].second - i) {
			result = arr[i].second - i;
		}
	}

	std::cout << result + 1;

	return 0;
}