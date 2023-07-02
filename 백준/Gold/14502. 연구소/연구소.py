import sys
from collections import deque

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

input = sys.stdin.readline

N, M = [*map(int, input().split())]

mapp = []
spot = []

wall = 0
result = 0

def bfs(y, x, visited, c):
    visited[y][x] = 1
    q = deque()
    q.append((y, x))
    while q:
        now = q.popleft()
        for i in range(4):
            ny = now[0] + dy[i]
            nx = now[1] + dx[i]
            if 0 <= ny < N and 0 <= nx < M:
                if visited[ny][nx] == 0 and mapp[ny][nx] == 0:
                    visited[ny][nx] = 1
                    q.append((ny, nx))
                    c += 1
    return c

def dfs(lv, st):
    global result
    if lv == 3 or lv == len(spot):
        visited = [[0 for i in range(M)] for j in range(N)]
        ret = 0
        for i in range(N):
            for j in range(M):
                if visited[i][j] == 0 and mapp[i][j] == 2:
                    ret += bfs(i, j, visited, 1)
        if result < N*M - wall - ret - lv:
            result = N*M - wall - ret - lv
        return

    for i in range(st, len(spot)):
        mapp[spot[i][0]][spot[i][1]] = 1
        dfs(lv + 1, i + 1)
        mapp[spot[i][0]][spot[i][1]] = 0

for i in range(N):
    mapp.append([*map(int, input().split())])

for i in range(N):
    for j in range(M):
        if mapp[i][j] == 0:
            spot.append((i, j))
        elif mapp[i][j] == 1:
            wall += 1

dfs(0, 0)

print(result)