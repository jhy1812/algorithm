#include <iostream>

int main()
{
	int n, cnt;
	cnt = 0;

	std::cin >> n;

	for (int i = 0; i < 5; i++) {
		int tmp;
		std::cin >> tmp;
		if (n == tmp) {
			cnt += 1;
		}
	}

	std::cout << cnt;

	return 0;
}