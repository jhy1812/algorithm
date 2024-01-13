#include <iostream>
#include <algorithm>
#include <vector>

long long a, d, q, gcd;

long long hoje(long long a, long long b) {
	while (true) {
		if (a % b == 0) {
			return b;
		}
		long long tmp = a % b;
		a = b;
		b = tmp;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> a >> d;
	std::cin >> q;

	if (d == 0) {
		gcd = a;
	}
	else {
		gcd = hoje(a, d);
	}

	for (int i = 0; i < q; i++) {
		long long order, l, r;
		std::cin >> order >> l >> r;
		if (order == 1) {
			std::cout << ((r - l + 1) * (2 * a + (l + r - 2) * d)) / 2 << "\n";
		}
		else {
			if (l == r) {
				std::cout << a + (l - 1) * d << "\n";
			}
			else {
				std::cout << gcd << "\n";
			}
		}
	}

	return 0;
}