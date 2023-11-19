#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main()
{
	int L;

	std::cin >> L;

	if (L >= 620) {
		std::cout << "Red";
	}
	else if (L >= 590) {
		std::cout << "Orange";
	}
	else if (L >= 570) {
		std::cout << "Yellow";
	}
	else if (L >= 495) {
		std::cout << "Green";
	}
	else if (L >= 450) {
		std::cout << "Blue";
	}
	else if (L >= 425) {
		std::cout << "Indigo";
	}
	else {
		std::cout << "Violet";
	}
	return 0;
}