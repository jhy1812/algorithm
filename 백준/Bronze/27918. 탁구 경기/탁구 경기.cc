#include <iostream>
#include <algorithm>

int N, d, p, flag;

int main()
{
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		char tmp;
		std::cin >> tmp;
		if (tmp == 'D' && flag == 0) {
			d++;
		}
		else if (tmp == 'P' && flag == 0) {
			p++;
		}
		if (d - p == 2 || p - d == 2) {
			flag = 1;
		}
	}

	std::cout << d << ":" << p;

	return 0;
}