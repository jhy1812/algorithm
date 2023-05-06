#include <iostream>
#include <algorithm>

int main()
{
int a, b, c, d, e;
int ham, coke;
std::cin >> a >> b >> c >> d >> e;

ham = 0;
coke = 0;

ham = std::min(a , b);
ham = std::min(ham, c);
coke = std::min(d, e);

std::cout << ham + coke - 50;

return 0;
}