#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

long long N, n;
std::vector<long long>expo;

int main()
{
	std::cin >> N;

	n = N;

	int lim = (int)sqrt(n) + 1;

	if (n == 1) {
		std::cout << 1;
	}
	else {
		for (int i = 2; i <= lim; i++) {
			if (n % i != 0) {
				continue;
			}
			else {
				while (true) {
					n = n / i;
					if (n % i != 0) {
						break;
					}
				}
			}
			expo.push_back(i);
			if (n == 1) {
				break;
			}
		}
		if (n != 1) {
			expo.push_back(n);
		}
		for (int i = 0; i<int(expo.size()); i++) {
			N = N / expo[i];
			N *= (expo[i] - 1);
		}
		std::cout << N;
	}
	return 0;
}