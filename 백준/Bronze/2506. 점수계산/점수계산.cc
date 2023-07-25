#include <iostream>

int N, result, score;

int main()
{
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		std::cin >> tmp;
		if (tmp == 0) {
			score = 0;
		}
		else {
			score++;
			result += score;
		}
	}
	
	std::cout << result;
	
	return 0;
}