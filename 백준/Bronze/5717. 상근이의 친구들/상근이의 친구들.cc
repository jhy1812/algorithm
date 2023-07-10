#include <iostream>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	while (true) {
		int t, f;
		std::cin >> t >> f;
		if (t == 0 && f == 0)
		{
			break;
		}
		std::cout << t + f << "\n";
	}

	return 0;
}