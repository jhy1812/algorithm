#include <iostream>
#include <algorithm>

int main()
{
    int a, b, c, d;
    std::cin >> a >> b;
    std::cin >> c >> d;
    
    std::cout << std::min(a+d, b+c);
}