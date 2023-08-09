#include <iostream>

int N, result;

int main()
{
	std::cin >> N;

	while (true) {
		int i = 1;
		while (true) {
			if (i > N) {
				break;
			}
			N -= i;
			i++;
			result++;
		}
		if (N <= 0) {
			break;
		}
	}

	std::cout << result;

	return 0;
}