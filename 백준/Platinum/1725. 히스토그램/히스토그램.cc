#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int N, result;
vector<int>arr;
stack<pair<int, int>>nop;

void compare() {
	for (int i = 1; i < N; i++) {
		if (nop.top().first < arr[i]) {
			nop.push(make_pair(arr[i], 1));
		}
		else if (nop.top().first == arr[i]) {
			nop.top().second += 1;
		}
		else {
			int w = 0;
			int h = 0;
			while (!nop.empty()) {
				w += nop.top().second;
				h = nop.top().first;
				if (result < w*h) {
					result = w * h;
				}
				nop.pop();
				if (nop.empty()) {
					nop.push(make_pair(arr[i], w + 1));
					break;
				}
				if (nop.top().first == arr[i]) {
					nop.top().second += w + 1;
					break;
				}
				else if (nop.top().first < arr[i]) {
					nop.push(make_pair(arr[i], w + 1));
					break;
				}
			}
		}
	}
	int w = 0;
	int h = 0;
	while (!nop.empty()) {
		w += nop.top().second;
		h = nop.top().first;
		if (result < w*h) {
			result = w * h;
		}
		nop.pop();
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

	nop.push(make_pair(arr[0], 1));
	result = arr[0];
	
	compare();

	cout << result;

	return 0;
}