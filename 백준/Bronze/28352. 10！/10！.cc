#include <iostream>

long long N, result;

int main()
{
	std::cin >> N;

	result = 6;

	for (int i = 11; i <= N; i++) {
		result *= i;
	}

	std::cout << result;

	return 0;
}