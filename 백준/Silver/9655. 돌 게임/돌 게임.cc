#include <iostream>
#include <algorithm>
#include <vector>

int N;
std::vector<int> turns(1001, 0);

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	turns[1] = 1;
	turns[2] = -1;
	turns[3] = 1;
	turns[4] = -1;

	for (int i = 5; i <= N; i++) {
		turns[i] = turns[i - 4];
	}

	if (turns[N] == 1) {
		std::cout << "SK";
	}
	else {
		std::cout << "CY";
	}

	return 0;
}