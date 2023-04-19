#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int N;
long long result;
vector<int>arr;
stack<pair<int, int>>ki;

void compare() {
	for (int i = 1; i < N; i++) {
		if (ki.top().first < arr[i]) {
			while (!ki.empty()) {
				result += ki.top().second;
				ki.pop();
				if (ki.empty()) {
					ki.push(make_pair(arr[i], 1));
					break;
				}
				if (ki.top().first == arr[i]) {
					result += ki.top().second;
					ki.top().second += 1;
					if (int(ki.size() > 1)) {
						result += 1;
					}
					break;
				}
				else if (ki.top().first > arr[i]) {
					ki.push(make_pair(arr[i], 1));
					if (int(ki.size() > 1)) {
						result += 1;
					}
					break;
				}
			}
		}
		else if (ki.top().first == arr[i]) {
			if (int(ki.size()) == 1) {
				result += ki.top().second;
				ki.top().second += 1;
			}
			else {
				result += ki.top().second + 1;
				ki.top().second += 1;
			}
		}
		else {
			result += 1;
			ki.push(make_pair(arr[i], 1));
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

	ki.push(make_pair(arr[0], 1));

	compare();

	cout << result;

	return 0;
}