#include <iostream>
#include <string>
#include <stack>

std::string s;
std::stack<char> check;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			check.push(s[i]);
		}
		else {
			if (check.size() == 0) {
				check.push(s[i]);
			}
			else if (check.top() == '(') {
				check.pop();
			}
			else {
				check.push(s[i]);
			}
		}
	}

	std::cout << check.size();

	return 0;
}