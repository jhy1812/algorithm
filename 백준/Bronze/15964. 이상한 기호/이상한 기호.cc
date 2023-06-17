#include <iostream>
#include <vector>

long long result;
int a, b;

int main()
{
    std::cin >> a >> b;

    result = (long long)(a + b) * (a - b);

    std::cout << result;

    return 0;
}