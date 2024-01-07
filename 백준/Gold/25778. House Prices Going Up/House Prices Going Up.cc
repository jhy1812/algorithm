#include <iostream>
#include <algorithm>
#include <vector>

int n, t;
long long result;
std::vector<int> arr(500001, 0);
std::vector<long long> segment(2000000, 0);

long long make_tree(int st, int ed, int idx) {
	if (st == ed) {
		return segment[idx] = arr[st];
	}

	int mid = (st + ed) / 2;
	return segment[idx] = make_tree(st, mid, 2 * idx) + make_tree(mid + 1, ed, 2 * idx + 1);
}

long long update_tree(int st, int ed, int idx, int target, int val) {
	if (target < st || ed < target) {
		return segment[idx];
	}

	if (st == target && target == ed) {
		return segment[idx] += val;
	}

	int mid = (st + ed) / 2;
	return segment[idx] = update_tree(st, mid, 2 * idx, target, val) + update_tree(mid + 1, ed, 2 * idx + 1, target, val);
}

long long get_result(int st, int ed, int idx, int left, int right) {

	if (right < st || ed < left) {
		return segment[idx];
	}

	if (left <= st && ed <= right) {
		result += segment[idx];
		return segment[idx];
	}

	if (st == ed) {
		return segment[idx];
	}

	int mid = (st + ed) / 2;
	return segment[idx] = get_result(st, mid, 2 * idx, left, right) + get_result(mid + 1, ed, 2 * idx + 1, left, right);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n;

	for (int i = 1; i <= n; i++) {
		int tmp;
		std::cin >> tmp;
		arr[i] = tmp;
	}

	make_tree(1, n, 1);

	std::cin >> t;

	for (int i = 0; i < t; i++) {
		char order;
		int a, b;
		std::cin >> order >> a >> b;
		if (order == 'U') {
			update_tree(1, n, 1, a, b);
		}
		else {
			result = 0;
			get_result(1, n, 1, a, b);
			std::cout << result << "\n";
		}
	}

	return 0;
}