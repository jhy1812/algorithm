#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, a, b, c, result;
vector<int>arr;
vector<vector<int>>segment(400000, vector<int>(1));

vector<int> make_tree(int st, int ed, int idx) {
	if (st == ed) {
		segment[idx].push_back(arr[st]);
		return segment[idx];
	}
	int mid = (st + ed) / 2;
	vector<int>left_node = make_tree(st, mid, 2 * idx);
	vector<int>right_node = make_tree(mid + 1, ed, 2 * idx + 1);
	int i = 1;
	int j = 1;
	while (true) {
		if (i >= int(left_node.size()) && j >= int(right_node.size())) {
			break;
		}
		if (i == int(left_node.size())) {
			segment[idx].push_back(right_node[j]);
			j += 1;
		}
		else if (j == int(right_node.size())) {
			segment[idx].push_back(left_node[i]);
			i += 1;
		}
		else if (left_node[i] > right_node[j]) {
			segment[idx].push_back(right_node[j]);
			j += 1;
		}
		else if (left_node[i] <= right_node[j]) {
			segment[idx].push_back(left_node[i]);
			i += 1;
		}
	}
	return segment[idx];
}

void get_result(int st, int ed, int idx, int left, int right, int val) {
	if (right < st || ed < left) {
		return;
	}
	if (left <= st && ed <= right) {
		result += int(segment[idx].size()) - int(upper_bound(segment[idx].begin(), segment[idx].end(), val) - segment[idx].begin());
		return;
	}
	int mid = (st + ed) / 2;
	get_result(st, mid, 2 * idx, left, right, val);
	get_result(mid + 1, ed, 2 * idx + 1, left, right, val);
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
	int last = 0;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		result = 0;
		a = (a ^ last);
		b = (b ^ last);
		c = (c ^ last);
		get_result(1, N, 1, a, b, c);
		last = result;
		cout << result << "\n";
	}
	return 0;
}