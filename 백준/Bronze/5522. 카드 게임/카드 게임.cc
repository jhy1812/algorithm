#include <iostream>

int main()
{
	int result = 0;
	
	for (int i = 0; i < 5; i++) {
		int tmp;
		std::cin >> tmp;
		result += tmp;
	}

	std::cout << result;

	return 0;
}