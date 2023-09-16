#include <iostream>
#include <string>
#include <vector>

int n, m;
std::vector<std::string> fish;

int main()
{
	std::cin >> n >> m;

	for (int i = 0; i < n; i++) {
		std::string tmp;
		std::cin >> tmp;
		fish.push_back(tmp);
	}

	for (int i = 0; i < n; i++) {
		for (int j = m - 1; j >= 0; j--) {
			std::cout << fish[i][j];
		}
		std::cout << "\n";
	}

	return 0;
}