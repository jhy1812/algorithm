#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int N, L;
deque<pair<int, int>>dq;
vector<int>visited(5000001);
vector<int>result(5000001);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		while (!dq.empty() && dq.back().first > tmp) {
			dq.pop_back();
		}
		dq.push_back(make_pair(tmp, i));

		if (dq.front().second <= i - L) {
			dq.pop_front();
		}
		result[i] = dq.front().first;
	}

	for (int i = 0; i < N; i++) {
		cout << result[i] << " ";
	}

	return 0;
}
