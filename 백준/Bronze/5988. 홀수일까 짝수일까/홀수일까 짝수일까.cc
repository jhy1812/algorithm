#include <iostream>
#include <string>

int main()
{
	int N;

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::string tmp;
		std::cin >> tmp;
		if ((tmp[tmp.size() - 1] - '0') % 2) {
			std::cout << "odd" << "\n";
		}
		else {
			std::cout << "even" << "\n";
		}
	}

	return 0;
}