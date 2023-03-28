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
	int N, M, a, b, c;
	int arr[100] = { 0, };
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		for (int j = a - 1; j < b; j++) {
			arr[j] = c;
		}
	}
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}