#include <iostream>
#include <string>

std::string s;
int result;

int main()
{
	std::cin >> s;
	int N = int(s.size());
	s += "QQ";
	int i = 0;

	while (true) {
		if (i >= N) {
			break;
		}
		if (s[i] == 'c') {
			if (s[i + 1] == '=' || s[i + 1] == '-') {
				result += 1;
				i += 2;
				continue;
			}
		}
		else if (s[i] == 'd') {
			if (s[i + 1] == 'z' && s[i + 2] == '=') {
				result += 1;
				i += 3;
				continue;
			}
			else if (s[i + 1] == '-') {
				result += 1;
				i += 2;
				continue;
			}
		}
		else if (s[i] == 'l') {
			if (s[i + 1] == 'j') {
				result += 1;
				i += 2;
				continue;
			}
		}
		else if (s[i] == 'n') {
			if (s[i + 1] == 'j') {
				result += 1;
				i += 2;
				continue;
			}
		}
		else if (s[i] == 's') {
			if (s[i + 1] == '=') {
				result += 1;
				i += 2;
				continue;
			}
		}
		else if (s[i] == 'z') {
			if (s[i + 1] == '=') {
				result += 1;
				i += 2;
				continue;
			}
		}
		result += 1;
		i += 1;
	}

	std::cout << result;

	return 0;
}