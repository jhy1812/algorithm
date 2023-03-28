#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{
	int cost, N, summ;
	summ = 0;
	cin >> cost;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		summ += a * b;
	}
	if (cost == summ) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	return 0;
}