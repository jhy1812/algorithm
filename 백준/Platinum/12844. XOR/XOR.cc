#include <iostream>
#include <algorithm>

int N, M, result;
int arr[500001];
int segment[2000000];
int lazy[2000000];

int make_segment(int st, int ed, int idx) {
	if (st == ed) {
		return segment[idx] = arr[st];
	}
	int mid = (st + ed) / 2;
	return segment[idx] = make_segment(st, mid, 2 * idx) ^ make_segment(mid + 1, ed, 2 * idx + 1);
}

int update_tree(int st, int ed, int idx, int left, int right, int upd, int val) {
	lazy[idx] = lazy[idx] ^ upd;
	if ((ed - st) % 2 == 0) {
		segment[idx] = segment[idx] ^ upd;
	}
	if (right < st || ed < left) {
		return segment[idx];
	}
	if (left <= st && ed <= right) {
		if ((ed - st) % 2 == 0) {
			segment[idx] = segment[idx] ^ val;
		}
		lazy[idx] = lazy[idx] ^ val;
		return segment[idx];
	}
	int mid = (st + ed) / 2;
	segment[idx] = update_tree(st, mid, 2 * idx, left, right, lazy[idx], val) ^ update_tree(mid + 1, ed, 2 * idx + 1, left, right, lazy[idx], val);
	lazy[idx] = 0;
	return segment[idx];
}

int get_result(int st, int ed, int idx, int left, int right, int upd) {
	lazy[idx] = lazy[idx] ^ upd;
	if ((ed - st) % 2 == 0) {
		segment[idx] = segment[idx] ^ upd;
	}
	if (right < st || ed < left) {
		return segment[idx];
	}
	if (left <= st && ed <= right) {
		result = result ^ segment[idx];
		return segment[idx];
	}
	int mid = (st + ed) / 2;
	segment[idx] = get_result(st, mid, 2 * idx, left, right, lazy[idx]) ^ get_result(mid + 1, ed, 2 * idx + 1, left, right, lazy[idx]);
	lazy[idx] = 0;
	return segment[idx];
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	for (int i = 1; i <= N; i++) {
		int tmp;
		std::cin >> tmp;
		arr[i] = tmp;
	}

	make_segment(1, N, 1);

	std::cin >> M;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		std::cin >> a >> b >> c;
		if (b > c) {
			int tmp = b;
			b = c;
			c = tmp;
		}
		if (a == 1) {
			int d;
			std::cin >> d;
			update_tree(1, N, 1, b + 1, c + 1, 0, d);
		}
		else {
			result = 0;
			get_result(1, N, 1, b + 1, c + 1, 0);
			std::cout << result << "\n";
		}
	}

	return 0;
}