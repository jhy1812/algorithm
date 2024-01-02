#include <iostream>
#include <algorithm>
#include <vector>

struct node
{
	int num;
	long long val;
};

int N, Q;
long long result;
std::vector<int> star;
std::vector<node> segment(2000000);

void make_tree(int st, int ed, int idx) {
	if (st == ed) {
		segment[idx].val = star[st];
		return;
	}
	int mid = (st + ed) / 2;
	make_tree(st, mid, 2 * idx);
	make_tree(mid + 1, ed, 2 * idx + 1);
}

void update_tree(int st, int ed, int idx, int left, int right, long long upd, int nupd) {
	segment[idx].val += upd;
	segment[idx].num += nupd;
	if (right < st || ed < left) {
		return;
	}

	if (left <= st && ed <= right) {
		segment[idx].val += st - left + 1;
		segment[idx].num++;
		return;
	}

	if (st == ed) {
		return;
	}

	int mid = (st + ed) / 2;
	update_tree(st, mid, 2 * idx, left, right, segment[idx].val, segment[idx].num);
	if (segment[idx].val == 0) {
		update_tree(mid + 1, ed, 2 * idx + 1, left, right, segment[idx].val, segment[idx].num);
	}
	else {
		update_tree(mid + 1, ed, 2 * idx + 1, left, right, segment[idx].val + segment[idx].num * (mid - st + 1), segment[idx].num);
	}
	segment[idx].val = 0;
	segment[idx].num = 0;
}

void get_result(int st, int ed, int idx, long long upd, int nupd, int target) {
	segment[idx].val += upd;
	segment[idx].num += nupd;
	if (target < st || ed < target) {
		return;
	}

	if (st == ed && st == target) {
		result = segment[idx].val;
		return;
	}

	if (st == ed) {
		return;
	}

	int mid = (st + ed) / 2;
	get_result(st, mid, 2 * idx, segment[idx].val, segment[idx].num, target);
	if (segment[idx].val == 0) {
		get_result(mid + 1, ed, 2 * idx + 1, segment[idx].val, segment[idx].num, target);
	}
	else {
		get_result(mid + 1, ed, 2 * idx + 1, segment[idx].val + segment[idx].num * (mid - st + 1), segment[idx].num, target);
	}
	segment[idx].val = 0;
	segment[idx].num = 0;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	star.push_back(0);

	for (int i = 0; i < N; i++) {
		int tmp;
		std::cin >> tmp;
		star.push_back(tmp);
	}

	make_tree(1, N, 1);

	std::cin >> Q;

	for (int i = 0; i < Q; i++) {
		int q;
		std::cin >> q;
		int a, b;
		result = 0;
		if (q == 1) {
			std::cin >> a >> b;
			update_tree(1, N, 1, a, b, 0, 0);
		}
		else {
			std::cin >> a;
			get_result(1, N, 1, 0, 0, a);
			std::cout << result << "\n";
		}
	}

	return 0;
}