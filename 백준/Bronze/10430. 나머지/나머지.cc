#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	cout << (a + b) % c << endl;
	cout << ((a%c) + (b%c)) % c << endl;
	cout << (a*b) % c << endl;
	cout << ((a%c)*(b%c)) % c << endl;

	return 0;
}