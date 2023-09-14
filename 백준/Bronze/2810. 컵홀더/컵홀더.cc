#include <iostream>
#include <algorithm>
#include <string>

int N, result;
std::string seat;

int main()
{
	std::cin >> N;
	std::cin >> seat;

	int i = 0;

	while (true) {
		if (i >= N) {
			result++;
			break;
		}
		if (seat[i] == 'S') {
			i++;
		}
		else {
			i += 2;
		}
		result++;
	}

	if (N > result) {
		std::cout << result;
	}
	else {
		std::cout << N;
	}

	return 0;
}