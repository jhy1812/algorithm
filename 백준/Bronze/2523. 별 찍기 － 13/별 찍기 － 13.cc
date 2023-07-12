#include <iostream>
#include <algorithm>

int N;

int main()
{
	std::cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			std::cout << '*';
		}
		std::cout << "\n";
	}

	for (int i = N - 1; i >= 1; i--) {
		for (int j = i; j >= 1; j--) {
			std::cout << '*';
		}
		std::cout << "\n";
	}

	return 0;
}