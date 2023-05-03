#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

vector<pair<int,int>>ry;
vector<pair<int,int>>rx;

int puzzlenum = 2;
int boardnum = 2;
int result = 0;

vector<vector<int>>realtable(51, vector<int>(51));
vector<vector<int>>realboard(51, vector<int>(51));

vector<int>usedpuzzle;
vector<int>usedboard;
vector<int>boardarea;
vector<pair<int, int>>spot;
vector<vector<pair<int, int>>>block;

void puzzle_check(int y, int x){
    queue<pair<int, int>>q;
    realtable[y][x] = puzzlenum;
    q.push(make_pair(y, x));
    while(!q.empty()){
        int nowy = q.front().first;
        int nowx = q.front().second;
        q.pop();
        for (int i = 0; i<4; i++){
            int ny = nowy + dy[i];
            int nx = nowx + dx[i];
            if (0 <= ny && ny < N && 0 <= nx && nx < N){
                if (realtable[ny][nx] == 1){
                    realtable[ny][nx] = puzzlenum;
                    q.push(make_pair(ny, nx));
                    block[puzzlenum - 2].push_back(make_pair(ny-y, nx-x));
                }
            }
        }
    }
}

void board_check(int y, int x){
    queue<pair<int, int>>q;
    realboard[y][x] = boardnum;
    q.push(make_pair(y, x));
    int area = 1;
    while (!q.empty()){
        int nowy = q.front().first;
        int nowx = q.front().second;
        q.pop();
        for (int i =0; i<4; i++){
            int ny = nowy + dy[i];
            int nx = nowx + dx[i];
            if (0 <= ny && ny < N && 0 <= nx && nx < N){
                if(realboard[ny][nx] == 0){
                    realboard[ny][nx] = boardnum;
                    q.push(make_pair(ny, nx));
                    area += 1;
                }
            }
        }
    }
    boardarea.push_back(area);
}

void puzzle(int y,int x, int bnum, int pnum, int area){
    for (int i = 0; i<4; i++){
        int flag = 0;
        for (int j = 1; j < int(block[pnum].size()); j++){
            int dyy = block[pnum][j].first;
            int dxx = block[pnum][j].second;
            int ny = y + dyy*ry[i].first + dxx*ry[i].second;
            int nx = x + dyy*rx[i].first + dxx*rx[i].second;
            if (0 <= ny && ny < N && 0 <= nx && nx < N){
                if (realboard[ny][nx] != bnum+2){
                    flag = 1;
                    break;
                }
            }
            else {
                flag = 1;
                break;
            }
        }
        if (flag == 0){
            usedpuzzle[pnum] = 1;
            usedboard[bnum] = 1;
            result += area;
            return;
        }
    }        
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    
    N = int(game_board.size());
    
    for (int i =0;i<N;i++){
        for(int j=0; j<N; j++){
            realboard[i][j] = game_board[i][j];
            realtable[i][j] = table[i][j];
        }
    }
    
    for (int i=0; i<N; i++){
        for (int j = 0; j<N; j++){
            if (realtable[i][j] == 1){
                usedpuzzle.push_back(0);
                block.push_back({});
                block[puzzlenum-2].push_back(make_pair(0, 0));
                puzzle_check(i, j);
                puzzlenum += 1;
            }
            if (realboard[i][j] == 0){
                usedboard.push_back(0);
                board_check(i, j);
                boardnum += 1;
            }
        }
    }
     
    ry.push_back(make_pair(1, 0));
    ry.push_back(make_pair(0, -1));
    ry.push_back(make_pair(-1, 0));
    ry.push_back(make_pair(0, 1));
    
    rx.push_back(make_pair(0, 1));
    rx.push_back(make_pair(1, 0));
    rx.push_back(make_pair(0, -1));
    rx.push_back(make_pair(-1, 0));
    
    for (int i = 0; i<int(block.size()); i++){
        if(usedpuzzle[i] == 1){
            continue;
        }
        for (int j = 0; j<N ; j++){
            if(usedpuzzle[i] == 1){
                break;
            }
            for (int k = 0; k<N ; k++){
                if(usedpuzzle[i] == 1){
                    break;
                }
                if (realboard[j][k] != 1 && usedboard[realboard[j][k]-2] == 0){
                    if (int(block[i].size()) == boardarea[realboard[j][k]-2]){
                        if (boardarea[realboard[j][k]-2] == 1){
                            result += 1;
                            usedboard[realboard[j][k]-2] = 1;
                            usedpuzzle[i] = 1;
                        }
                        else{
                            puzzle(j, k, realboard[j][k]-2, i, boardarea[realboard[j][k]-2]);
                        }
                    }
                } 
            }
        }
    }
    return result;
}