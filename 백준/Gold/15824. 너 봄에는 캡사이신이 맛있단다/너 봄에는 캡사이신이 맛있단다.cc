#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define MOD 1000000007

int N;
long long result;
std::vector<int>arr;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		std::cin >> tmp;
		arr.push_back(tmp);
	}

	sort(arr.begin(), arr.end());

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			int p = i - j - 1;
			long long cha = arr[i] - arr[j];
			long long mull = 2;
			while (p > 0) {
				if (p % 2 == 1) {
					cha = (cha * mull) % MOD;
				}
				p = p / 2;
				mull = (mull * mull) % MOD;
			}
			result = (result + cha) % MOD;
		}
	}

	std::cout << result;

	return 0;
}