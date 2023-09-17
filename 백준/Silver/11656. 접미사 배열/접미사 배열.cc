#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

std::string s, tail;
std::vector<std::string> result;

int main()
{
	std::cin >> s;

	for (int i = int(s.size()) - 1; i >= 0; i--) {
		tail = s[i] + tail;
		result.push_back(tail);
	}

	std::sort(result.begin(), result.end());

	for (int i = 0; i < result.size(); i++) {
		std::cout << result[i] << "\n";
	}

	return 0;
}