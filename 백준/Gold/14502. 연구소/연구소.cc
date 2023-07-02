#include <iostream>
#include <queue>
#include <vector>

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int N, M;

std::vector<std::vector<int>> mapp;
std::vector<std::pair<int, int>> spot;
int wall = 0;
int result = 0;

int bfs(int y, int x, std::vector<std::vector<int>>& visited) {
    visited[y][x] = 1;
    std::queue<std::pair<int, int>> q;
    q.push({ y, x });
    int c = 1;

    while (!q.empty()) {
        int nowy = q.front().first;
        int nowx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = nowy + dy[i];
            int nx = nowx + dx[i];

            if (0 <= ny && ny < N && 0 <= nx && nx < M) {
                if (visited[ny][nx] == 0 && mapp[ny][nx] == 0) {
                    visited[ny][nx] = 1;
                    q.push({ ny, nx });
                    c++;
                }
            }
        }
    }

    return c;
}

void dfs(int lv, int st) {
    if (lv == 3 || lv == spot.size()) {
        std::vector<std::vector<int>> visited(N, std::vector<int>(M, 0));
        int ret = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (visited[i][j] == 0 && mapp[i][j] == 2) {
                    ret += bfs(i, j, visited);
                }
            }
        }

        if (result < N * M - wall - ret - lv) {
            result = N * M - wall - ret - lv;
        }

        return;
    }

    for (int i = st; i < spot.size(); i++) {
        mapp[spot[i].first][spot[i].second] = 1;
        dfs(lv + 1, i + 1);
        mapp[spot[i].first][spot[i].second] = 0;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> N >> M;

    mapp.resize(N, std::vector<int>(M, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> mapp[i][j];

            if (mapp[i][j] == 0) {
                spot.push_back({ i, j });
            }
            else if (mapp[i][j] == 1) {
                wall++;
            }
        }
    }

    dfs(0, 0);

    std::cout << result;

    return 0;
}
