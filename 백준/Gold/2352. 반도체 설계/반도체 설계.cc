#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int n;
vector<int>port(1);
vector<int>arr(1);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		port.push_back(tmp);
	}

	for (int i = 1; i <= n; i++) {
		if (port[i] > arr[int(arr.size()-1)]) {
			arr.push_back(port[i]);
		}
		else {
			int idx = int(lower_bound(arr.begin(), arr.end(), port[i]) - arr.begin());
			arr[idx] = port[i];
		}
	}

	cout << int(arr.size()) - 1;

	return 0;
}