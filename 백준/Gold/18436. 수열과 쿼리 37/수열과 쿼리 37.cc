#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, a, b, c, result;
vector<int>arr;
vector<pair<int, int>>segment(400000);

pair<int, int> make_tree(int st, int ed, int idx) {
	if (st == ed) {
		if (arr[st] % 2 == 0) {
			return segment[idx] = make_pair(1, 0);
		}
		else {
			return segment[idx] = make_pair(0, 1);
		}
	}
	int mid = (st + ed) / 2;
	pair<int, int>left_node = make_tree(st, mid, 2 * idx);
	pair<int, int>right_node = make_tree(mid + 1, ed, 2 * idx + 1);
	return segment[idx] = make_pair(left_node.first + right_node.first, left_node.second + right_node.second);
}

pair<int, int> update(int st, int ed, int idx, int target, int val) {
	if (target < st || ed < target) {
		return segment[idx];
	}
	if (st == ed) {
		if (val % 2 == 0) {
			return segment[idx] = make_pair(1, 0);
		}
		else {
			return segment[idx] = make_pair(0, 1);
		}
	}
	int mid = (st + ed) / 2;
	pair<int, int>left_node = update(st, mid, 2 * idx, target, val);
	pair<int, int>right_node = update(mid + 1, ed, 2 * idx + 1, target, val);
	return segment[idx] = make_pair(left_node.first + right_node.first, left_node.second + right_node.second);
}

void get_num(int st, int ed, int idx, int left, int right, int val) {
	if (right < st || ed < left) {
		return;
	}
	if (left <= st && ed <= right) {
		if (val == 2) {
			result += segment[idx].first;
		}
		else {
			result += segment[idx].second;
		}
		return;
	}
	int mid = (st + ed) / 2;
	get_num(st, mid, 2 * idx, left, right, val);
	get_num(mid + 1, ed, 2 * idx + 1, left, right, val);
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

	for (int i = 0; i < M; i ++) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, N, 1, b, c);
		}
		else {
			result = 0;
			get_num(1, N, 1, b, c, a);
			cout << result << "\n";
		}
	}

	return 0;
}