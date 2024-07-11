#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <climits> 
using namespace std;

class Node {
public:
    int n;
    int b;
    Node(int n, int b) : n(n), b(b) {}
    bool operator<(const Node& other) const {
        return b < other.b;
    }
};

vector<vector<Node>> arr;
int visited[1001];

void bfs(int s, int t) {
    priority_queue<Node> q;
    visited[s] = INT_MAX;
    q.push(Node(s, visited[s]));
    while (!q.empty()) {
        Node now = q.top();
        q.pop();
        int currentNode = now.n;
        if (currentNode == t) {
            break;
        }
        int currentBandwidth = now.b;
        for (Node& neighbor : arr[currentNode]) {
            int newBandwidth = min(currentBandwidth, neighbor.b);
            if (newBandwidth > visited[neighbor.n]) {
                visited[neighbor.n] = newBandwidth;
                q.push(Node(neighbor.n, newBandwidth));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        arr.clear();
        arr.resize(n + 1);
        memset(visited, -1, sizeof(visited));
        for (int i = 0; i < m; i++) {
            int u, v, b;
            cin >> u >> v >> b;
            arr[u].emplace_back(v, b);
            arr[v].emplace_back(u, b);
        }
        bfs(s, t);
        cout << visited[t] << "\n";
    }
    return 0;
}
