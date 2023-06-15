#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

std::string N;
std::vector<char>arr;

int main()
{
	std::cin >> N;

	for (int i = 0; i<int(N.size()); i++) {
		arr.push_back(N[i]);
	}

	sort(arr.begin(), arr.end(), std::greater<>());

	for (int i = 0; i<int(N.size()); i++) {
		std::cout << arr[i];
	}

	return 0;
}