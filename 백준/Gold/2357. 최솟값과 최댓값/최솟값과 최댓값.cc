#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, a, b;		// N - 정수 개수, M - 최대, 최소 구할 구간 수, a - 구간 시작, b - 구간 끝
long long int maxx, minn;
vector<long long int>arr;	// 정수 저장할 벡터
vector<pair<long long int, long long int>>segment(400000);	// 각 구간별 최대 최소 저장할 세그먼트 트리

pair<long long int, long long int> make_tree(int st, int ed, int idx) { // 세그먼트 트르 만들 함수
	if (st == ed) {		// 리프노드라면
		segment[idx] = make_pair(arr[st], arr[st]);	// 대응되는 배열의 수 저장 후 반환
		return segment[idx];
	}
	int mid = (st + ed) / 2;		
	pair<long long int, long long int>tmp1 = make_tree(st, mid, 2 * idx);		// 자식 노드들로 가서 최대 최소 쌍 가져오기
	pair<long long int, long long int>tmp2 = make_tree(mid + 1, ed, 2 * idx + 1);

	segment[idx].first = max(tmp1.first, tmp2.first);		// 가져온 쌍들을 비교하여 최대 최소 저장
	segment[idx].second = min(tmp1.second, tmp2.second);

	return segment[idx];
}

void get_result(int st, int ed, int idx, int left, int right) {		// 최대 최소 구할 함수	
	if (left > ed || right < st) {	// 노드의 구간이 벗어난 구간이면 리턴
		return;
	}
	if (left <= st && ed <= right) {// 노드의 구간이 최대 최소 구하려는 구간에 포함되어 있으면 
		maxx = max(maxx, segment[idx].first);	// 최댓값, 최솟값 갱신
		minn = min(minn, segment[idx].second);
		return;
	}
	int mid = (st + ed) / 2;
	get_result(st, mid, 2 * idx, left, right);		// 자식 노드 탐색
	get_result(mid + 1, ed, 2 * idx + 1, left, right);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	arr.push_back(0);

	for (int i = 0; i < N; i++) {
		long long int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}

	make_tree(1, N, 1);

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		maxx = 0;
		minn = 1000000000;
		get_result(1, N, 1, a, b);
		cout << minn << " " << maxx << "\n";
	}

	return 0;
}