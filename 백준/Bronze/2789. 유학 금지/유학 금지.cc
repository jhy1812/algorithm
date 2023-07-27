#include <iostream>
#include <string>

std::string s, result;

int main()
{
	std::cin >> s;

	std::string word = "CAMBRIDGE";

	for (int i = 0; i < s.size(); i++) {
		int flag = 0;
		for (int j = 0; j < word.size(); j++) {
			if (s[i] == word[j]) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			result += s[i];
		}
	}

	std::cout << result;

	return 0;
}