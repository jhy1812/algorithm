#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K, a, b;          // N - 수의 개수, M - 수 변경 횟수, K - 합을 구하는 횟수
long long int c, summ;      // a -> 1(수 변경) or 2(구간 합 구하기)
vector<long long int>arr;   // 수열 저장할 벡터
vector<long long int>segment(3000000);  // 세그먼트 트리 저장할 벡터

long long int make_tree(int st, int ed, int idx) {      // 수열을 세그먼트 트리 구조로 저장하는 함수
    if (st == ed) {     // 리프 노드면
        segment[idx] = arr[st];     // 대응되는 수열의 값 저장 후 반환
        return segment[idx];
    }
    int mid = (st + ed) / 2;        // 현재 노드의 구간합 중간 인덱스
    segment[idx] = make_tree(st, mid, idx * 2) + make_tree(mid + 1, ed, idx * 2 + 1); // 현재 노드의 값은 자식 노드들의 합
    return segment[idx];
}

void update(int st, int ed, int idx, long long int diff, int spot) {    // 수열의 특정 수가 바뀌었을 때 
    if (spot < st || ed < spot) {                                       // 세그먼트 트리 업데이트하는 함수
        return;         // 업데이트 하려는 구간이 아니면 리턴
    }
    if (st == ed) {     // 리프노드 업데이트 후 리턴
        segment[idx] += diff;
        return;
    }
    int mid = (st + ed) / 2;
    update(st, mid, 2 * idx, diff, spot);   // 자식노드들 방문
    update(mid + 1, ed, 2 * idx + 1, diff, spot);
    segment[idx] += diff;
}

void get_sum(int st, int ed, int left, long long int right, int idx) {  // 구간합 구하는 함수
    if (right < st || left > ed) {      // 현재 노드가 구하려는 범위 벗어난 노드면 리턴
        return;
    }
    if (left <= st && ed <= right) {    // 현재 노드의 구간이 구하려는 범위에 포함되어 있으면
        summ += segment[idx];           // 더해주고 리턴
        return;
    }
    int mid = (st + ed) / 2;                
    get_sum(st, mid, left, right, idx * 2);     // 자식 노드들 방문
    get_sum(mid + 1, ed, left, right, idx * 2 + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    arr.push_back(0);

    for (int i = 0; i < N; i++) {
        long long int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    make_tree(1, N, 1);

    for (int i = 0; i < M + K; i++) {
        cin >> a >> b >> c; 
        summ = 0;
        if (a == 1) {       // a가 1이면 트리 업데이트
            long long int tmp;
            tmp = c - arr[b];
            arr[b] = c;
            update(1, N, 1, tmp, b);
        }
        else if (a == 2) {  // a가 2면 구간합 구한 후 출력
            get_sum(1, N, b, c, 1);
            cout << summ << "\n";
        }
    }



    return 0;
}