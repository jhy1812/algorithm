#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, A, B, C, tas;
vector<int>candy(1000001);
vector<int>segment(4000000);

void update(int st, int ed, int idx, int taste, int val) { // 사탕 넣었을 때 세그먼트 트리 업데이트
    if (taste < st || taste > ed) {
        return;
    }
    if (st == ed) {
        segment[idx] += val;
        return;
    }
    int mid = (st + ed) / 2;
    update(st, mid, 2 * idx, taste, val);
    update(mid + 1, ed, 2 * idx + 1, taste, val);
    segment[idx] += val;
}

int get_candy(int st, int ed, int idx, int target) {  // 어떤 맛을 꺼낼지 구하는 함수
    if (st == ed) {
        return st;
    }
    int mid = (st + ed) / 2;
    if (target > segment[2 * idx]) {
        return get_candy(mid + 1, ed, 2 * idx + 1, target - segment[2 * idx]);
    }
    else {
        return get_candy(st, mid, 2 * idx, target);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> A;
        if (A == 2) {
            cin >> B >> C;
            update(1, 1000000, 1, B, C);
        }
        else {
            cin >> B;
            int tmp = get_candy(1, 1000000, 1, B);
            cout << tmp << "\n";
            update(1, 1000000, 1, tmp, -1);
        }
    }
    return 0;
}