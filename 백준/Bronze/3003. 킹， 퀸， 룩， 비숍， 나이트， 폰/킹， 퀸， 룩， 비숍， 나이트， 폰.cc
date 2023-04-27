#include <iostream>

using namespace std;

int N = 6;
int arr[6];
int lst[6] = { 1, 1, 2, 2, 2, 8 };

int main() {
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		arr[i] = lst[i] - tmp;
	}
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}