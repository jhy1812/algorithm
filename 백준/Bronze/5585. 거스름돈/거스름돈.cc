#include <iostream>
#include <vector>
#include <algorithm>

int N, result;
int coin[6] = { 500, 100, 50, 10, 5, 1 };

int main()
{
	std::cin >> N;

	N = 1000 - N;

	for (int i = 0; i < 6; i++) {
		if (N == 0) {
			break;
		}
		result += N / coin[i];
		N = N % coin[i];
	}

	std::cout << result;

	return 0;
}