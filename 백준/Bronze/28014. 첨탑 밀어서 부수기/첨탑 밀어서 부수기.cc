#include <iostream>
#include <vector>
#include <algorithm>

int N, bef, aft, cnt;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	std::cin >> bef;
	cnt = 1;

	for (int i = 1; i < N; i++) {
		std::cin >> aft;
		if (bef <= aft) {
			cnt += 1;
		}
		bef = aft;
	}
	
	std::cout << cnt;

	return 0;
}