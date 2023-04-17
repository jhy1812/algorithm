#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
long long a, b, c, d, result;
vector<long long>arr;
vector<long long>segment(4000000);
vector<long long>lazy(4000000);

long long make_tree(int st, int ed, int idx) {
	if (st == ed) {
		return segment[idx] = arr[st];
	}
	int mid = (st + ed) / 2;
	return segment[idx] = make_tree(st, mid, 2 * idx) + make_tree(mid + 1, ed, 2 * idx + 1);
}

long long update_tree(int st, int ed, int idx, long long left, long long right, long long val, long long upd) {
	lazy[idx] += upd;
	if (right < st || ed < left) {
		segment[idx] += (ed - st + 1)*upd;
		return segment[idx];
	}
	if (left <= st && ed <= right) {
		lazy[idx] += val;
		segment[idx] += (ed - st + 1)*upd;
		segment[idx] += (ed - st + 1) * val;
		return segment[idx];
	}
	int mid = (st + ed) / 2;
	segment[idx] = update_tree(st, mid, 2 * idx, left, right, val, lazy[idx]) + update_tree(mid + 1, ed, 2 * idx + 1, left, right, val, lazy[idx]);
	lazy[idx] = 0;
	return segment[idx];
}

void get_result(int st, int ed, int idx, long long left, long long right, long long val) {
	lazy[idx] += val;
	segment[idx] += (ed - st + 1)*val;
	if (right < st || ed < left) {
		return;
	}
	if (left <= st && ed <= right) {
		result += segment[idx];
		return;
	}
	int mid = (st + ed) / 2;
	get_result(st, mid, 2 * idx, left, right, lazy[idx]);
	get_result(mid + 1, ed, 2 * idx + 1, left, right, lazy[idx]);
	lazy[idx] = 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	arr.push_back(0);

	for (int i = 0; i < N; i++) {
		long long tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}

	make_tree(1, N, 1);

	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			cin >> d;
			update_tree(1, N, 1, b, c, d, 0);
		}
		else {
			result = 0;
			get_result(1, N, 1, b, c, 0);
			cout << result << "\n";
		}
	}
	return 0;
}