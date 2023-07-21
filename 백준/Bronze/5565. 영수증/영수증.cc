#include <iostream>

int main()
{
	int summ = 0;
	
	std::cin >> summ;

	for (int i = 0; i < 9; i++) {
		int tmp;
		std::cin >> tmp;
		summ -= tmp;
	}

	std::cout << summ;

	return 0;
}