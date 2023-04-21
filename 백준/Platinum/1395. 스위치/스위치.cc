#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int N, M, a, b, c, onn;
vector<int>swi(100001);
vector<int>lazy(400000);
vector<pair<int, int>>segment(400000);

pair<int, int> make_tree(int st, int ed, int idx) {
	if (st == ed) {
		return segment[idx] = make_pair(1, 0);
	}
	int mid = (st + ed) / 2;
	pair<int, int> left_node = make_tree(st, mid, 2 * idx);
	pair<int, int> right_node = make_tree(mid + 1, ed, 2 * idx + 1);
	segment[idx].first = left_node.first + right_node.first;
	segment[idx].second = left_node.second + right_node.second;
	return segment[idx];
}

pair<int, int> update(int st, int ed, int idx, int left, int right, int upd) {
	lazy[idx] += upd;
	if (right < st || ed < left) {
		if (upd % 2 == 1) {
			int tmp = segment[idx].first;
			segment[idx].first = segment[idx].second;
			segment[idx].second = tmp;
		}
		return segment[idx];
	}
	if (left <= st && ed <= right) {
		lazy[idx] += 1;
		if ((upd+1) % 2 == 1) {
			int tmp = segment[idx].first;
			segment[idx].first = segment[idx].second;
			segment[idx].second = tmp;
		}
		return segment[idx];
	}
	int mid = (st + ed) / 2;
	pair<int, int>left_node = update(st, mid, 2 * idx, left, right, lazy[idx]);
	pair<int, int>right_node = update(mid + 1, ed, 2 * idx + 1, left, right, lazy[idx]);
	segment[idx].first = left_node.first + right_node.first;
	segment[idx].second = left_node.second + right_node.second;
	lazy[idx] = 0;
	return segment[idx];
}

void get_result(int st, int ed, int idx, int left, int right, int upd) {
	lazy[idx] += upd;
	if (upd % 2 == 1) {
		int tmp = segment[idx].first;
		segment[idx].first = segment[idx].second;
		segment[idx].second = tmp;
	}
	if (right < st || ed < left) {
		return;
	}
	if (left <= st && ed <= right) {
		onn += segment[idx].second;
		return;
	}
	int mid = (st + ed) / 2;
	get_result(st, mid, 2 * idx, left, right, lazy[idx]);
	get_result(mid + 1, ed, 2 * idx + 1, left, right, lazy[idx]);
	lazy[idx] = 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	make_tree(1, N, 1);

	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		if (a == 0) {
			update(1, N, 1, b, c, 0);
		}
		else {
			onn = 0;
			get_result(1, N, 1, b, c, 0);
			cout << onn << "\n";
		}
	}

	return 0;
}