#include <iostream>
#include <algorithm>
#include <vector>

int n, m, result;
std::vector<int> arr(1);
std::vector<int> segment(2000000);

void make_tree(int st, int ed, int idx) {
	if (st == ed) {
		segment[idx] = arr[st];
		return;
	}
	int mid = (st + ed) / 2;
	make_tree(st, mid, 2 * idx);
	make_tree(mid + 1, ed, 2 * idx + 1);
	return;
}

void update_tree(int st, int ed, int idx, int left, int right, int upd, int val) {
	segment[idx] = segment[idx] ^ upd;
	if (right < st || ed < left) {
		return;
	}
	if (left <= st && ed <= right) {
		segment[idx] = segment[idx] ^ val;
		return;
	}
	int mid = (st + ed) / 2;
	update_tree(st, mid, 2 * idx, left, right, segment[idx], val);
	update_tree(mid + 1, ed, 2 * idx + 1, left, right, segment[idx], val);
	segment[idx] = 0;
	return;
}

void get_result(int st, int ed, int idx, int target, int upd) {
	segment[idx] = segment[idx] ^ upd;
	if (target < st || ed < target) {
		return;
	}
	if (st == ed) {
		result = segment[idx];
		return;
	}
	int mid = (st + ed) / 2;
	get_result(st, mid, 2 * idx, target, segment[idx]);
	get_result(mid + 1, ed, 2 * idx + 1, target, segment[idx]);
	segment[idx] = 0;
	return;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp;
		std::cin >> tmp;
		arr.push_back(tmp);
	}

	make_tree(1, n, 1);

	std::cin >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		std::cin >> a >> b;
		if (a == 1) {
			int c, d;
			std::cin >> c >> d;
			update_tree(1, n, 1, b + 1, c + 1, 0, d);
		}
		else {
			get_result(1, n, 1, b + 1, 0);
			std::cout << result << "\n";
		}
	}

	return 0;
}