#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
#include <vector>

std::string s;
std::string bomb;
std::vector<char>stack;



int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> s;
	std::cin >> bomb;

	char st = bomb[int(bomb.size()) - 1];
	
	for (int i = 0; i<int(s.size()); i++) {
		stack.push_back(s[i]);
		if (s[i] == st) {
			if (int(stack.size()) < int(bomb.size())) {
				continue;
			}
			int flag = 0;
			for (int j = 1; j <= int(bomb.size()); j++) {
				if (bomb[int(bomb.size()) - j] != stack[int(stack.size()) - j]) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				for (int j = 0; j<int(bomb.size()); j++) {
					stack.pop_back();
				}
			}
		}
	}

	if (int(stack.size()) == 0) {
		std::cout << "FRULA";
	}
	else {
		for (int i = 0; i<int(stack.size()); i++) {
			std::cout << stack[i];
		}
	}

	return 0;
}