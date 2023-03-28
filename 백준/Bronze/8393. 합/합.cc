#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{
	int n, summ;
	summ = 0;
	cin >> n;
	for (int i = 1; i < n+1; i++) {
		summ += i;
	}
	cout << summ;
	return 0;
}