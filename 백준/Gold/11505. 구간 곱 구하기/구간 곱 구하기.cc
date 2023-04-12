#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K, a;
long long int b, c, result;
long long int divi = 1000000007;
vector<long long int>arr;
vector<long long int>segment(4000000);

long long int make_tree(int st, int ed, int idx) {
	if (st == ed) {
		return segment[idx] = (arr[st]%divi);
	}
	int mid = (st + ed) / 2;
	segment[idx] = (make_tree(st, mid, 2 * idx)*make_tree(mid + 1, ed, 2 * idx + 1)) % divi;
	return segment[idx];
}

long long int update_tree(int st, int ed, int idx, long long int target, long long int val) {
	if (target < st || target > ed) {
		return segment[idx]%divi;
	}
	if (st == ed) {
		return segment[idx] = val%divi;
	}
	int mid = (st + ed) / 2;
	segment[idx] = ((update_tree(st, mid, 2 * idx, target, val) % divi)*(update_tree(mid + 1, ed, 2 * idx + 1, target, val) % divi)) % divi;
	return segment[idx] % divi;
}

long long int get_mul(int st, int ed, int idx, long long int left, long long int right) {
	if (left > ed || right < st) {
		return 1;
	}
	if (left <= st && ed <= right) {
		return segment[idx];
	}
	int mid = (st + ed) / 2;
	return (get_mul(st, mid, 2 * idx, left, right)*get_mul(mid + 1, ed, 2 * idx + 1, left, right))%divi;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	arr.push_back(0);

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp%divi);
	}
	
	make_tree(1, N, 1);

	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			update_tree(1, N, 1, b, c);
		}
		else {
			cout << get_mul(1, N, 1, b, c) << "\n";
		}
	}
	return 0;
}