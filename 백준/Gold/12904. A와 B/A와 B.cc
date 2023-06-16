#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

std::string S, T;
std::vector<char>lst;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> S;
	std::cin >> T;

	int sl = int(S.size());
	int tl = int(T.size());

	for (int i = 0; i < tl; i++) {
		lst.push_back(T[i]);
	}

	for (int i = 0; i < tl - sl; i++) {
		if (lst[int(lst.size()) - 1] == 'A') {
			lst.pop_back();
		}
		else {
			lst.pop_back();
			reverse(lst.begin(), lst.end());
		}
	}

	int flag = 1;

	for (int i = 0; i < sl; i++) {
		if (S[i] != lst[i]) {
			flag = 0;
			break;
		}
	}

	std::cout << flag;

	return 0;
}