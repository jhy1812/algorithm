#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, cnt, tmp;
vector<int>arr;
vector<int>dp;
vector<int>lis;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	}

	lis.push_back(arr[0]);

	for (int i = 0; i < N; i++) {
		if (lis.back() < arr[i]) {
			lis.push_back(arr[i]);
		}
		else {
			int idx = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
			lis[idx] = arr[i];
		}
	}
	
	cout << lis.size();
	return 0;
}