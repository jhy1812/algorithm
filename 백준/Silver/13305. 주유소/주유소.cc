#include <iostream>
#include <vector>
#include <algorithm>

int N;
int price = 1000000000;
long long result;
std::vector<int>city;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int tmp;
		std::cin >> tmp;
		city.push_back(tmp);
	}

	for (int i = 0; i < N; i++) {
		int tmp;
		std::cin >> tmp;
		if (i == N - 1) {
			break;
		}
		if (tmp < price) {
			price = tmp;
		}
		result += price * city[i];
	}

	std::cout << result;

	return 0;
}