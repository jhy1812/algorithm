#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, a, b, minn;
vector<int>arr;
vector<int>segment(400000);

int make_tree(int st, int ed, int idx) {
	if (st == ed) {
		return segment[idx] = arr[st];
	}
	int mid = (st + ed) / 2;
	return segment[idx] = min(make_tree(st, mid, 2 * idx), make_tree(mid + 1, ed, 2 * idx + 1));
}

void get_minn(int st, int ed, int idx, int left, int right) {
	if (left > ed || right < st) {
		return;
	}
	if (left <= st && ed <= right) {
		minn = min(minn, segment[idx]);
		return;
	}
	int mid = (st + ed) / 2;
	get_minn(st, mid, 2 * idx, left, right);
	get_minn(mid+1, ed, 2 * idx + 1, left, right);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	arr.push_back(0);


	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}

	make_tree(1, N, 1);

	for (int i = 0; i < M; i++) {
		minn = 1e9;
		cin >> a >> b;
		get_minn(1, N, 1, a, b);
		cout << minn << "\n";
	}

	return 0;
}