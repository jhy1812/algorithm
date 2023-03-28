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

	int N, v, arr[100], cnt;
	cnt = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	cin >> v;

	for (int i = 0; i < N; i++) {
		if (arr[i] == v) {
			cnt += 1;
		}
	}
	cout << cnt;
	return 0;
}