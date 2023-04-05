#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, a, b, cnt, minn;

vector<pair<int, int>>arr;
vector<int>all;
vector<pair<int, int>>ins;
vector<int>dp;

typedef pair<int, int> pii;

bool comp(const pii &a, const pii &b) {
	return a.second < b.second;
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		arr.push_back(make_pair(a, b));
		dp.push_back(0);
	}

	sort(arr.begin(), arr.end());

	ins.push_back(arr[0]);
	dp[0] = 1;

	for (int i = 1; i < N; i++) {
		if (ins.back().second < arr[i].second) {
			ins.push_back(arr[i]);
			dp[i] = int(ins.size());
		}
		else {
			int idx = int(lower_bound(ins.begin(), ins.end(), arr[i], comp) - ins.begin());
			ins[idx] = arr[i];
			dp[i] = idx + 1;
		}
	}

	cnt = int(ins.size());
	minn = N - int(ins.size());

	for (int i = N - 1; i >= 0; i--) {
		if (dp[i] == cnt) {
			arr[i] = make_pair(-1, -1);
			cnt -= 1;
		}
	}

	cout << minn << "\n";
	//for (int i = 0; i < N; i++) {
	//	if (arr[i].first != -1) {
	//		cout << arr[i].first << " ";
	//	}
	//}

	return 0;
}