#include <iostream>
#include <algorithm>
#include <vector>

int N;
std::vector<int> segment(400000, 0);
std::vector<int> lazy(400000, 0);
std::vector<int> flower(100001, 0);
std::vector<int> result;

void update_tree(int st, int ed, int idx, int left, int right, int upd, int day) {
	lazy[idx] += upd;
	segment[idx] += upd;
	if (right < st || ed < left) {
		return;
	}

	if (left < st && ed < right) {
		lazy[idx]++;
		segment[idx]++;
		return;
	}

	if (left == st && st == ed) {
		result[day] += segment[idx] - flower[left];
		flower[left] = segment[idx];
	}

	if (right == ed && st == ed) {
		result[day] += segment[idx] - flower[right];
		flower[right] = segment[idx];
	}

	if (st == ed) {
		return;
	}

	int mid = (st + ed) / 2;
	update_tree(st, mid, 2 * idx, left, right, lazy[idx], day);
	update_tree(mid + 1, ed, 2 * idx + 1, left, right, lazy[idx], day);
	lazy[idx] = 0;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		int a, b;
		std::cin >> a >> b;
		result.push_back(0);
		update_tree(1, 100000, 1, a, b, 0, i);
	}

	for (int i = 0; i < N; i++) {
		std::cout << result[i] << "\n";
	}
	
	return 0;
}