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
	dp[0] = arr[0];
	result = arr[0];
	for (int i = 1; i < N; i++) {
		maxx = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (arr[i] > arr[j]) {
				if (dp[j] >= maxx) {
					maxx = dp[j];
				}
			}
		}
		dp[i] = maxx + arr[i];
		if (result < dp[i]) {
			result = dp[i];
		}
	}

	cout << result;
	return 0;
}