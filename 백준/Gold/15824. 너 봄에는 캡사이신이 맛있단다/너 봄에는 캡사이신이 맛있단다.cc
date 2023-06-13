#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define MOD 1000000007

long long N;
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

	for (int i = 0; i < N; i++) {
		long long tmp = 1;
		long long mull = 2;
		int pp = i;
		int pm = N - i - 1;
		while (pp > 0) {
			if (pp % 2 == 1) {
				tmp = (tmp * mull) % MOD;
			}
			pp = pp / 2;
			mull = (mull * mull) % MOD;
		}
		tmp -= 1;
		mull = 2;
		long long ttmp = 1;
		while (pm > 0) {
			if (pm % 2 == 1) {
				ttmp = (ttmp * mull) % MOD;
			}
			pm = pm / 2;
			mull = (mull * mull) % MOD;
		}
		ttmp -= 1;
		tmp = (tmp - ttmp) % MOD;
		if (tmp < 0) {
			tmp += MOD;
		}
		result += (arr[i] * tmp) % MOD;
		result = result % MOD;
	}

	std::cout << result;

	return 0;
}