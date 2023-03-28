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

	int N, minn, maxx, a;
	cin >> N;
	minn = 21e8;
	maxx = -21e8;
	for (int i = 0; i < N; i++) {
		cin >> a;
		if (maxx < a) {
			maxx = a;
		}
		if (minn > a) {
			minn = a;
		}
	}
	cout << minn << " " << maxx;
	return 0;
}