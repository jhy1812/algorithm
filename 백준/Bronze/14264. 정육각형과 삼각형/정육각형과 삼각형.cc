#include <iostream>
#include <cmath>

double L, result;

int main()
{
    std::cin >> L;

    result = (double)L * L * sqrt(3) / 4;

    std::cout << std::fixed;
    std::cout.precision(14);
    std::cout << result;

    return 0;
}