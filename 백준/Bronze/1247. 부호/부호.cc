#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

int N, of;
long long summ;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	for (int tc = 0; tc < 3; tc++) {
		summ = 0;
		of = 0;
		std::cin >> N;


		for (int i = 0; i < N; i++) {
			long long tmp;
			std::cin >> tmp;
			if (summ > 0 && tmp > 0 && summ > LLONG_MAX - tmp) {
				of++;
				summ += tmp;
			}
			else if (summ < 0 && tmp < 0 && summ < LLONG_MIN - tmp) {
				of--;
				summ += tmp;
			}
			else {
				summ += tmp;
			}
		}
		if (of > 0) {
			std::cout << "+" << "\n";
		}
		else if (of < 0) {
			std::cout << "-" << "\n";
		}
		else if (summ < 0) {
			std::cout << "-" << "\n";
		}
		else if (summ > 0) {
			std::cout << "+" << "\n";
		}
		else {
			std::cout << "0" << "\n";
		}
	}

	return 0;
}