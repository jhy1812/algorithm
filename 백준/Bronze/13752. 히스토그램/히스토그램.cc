#include <iostream>

int n;

int main()
{
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp;
		std::cin >> tmp;
		for (int j = 0; j < tmp; j++) {
			std::cout << "=";
		}
		std::cout << "\n";
	}
	return 0;
}