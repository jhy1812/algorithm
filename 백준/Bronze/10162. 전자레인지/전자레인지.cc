#include <iostream>
#include <vector>
#include <algorithm>

int T;
int btn[3] = { 300, 60, 10 };
int result[3];

int main()
{
	std::cin >> T;

	for (int i = 0; i < 3; i++) {
		result[i] += T / btn[i];
		T = T % btn[i];
	}

	if (T == 0) {
		for (int i = 0; i < 3; i++) {
			std::cout << result[i] << " ";
		}
	}
	else {
		std::cout << -1;
	}

	return 0;
}