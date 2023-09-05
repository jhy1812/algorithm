#include <iostream>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int i = 1;

	while (true) {
		int l, p, v;
		std::cin >> l >> p >> v;
		if (l == 0 && p == 0 && v == 0) {
			break;
		}
		std::cout << "Case " << i << ": " << (v / p) * l + std::min(v % p, l) << "\n";
		i++;
	}


	return 0;
}