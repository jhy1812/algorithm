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

	int N, X, arr[10000];
	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (arr[i] < X) {
			cout << arr[i] << " ";
		}
	}
	return 0;
}