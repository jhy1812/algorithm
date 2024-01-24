#include <iostream>
#include <algorithm>
#include <vector>

long long N;
std::vector<long long> result(10, 0);

int main()
{
	std::cin >> N;

	long long mod = 1;

	while (true) {

		if (N / mod == 0) {
			break;
		}

		for (long long i = 1; i < 10; i++) {
			result[i] += (N / (mod * 10)) * mod;
		}

		for (long long i = 1; i <= (N / mod) % 10; i++) {
			if (i == (N / mod) % 10) {
				result[i] += N % mod + 1;
			}
			else {
				result[i] += mod;
			}
		}

		if ((N / mod) % 10 == 0) {
			if (N / (mod * 10) > 0) {
				result[0] += (N / (mod * 10) - 1) * mod;
			}
			result[0] += N % mod + 1;
		}
		else {
			result[0] += (N / (mod * 10)) * mod;

		}

		mod *= 10;
	}

	for (int i = 0; i < 10; i++) {
		std::cout << result[i] << " ";
	}

	return 0;
}