#include <iostream>
#include <cmath>

int N;
long long result;

int main()
{
	std::cin >> N;

	for (int i = 2; i <= N; i++) {
		int lim = int(sqrt(i)) + 1;
		int tmp = i;
		int tmp_result = i;
		for (int j = 2; j <= lim; j++) {
			if (tmp % j == 0) {
				while (true) {
					if (tmp % j != 0) {
						break;
					}
					tmp = tmp / j;
				}
				tmp_result = tmp_result / j;
				tmp_result *= (j - 1);
			}
		}
		if (tmp != 1) {
			tmp_result = tmp_result / tmp;
			tmp_result *= (tmp - 1);
		}
		result += tmp_result;
	}

	std::cout << result;

	return 0;
}