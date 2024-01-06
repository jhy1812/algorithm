#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int N, K, result;
std::vector<int> arr(100001, 0);
std::vector<int> segment(400000, 0);

int make_tree(int st, int ed, int idx) {
	if (st == ed) {
		if (arr[st] < 0) {
			return segment[idx] = -1;
		}
		else if (arr[st] > 0) {
			return segment[idx] = 1;
		}
		else {
			return segment[idx] = 0;
		}
	}

	int mid = (st + ed) / 2;

	return segment[idx] = make_tree(st, mid, 2 * idx) * make_tree(mid + 1, ed, 2 * idx + 1);
}

int update_tree(int st, int ed, int idx, int target, int val) {
	if (target < st || ed < target) {
		return segment[idx];
	}

	if (st == ed && target == st) {
		if (val < 0) {
			return segment[idx] = -1;
		}
		else if (val > 0) {
			return segment[idx] = 1;
		}
		else {
			return segment[idx] = 0;
		}
	}

	if (st == ed) {
		return segment[idx];
	}

	int mid = (st + ed) / 2;

	return segment[idx] = update_tree(st, mid, 2 * idx, target, val) * update_tree(mid + 1, ed, 2 * idx + 1, target, val);
}

void get_result(int st, int ed, int idx, int left, int right) {
	if (right < st || ed < left) {
		return;
	}

	if (left <= st && ed <= right) {
		result *= segment[idx];
		return;
	}

	if (st == ed) {
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

	while (std::cin >> N >> K) {
		for (int i = 1; i <= N; i++) {
			int tmp;
			std::cin >> tmp;
			arr[i] = tmp;
		}

		make_tree(1, N, 1);

		for (int i = 0; i < K; i++) {
			char order;
			int a, b;
			std::cin >> order >> a >> b;

			if (order == 'C') {
				update_tree(1, N, 1, a, b);
			}
			else {
				result = 1;
				get_result(1, N, 1, a, b);
				if (result < 0) {
					std::cout << "-";
				}
				else if (result > 0) {
					std::cout << "+";
				}
				else {
					std::cout << 0;
				}
			}
		}
		std::cout << "\n";
	}

	return 0;
}