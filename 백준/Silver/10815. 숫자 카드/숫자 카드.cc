#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int>arr;
vector<int>result;

void Exist(int target) {
	int st = 0;
	int ed = N - 1;
	int mid = (st + ed) / 2;
	while (true) {
		if (target == arr[mid]) {
			result.push_back(1);
			return;
		}
		else if (target < arr[mid]) {
			ed = mid - 1;
			mid = (st + ed) / 2;
		}
		else if (target > arr[mid]) {
			st = mid + 1;
			mid = (st + ed) / 2;
		}
		if (st > ed) {
			result.push_back(0);
			return;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}

	sort(arr.begin(), arr.end(), less<>());

	cin >> M;

	for (int i = 0; i < M; i++) {
		int tmp;
		cin >> tmp;
		Exist(tmp);
	}
	
	for (int i = 0; i < M; i++) {
		cout << result[i] << " ";
	}
	return 0;
}