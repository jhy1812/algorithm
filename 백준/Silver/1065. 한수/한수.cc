#include <iostream>
#include <algorithm>
#include <cmath>

int N, cnt;

int main()
{
	std::cin >> N;

	for (int i = 1; i <= N; i++) {
		if (i / 100 == 0) {
			cnt += 1;
		}
		else if (i / 1000 == 0) {
			int tmp;
			tmp = i;
			int j3 = tmp / 100;
			tmp -= j3 * 100;
			int j2 = tmp / 10;
			tmp -= j2 * 10;
			int j1 = tmp;
			if (j3 - j2 == j2 - j1) {
				cnt += 1;
			}
		}
	}

	std::cout << cnt;

	return 0;
}