#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

int N;
int arr[1000001];
std::vector<int>result(1);
std::vector<int>check;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	for (int i = 1; i <= N; i++) {
		int tmp;
		std::cin >> tmp;
		result.push_back(0);
		check.push_back(tmp);
		arr[tmp] = i;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 2 * check[i]; j <= 1000000; j+=check[i]) {
			if (arr[j] != 0) {
				result[i + 1] += 1;
				result[arr[j]] -= 1;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		std::cout << result[i] << " ";
	}

	return 0;
}