#include <iostream>
#include <vector>
#include <algorithm>

int N, Q;
long long result;
std::vector<int>arr(1);
std::vector<long long>segment(400000);

long long make_tree(int st, int ed, int idx) {
	if (st == ed) {
		return segment[idx] = arr[st];
	}
	int mid = (st + ed) / 2;
	return segment[idx] = make_tree(st, mid, 2 * idx) + make_tree(mid + 1, ed, 2 * idx + 1);
}

void get_result(int st, int ed, int idx, int left, int right) {
	if (right < st || ed < left) {
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

long long update_tree(int st, int ed, int idx, int target, int val) {
	if (target < st || ed < target) {
		return segment[idx];
	}
	if (st == ed) {
		return segment[idx] = val;
	}
	int mid = (st + ed) / 2;
	return segment[idx] = update_tree(st, mid, 2 * idx, target, val) + update_tree(mid + 1, ed, 2 * idx + 1, target, val);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> Q;

	for (int i = 0; i < N; i++) {
		int tmp;
		std::cin >> tmp;
		arr.push_back(tmp);
	}

	make_tree(1, N, 1);
	
	for (int i = 0; i < Q; i++) {
		int a, b, c, d;
		std::cin >> a >> b >> c >> d;
		result = 0;
		if (a <= b) {
			get_result(1, N, 1, a, b);
		}
		else {
			get_result(1, N, 1, b, a);
		}
		std::cout << result << "\n";
		update_tree(1, N, 1, c, d);
	}
	

	return 0;
}