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
	int N, M, tmp, a, b;
	cin >> N >> M;
	int arr[101] = { 0, };
	for (int i = 1; i < N + 1; i++) {
		arr[i] = i;
	}

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		tmp = arr[a];
		arr[a] = arr[b];
		arr[b] = tmp;
	}
	for (int i = 1; i < N + 1; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}