#include <iostream>

int N;
 
int main()
{
	std::cin >> N;
 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++)
			std::cout << ' ';
		for (int j = 1; j <= (2 * (N - i)) - 1; j++)
			std::cout << '*';
		std::cout << '\n';
	}
 
	return 0;
}