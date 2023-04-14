#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, a, b, c, d;
long long result;
vector<int>arr;
vector<long long>segment(400000);
vector<long long>lazy(400000);

long long make_tree(int st, int ed, int idx) {
	if (st == ed) {
		return segment[idx] = arr[st];
	}
	int mid = (st + ed) / 2;
	return segment[idx] = make_tree(st, mid, 2 * idx) + make_tree(mid + 1, ed, 2 * idx + 1);
}

void save_lazy(int st, int ed, int idx, int left, int right, int val) {
	if (right < st || ed < left) {
		return;
	}
	if (left <= st && ed <= right) {
		segment[idx] += (ed - st + 1)*val;
		lazy[idx] += val;
		return;
	}
	int mid = (st + ed) / 2;
	save_lazy(st, mid, 2 * idx, left, right, val);
	save_lazy(mid + 1, ed, 2 * idx + 1, left, right, val);
}

void get_result(int st, int ed, int idx, int target, long long val) {
	lazy[idx] += val;
	segment[idx] += (ed - st + 1)*val;
	if (target < st || ed < target) {
		return;
	}
	if (st == ed) {
		result = segment[idx];
		return;
	}
	int mid = (st + ed) / 2;
	get_result(st, mid, 2 * idx, target, lazy[idx]);
	get_result(mid + 1, ed, 2 * idx + 1, target, lazy[idx]);
	lazy[idx] = 0;
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	arr.push_back(0);

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}

	make_tree(1, N, 1);

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		if (a == 1) {
			cin >> c >> d;
			save_lazy(1, N, 1, b, c, d);
		}
		else {
			result = 0;
			get_result(1, N, 1, b, 0);
			cout << result << "\n";
		}
	}
	return 0;
}