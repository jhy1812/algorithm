#include <iostream>

int N;
long long result = 1;

int main()
{
	std::cin >> N;

	for (int i = 2; i <= N; i++) {
		result *= i;
	}

	std::cout << result;

	return 0;
}