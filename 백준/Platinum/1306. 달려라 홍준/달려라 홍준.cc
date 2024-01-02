#include <iostream>
#include <algorithm>
#include <vector>

int N, M, result;
std::vector<int> ad;
std::vector<int> segment(4000000, 0);

int make_tree(int st, int ed, int idx) {
	if (st == ed) {
		return segment[idx] = ad[st];
	}

	int mid = (st + ed) / 2;
	return segment[idx] = std::max(make_tree(st, mid, 2 * idx), make_tree(mid + 1, ed, 2 * idx + 1));
}

void get_result(int st, int ed, int idx, int left, int right) {
	if (right < st || ed < left) {
		return;
	}

	if (left <= st && ed <= right) {
		result = std::max(segment[idx], result);
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

	std::cin >> N >> M;

	ad.push_back(0);

	for (int i = 0; i < N; i++) {
		int tmp;
		std::cin >> tmp;
		ad.push_back(tmp);
	}

	make_tree(1, N, 1);

	for (int i = M; i <= N - M + 1; i++) {
		result = 0;
		get_result(1, N, 1, i - M + 1, i + M - 1);
		std::cout << result << " ";
	}

	return 0;
}