#include <iostream>
#include <vector>
#include <string>

std::string s;
std::string ppap = "PPAP";
std::vector<char>stack;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> s;

	for (int i = 0; i < s.length(); i++) {
		stack.push_back(s[i]);
		if (s[i] == 'P') {
			if (int(stack.size()) >= 4) {
				int flag = 0;
				for (int j = 1; j <= 4; j++) {
					if (stack[int(stack.size()) - j] != ppap[4 - j]) {
						flag = 1;
					}
				}
				if (flag == 0) {
					for (int j = 0; j < 3; j++) {
						stack.pop_back();
					}
				}
			}
		}
	}


	if (int(stack.size()) == 1 && stack[0] == 'P') {
		std::cout << "PPAP";
	}
	else {
		std::cout << "NP";
	}

	return 0;
}