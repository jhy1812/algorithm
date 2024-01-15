#include <iostream>
#include <map>

int N, M;
std::map<int, int> check;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		std::cin >> tmp;
		check[tmp] = 1;
	}

	std::cin >> M;
	
	for (int i = 0; i < M; i++) {
		int tmp;
		std::cin >> tmp;
		if (check[tmp] == 1) {
			std::cout << 1 << "\n";
		}
		else {
			std::cout << 0 << "\n";
		}
	}

	return 0;
}