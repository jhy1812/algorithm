#include <iostream>
#include <cmath>
#include <algorithm>

int D, H, W;
double x;

int main()
{
	std::cin >> D >> H >> W;

	x = (double)D * D /(H * H + W * W);
	x = sqrt(x);

	std::cout << (int)(x * H) << " " << (int)(x * W);

	return 0;
}