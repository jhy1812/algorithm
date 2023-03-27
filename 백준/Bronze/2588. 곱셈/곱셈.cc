#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a;
	cin >> b;

	cout << (b % 10)*a << endl;
	cout << (b % 100 - b % 10)/10*a << endl;
	cout << (b / 100)*a << endl;
	cout << a * b << endl;
	return 0;
}