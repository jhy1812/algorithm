#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

std::string s;


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	while (true) {
		getline(std::cin, s);
		if (s == ".") {
			break;
		}
		else {
			int flag = 0;
			std::stack<char>arr;
			for (int i = 0; i<int(s.size()); i++) {
				if (s[i] == '[' || s[i] == '(') {
					arr.push(s[i]);
				}
				else if (s[i] == ']') {
					if (int(arr.size()) == 0) {
						flag = 1;
						break;
					}
					else {
						char check = arr.top();
						arr.pop();
						if (check != '[') {
							flag = 1;
							break;
						}
					}
				}
				else if (s[i] == ')') {
					if (int(arr.size()) == 0) {
						flag = 1;
						break;
					}
					else {
						char check = arr.top();
						arr.pop();
						if (check != '(') {
							flag = 1;
							break;
						}
					}
				}
			}
			if (flag == 1) {
				std::cout << "no" << "\n";
			}
			else if (int(arr.size()) != 0) {
				std::cout << "no" << "\n";
			}
			else {
				std::cout << "yes" << "\n";
			}
		}
	}

	return 0;
}