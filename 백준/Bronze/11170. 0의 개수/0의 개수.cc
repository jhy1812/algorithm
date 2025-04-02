#include <iostream>
#include <algorithm>
#include <vector>

int T;
long long N, M;

int main()
{
	std::cin >> T;

	for (int tc = 1; tc <= T; tc++) {

		std::cin >> N >> M;
		N--;

		long long mod = 1;
		std::vector<long long> result1(10, 0);
		std::vector<long long> result2(10, 0);

		if (N >= 0) result1[0] = 1;

		result2[0] = 1;

		while (N >= 0) {

			if (N / mod == 0) {
				break;
			}

			for (long long i = 1; i < 10; i++) {
				result1[i] += (N / (mod * 10)) * mod;
			}

			for (long long i = 1; i <= (N / mod) % 10; i++) {
				if (i == (N / mod) % 10) {
					result1[i] += N % mod + 1;
				}
				else {
					result1[i] += mod;
				}
			}

			if ((N / mod) % 10 == 0) {
				if (N / (mod * 10) > 0) {
					result1[0] += (N / (mod * 10) - 1) * mod;
				}
				result1[0] += N % mod + 1;
			}
			else {
				result1[0] += (N / (mod * 10)) * mod;

			}

			mod *= 10;
		}

		mod = 1;

		while (M >= 0) {

			if (M / mod == 0) {
				break;
			}

			for (long long i = 1; i < 10; i++) {
				result2[i] += (M / (mod * 10)) * mod;
			}

			for (long long i = 1; i <= (M / mod) % 10; i++) {
				if (i == (M / mod) % 10) {
					result2[i] += M % mod + 1;
				}
				else {
					result2[i] += mod;
				}
			}

			if ((M / mod) % 10 == 0) {
				if (M / (mod * 10) > 0) {
					result2[0] += (M / (mod * 10) - 1) * mod;
				}
				result2[0] += M % mod + 1;
			}
			else {
				result2[0] += (M / (mod * 10)) * mod;

			}

			mod *= 10;
		}

		std::cout << result2[0]-result1[0] << "\n";
	}

	return 0;
}