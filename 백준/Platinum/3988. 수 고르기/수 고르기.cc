#include <iostream>
#include <algorithm>
#include <vector>

#define MaxVal 100000000

struct node {
	int max;
	int min;
	int lm;
	int rm;
	int m;
};

int N, K, m, M, result, maxx, minn;
std::vector<int> arr;
std::vector<node> segment(4000000);

node make_tree(int st, int ed, int idx) {
	segment[idx].m = MaxVal;

	if (st == ed) {
		segment[idx].max = arr[st];
		segment[idx].min = arr[st];
		if (st > 0) {
			segment[idx].lm = arr[st] - arr[st - 1];
		}
		else{
			segment[idx].lm = MaxVal;
		}
		if (st < N - 1) {
			segment[idx].rm = arr[st + 1] - arr[st];
		}
		else {
			segment[idx].rm = MaxVal;
		}

		return segment[idx];
	}

	int mid = (st + ed) / 2;

	node ln = make_tree(st, mid, 2 * idx);
	node rn = make_tree(mid + 1, ed, 2 * idx + 1);

	segment[idx].max = std::max(ln.max, rn.max);
	segment[idx].min = std::min(ln.min, rn.min);
	segment[idx].lm = std::min(ln.lm, rn.lm);
	segment[idx].rm = std::min(ln.rm, rn.rm);
	segment[idx].m = std::min(segment[idx].m, ln.m);
	segment[idx].m = std::min(segment[idx].m, rn.m);
	segment[idx].m = std::min(segment[idx].m, ln.rm);
	segment[idx].m = std::min(segment[idx].m, rn.lm);
	
	return segment[idx];
}

void get_result(int st, int ed, int idx, int left, int right) {

	if (right < st || ed < left) {
		return;
	}

	if (left <= st && ed <= right) {
		if (left != st) {
			m = std::min(m, segment[idx].lm);
		}
		if (right != ed) {
			m = std::min(m, segment[idx].rm);
		}

		m = std::min(m, segment[idx].m);

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

	std::cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int tmp;
		std::cin >> tmp;
		arr.push_back(tmp);
	}

	std::sort(arr.begin(), arr.end());

	result = MaxVal;

	make_tree(0, N - 1, 1);

	for (int i = 0; i < K + 1; i++) {
		M = MaxVal;
		m = MaxVal;
		maxx = -MaxVal;
		minn = MaxVal;
		get_result(0, N - 1, 1, i, N - (K - i + 1));
		M = std::min(M, maxx - minn);
		result = std::min(result, M + m);
	}

	std::cout << result;

	return 0;
}