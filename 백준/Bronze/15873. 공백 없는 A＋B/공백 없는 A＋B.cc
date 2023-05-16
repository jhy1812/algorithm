#include <iostream>

int n, summ;

int main()
{
std::cin >> n;

if (n%10 == 0){
summ = n/100 + n%100;
}
else {
summ = n/10 + n%10;
}

std::cout << summ;

return 0;
}