#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N, M, summ, result;
	summ = 0;
	result = 0;
	cin >> N >> M;
	int arr[100] = { 0, };
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				summ = arr[i] + arr[j] + arr[k];
				if (summ <= M && result < summ) {
					result = summ;
				}
			}
		}
	}
	cout << result;
	return 0;
}