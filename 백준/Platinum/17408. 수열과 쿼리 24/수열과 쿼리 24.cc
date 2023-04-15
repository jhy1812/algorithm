#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, a, b, c;
pair<int, int>result;
vector<int>arr;
vector<pair<int, int>>segment(400000);

pair<int, int> make_tree(int st, int ed, int idx) {
	if (st == ed) {
		return segment[idx] = make_pair(arr[st], 0);
	}
	int mid = (st + ed) / 2;
	pair<int, int>left_node = make_tree(st, mid, 2 * idx);
	pair<int, int>right_node = make_tree(mid + 1, ed, 2 * idx + 1);
	if (left_node.first >= right_node.first) {
		segment[idx].first = left_node.first;
		if (right_node.first >= left_node.second) {
			segment[idx].second = right_node.first;
		}
		else {
			segment[idx].second = left_node.second;
		}
	}
	else {
		segment[idx].first = right_node.first;
		if (left_node.first >= right_node.second) {
			segment[idx].second = left_node.first;
		}
		else {
			segment[idx].second = right_node.second;
		}
	}
	return segment[idx];
}

pair<int, int> update_tree(int st, int ed, int idx, int target, int val) {
	if (target < st || ed < target) {
		return segment[idx];
	}
	if (st == ed) {
		return segment[idx] = make_pair(val, 0);
	}
	int mid = (st + ed) / 2;
	pair<int, int>left_node = update_tree(st, mid, 2 * idx, target, val);
	pair<int, int>right_node = update_tree(mid + 1, ed, 2 * idx + 1, target, val);
	if (left_node.first >= right_node.first) {
		segment[idx].first = left_node.first;
		if (right_node.first >= left_node.second) {
			segment[idx].second = right_node.first;
		}
		else {
			segment[idx].second = left_node.second;
		}
	}
	else {
		segment[idx].first = right_node.first;
		if (left_node.first >= right_node.second) {
			segment[idx].second = left_node.first;
		}
		else {
			segment[idx].second = right_node.second;
		}
	}
	return segment[idx];
}

void get_result(int st, int ed, int idx, int left, int right) {
	if (right < st || ed < left) {
		return;
	}
	if (left <= st && ed <= right) {
		if (result.first >= segment[idx].first) {
			if (segment[idx].first > result.second) {
				result.second = segment[idx].first;
			}
		}
		else {
			int tmp = result.first;
			result.first = segment[idx].first;
			if (tmp >= segment[idx].second) {
				result.second = tmp;
			}
			else {
				result.second = segment[idx].second;
			}
		}
		return;
	}
	int mid = (st + ed) / 2;
	get_result(st, mid, 2 * idx, left, right);
	get_result(mid + 1, ed, 2 * idx + 1, left, right);
	return;
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
			update_tree(1, N, 1, b, c);
		}
		else {
			result = make_pair(0, 0);
			get_result(1, N, 1, b, c);
			cout << result.first + result.second << "\n";
		}
	}

	return 0;
}