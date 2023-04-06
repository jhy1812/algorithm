#include <iostream>

using namespace std;

int main()
{
	long long int n, summ;
	summ = 0;

	for (int i = 0; i < 5; i++) {
		cin >> n;
		summ += (n * n)%10;
	}

	cout << summ%10;
	return 0;
}