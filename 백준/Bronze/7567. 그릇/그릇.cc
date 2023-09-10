#include <iostream>
#include <string>

int result = 10;
std::string s;

int main()
{
	std::cin >> s;

	for (int i = 1; i < s.size(); i++) {
		if (s[i] == s[i - 1]) {
			result += 5;
		}
		else {
			result += 10;
		}
	}

	std::cout << result;

	return 0;
}