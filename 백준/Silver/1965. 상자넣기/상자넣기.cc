#include <iostream>
#include <algorithm>
#include <vector>

int n;
std::vector<int> arr;
std::vector<int> result;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp;
		std::cin >> tmp;
		arr.push_back(tmp);
	}

	for (int i = 0; i < n; i++) {
		if (result.empty()) {
			result.push_back(arr[i]);
		}
		else if (result.back() < arr[i]) {
			result.push_back(arr[i]);
		}
		else if (result.back() > arr[i]) {
			int idx = std::lower_bound(result.begin(), result.end(), arr[i]) - result.begin();
			result[idx] = arr[i];
		}
	}

	std::cout << result.size();

	return 0;
}