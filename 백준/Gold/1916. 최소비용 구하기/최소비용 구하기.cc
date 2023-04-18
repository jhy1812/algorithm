#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define INF 1e9

int N, M, a, b, c, st, ed;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cin >> M;
    vector<vector<pair<int, int>>>arr(N + 1, vector<pair<int, int>>());
    vector<int>result(N + 1, INF);

    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        arr[a].push_back(make_pair(b, c));
    }

    for (int i = 1; i <= N; i++) {
        sort(arr[i].begin(), arr[i].end());
    }

    cin >> st >> ed;
    result[st] = 0;

    priority_queue < pair<int, int>, vector < pair<int, int>>, greater<pair<int, int>>>q;
    q.push(make_pair(0, st));

    while (!q.empty()) {
        int nowd = q.top().first;
        int nown = q.top().second;
        q.pop();
        for (int i = 0; i<int(arr[nown].size()); i++) {
            int next = arr[nown][i].first;
            int dis = arr[nown][i].second;
            if (result[next] > nowd + dis) {
                result[next] = nowd + dis;
                q.push(make_pair(result[next], next));
            }
        }
    }

    cout << result[ed];

    return 0;
}
