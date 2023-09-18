#include <iostream>
#include <algorithm>
#include <map>
#include <string>

int N, M, result;
std::map<std::string, int> check;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		std::string tmp;
		std::cin >> tmp;
		check[tmp] = 1;
	}

	for (int i = 0; i < M; i++) {
		std::string tmp;
		std::cin >> tmp;
		if (check[tmp] == 1) {
			result++;
		}
	}

	std::cout << result;

	return 0;
}