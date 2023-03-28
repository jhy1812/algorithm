#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int tc = 1; tc < T + 1; tc++) {
		int a, b;
		cin >> a >> b;
		cout << a+b << endl;
	}
	return 0;
}