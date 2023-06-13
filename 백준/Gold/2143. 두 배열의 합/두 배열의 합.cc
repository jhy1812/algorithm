#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

int T, n, m;
long long result;
std::vector<int>arr1(1);
std::vector<int>arr2(1);
std::map<int, int>hap;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> T;
	std::cin >> n;

	for (int i = 1; i <= n; i++) {
		int tmp;
		std::cin >> tmp;
		arr1.push_back(arr1[i - 1] + tmp);
	}

	std::cin >> m;

	for (int i = 1; i <= m; i++) {
		int tmp;
		std::cin >> tmp;
		arr2.push_back(arr2[i - 1] + tmp);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			hap[arr1[i] - arr1[j]]++;
		}
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < i; j++) {
			result += hap[T - arr2[i] + arr2[j]];
		}
	}

	std::cout << result;

	return 0;
}