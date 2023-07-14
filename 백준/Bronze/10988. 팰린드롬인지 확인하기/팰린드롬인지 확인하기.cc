#include <iostream>
#include <algorithm>
#include <string>

std::string s;
int result;

int main()
{
	std::cin >> s;

	result = 1;

	for (int i = 0; i<int(s.size()); i++) {
		if (s[i] != s[int(s.size()) - i - 1]) {
			result = 0;
			break;
		}
	}

	std::cout << result;

	return 0;
}