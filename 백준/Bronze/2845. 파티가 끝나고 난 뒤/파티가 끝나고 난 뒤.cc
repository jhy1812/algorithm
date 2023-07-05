#include <iostream>

int L, P;

int main()
{
	std::cin >> L >> P;

	for (int i = 0; i < 5; i++) {
		int tmp;
		std::cin >> tmp;
		std::cout << tmp - L * P << " ";
	}

	return 0;
}