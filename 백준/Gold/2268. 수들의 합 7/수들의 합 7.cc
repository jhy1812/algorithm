#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int N, M, a, b, c;
long long result;

vector<long long>segment(4000000);

long long update_tree(int st, int ed, int idx, int target, int val) {
	if (target < st || ed < target) {
		return segment[idx];
	}
	if (st == ed) {
		return segment[idx] = val;
	}
	int mid = (st + ed) / 2;
	return segment[idx] = update_tree(st, mid, 2 * idx, target, val) + update_tree(mid + 1, ed, 2 * idx + 1, target, val);
}

void get_result(int st, int ed, int idx, int left, int right) {
	if (right < st || ed < left) {
		return;
	}
	if (left <= st && ed <= right) {
		result += segment[idx];
		return;
	}
	int mid = (st + ed) / 2;
	get_result(st, mid, 2 * idx, left, right);
	get_result(mid + 1, ed, 2 * idx + 1, left, right);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		if (a == 0) {
			if (c > b) {
				result = 0;
				get_result(1, N, 1, b, c);
				cout << result << "\n";
			}
			else {
				result = 0;
				get_result(1, N, 1, c, b);
				cout << result << "\n";
			}
		}
		else {
			update_tree(1, N, 1, b, c);
		}
	}

	return 0;
}