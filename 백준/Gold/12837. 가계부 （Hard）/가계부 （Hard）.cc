#include <iostream>
#include <vector>
#include <algorithm>

int N, Q;
long long result;
std::vector<long long>segment(4000000);

long long update_tree(int st, int ed, int idx, int target, int val) {
	if (target < st || ed < target) {
		return segment[idx];
	}
	if (st == ed) {
		segment[idx] += val;
		return segment[idx];
	}
	int mid = (st + ed) / 2;
	return segment[idx] = update_tree(st, mid, 2 * idx, target, val) + update_tree(mid + 1, ed, 2 * idx + 1, target, val);
}

void get_result(int st, int ed, int idx, int left, int right) {
	if (right < st | ed < left) {
		return;
	}
	if (left <= st && ed <= right) {
		result += segment[idx];
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

	for (int i = 0; i < Q; i++) {
		int a, b, c;
		std::cin >> a >> b >> c;
		if (a == 1) {
			update_tree(1, N, 1, b, c);
		}
		else {
			result = 0;
			get_result(1, N, 1, b, c);
			std::cout << result << "\n";
		}
	}

	return 0;
}