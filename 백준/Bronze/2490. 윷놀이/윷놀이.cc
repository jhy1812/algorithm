#include <iostream>
#include <algorithm>

int main()
{
	for (int i = 0; i < 3; i++) {
		int u[2] = {0, 0};
		for (int j = 0; j < 4; j++) {
			int tmp;
			std::cin >> tmp;
			u[tmp]++;
		}
		if (u[0] == 0) {
			std::cout << "E" << "\n";
		}
		else if (u[0] == 1) {
			std::cout << "A" << "\n";
		}
		else if (u[0] == 2) {
			std::cout << "B" << "\n";
		}
		else if (u[0] == 3) {
			std::cout << "C" << "\n";
		}
		else {
			std::cout << "D" << "\n";
		}
	}

	return 0;
}