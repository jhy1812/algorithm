#include <iostream>
#include <vector>

#define ull unsigned long long

int N, result;
ull A;

int base[3] = { 2, 3, 61};

ull power(ull a, ull n, ull m) {
	ull ret = 1;
	a = a % m;
	while (n > 0) {
		if (n % 2) {
			ret = (ret * a) % m;
		}
		n = n / 2;
		a = (a * a) % m;
	}
	return ret;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> A;
		if (A < 4) {
			result++;
			continue;
		}
		if (A <= 30) {
			int flag = 0;
			A = 2 * A + 1;
			for (int i = 2; i < A; i++) {
				if (A % i == 0) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				result++;
			}
			continue;
		}
		A = 2 * A + 1;
		int flag = 0;
		ull MOD = A;
		for (int j = 0; j < 3; j++) {
			ull d = A - 1;
			int cnt = 0;
			int check = 0;
			while (d % 2 == 0) {
				d = d / 2;
				cnt++;
			}
			ull tmp = power(base[j], d, MOD);
			if (tmp == A - 1 || tmp == 1) {
				flag++;
				continue;
			}
			for (int k = 0; k < cnt; k++) {
				tmp = power(tmp, 2, MOD);
				if (tmp == A - 1) {
					flag++;
					check = 1;
					break;
				}
			}
			if (check) {
				continue;
			}
		}
		if (flag == 3) {
			result++;
		}
	}

	std::cout << result;

	return 0;
}