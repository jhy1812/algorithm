#include <iostream>
#include <algorithm>

int T, summ, minn;

int main()
{
	std::cin >> T;

	for (int tc = 0; tc < T; tc++) {
		summ = 0;
		minn = 200;
		for (int i = 0; i < 7; i++) {
			int tmp;
			std::cin >> tmp;
			if (tmp % 2 == 0) {
				minn = std::min(minn, tmp);
				summ += tmp;
			}
		}
		std::cout << summ <<  " " << minn << "\n";
	}

	return 0;
}