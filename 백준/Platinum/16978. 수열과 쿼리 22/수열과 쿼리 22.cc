#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct q2
{
	int k;
	int lef;
	int rig;
	int num;
};

int N, M, a, b, c, d, now;
vector<int>arr;
vector<long long>segment(400000);
vector<pair<int, int>>query(1);
vector<q2>query2;
vector<long long>result(100001);

bool compare(q2 a, q2 b) {
	return a.k < b.k;
}

long long make_tree(int st, int ed, int idx) {
	if (st == ed) {
		return segment[idx] = arr[st];
	}
	int mid = (st + ed) / 2;
	return segment[idx] = make_tree(st, mid, 2 * idx) + make_tree(mid + 1, ed, 2 * idx + 1);
}

long long update(int st, int ed, int idx, int target, int val) {
	if (target < st || ed < target) {
		return segment[idx];
	}
	if (st == ed) {
		return segment[idx] = val;
	}
	int mid = (st + ed) / 2;
	return segment[idx] = update(st, mid, 2 * idx, target, val) + update(mid + 1, ed, 2 * idx + 1, target, val);

}

void get_result(int st, int ed, int idx, int left, int right, int number) {
	if (right < st || ed < left) {
		return;
	}
	if (left <= st && ed <= right) {
		result[number] += segment[idx];
		return;
	}
	int mid = (st + ed) / 2;
	get_result(st, mid, 2 * idx, left, right, number);
	get_result(mid + 1, ed, 2 * idx + 1, left, right, number);
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
	int cnt = 1;

	for (int i = 1; i <= M; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			query.push_back(make_pair(b, c));
		}
		else {
			cin >> d;
			q2 tmp;
			tmp.k = b;
			tmp.lef = c;
			tmp.rig = d;
			tmp.num = cnt;
			query2.push_back(tmp);
			cnt += 1;
		}
	}
	sort(query2.begin(), query2.end(), compare);

	if (cnt > 2) {
		if (int(query.size()) > 1) {
			for (int i = 1; i <= query2[0].k; i++) {
				update(1, N, 1, query[i].first, query[i].second);
			}
		}
		get_result(1, N, 1, query2[0].lef, query2[0].rig, query2[0].num);
	}

	for (int i = 1; i < cnt - 1; i++) {
		if (query2[i].k > query2[i - 1].k) {
			for (int j = query2[i - 1].k + 1; j <= query2[i].k; j++) {
				update(1, N, 1, query[j].first, query[j].second);
			}
			get_result(1, N, 1, query2[i].lef, query2[i].rig, query2[i].num);
		}
		else {
			get_result(1, N, 1, query2[i].lef, query2[i].rig, query2[i].num);
		}
	}

	for (int i = 1; i < cnt; i++) {
		cout << result[i] << "\n";
	}

	return 0;
}