#include <iostream>
#include <algorithm>
#include <vector>

#define MOD 1000;

int N, a, b, d;
long long al, ca;
std::vector<int> arr(1, 0);

int main()
{
	std::cin >> a >> b >> d >> N;

	arr[0] = 1;
	al = 1;

	for (int i = 1; i <= N; i++) {
		if (i >= d) {
			al -= arr[i - d] % MOD;
			if (al < 0) {
				al += MOD;
			}
		}
		if (i >= a) {
			ca += arr[i - a] % MOD;
		}
		if (i >= b) {
			ca -= arr[i - b] % MOD;
			if (ca < 0) {
				ca += MOD;
			}
		}
		ca %= MOD;
		al += ca;
		al %= 1000;
		arr.push_back(ca);
	}

	std::cout << al;

	return 0;
}