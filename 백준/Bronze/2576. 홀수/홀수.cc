#include <iostream>
#include <algorithm>

int summ, minn;

int main()
{
	minn = 1000;

	for (int i = 0; i < 7; i++) {
		int tmp;
		std::cin >> tmp;
		if (tmp % 2 == 1) {
			summ += tmp;
			if (tmp < minn) {
				minn = tmp;
			}
		}
	}

	if (summ == 0) {
		std::cout << -1;
	}
	else {
		std::cout << summ << "\n" << minn;
	}

	return 0;
}