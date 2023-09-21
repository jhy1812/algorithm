#include <iostream>
#include <algorithm>

int M, N, summ, minn;

int main()
{
	std::cin >> M;
	std::cin >> N;

	for (int i = 100; i >= 1; i--) {
		if (M <= i * i && i * i <= N) {
			summ += i * i;
			minn = i * i;
		}
	}

	if (summ == 0) {
		std::cout << -1;
	}
	else {
		std::cout << summ << "\n";
		std::cout << minn;
	}

	return 0;
}