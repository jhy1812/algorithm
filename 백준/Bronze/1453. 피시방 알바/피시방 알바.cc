#include <iostream>
#include <algorithm>

int n, result;
int arr[101];

int main()
{
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp;
		std::cin >> tmp;
		if (arr[tmp] == 1) {
			result++;
		}
		else {
			arr[tmp] = 1;
		}
	}

	std::cout << result;

	return 0;
}