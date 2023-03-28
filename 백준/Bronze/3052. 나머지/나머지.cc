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
	
	int arr[42] = { 0, };
	int cnt, a;
	cnt = 0;
	for (int i = 0; i < 10; i++) {
		cin >> a;
		arr[a % 42] = 1;
	}
	for (int i = 0; i < 42; i++) {
		if (arr[i] == 1) {
			cnt += 1;
		}
	}
	cout << cnt;
	return 0;
}