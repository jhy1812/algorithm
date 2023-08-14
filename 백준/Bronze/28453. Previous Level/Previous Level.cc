#include <iostream>

int N;

int main()
{
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		std::cin >> tmp;
		if (tmp == 300) {
			std::cout << 1 << " ";
		}
		else if (tmp >= 275) {
			std::cout << 2 << " ";
		}
		else if (tmp >= 250) {
			std::cout << 3 << " ";
		}
		else {
			std::cout << 4 << " ";
		}
	}

	return 0;
}