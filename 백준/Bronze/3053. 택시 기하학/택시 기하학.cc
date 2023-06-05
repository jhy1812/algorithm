#include <iostream>
#include <algorithm>
#include <cmath>

#define pi  3.141592653589

double R;
double ur, tr;

int main()
{
	std::cin >> R;

	ur = pi * pow(R, 2);
	tr = (double)2 * R * R;

	std::cout << std::fixed;
	std::cout.precision(6);
	std::cout << ur << "\n" << tr;

	return 0;
}