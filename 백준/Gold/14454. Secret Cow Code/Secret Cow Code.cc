#include <iostream>
#include <algorithm>
#include <string>

long long N;
std::string s;

void get_result(int lv, long long leng) {
	if (N <= leng) {
		return;
	}

	get_result(lv + 1, leng * 2);

	if (N <= leng) {
		return;
	}

	if (leng + 1 == N) {
		N -= 1;
	}
	else {
		N -= leng + 1;
	}
}

int main()
{
	std::cin >> s >> N;

	get_result(0, (long long)s.size());

	N--;

	std::cout << s[N];

	return 0;
}