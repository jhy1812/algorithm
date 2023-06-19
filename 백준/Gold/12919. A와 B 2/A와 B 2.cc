#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int flag, lim, Ta, Tb, Sa, Sb;
std::string S, T;
std::vector<char>lst;

void dfs(int lv, int ta, int tb) {
	if (flag == 1) {
		return;
	}
	if (ta < Sa || tb < Sb) {
		return;
	}
	if (lv == lim) {
		int check = 0;
		for (int i = 0; i<int(S.size()); i++) {
			if (S[i] != lst[i]) {
				check = 1;
				break;
			}
		}
		if (check == 0) {
			flag = 1;
		}
		return;
	}
	if (lst[int(lst.size()) - 1] == 'A') {
		lst.pop_back();
		dfs(lv + 1, ta - 1, tb);
		lst.push_back('A');
	}
	if (lst[0] == 'B') {
		reverse(lst.begin(), lst.end());
		lst.pop_back();
		dfs(lv + 1, ta, tb - 1);
		lst.push_back('B');
		reverse(lst.begin(), lst.end());
	}
}

int main()
{
	std::cin >> S;
	std::cin >> T;

	int sl = int(S.size());
	int tl = int(T.size());

	lim = tl - sl;

	for (int i = 0; i<tl; i++) {
		lst.push_back(T[i]);
		if (T[i] == 'A') {
			Ta += 1;
		}
	}

	for (int i = 0; i < sl; i++) {
		if (S[i] == 'A') {
			Sa += 1;
		}
	}

	Sb = sl - Sa;
	Tb = tl - Ta;

	dfs(0, Ta, Tb);

	std::cout << flag;

	return 0;
}