#include <iostream>

int min, sec, t;

int main()
{
	for (int i = 0; i < 4; i++) {
		int tmp;
		std::cin >> tmp;
		t += tmp;
	}

	min = t / 60;
	sec = t % 60;

	std::cout << min << "\n" << sec;

	return 0;
}