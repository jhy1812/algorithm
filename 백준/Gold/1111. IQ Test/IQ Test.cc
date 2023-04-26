#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, d, result;
vector<int>arr;
vector<int>diff;

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

	if (N == 1) {
		cout << "A";
	}
	else if (N == 2) {
		if (arr[0] == arr[1]) {
			cout << arr[0];
		}
		else {
			cout << "A";
		}
	}
	else {
		int d1 = arr[1] - arr[0];
		int d2 = arr[2] - arr[1];
		if (d1 == 0) {
			if (d2 != 0) {
				cout << "B";
			}
			else {
				int flag = 0;
				for (int i = 3; i<int(arr.size()); i++) {
					int tmp = arr[i] - arr[i - 1];
					if (tmp != 0) {
						flag = 1;
						break;
					}
				}
				if (flag == 1) {
					cout << "B";
				}
				else {
					cout << arr[0];
				}
			}
		}
		else {
			if (d2 % d1 != 0) {
				cout << "B";
			}
			else {
				int r = d2 / d1;
				int flag = 0;
				diff.push_back(d1);
				diff.push_back(d2);
				for (int i = 3; i<int(arr.size()); i++) {
					int tmp = arr[i] - arr[i - 1];
					if (tmp != d2 * r) {
						flag = 1;
						break;
					}
					diff.push_back(tmp);
					d2 = tmp;
				}
				if (flag == 1) {
					cout << "B";
				}
				else {
					cout << arr[N - 1] + diff[N - 2] * r;
				}
			}
			
		}
	}
	return 0;
}