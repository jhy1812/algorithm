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
	
	int N = 30;
	int arr[31] = { 0, };
	int a;
	for (int i = 1; i < 29; i++) {
		cin >> a;
		arr[a] = 1;
	}
	for (int i = 1; i < 31; i++) {
		if (arr[i] != 1) {
			cout << i << "\n";
		}
	}

	return 0;
}