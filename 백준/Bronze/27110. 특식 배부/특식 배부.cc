#include <iostream>
#include <algorithm>

int N, a, b, c, result;

int main()
{
	std::cin >> N;

	std::cin >> a >> b >> c;

	result += std::min(N, a) + std::min(N, b) + std::min(N, c);

	std::cout << result;

	return 0;
}