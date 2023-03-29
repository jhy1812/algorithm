#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N, maxx, result;
	cin >> N;
	int arr[1000] = { 0, };
	int dp[1000] = { 0, };
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	result = 1;
	dp[0] = 1;
	for (int i = 1; i < N; i++) {
		maxx = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (arr[j] > arr[i]) {
				if (maxx < dp[j]) {
					maxx = dp[j];
				}
			}
		}
		dp[i] = maxx + 1;
		if (dp[i] > result) {
			result = dp[i];
		}
	}
	cout << result;
	return 0;
}