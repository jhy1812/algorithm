#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>

int N, M, flag, mod;
std::string s, n, m;

int gcd(int a, int b) {
	while (b > 0) {
		int tmp = a;
		a = b;
		b = tmp % b;
	}
	return a;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ':') {
			flag = 1;
		}
		else if (flag) {
			m += s[i];
		}
		else {
			n += s[i];
		}
	}

	N = stoi(n);
	M = stoi(m);

	mod = gcd(N, M);
	
	std::cout << N / mod << ':' << M / mod;

	return 0;
}