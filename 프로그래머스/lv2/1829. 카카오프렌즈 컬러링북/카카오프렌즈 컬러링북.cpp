#include <vector>
#include <queue>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};
    int cnt = 0;
    int maxx = 0;
    vector<vector<int>>visited(m, vector<int>(n));
    for (int i = 0; i<m; i++){
        for (int j = 0; j<n; j++){
            visited[i][j] = 0;
        }
    }
    
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (picture[i][j] != 0 && visited[i][j] == 0){
                int area = 1;
                cnt += 1;
                queue<pair<int, int>>q;
                q.push(make_pair(i, j));
                visited[i][j] = 1;
                while (!q.empty()){
                    int nowy = q.front().first;
                    int nowx = q.front().second;
                    q.pop();
                    for(int k = 0; k<4; k++){
                        int ny = nowy + dy[k];
                        int nx = nowx + dx[k];
                        if (0 <= ny && ny < m && 0 <= nx && nx < n){
                            if (picture[ny][nx] == picture[i][j] && visited[ny][nx] == 0){
                                q.push(make_pair(ny, nx));
                                visited[ny][nx] = 1;
                                area += 1;
                            }
                        }
                    }
                }
                if (maxx < area){
                    maxx = area;
                }
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = cnt;
    answer[1] = maxx;
    return answer;
}