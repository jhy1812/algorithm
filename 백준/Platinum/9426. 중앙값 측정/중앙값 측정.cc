#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_VAL 65536

int N, K;
long long result;
std::vector<int> temp(1, 0);
std::vector<int> segment(4*MAX_VAL, 0);

int update_tree(int st, int ed, int idx, int val, int state) {
	if (val < st || ed < val) {
		return segment[idx];
	}

	if (st == ed) {
		segment[idx] += state;
		return segment[idx];
	}

	int mid = (st + ed) / 2;

	return segment[idx] = update_tree(st, mid, 2 * idx, val, state) + update_tree(mid + 1, ed, 2 * idx + 1, val, state);
}

int get_result(int st, int ed, int idx, int target) {
	if (segment[idx] < target) {
		return segment[idx];
	}

	if (st == ed) {
		result += st;
		return segment[idx];
	}

	int mid = (st + ed) / 2;
	
	int ln = get_result(st, mid, 2 * idx, target);

	if (target - ln > 0) {
		int rn = get_result(mid + 1, ed, 2 * idx + 1, target - ln);
	}
	return segment[idx];
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int tmp;
		std::cin >> tmp;
		temp.push_back(tmp);
	}

	for (int i = 1; i <= K; i++) {
		update_tree(0, MAX_VAL, 1, temp[i], 1);
	}

	get_result(0, MAX_VAL, 1, (K + 1) / 2);

	for (int i = K + 1; i <= N; i++) {
		update_tree(0, MAX_VAL, 1, temp[i - K], -1);
		update_tree(0, MAX_VAL, 1, temp[i], 1);
		get_result(0, MAX_VAL, 1, (K + 1) / 2);
	}

	std::cout << result;

	return 0;
}