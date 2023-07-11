#include <iostream>
#include <vector>
#include <algorithm>

int N;
long long result;
std::vector<int> arr(1);
std::vector<std::vector<int>> segment(2000000, std::vector<int>());

std::vector<int> make_tree(int st, int ed, int idx) {
	if (st == ed) {
		segment[idx].push_back(arr[st]);
		return segment[idx];
	}
	int mid = (st + ed) / 2;
	std::vector<int> left_node = make_tree(st, mid, 2 * idx);
	std::vector<int> right_node = make_tree(mid + 1, ed, 2 * idx + 1);
	int i = 0;
	int j = 0; 
	while (true) {
		if (i >= int(left_node.size()) && j >= int(right_node.size())) {
			break;
		}
		else if (i >= int(left_node.size())) {
			segment[idx].push_back(right_node[j]);
			j++;
		}
		else if (j >= int(right_node.size())) {
			segment[idx].push_back(left_node[i]);
			i++;
		}
		else if (left_node[i] <= right_node[j]) {
			segment[idx].push_back(left_node[i]);
			i++;
		}
		else if (left_node[i] > right_node[j]) {
			segment[idx].push_back(right_node[j]);
			j++;
		}
	}
	return segment[idx];
}

void get_result(int st, int ed, int idx, int left, int target) {
	if (ed <= left) {
		return;
	}
	if (st > left) {
		result += int(std::lower_bound(segment[idx].begin(), segment[idx].end(), target) - segment[idx].begin());
		return;
	}
	int mid = (st + ed) / 2;
	get_result(st, mid, 2 * idx, left, target);
	get_result(mid + 1, ed, 2 * idx + 1, left, target);
	return;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		std::cin >> tmp;
		arr.push_back(tmp);
	}

	make_tree(1, N, 1);

	for (int i = 1; i < N; i++) {
		get_result(1, N, 1, i, arr[i]);
	}

	std::cout << result;

	return 0;
}