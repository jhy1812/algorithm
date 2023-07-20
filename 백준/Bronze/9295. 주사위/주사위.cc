#include <iostream>
#include <algorithm>

int T;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int a, b;
		std::cin >> a >> b;

		std::cout << "Case " << tc << ": " << a + b << "\n";
	}

	return 0;
}