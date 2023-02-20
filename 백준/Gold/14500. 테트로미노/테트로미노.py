import sys
input = sys.stdin.readline

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

def dfs(y, x, sum, level):
    global maxx
    visited[y][x] = 1
    if level == 3:
        maxx = max(sum, maxx)
        visited[y][x] = 0
        return
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if 0 <= ny < N and 0 <= nx < M:
            if visited[ny][nx] == 0:
                dfs(ny, nx, sum+mapp[ny][nx], level+1)
    visited[y][x] = 0
def f_check(y, x):
    global maxx
    flag = 0
    sum = mapp[y][x]
    minn = 10000
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if 0 <= ny < N and 0 <= nx < M:
            flag += 1
            sum += mapp[ny][nx]
            if minn > mapp[ny][nx]:
                minn = mapp[ny][nx]
    if flag == 4:
        maxx = max(maxx, sum-minn)
    else:
        maxx = max(maxx, sum)
N, M = [*map(int, input().split())]

mapp = [0]*N
visited = [[0 for _ in range(M)] for _ in range(N)]
maxx = 0
for i in range(N):
    mapp[i] = [*map(int, input().split())]
for i in range(N):
    for j in range(M):
        dfs(i, j, mapp[i][j], 0)
        f_check(i, j)
print(maxx)

