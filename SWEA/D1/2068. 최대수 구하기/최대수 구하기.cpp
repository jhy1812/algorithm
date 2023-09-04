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
		int result = -1;
		for (int i = 0; i < 10; i++) {
			int tmp;
			std::cin >> tmp;
			result = std::max(result, tmp);
		}
		std::cout << "#" << tc << " " << result << "\n";
	}

	return 0;
}