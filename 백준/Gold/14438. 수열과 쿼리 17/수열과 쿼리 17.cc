#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, a, b, c, minn;
vector<int>arr;
vector<int>segment(400000);

int make_tree(int st, int ed, int idx) {
	if (st == ed) {
		return segment[idx] = arr[st];
	}
	int mid = (st + ed) / 2;
	return segment[idx] = min(make_tree(st, mid, 2 * idx), make_tree(mid + 1, ed, 2 * idx + 1));
}

int update(int st, int ed, int idx, int target, int val) {
	if (target < st || ed < target) {
		return segment[idx];
	}
	if (st == ed) {
		return segment[idx] = val;
	}
	int mid = (st + ed) / 2;
	return segment[idx] = min(update(st, mid, 2 * idx, target, val), update(mid + 1, ed, 2 * idx + 1, target, val));
}

void get_min(int st, int ed, int idx, int left, int right) {
	if (right < st || ed < left) {
		return;
	}
	if (left <= st && ed <= right) {
		minn = min(minn, segment[idx]);
		return;
	}
	int mid = (st + ed) / 2;
	get_min(st, mid, 2 * idx, left, right);
	get_min(mid + 1, ed, 2 * idx + 1, left, right);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	arr.push_back(0);

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
	
	make_tree(1, N, 1);

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, N, 1, b, c);
		}
		else {
			minn = 1000000001;
			get_min(1, N, 1, b, c);
			cout << minn << "\n";
		}
	}
	return 0;
}