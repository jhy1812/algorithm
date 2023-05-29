#include <iostream>

int main()
{
	int N, M;

	std::cin >> N >> M;

	if (N * 100 >= M) {
		std::cout << "Yes";
	}
	else {
		std::cout << "No";
	}

	return 0;
}