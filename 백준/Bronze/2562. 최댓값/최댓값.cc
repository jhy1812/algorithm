#include <iostream>
#include <stdio.h>
#include <string>
#define _CRT_SECURE_NO_WARNINGS 
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, maxx, cnt, a;
	N = 9;
	maxx = -21e8;
	cnt = 0;
	for (int i = 0; i < N; i++) {
		cin >> a;
		if (maxx < a) {
			maxx = a;
			cnt = i + 1;
		}
	}
	cout << maxx << "\n" << cnt;
	return 0;
}