#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

int N;
std::map<std::string, int> check;
std::vector<std::string> arr;

bool cmp(std::string a, std::string b) {
	if (a.size() > b.size()) {
		return false;
	}
	else if (a.size() == b.size()) {
		return a < b;
	}
	return true;
}

int main()
{
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::string tmp;
		std::cin >> tmp;
		if (check[tmp] == 1) {
			continue;
		}
		check[tmp] = 1;
		arr.push_back(tmp);
	}

	std::sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << "\n";
	}

	return 0;
}