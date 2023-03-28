#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, a, b;
	cin >> T;
	for (int i = 1; i < T + 1; i++) {
		cin >> a >> b;
		cout << a + b << "\n";
	}
	return 0;
}