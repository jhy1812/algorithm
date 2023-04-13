#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, minn, spot;
int a, b, c;
vector<int>arr;
vector<pair<int, int>>segment(400000);

pair<int, int> make_tree(int st, int ed, int idx) {
	if (st == ed) {
		return segment[idx] = make_pair(st, arr[st]);
	}
	int mid = (st + ed) / 2;
	pair<int, int>left_node = make_tree(st, mid, 2 * idx);
	pair<int, int>right_node = make_tree(mid + 1, ed, 2 * idx + 1);
	if (left_node.second <= right_node.second) {
		return segment[idx] = left_node;
	}
	else {
		return segment[idx] = right_node;
	}
}

pair<int, int> update(int st, int ed, int idx, int target, int val) {
	if (target < st || ed < target) {
		return segment[idx];
	}
	if (st == ed) {
		return segment[idx] = make_pair(target, val);
	}
	int mid = (st + ed) / 2;
	pair<int, int>left_node = update(st, mid, 2 * idx, target, val);
	pair<int, int>right_node = update(mid + 1, ed, 2 * idx + 1, target, val);
	if (left_node.second <= right_node.second) {
		return segment[idx] = left_node;
	}
	else {
		return segment[idx] = right_node;
	}
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
		cin >> a;
		if (a == 1) {
			cin >> b >> c;
			update(1, N, 1, b, c);
		}
		else {
			cout << segment[1].first << "\n";
		}
	}

	return 0;
}