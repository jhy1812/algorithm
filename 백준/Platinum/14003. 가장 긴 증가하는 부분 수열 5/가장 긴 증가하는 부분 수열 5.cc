#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, cnt, tmp, num;
vector<int>arr;
vector<int>dp;
vector<int>lis;
vector<int>result;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		arr.push_back(tmp);
		dp.push_back(0);
	}

	lis.push_back(arr[0]);

	for (int i = 0; i < N; i++) {
		if (lis.back() < arr[i]) {
			lis.push_back(arr[i]);
			dp[i] = int(lis.size());
		}
		else {
			int idx = int(lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin());
			lis[idx] = arr[i];
			dp[i] = idx + 1;
		}
	}

	cnt = int(lis.size());
	num = int(lis.size());
	cout << cnt << "\n";
	

	for (int i = N - 1; i >= 0; i--) {
		if (dp[i] == cnt) {
			result.push_back(arr[i]);
			cnt -= 1;
		}
	}

	for (int i = num - 1; i >= 0; i--) {
		cout << result[i] << " ";
	}
	return 0;
}