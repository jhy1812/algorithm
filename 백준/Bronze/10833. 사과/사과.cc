#include <iostream>

int N, result;

int main()
{
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		int a, b;
		std::cin >> a >> b;
		result += b % a;
	}

	std::cout << result;

	return 0;
}