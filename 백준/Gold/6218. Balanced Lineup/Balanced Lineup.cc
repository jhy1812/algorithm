#include <iostream>
#include <algorithm>
#include <vector>

struct node {
	int max;
	int min;
};

int N, Q, maxx, minn;
std::vector<int> arr(50001, 0);
std::vector<node> segment(200000);

node make_tree(int st, int ed, int idx) {
	if (st == ed) {
		segment[idx].max = arr[st];
		segment[idx].min = arr[ed];
		return segment[idx];
	}

	int mid = (st + ed) / 2;
	
	node left_node = make_tree(st, mid, 2 * idx);
	node right_node = make_tree(mid + 1, ed, 2 * idx + 1);
	segment[idx].max = std::max(left_node.max, right_node.max);
	segment[idx].min = std::min(left_node.min, right_node.min);
	return segment[idx];
}

void get_result(int st, int ed, int idx, int left, int right) {
	if (right < st || ed < left) {
		return;
	}

	if (left <= st && ed <= right) {
		maxx = std::max(maxx, segment[idx].max);
		minn = std::min(minn, segment[idx].min);
		return;
	}

	int mid = (st + ed) / 2;
	get_result(st, mid, 2 * idx, left, right);
	get_result(mid + 1, ed, 2 * idx + 1, left, right);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> Q;

	for (int i = 1; i <= N; i++) {
		int tmp;
		std::cin >> tmp;
		arr[i] = tmp;
	}

	make_tree(1, N, 1);

	for (int i = 0; i < Q; i++) {
		int a, b;
		std::cin >> a >> b;
		maxx = 0;
		minn = 1000001;
		get_result(1, N, 1, a, b);
		std::cout << maxx - minn << "\n";
	}

	return 0;
}