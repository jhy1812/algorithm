#include <iostream>
#include <string>

int T;

int main()
{
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		std::string tmp;
		std::cin >> tmp;
		std::cout << (tmp[0] - '0') + (tmp[2] - '0') << "\n";
	}

	return 0;
}