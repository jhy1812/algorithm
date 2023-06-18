#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

std::string s;
int result;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> s;
	char check = s[0];

	for (int i = 1; i<int(s.size()); i++) {
		if (s[i] != check) {
			result += 1;
			check = s[i];
		}
	}

	std::cout << (result + 1) / 2;

	return 0;
}