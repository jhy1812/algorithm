#include <iostream>

int a, b, c, d;

int main()
{
    std::cin >> a >> b >> c;
    std::cin >> d;

    c += d;
    b += c / 60;
    a += b / 60;

    a = a % 24;
    b = b % 60;
    c = c % 60;

    std::cout << a << " " << b << " " << c;

    return 0;
}